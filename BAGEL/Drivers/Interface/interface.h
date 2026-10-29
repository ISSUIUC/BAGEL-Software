/*
 * interface.h
 *
 *  Created on: Jan 30, 2026
 *      Author: tjmcm
 */

#ifndef INTERFACE_INTERFACE_H_
#define INTERFACE_INTERFACE_H_

#include <stdint.h>
#include "custom_stm.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32wbxx_hal.h"
#include <stdbool.h>
#include "inttypes.h"

#define GPIO_OUTPUT_PIN_CNT 16
#define GPIO_OUTPUT_CNT 11
#define GPIO_INPUT_CNT 12
#define SWITCH_CNT 6


extern UART_HandleTypeDef * my_huart;

extern int gpio_output_status[GPIO_OUTPUT_CNT];

extern int bluetooth_status; // whether the board is connected to Bluetooth

extern uint8_t battery_voltage;


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
	SWITCH_6_PG
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
	OUTPUT_11,
	OUTPUT_12,
	OUTPUT_13,
	OUTPUT_14,
	OUTPUT_15
};

enum SWITCH_STATUS_MONITOR {
	SWITCH_STATE,
	POWER_STATE,
	EXP_STATE
};

enum ports {
	PORT_A = 0,
	EXPANDER1 = 1,
	EXPANDER2 = 2,
	PORT_B = 3
};

struct gpio_pin {
	enum ports expander;	// 0 is GPIOA, 1 is expander 1, 2 is expander 2, and 3 is GPIOB
	uint16_t pin;			// GPIO_PIN_x on PORT_A/B, 0-7 on EXPANDER1/2
	bool active_low;    	// true if a low level on the pin means "on"
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



extern struct switch_t switches[SWITCH_CNT];
extern const struct gpio_pin gpio_input_pins[GPIO_INPUT_CNT];
extern const struct gpio_pin gpio_output_pins[GPIO_OUTPUT_PIN_CNT];

uint8_t interface_init(UART_HandleTypeDef * huart1);

uint8_t interface_send(uint8_t * data, uint16_t len);

uint8_t set_bluetooth_status(int newStatus);

uint8_t update_gpio_output(int gpio_output, int status);

uint8_t toggle_gpio_output(int gpio_output);
// new functions

//sw = switch
uint8_t set_switch_status(int sw, bool newStatus);
uint8_t get_switch_status(int sw);

void init_switch_monitors(void);
char get_configured_packet(Custom_STM_Char_Opcode_t char_opcode);
uint8_t push_configured_packet(Custom_STM_Char_Opcode_t char_opcode, char source_character);
uint8_t store_state_monitor(Custom_STM_Char_Opcode_t char_opcode, uint8_t *payload_switch, uint8_t *payload_power, uint8_t *payload_exp);
int push_packet(Custom_STM_Char_Opcode_t char_opcode);

#ifdef __cplusplus
}
#endif


#endif /* INTERFACE_INTERFACE_H_ */
