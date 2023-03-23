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
#include "mimxrt10xx/pins.h"

const mcu_pin_obj_t pin_GPIO_EMC_B1_00 = PIN(GPIO7, 0, GPIO_EMC_B1_00, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_01 = PIN(GPIO7, 1, GPIO_EMC_B1_01, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_02 = PIN(GPIO7, 2, GPIO_EMC_B1_02, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_03 = PIN(GPIO7, 3, GPIO_EMC_B1_03, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_04 = PIN(GPIO7, 4, GPIO_EMC_B1_04, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_05 = PIN(GPIO7, 5, GPIO_EMC_B1_05, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_06 = PIN(GPIO7, 6, GPIO_EMC_B1_06, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_07 = PIN(GPIO7, 7, GPIO_EMC_B1_07, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_08 = PIN(GPIO7, 8, GPIO_EMC_B1_08, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_09 = PIN(GPIO7, 9, GPIO_EMC_B1_09, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_10 = PIN(GPIO7, 10, GPIO_EMC_B1_10, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_11 = PIN(GPIO7, 11, GPIO_EMC_B1_11, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_12 = PIN(GPIO7, 12, GPIO_EMC_B1_12, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_13 = PIN(GPIO7, 13, GPIO_EMC_B1_13, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_14 = PIN(GPIO7, 14, GPIO_EMC_B1_14, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_15 = PIN(GPIO7, 15, GPIO_EMC_B1_15, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_16 = PIN(GPIO7, 16, GPIO_EMC_B1_16, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_17 = PIN(GPIO7, 17, GPIO_EMC_B1_17, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_18 = PIN(GPIO7, 18, GPIO_EMC_B1_18, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_19 = PIN(GPIO7, 19, GPIO_EMC_B1_19, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_20 = PIN(GPIO7, 20, GPIO_EMC_B1_20, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_21 = PIN(GPIO7, 21, GPIO_EMC_B1_21, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_22 = PIN(GPIO7, 22, GPIO_EMC_B1_22, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_23 = PIN(GPIO7, 23, GPIO_EMC_B1_23, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_24 = PIN(GPIO7, 24, GPIO_EMC_B1_24, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_25 = PIN(GPIO7, 25, GPIO_EMC_B1_25, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_26 = PIN(GPIO7, 26, GPIO_EMC_B1_26, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_27 = PIN(GPIO7, 27, GPIO_EMC_B1_27, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_28 = PIN(GPIO7, 28, GPIO_EMC_B1_28, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_29 = PIN(GPIO7, 29, GPIO_EMC_B1_29, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_30 = PIN(GPIO7, 30, GPIO_EMC_B1_30, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_31 = PIN(GPIO7, 31, GPIO_EMC_B1_31, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_32 = PIN(GPIO8, 0, GPIO_EMC_B1_32, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_33 = PIN(GPIO8, 1, GPIO_EMC_B1_33, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_34 = PIN(GPIO8, 2, GPIO_EMC_B1_34, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_35 = PIN(GPIO8, 3, GPIO_EMC_B1_35, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_36 = PIN(GPIO8, 4, GPIO_EMC_B1_36, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_37 = PIN(GPIO8, 5, GPIO_EMC_B1_37, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_38 = PIN(GPIO8, 6, GPIO_EMC_B1_38, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_39 = PIN(GPIO8, 7, GPIO_EMC_B1_39, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_40 = PIN(GPIO8, 8, GPIO_EMC_B1_40, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B1_41 = PIN(GPIO8, 9, GPIO_EMC_B1_41, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_00 = PIN(GPIO8, 10, GPIO_EMC_B2_00, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_01 = PIN(GPIO8, 11, GPIO_EMC_B2_01, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_02 = PIN(GPIO8, 12, GPIO_EMC_B2_02, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_03 = PIN(GPIO8, 13, GPIO_EMC_B2_03, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_04 = PIN(GPIO8, 14, GPIO_EMC_B2_04, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_05 = PIN(GPIO8, 15, GPIO_EMC_B2_05, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_06 = PIN(GPIO8, 16, GPIO_EMC_B2_06, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_07 = PIN(GPIO8, 17, GPIO_EMC_B2_07, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_08 = PIN(GPIO8, 18, GPIO_EMC_B2_08, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_EMC_B2_09 = PIN(GPIO8, 19, GPIO_EMC_B2_09, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_10 = PIN(GPIO8, 20, GPIO_EMC_B2_10, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_11 = PIN(GPIO8, 21, GPIO_EMC_B2_11, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_EMC_B2_12 = PIN(GPIO8, 22, GPIO_EMC_B2_12, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_13 = PIN(GPIO8, 23, GPIO_EMC_B2_13, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_14 = PIN(GPIO8, 24, GPIO_EMC_B2_14, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_15 = PIN(GPIO8, 25, GPIO_EMC_B2_15, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_16 = PIN(GPIO8, 26, GPIO_EMC_B2_16, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_17 = PIN(GPIO8, 27, GPIO_EMC_B2_17, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_18 = PIN(GPIO8, 28, GPIO_EMC_B2_18, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_19 = PIN(GPIO8, 29, GPIO_EMC_B2_19, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_EMC_B2_20 = PIN(GPIO8, 30, GPIO_EMC_B2_20, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_AD_00 = PIN(GPIO8, 31, GPIO_AD_00, NO_ADC, 0, 0x00000005, 0x0000000E);
const mcu_pin_obj_t pin_GPIO_AD_01 = PIN(GPIO9, 0, GPIO_AD_01, NO_ADC, 0, 0x00000005, 0x0000000E);
const mcu_pin_obj_t pin_GPIO_AD_02 = PIN(GPIO9, 1, GPIO_AD_02, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_03 = PIN(GPIO9, 2, GPIO_AD_03, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_04 = PIN(GPIO9, 3, GPIO_AD_04, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_05 = PIN(GPIO9, 4, GPIO_AD_05, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_06 = PIN(GPIO9, 5, GPIO_AD_06, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_07 = PIN(GPIO9, 6, GPIO_AD_07, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_08 = PIN(GPIO9, 7, GPIO_AD_08, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_09 = PIN(GPIO9, 8, GPIO_AD_09, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_10 = PIN(GPIO9, 9, GPIO_AD_10, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_11 = PIN(GPIO9, 10, GPIO_AD_11, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_12 = PIN(GPIO9, 11, GPIO_AD_12, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_13 = PIN(GPIO9, 12, GPIO_AD_13, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_14 = PIN(GPIO9, 13, GPIO_AD_14, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_15 = PIN(GPIO9, 14, GPIO_AD_15, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_16 = PIN(GPIO9, 15, GPIO_AD_16, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_17 = PIN(GPIO9, 16, GPIO_AD_17, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_18 = PIN(GPIO9, 17, GPIO_AD_18, NO_ADC, 0, 0x00000005, 0x0000000E);
const mcu_pin_obj_t pin_GPIO_AD_19 = PIN(GPIO9, 18, GPIO_AD_19, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_20 = PIN(GPIO9, 19, GPIO_AD_20, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_21 = PIN(GPIO9, 20, GPIO_AD_21, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_22 = PIN(GPIO9, 21, GPIO_AD_22, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_23 = PIN(GPIO9, 22, GPIO_AD_23, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_24 = PIN(GPIO9, 23, GPIO_AD_24, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_25 = PIN(GPIO9, 24, GPIO_AD_25, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_26 = PIN(GPIO9, 25, GPIO_AD_26, NO_ADC, 0, 0x00000005, 0x0000000E);
const mcu_pin_obj_t pin_GPIO_AD_27 = PIN(GPIO9, 26, GPIO_AD_27, NO_ADC, 0, 0x00000005, 0x0000000E);
const mcu_pin_obj_t pin_GPIO_AD_28 = PIN(GPIO9, 27, GPIO_AD_28, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_29 = PIN(GPIO9, 28, GPIO_AD_29, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_30 = PIN(GPIO9, 29, GPIO_AD_30, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_31 = PIN(GPIO9, 30, GPIO_AD_31, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_32 = PIN(GPIO9, 31, GPIO_AD_32, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_33 = PIN(GPIO10, 0, GPIO_AD_33, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_34 = PIN(GPIO10, 1, GPIO_AD_34, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_AD_35 = PIN(GPIO10, 2, GPIO_AD_35, NO_ADC, 0, 0x00000005, 0x0000000E);
const mcu_pin_obj_t pin_GPIO_SD_B1_00 = PIN(GPIO10, 3, GPIO_SD_B1_00, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_SD_B1_01 = PIN(GPIO10, 4, GPIO_SD_B1_01, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B1_02 = PIN(GPIO10, 5, GPIO_SD_B1_02, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_SD_B1_03 = PIN(GPIO10, 6, GPIO_SD_B1_03, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_SD_B1_04 = PIN(GPIO10, 7, GPIO_SD_B1_04, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_SD_B1_05 = PIN(GPIO10, 8, GPIO_SD_B1_05, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_00 = PIN(GPIO10, 9, GPIO_SD_B2_00, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_01 = PIN(GPIO10, 10, GPIO_SD_B2_01, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_02 = PIN(GPIO10, 11, GPIO_SD_B2_02, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_03 = PIN(GPIO10, 12, GPIO_SD_B2_03, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_04 = PIN(GPIO10, 13, GPIO_SD_B2_04, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_SD_B2_05 = PIN(GPIO10, 14, GPIO_SD_B2_05, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_SD_B2_06 = PIN(GPIO10, 15, GPIO_SD_B2_06, NO_ADC, 0, 0x00000005, 0x00000004);
const mcu_pin_obj_t pin_GPIO_SD_B2_07 = PIN(GPIO10, 16, GPIO_SD_B2_07, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_08 = PIN(GPIO10, 17, GPIO_SD_B2_08, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_09 = PIN(GPIO10, 18, GPIO_SD_B2_09, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_10 = PIN(GPIO10, 19, GPIO_SD_B2_10, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_SD_B2_11 = PIN(GPIO10, 20, GPIO_SD_B2_11, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_DISP_B1_00 = PIN(GPIO10, 21, GPIO_DISP_B1_00, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_DISP_B1_01 = PIN(GPIO10, 22, GPIO_DISP_B1_01, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_DISP_B1_02 = PIN(GPIO10, 23, GPIO_DISP_B1_02, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_DISP_B1_03 = PIN(GPIO10, 24, GPIO_DISP_B1_03, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_DISP_B1_04 = PIN(GPIO10, 25, GPIO_DISP_B1_04, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_DISP_B1_05 = PIN(GPIO10, 26, GPIO_DISP_B1_05, NO_ADC, 0, 0x00000005, 0x00000008);
const mcu_pin_obj_t pin_GPIO_DISP_B1_06 = PIN(GPIO10, 27, GPIO_DISP_B1_06, NO_ADC, 0, 0x00000005, 0x0000000C);
const mcu_pin_obj_t pin_GPIO_DISP_B1_07 = PIN(GPIO10, 28, GPIO_DISP_B1_07, NO_ADC, 0, 0x00000005, 0x0000000C);
const mcu_pin_obj_t pin_GPIO_DISP_B1_08 = PIN(GPIO10, 29, GPIO_DISP_B1_08, NO_ADC, 0, 0x00000005, 0x0000000C);
const mcu_pin_obj_t pin_GPIO_DISP_B1_09 = PIN(GPIO10, 30, GPIO_DISP_B1_09, NO_ADC, 0, 0x00000005, 0x0000000C);
const mcu_pin_obj_t pin_GPIO_DISP_B1_10 = PIN(GPIO10, 31, GPIO_DISP_B1_10, NO_ADC, 0, 0x00000005, 0x0000000C);
const mcu_pin_obj_t pin_GPIO_DISP_B1_11 = PIN(GPIO11, 0, GPIO_DISP_B1_11, NO_ADC, 0, 0x00000005, 0x0000000C);
const mcu_pin_obj_t pin_GPIO_DISP_B2_00 = PIN(GPIO11, 1, GPIO_DISP_B2_00, NO_ADC, 0, 0x00000005, 0x00000002);
const mcu_pin_obj_t pin_GPIO_DISP_B2_01 = PIN(GPIO11, 2, GPIO_DISP_B2_01, NO_ADC, 0, 0x00000005, 0x00000002);
const mcu_pin_obj_t pin_GPIO_DISP_B2_02 = PIN(GPIO11, 3, GPIO_DISP_B2_02, NO_ADC, 0, 0x00000005, 0x00000002);
const mcu_pin_obj_t pin_GPIO_DISP_B2_03 = PIN(GPIO11, 4, GPIO_DISP_B2_03, NO_ADC, 0, 0x00000005, 0x00000002);
const mcu_pin_obj_t pin_GPIO_DISP_B2_04 = PIN(GPIO11, 5, GPIO_DISP_B2_04, NO_ADC, 0, 0x00000005, 0x00000002);
const mcu_pin_obj_t pin_GPIO_DISP_B2_05 = PIN(GPIO11, 6, GPIO_DISP_B2_05, NO_ADC, 0, 0x00000005, 0x00000002);
const mcu_pin_obj_t pin_GPIO_DISP_B2_06 = PIN(GPIO11, 7, GPIO_DISP_B2_06, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_07 = PIN(GPIO11, 8, GPIO_DISP_B2_07, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_08 = PIN(GPIO11, 9, GPIO_DISP_B2_08, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_09 = PIN(GPIO11, 10, GPIO_DISP_B2_09, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_10 = PIN(GPIO11, 11, GPIO_DISP_B2_10, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_11 = PIN(GPIO11, 12, GPIO_DISP_B2_11, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_12 = PIN(GPIO11, 13, GPIO_DISP_B2_12, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_13 = PIN(GPIO11, 14, GPIO_DISP_B2_13, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_14 = PIN(GPIO11, 15, GPIO_DISP_B2_14, NO_ADC, 0, 0x00000005, 0x00000006);
const mcu_pin_obj_t pin_GPIO_DISP_B2_15 = PIN(GPIO11, 16, GPIO_DISP_B2_15, NO_ADC, 0, 0x00000005, 0x0000000E);
