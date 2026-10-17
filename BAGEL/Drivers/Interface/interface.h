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
#include <stdbool.h>
#include "inttypes.h"


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

enum ports {
	PORT_A = 0,
	EXPANDER1 = 1,
	EXPANDER2 = 2,
	PORT_B = 3
};

struct gpio_pin {
	enum ports expander; 	// 0 is GPIOA, 1 is expander 1, 2 is expander 2, and 3 is GPIOB
	uint16_t pin;		// GPIO_PIN_x on PORT_A/B, 0-7 on EXPANDER1/2
	bool active_low;    // true if a low level on the pin means "on"
};



struct switch_t {
    struct gpio_pin qnot_pin;
    struct gpio_pin pg_pin;
    struct gpio_pin output;

    bool state;  //what we want.current status: on or off
    bool qnot; // what it actually is. value of opposite of switch (true = off, false = on)
	bool pg; //power good. | true = has power
	//connected to power and whether flip flop has power

	//also need something for bluetooth
};



extern struct switch_t switches[6];

extern struct gpio_pin gpio_input_pins[12];
extern struct gpio_pin gpio_output_pins[11];

uint8_t interface_init(UART_HandleTypeDef * huart1);

uint8_t interface_send(uint8_t * data, uint16_t len);

uint8_t set_bluetooth_status(int newStatus);

uint8_t update_gpio_output(int gpio_output, int status);

uint8_t toggle_gpio_output(int gpio_output);
// new functions

//sw = switch
uint8_t set_switch_status(int sw, bool newStatus);
uint8_t get_switch_status(int sw);


#ifdef __cplusplus
}
#endif


#endif /* INTERFACE_INTERFACE_H_ */
