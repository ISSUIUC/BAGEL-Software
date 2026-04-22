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



extern int gpio_output_status[11];

extern int bluetooth_status; // whether the board is connected to Bluetooth

extern char battery_voltage;


enum GPIO_INPUT {
	SWITCH_1_Q,
	SWITCH_2_Q,
	SWITCH_3_Q,
	SWITCH_4_Q,
	SWITCH_5_Q,
	SWITCH_6_Q,
	SWITCH_1_PG,
	SWITCH_2_PG,
	SWITCH_3_PG,
	SWITCH_4_PG,
	SWITCH_5_PG,
	SWITCH_6_PG,
	GPIO_INPUT_END
};

struct gpio_pin {
	uint8_t expander; 	// 0 is GPIOA, 1 is expander 1, 2 is expander 2, and 3 is GPIOB
	uint16_t pin;		// pin

};

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
	CLOCK,
	GPIO_OUTPUT_END
};


extern struct gpio_pin gpio_input_pins[12];
extern struct gpio_pin gpio_output_pins[11];

uint8_t interface_init(UART_HandleTypeDef * huart1);

uint8_t interface_send(uint8_t * data, uint16_t len);

uint8_t set_bluetooth_status(int newStatus);

uint8_t update_gpio_output(int gpio_output, int status);

uint8_t toggle_gpio_output(int gpio_output);





#ifdef __cplusplus
}
#endif


#endif /* INTERFACE_INTERFACE_H_ */
