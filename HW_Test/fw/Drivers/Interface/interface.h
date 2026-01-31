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


struct gpio_status {
	int led1_status;
	int led2_status;
};

extern struct gpio_status status;


uint8_t interface_init(UART_HandleTypeDef * huart1);

uint8_t interface_send(uint8_t * data, uint16_t len);

void led_struct_init(void);

int update_led(int led_num, int newStatus);

int toggle_led(int led_num);

#ifdef __cplusplus
}
#endif


#endif /* INTERFACE_INTERFACE_H_ */
