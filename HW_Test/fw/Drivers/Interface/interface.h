/*
 * interface.h
 *
 *  Created on: Jan 30, 2026
 *      Author: tjmcm
 */

#ifndef INTERFACE_INTERFACE_H_
#define INTERFACE_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32wbxx_hal.h"

extern UART_HandleTypeDef * my_huart;



extern int gpio_output_status[10];

extern int bluetooth_status; // whether the board is connected to Bluetooth

enum GPIO_OUTPUT {
	SWITCH_1,
	SWITCH_2,
	SWITCH_3,
	SWITCH_4,
	SWITCH_5,
	SWITCH_6,
	RED_LED,
	ORANGE_LED,
	GREEN_LED,
	BLUE_LED,
};


uint8_t interface_init(UART_HandleTypeDef * huart1);

uint8_t interface_send(uint8_t * data, uint16_t len);


uint8_t update_gpio_output(int gpio_output, int status);

uint8_t toggle_gpio_output(int gpio_output);

#ifdef __cplusplus
}
#endif


#endif /* INTERFACE_INTERFACE_H_ */
