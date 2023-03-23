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

#pragma once
extern LPI2C_Type *const mcu_i2c_banks[2];
extern const mcu_periph_obj_t mcu_i2c_sda_list[2];
extern const mcu_periph_obj_t mcu_i2c_scl_list[2];

extern LPSPI_Type *const mcu_spi_banks[2];
extern const mcu_periph_obj_t mcu_spi_sck_list[2];
extern const mcu_periph_obj_t mcu_spi_sdo_list[2];
extern const mcu_periph_obj_t mcu_spi_sdi_list[2];

extern LPUART_Type *const mcu_uart_banks[4];
extern const mcu_periph_obj_t mcu_uart_rx_list[6];
extern const mcu_periph_obj_t mcu_uart_tx_list[6];
extern const mcu_periph_obj_t mcu_uart_rts_list[3];
extern const mcu_periph_obj_t mcu_uart_cts_list[3];

extern I2S_Type *const mcu_i2s_banks[3];
extern const mcu_periph_obj_t mcu_i2s_rx_data0_list[3];
extern const mcu_periph_obj_t mcu_i2s_rx_sync_list[3];
extern const mcu_periph_obj_t mcu_i2s_tx_bclk_list[4];
extern const mcu_periph_obj_t mcu_i2s_tx_data0_list[4];
extern const mcu_periph_obj_t mcu_i2s_tx_sync_list[4];

extern const mcu_periph_obj_t mcu_mqs_left_list[2];
extern const mcu_periph_obj_t mcu_mqs_right_list[2];

extern const mcu_pwm_obj_t mcu_pwm_list[12];
