/**
 * Copyright (c) 2014 - 2020, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef PCA10040_H
#define PCA10040_H

#include "nrf_gpio.h"

// LEDs definitions for Board
#define LEDS_NUMBER    1

#define LED_1          8
#define LEDS_ACTIVE_STATE 1
#define LEDS_LIST { LED_1 }
//#define BSP_LED_0      LED_1

#define BUTTONS_NUMBER 0
#define BUTTONS_ACTIVE_STATE 0

//Sensor Pin Contact
#define USE_IIC

#define IIC_SDA                 NRF_GPIO_PIN_MAP(0,9)
#define IIC_SCL                 NRF_GPIO_PIN_MAP(0,24)

#define CCS811_WAKE             NRF_GPIO_PIN_MAP(0,10)
#define CCS811_INT              NRF_GPIO_PIN_MAP(1,9)
#define APDS_INT                NRF_GPIO_PIN_MAP(0,13)
#define USE_INTERRUPT

#define USE_SPI

#define SPI_PIN_SCK				NRF_GPIO_PIN_MAP(1,11)
#define SPI_PIN_MOSI			NRF_GPIO_PIN_MAP(1,10)
#define SPI_PIN_MISO			NRF_DRV_SPI_PIN_NOT_USED
#define SPI_PIN_CS              NRF_DRV_SPI_PIN_NOT_USED

#define SHARPMEM_PIN_CS			NRF_GPIO_PIN_MAP(0,3)
#define SHARPMEM_PIN_COM        NRF_GPIO_PIN_MAP(0,28)
#define SHARPMEM_PIN_DISP       NRF_GPIO_PIN_MAP(1,13)

#define USE_UART

#define UART_SENSOR_TX          NRF_GPIO_PIN_MAP(0,5)
#define UART_SENSOR_RX          NRF_GPIO_PIN_MAP(0,30)
#define UART_SENSOR_RTS         NRF_GPIO_PIN_MAP(0,29)
#define UART_SENSOR_CTS         NRF_GPIO_PIN_MAP(0,31)

#define NBIOT_RST               NRF_GPIO_PIN_MAP(0,4)

#endif // PCA10040_H
