/*
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

#include "py/obj.h"
#include "py/mphal.h"
#include "mimxrt10xx/periph.h"

LPI2C_Type *const mcu_i2c_banks[2] = { LPI2C1, LPI2C2 };

const mcu_periph_obj_t mcu_i2c_sda_list[2] = {
    PERIPH_PIN(1, 0, 0, 0, &pin_GPIO_AD_B1_15),

    PERIPH_PIN(2, 2, 0, 0, &pin_GPIO_EMC_18),
};

const mcu_periph_obj_t mcu_i2c_scl_list[2] = {
    PERIPH_PIN(1, 0, 0, 0, &pin_GPIO_AD_B1_14),

    PERIPH_PIN(2, 2, 0, 0, &pin_GPIO_EMC_19),
};

LPSPI_Type *const mcu_spi_banks[2] = { LPSPI1, LPSPI2 };

const mcu_periph_obj_t mcu_spi_sck_list[2] = {
    PERIPH_PIN(1, 1, 0, 0, &pin_GPIO_AD_B0_10),

    PERIPH_PIN(2, 4, 0, 0, &pin_GPIO_SD_B1_07),
};

const mcu_periph_obj_t mcu_spi_sdo_list[2] = {
    PERIPH_PIN(1, 1, 0, 0, &pin_GPIO_AD_B0_12),

    PERIPH_PIN(2, 4, 0, 0, &pin_GPIO_SD_B1_08),
};

const mcu_periph_obj_t mcu_spi_sdi_list[2] = {
    PERIPH_PIN(1, 1, 0, 0, &pin_GPIO_AD_B0_13),

    PERIPH_PIN(2, 4, 0, 0, &pin_GPIO_SD_B1_09),
};

LPUART_Type *const mcu_uart_banks[4] = { LPUART1, LPUART2, LPUART3, LPUART4 };

const mcu_periph_obj_t mcu_uart_rx_list[6] = {
    PERIPH_PIN(1, 2, 0, 0, &pin_GPIO_AD_B0_07),

    PERIPH_PIN(2, 2, 0, 0, &pin_GPIO_EMC_23),

    PERIPH_PIN(3, 2, 0, 0, &pin_GPIO_EMC_07),
    PERIPH_PIN(3, 2, 0, 0, &pin_GPIO_AD_B0_15),

    PERIPH_PIN(4, 2, 0, 0, &pin_GPIO_EMC_33),
    PERIPH_PIN(4, 2, 0, 0, &pin_GPIO_AD_B1_11),
};

const mcu_periph_obj_t mcu_uart_tx_list[6] = {
    PERIPH_PIN(1, 2, 0, 0, &pin_GPIO_AD_B0_06),

    PERIPH_PIN(2, 2, 0, 0, &pin_GPIO_EMC_22),

    PERIPH_PIN(3, 2, 0, 0, &pin_GPIO_EMC_06),
    PERIPH_PIN(3, 2, 0, 0, &pin_GPIO_AD_B0_14),

    PERIPH_PIN(4, 2, 0, 0, &pin_GPIO_EMC_32),
    PERIPH_PIN(4, 2, 0, 0, &pin_GPIO_AD_B1_10),
};

const mcu_periph_obj_t mcu_uart_rts_list[3] = {
    PERIPH_PIN(1, 2, 0, 0, &pin_GPIO_AD_B0_09),

    PERIPH_PIN(2, 2, 0, 0, &pin_GPIO_EMC_21),

    PERIPH_PIN(3, 2, 0, 0, &pin_GPIO_AD_B0_13),
};

const mcu_periph_obj_t mcu_uart_cts_list[3] = {
    PERIPH_PIN(1, 2, 0, 0, &pin_GPIO_AD_B0_08),

    PERIPH_PIN(2, 2, 0, 0, &pin_GPIO_EMC_20),

    PERIPH_PIN(3, 2, 0, 0, &pin_GPIO_AD_B0_12),
};

I2S_Type *const mcu_i2s_banks[3] = { SAI1, SAI2, SAI3 };

const mcu_periph_obj_t mcu_i2s_rx_data0_list[3] = {
    PERIPH_PIN(1, 3, 0, 0, &pin_GPIO_EMC_21),

    PERIPH_PIN(2, 3, 0, 0, &pin_GPIO_EMC_08),

    PERIPH_PIN(3, 3, 0, 0, &pin_GPIO_SD_B1_11),
};

const mcu_periph_obj_t mcu_i2s_rx_sync_list[3] = {
    PERIPH_PIN(1, 3, 0, 0, &pin_GPIO_EMC_18),

    PERIPH_PIN(2, 3, 0, 0, &pin_GPIO_EMC_07),

    PERIPH_PIN(3, 3, 0, 0, &pin_GPIO_SD_B1_10),
};

const mcu_periph_obj_t mcu_i2s_tx_bclk_list[4] = {
    PERIPH_PIN(1, 3, 0, 0, &pin_GPIO_EMC_26),

    PERIPH_PIN(2, 3, 0, 0, &pin_GPIO_EMC_04),

    PERIPH_PIN(3, 3, 0, 0, &pin_GPIO_EMC_33),
    PERIPH_PIN(3, 3, 0, 0, &pin_GPIO_SD_B1_06),
};

const mcu_periph_obj_t mcu_i2s_tx_data0_list[4] = {
    PERIPH_PIN(1, 3, 0, 0, &pin_GPIO_EMC_25),

    PERIPH_PIN(2, 3, 0, 0, &pin_GPIO_EMC_06),

    PERIPH_PIN(3, 3, 0, 0, &pin_GPIO_EMC_32),
    PERIPH_PIN(3, 3, 0, 0, &pin_GPIO_SD_B1_08),
};

const mcu_periph_obj_t mcu_i2s_tx_sync_list[4] = {
    PERIPH_PIN(1, 3, 0, 0, &pin_GPIO_EMC_27),

    PERIPH_PIN(2, 3, 0, 0, &pin_GPIO_EMC_05),

    PERIPH_PIN(3, 3, 0, 0, &pin_GPIO_EMC_34),
    PERIPH_PIN(3, 3, 0, 0, &pin_GPIO_SD_B1_07),
};

const mcu_periph_obj_t mcu_mqs_left_list[2] = {
    PERIPH_PIN(3, 2, 0, 0, &pin_GPIO_EMC_17),
    PERIPH_PIN(3, 1, 0, 0, &pin_GPIO_AD_B0_07),
};

const mcu_periph_obj_t mcu_mqs_right_list[2] = {
    PERIPH_PIN(3, 2, 0, 0, &pin_GPIO_EMC_16),
    PERIPH_PIN(3, 1, 0, 0, &pin_GPIO_AD_B0_06),
};

const mcu_pwm_obj_t mcu_pwm_list[12] = {
    PWM_PIN(PWM1, kPWM_Module_0, kPWM_PwmA, IOMUXC_GPIO_EMC_26_FLEXPWM1_PWMA00, &pin_GPIO_EMC_26),

    PWM_PIN(PWM1, kPWM_Module_0, kPWM_PwmB, IOMUXC_GPIO_EMC_27_FLEXPWM1_PWMB00, &pin_GPIO_EMC_27),

    PWM_PIN(PWM1, kPWM_Module_1, kPWM_PwmA, IOMUXC_GPIO_EMC_24_FLEXPWM1_PWMA01, &pin_GPIO_EMC_24),

    PWM_PIN(PWM1, kPWM_Module_1, kPWM_PwmB, IOMUXC_GPIO_EMC_25_FLEXPWM1_PWMB01, &pin_GPIO_EMC_25),

    PWM_PIN(PWM1, kPWM_Module_2, kPWM_PwmA, IOMUXC_GPIO_EMC_22_FLEXPWM1_PWMA02, &pin_GPIO_EMC_22),
    PWM_PIN(PWM1, kPWM_Module_2, kPWM_PwmA, IOMUXC_GPIO_AD_B1_10_FLEXPWM1_PWMA02, &pin_GPIO_AD_B1_10),

    PWM_PIN(PWM1, kPWM_Module_2, kPWM_PwmB, IOMUXC_GPIO_EMC_23_FLEXPWM1_PWMB02, &pin_GPIO_EMC_23),
    PWM_PIN(PWM1, kPWM_Module_2, kPWM_PwmB, IOMUXC_GPIO_AD_B1_11_FLEXPWM1_PWMB02, &pin_GPIO_AD_B1_11),

    PWM_PIN(PWM1, kPWM_Module_3, kPWM_PwmA, IOMUXC_GPIO_EMC_20_FLEXPWM1_PWMA03, &pin_GPIO_EMC_20),
    PWM_PIN(PWM1, kPWM_Module_3, kPWM_PwmA, IOMUXC_GPIO_AD_B1_12_FLEXPWM1_PWMA03, &pin_GPIO_AD_B1_12),

    PWM_PIN(PWM1, kPWM_Module_3, kPWM_PwmB, IOMUXC_GPIO_EMC_21_FLEXPWM1_PWMB03, &pin_GPIO_EMC_21),
    PWM_PIN(PWM1, kPWM_Module_3, kPWM_PwmB, IOMUXC_GPIO_AD_B1_13_FLEXPWM1_PWMB03, &pin_GPIO_AD_B1_13),
};
