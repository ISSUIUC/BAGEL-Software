#include "interface.h"
#include "stm32wbxx_hal_gpio.h"
#include <stddef.h>
//#include "../../Middlewares/ST/STM32_WPAN/ble/core/auto/ble_types.h"
//#include "../../STM32_WPAN/app/custom_app.h"
//#include "../../STM32_WPAN/app/custom_stm.h"
//#include "../TCAL9538/TCAL9538.hpp"

int gpio_output_status[GPIO_OUTPUT_CNT] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
};

const struct gpio_pin gpio_output_pins[GPIO_OUTPUT_PIN_CNT] = {
	[SWITCH_1] 		= { .expander=PORT_A, .pin=GPIO_PIN_12 },
	[SWITCH_2] 		= { .expander=EXPANDER1, .pin=5 },
	[SWITCH_3] 		= { .expander=EXPANDER1, .pin=0 },
	[SWITCH_4] 		= { .expander=EXPANDER2, .pin=5 },
	[SWITCH_5] 		= { .expander=EXPANDER2, .pin=0 },
	[SWITCH_6] 		= { .expander=PORT_A, .pin=GPIO_PIN_11 },
	[RED_LED]		= { .expander=EXPANDER1, .pin=6 },
	[ORANGE_LED] 	= { .expander=EXPANDER1, .pin=7 },
	[GREEN_LED] 	= { .expander=EXPANDER2, .pin=6 },
	[BLUE_LED] 		= { .expander=EXPANDER2, .pin=7 },
	[CLOCK] 		= { .expander=PORT_A, .pin=GPIO_PIN_0 },
	[OUTPUT_11] 	= { .expander=EXPANDER1, .pin=6 },
	[OUTPUT_12] 	= { .expander=EXPANDER1, .pin=7 },
	[OUTPUT_13] 	= { .expander=EXPANDER2, .pin=6 },
	[OUTPUT_14] 	= { .expander=EXPANDER2, .pin=7 },
	[OUTPUT_15] 	= { .expander=PORT_A, .pin=GPIO_PIN_0 }
};

const struct gpio_pin gpio_input_pins[GPIO_INPUT_CNT] = {
	[SWITCH_1_Q]	= { .expander=PORT_A, .pin=GPIO_PIN_5 },
	[SWITCH_2_Q]	= { .expander=EXPANDER1, .pin=3 },
	[SWITCH_3_Q]	= { .expander=EXPANDER1, .pin=2 },
	[SWITCH_4_Q]	= { .expander=EXPANDER2, .pin=3 },
	[SWITCH_5_Q]	= { .expander=EXPANDER2, .pin=2 },
	[SWITCH_6_Q]	= { .expander=PORT_B, .pin=GPIO_PIN_8 },
	[SWITCH_1_PG]	= { .expander=PORT_A, .pin=GPIO_PIN_3 },
	[SWITCH_2_PG]	= { .expander=EXPANDER1, .pin=4 },
	[SWITCH_3_PG]	= { .expander=EXPANDER1, .pin=1 },
	[SWITCH_4_PG]	= { .expander=EXPANDER2, .pin=4 },
	[SWITCH_5_PG]	= { .expander=EXPANDER2, .pin=1 },
	[SWITCH_6_PG]	= { .expander=PORT_A, .pin=GPIO_PIN_4 }
};

struct switch_t switches[SWITCH_CNT] = {
	//switches
	[SWITCH_1] = { .qnot_pin=gpio_input_pins[SWITCH_1_Q], .pg_pin=gpio_input_pins[SWITCH_1_PG], .output=gpio_output_pins[SWITCH_1] },
	[SWITCH_2] = { .qnot_pin=gpio_input_pins[SWITCH_2_Q], .pg_pin=gpio_input_pins[SWITCH_2_PG], .output=gpio_output_pins[SWITCH_2] },
	[SWITCH_3] = { .qnot_pin=gpio_input_pins[SWITCH_3_Q], .pg_pin=gpio_input_pins[SWITCH_3_PG], .output=gpio_output_pins[SWITCH_3] },
	[SWITCH_4] = { .qnot_pin=gpio_input_pins[SWITCH_4_Q], .pg_pin=gpio_input_pins[SWITCH_4_PG], .output=gpio_output_pins[SWITCH_4] },
	[SWITCH_5] = { .qnot_pin=gpio_input_pins[SWITCH_5_Q], .pg_pin=gpio_input_pins[SWITCH_5_PG], .output=gpio_output_pins[SWITCH_5] },
	[SWITCH_6] = { .qnot_pin=gpio_input_pins[SWITCH_6_Q], .pg_pin=gpio_input_pins[SWITCH_6_PG], .output=gpio_output_pins[SWITCH_6] },
};


int bluetooth_status = 0;
uint8_t battery_voltage = 0;


uint8_t interface_init(UART_HandleTypeDef * huart1){
	my_huart = huart1;
	return 0;
}

uint8_t interface_send(uint8_t * data, uint16_t len){
	HAL_UART_Transmit(my_huart, data, len, 1000);
	return 0;
}

uint8_t set_bluetooth_status(int newStatus) {
	bluetooth_status = newStatus;
	return 0;
}


uint8_t update_gpio_output(int gpio_output, int status) {
	if (gpio_output < 0 || (gpio_output >= sizeof(gpio_output_status)/sizeof(gpio_output_status[0]))) {
		return 1;
	}
	gpio_output_status[gpio_output] = status;
	return 0;
}



uint8_t toggle_gpio_output(int gpio_output) {
	if (gpio_output < 0 || gpio_output >= sizeof(gpio_output_status)/sizeof(gpio_output_status[0])) {
		return 1;
	}
	gpio_output_status[gpio_output] = !gpio_output_status[gpio_output];
	return 0;
}

// new functions
uint8_t set_switch_status(int sw, bool newStatus) {
	if (sw < 0 || sw >= 6) {
		return 1;
	}
	switches[sw].state = newStatus;
	return 0;
}

uint8_t get_switch_status(int sw) {
	if (sw < 0 || sw >= 6) {
		return 0;
	}
	return switches[sw].pg && !switches[sw].qnot;
}

//uint8_t init_gpio_inputs() {
//	return 0;
//}


//<<<<<<< Updated upstream
//uint8_t read_gpio_input(int gpio_input) {
//	 struct gpio_pin pin = gpio_input_pins[gpio_input];
//	 if (!pin.expander) {
//		 HAL_GPIO_ReadPin(GPIOA, pin.pin);
//		 return 0;
//	 }
//	 gpioDigitalRead(GpioAddress(pin.expander - 1, pin.pin))
//
//}
//=======
//>>>>>>> Stashed changes


//uint8_t init_ble_switch_values() {
//
//}

//command_queue = {
//
//};


typedef struct {
  Custom_STM_Char_Opcode_t char_opcode;
  uint8_t switch_state;
  uint8_t power_state;
  bool exp_state;
  int battery_voltage; // reserved variable for battery voltage switch
} SingleSwitchStatusMonitor;

static SingleSwitchStatusMonitor make_switch_status_monitor(Custom_STM_Char_Opcode_t opcode) {
	return (SingleSwitchStatusMonitor) {
		.char_opcode = opcode,
		.switch_state = false,
		.power_state = false,
		.exp_state = false
	};
}

static SingleSwitchStatusMonitor switch_status_monitor[7];

static SingleSwitchStatusMonitor *find_switch_status_monitor(
		Custom_STM_Char_Opcode_t char_opcode) {
	for (int i = 0; i < 7; i++) {
		if (switch_status_monitor[i].char_opcode == char_opcode) {
			return &switch_status_monitor[i];
		}
	}
	return NULL;
}

void init_switch_monitors(void) {
	const Custom_STM_Char_Opcode_t char_opcodes[7] = {
		CUSTOM_STM_SWITCH_1,
		CUSTOM_STM_SWITCH_2,
		CUSTOM_STM_SWITCH_3,
		CUSTOM_STM_SWITCH_4,
		CUSTOM_STM_SWITCH_5,
		CUSTOM_STM_SWITCH_6,
		CUSTOM_STM_BATTERY_VOLTAGE
	};

	for (int i = 0; i < 7; i++) {
		switch_status_monitor[i] = make_switch_status_monitor(char_opcodes[i]);
	}
}


//0: invalid target monitor, 1: valid write to all mandatory portions (emtpy or null payloads are replaced with a 0)
uint8_t store_state_monitor(Custom_STM_Char_Opcode_t char_opcode, uint8_t *payload_switch, uint8_t *payload_power,uint8_t *payload_exp){

	SingleSwitchStatusMonitor *target_monitor =
			find_switch_status_monitor(char_opcode);
	if (target_monitor == NULL) {
		return 0;
	}

	if(char_opcode == CUSTOM_STM_BATTERY_VOLTAGE){ // editing the voltage requires only a single val I think
		target_monitor->battery_voltage = payload_switch != NULL ? *payload_switch : 0;
		return 1;
	}

	//If it's a real value then we write write it to the value of the payload
	target_monitor->switch_state = payload_switch != NULL && *payload_switch != 0;
	target_monitor->power_state  = payload_power  != NULL && *payload_power  != 0;
	target_monitor->exp_state    = payload_exp    != NULL && *payload_exp    != 0;
	return 1;
}

char get_configured_packet(Custom_STM_Char_Opcode_t char_opcode) {
	const SingleSwitchStatusMonitor *monitor =
			find_switch_status_monitor(char_opcode);
	if (monitor == NULL) {
		return 0;
	}

	if(char_opcode == CUSTOM_STM_BATTERY_VOLTAGE){
		return monitor->battery_voltage;
	}

	const int encoding =
			((int)monitor->switch_state << 2) |
			((int)monitor->power_state << 1) |
			(int)monitor->exp_state;
											//	switch	|	power	|	expected
	char disconnected 			= 'D';		//	0		|	0		|	0
	char impossible   			= 'I';		//	0		|	0		|	1
	char nominal      			= 'N';		//	0		|	1		|	0
	char off          			= 'O';		//	0		|	1		|	1
	char disconnected_expected  = 'S';		//	1		|	0		|	0
	char impossible_expected 	= 'A';		//	1		|	0		|	1
	char nominal_expected		= 'U';		//	1		|	1		|	0
	char off_expected 			= 'R';		//	1		|	1		|	1

	return (char[]){disconnected,impossible,nominal,off,disconnected_expected,impossible_expected,nominal_expected,off_expected}[encoding];
}

int push_packet(Custom_STM_Char_Opcode_t char_opcode){
	const SingleSwitchStatusMonitor *monitor =
			find_switch_status_monitor(char_opcode);
	if (monitor == NULL) {
		return 0;
	}

	uint8_t packet = (uint8_t)get_configured_packet(char_opcode);
	Custom_STM_App_Update_Char(char_opcode, &packet);
	return 1;
}