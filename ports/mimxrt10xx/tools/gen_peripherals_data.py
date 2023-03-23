import sys
import pathlib
import xml.etree.ElementTree as ET

SIGNALS = {
    "LPI2C": ["SDA", "SCL"],
    "LPSPI": ["SCK", "SDO", "SDI"],
    "LPUART": ["RX", "TX", "RTS", "CTS"],
    "I2S": ["RX_DATA0", "RX_SYNC", "TX_BCLK", "TX_DATA0", "TX_SYNC"],
    "MQS": ["LEFT", "RIGHT"],
}

SIGNAL_RENAME = {
    "CTS_B": "CTS",
    "RTS_B": "RTS",
    "RXD": "RX",
    "TXD": "TX",
    "TX_DATA00": "TX_DATA0",
    "RX_DATA00": "RX_DATA0",
    "TX_DATA": "TX_DATA0",
    "RX_DATA": "RX_DATA0",
}

SKIP_LPSR = True

svd_folder = pathlib.Path(sys.argv[1])

# Download and extract config tools data from https://mcuxpresso.nxp.com/en/select_config_tools_data
config_data_folder = pathlib.Path(sys.argv[2])
devices = sys.argv[3:]

peripherals_dir = pathlib.Path("peripherals/mimxrt10xx")

copyright = """/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Lucian Copeland for Adafruit Industries
 * Copyright (c) 2019 Artur Pacholec
 * Copyright (c) 2023 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
"""

for device in devices:
    print(device)
    svd_fn = svd_folder / device / (device + ".xml")
    if not svd_fn.exists():
        svd_fn = svd_folder / device / (device + "_cm7.xml")

    pin_to_analog = {}
    out_dir = peripherals_dir / device
    largest_signals = None
    for signal_file in config_data_folder.glob(
        f"{device}*ConfigTools_data*/**/signal_configuration.xml"
    ):
        if largest_signals is None or signal_file.stat().st_size > largest_signals.stat().st_size:
            largest_signals = signal_file

    # Use the signal file to find analog connections
    signal_tree = ET.parse(largest_signals)
    signal_root = signal_tree.getroot()
    for connection in signal_root.iter("connections"):
        if "name_part" not in connection.attrib or not connection.attrib["name_part"].startswith(
            "ADC"
        ):
            continue
        name_part = connection.attrib["name_part"]
        try:
            assign = next(connection.iter("assign"))
        except StopIteration:
            continue
        split_pin = assign.attrib["register"].split("_")
        pin_name = "_".join(split_pin[split_pin.index("GPIO") :])
        adc_instance, adc_channel = name_part.split("_")

        try:
            adc_channel = int(adc_channel[2:])
        except ValueError:
            continue
        pin_to_analog[pin_name] = (adc_instance, adc_channel)

    # Find USB pins
    usb_pins = []
    all_pins = set()
    for pin in signal_root.iter("pin"):
        pin_name = pin.get("name")
        if SKIP_LPSR and "LPSR" in pin_name:
            continue
        all_pins.add(pin_name)
        if not pin_name.startswith("USB_OTG"):
            continue
        if not pin_name.endswith(("DN", "DP")):
            continue
        usb_pins.append(pin_name)

    # Find peripherals
    all_peripherals = {}
    for peripheral in signal_root.iter("peripheral"):
        ptype = peripheral.get("peripheral_type")
        if ptype not in all_peripherals:
            all_peripherals[ptype] = []
        all_peripherals[ptype].append(peripheral.get("id"))

    print(svd_fn)
    tree = ET.parse(svd_fn)
    root = tree.getroot()
    pin_number = 0
    last_gpio_base = None
    mux_register_base = None

    pins_h = [
        copyright,
        "#pragma once",
        "",
        "#define FORMAT_PIN(pin_name) extern const mcu_pin_obj_t pin_##pin_name;",
        '#include "pin_names.h"',
        "#undef FORMAT_PIN",
    ]
    pins_c = [
        copyright,
        '#include "py/obj.h"',
        '#include "py/mphal.h"',
        '#include "mimxrt10xx/pins.h"',
        "",
    ]
    pin_names_h = [copyright, "", "// define FORMAT_PIN(pin_name) and then include this file."]
    mux_registers_by_pin = {}
    peripheral_inputs = {}
    pwm_outputs = []
    for register in root.iter("register"):
        name = register.find("name").text
        if name.endswith("SELECT_INPUT"):
            name_split = name.split("_")
            instance = name_split[0]
            signal = "_".join(name_split[1:-2])
            signal = SIGNAL_RENAME.get(signal, signal)
            if instance not in peripheral_inputs:
                peripheral_inputs[instance] = {}
            if signal not in peripheral_inputs[instance]:
                peripheral_inputs[instance][signal] = {}
            for evalue in register.iter("enumeratedValue"):
                ename = evalue.find("name").text.strip("_")
                if "_ALT" in ename:
                    pin_name, alt = ename.rsplit("_", maxsplit=1)
                else:
                    pin_name = ename
                    alt = evalue.find("description").text.rsplit(maxsplit=1)[1]
                if SKIP_LPSR and "LPSR" in pin_name:
                    continue
                alt = int(alt[3:])
                value = int(evalue.find("value").text, 0)
                peripheral_inputs[instance][signal][pin_name] = [alt, name, value]
        # Mux registers come before PAD registers.
        elif name.startswith("SW_MUX_CTL_PAD_GPIO"):
            address_offset = int(register.find("addressOffset").text, 16)
            if mux_register_base is None:
                mux_register_base = address_offset

            split_pin = name.split("_")
            pin_name = "_".join(split_pin[4:])
            if pin_name not in all_pins:
                continue
            gpio_base = "_".join(split_pin[4:-1])

            mux_registers_by_pin[pin_name] = register

            if last_gpio_base != gpio_base:
                pin_names_h.append("")
            last_gpio_base = gpio_base

            pin_number += 1

            pin_names_h.append(f"FORMAT_PIN({pin_name})")
        elif name.startswith("SW_PAD_CTL_PAD_GPIO"):
            split_pin = name.split("_")
            pin_name = "_".join(split_pin[4:])
            if pin_name not in all_pins:
                continue
            mux_register = mux_registers_by_pin[pin_name]
            mux_reset = int(mux_register.find("resetValue").text, 16)

            pad_reset = int(register.find("resetValue").text, 16)

            # Look through alt modes to find GPIO.
            mux_field = mux_register.find("fields").find("field")
            assert mux_field.find("name").text == "MUX_MODE"
            for alt in mux_field.iter("enumeratedValue"):
                desc = alt.find("description").text
                if "FLEXPWM" in desc:
                    desc_split = desc.split()
                    alt = desc_split[3]
                    connection = desc_split[6]
                    pwm_instance = int(connection[7:8])
                    if connection.count("_") == 1:
                        # Form: FLEXPWM#_PWMC##
                        channel = connection[-3:-2]
                        module = int(connection[-2:])
                    else:  # two _
                        # Form: FLEXPWM#_PWM#_C
                        channel = connection[-1:]
                        module = int(connection[-3:-2])
                    pwm_outputs.append((pwm_instance, module, channel, connection, pin_name))
                elif "GPIO" in desc:
                    alt_name = desc.split()[-4]
                    # The 117x has a GPIO mux between GPIOn and CM7_GPIOn. For now,
                    # we use the the slow, default GPIOn.
                    if alt_name.startswith("GPIO_MUX"):
                        alt_name = alt_name.replace("GPIO_MUX", "GPIO")
                    gpio_instance, gpio_number = alt_name.split("_")
                    if gpio_instance == "GPIOMUX":
                        gpio_instance = "GPIO1"
                    gpio_number = int(gpio_number[2:])
                else:
                    desc_split = desc.split()
                    alt = desc_split[3]
                    connection = desc_split[6]
                    alt = int(alt[3:])
                    if "_" not in connection:
                        print("skipping", pin_name, connection)
                        continue
                    instance, signal = connection.split("_", maxsplit=1)
                    signal = SIGNAL_RENAME.get(signal, signal)
                    if instance not in peripheral_inputs:
                        peripheral_inputs[instance] = {}
                    if signal not in peripheral_inputs[instance]:
                        peripheral_inputs[instance][signal] = {}
                    peripheral_inputs[instance][signal][pin_name] = [alt, None, 0]

            if pin_name in pin_to_analog:
                adc_instance, adc_channel = pin_to_analog[pin_name]
            else:
                adc_instance = "NO_ADC"
                adc_channel = 0

            pins_c.append(
                f"const mcu_pin_obj_t pin_{pin_name} = PIN({gpio_instance}, {gpio_number}, {pin_name}, {adc_instance}, {adc_channel}, 0x{mux_reset:08X}, 0x{pad_reset:08X});"
            )

    pins_c.append("")

    for pin_name in sorted(usb_pins):
        pin_names_h.append(f"FORMAT_PIN({pin_name})")
        pins_c.append(f"const mcu_pin_obj_t pin_{pin_name} = {{ {{ &mcu_pin_type }}, }};")

    pin_names_h.append("")
    pins_c.append("")

    pins_h.append("")
    pins_h.append(f"#define PIN_COUNT (IOMUXC_SW_PAD_CTL_PAD_COUNT + {len(usb_pins)})")
    pins_h.append(f"extern const mcu_pin_obj_t mcu_pin_list[PIN_COUNT];")
    pins_h.append("")

    out_dir.mkdir(exist_ok=True)

    (out_dir / "pin_names.h").write_text("\n".join(pin_names_h))
    (out_dir / "pins.h").write_text("\n".join(pins_h))
    (out_dir / "pins.c").write_text("\n".join(pins_c))

    periph_h = [copyright, "#pragma once"]
    periph_c = [
        copyright,
        '#include "py/obj.h"',
        '#include "py/mphal.h"',
        '#include "mimxrt10xx/periph.h"',
        "",
    ]

    for ptype in SIGNALS:
        instances = all_peripherals[ptype]
        short_name = ptype.lower()
        if short_name.startswith("lp"):
            short_name = short_name[2:]
        # Only one MQS exists and it is related to SAI3
        if ptype != "MQS":
            periph_h.append(
                f"extern {ptype}_Type *const mcu_{short_name}_banks[{len(instances)}];"
            )
            joined_instances = ", ".join(instances)
            periph_c.append(
                f"{ptype}_Type *const mcu_{short_name}_banks[{len(instances)}] = {{ {joined_instances} }};"
            )
            periph_c.append("")
        for signal in SIGNALS[ptype]:
            pin_count = 0
            for instance in instances:
                if instance not in peripheral_inputs or signal not in peripheral_inputs[instance]:
                    continue
                pin_count += len(peripheral_inputs[instance][signal])
            periph_h.append(
                f"extern const mcu_periph_obj_t mcu_{short_name}_{signal.lower()}_list[{pin_count}];"
            )
            periph_c.append(
                f"const mcu_periph_obj_t mcu_{short_name}_{signal.lower()}_list[{pin_count}] = {{"
            )
            for instance in instances:
                if instance not in peripheral_inputs or signal not in peripheral_inputs[instance]:
                    continue
                # MQS is tied to SAI3
                if instance == "MQS":
                    instance_number = 3
                else:
                    instance_number = int(instance[len(ptype) :])
                    if instance_number > 1:
                        periph_c.append("")
                pins = peripheral_inputs[instance][signal]
                pin_names = list(pins.keys())
                pin_names.sort(key=lambda x: pins[x][-1])
                for pin_name in pin_names:
                    alt, select_input, input_value = pins[pin_name]
                    if select_input:
                        select_input = f"kIOMUXC_{select_input}"
                    else:
                        select_input = "0"
                    periph_c.append(
                        f"    PERIPH_PIN({instance_number}, {alt}, {select_input}, {input_value}, &pin_{pin_name}),"
                    )
            periph_c.append(f"}};")
            periph_c.append(f"")
        periph_h.append("")

    pwm_outputs.sort(key=lambda x: x[:3])
    periph_c.append(f"const mcu_pwm_obj_t mcu_pwm_list[{len(pwm_outputs)}] = {{")
    periph_h.append(f"extern const mcu_pwm_obj_t mcu_pwm_list[{len(pwm_outputs)}];")
    last_channel = None
    for pwm_instance, module, channel, connection, pin_name in pwm_outputs:
        this_channel = (pwm_instance, module, channel)
        if last_channel is not None and last_channel != this_channel:
            periph_c.append("")
        last_channel = this_channel
        periph_c.append(
            f"    PWM_PIN(PWM{pwm_instance}, kPWM_Module_{module}, kPWM_Pwm{channel}, IOMUXC_{pin_name}_{connection}, &pin_{pin_name}),"
        )
    periph_c.append(f"}};")
    periph_c.append("")

    (out_dir / "periph.h").write_text("\n".join(periph_h))
    (out_dir / "periph.c").write_text("\n".join(periph_c))
