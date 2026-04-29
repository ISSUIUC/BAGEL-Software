#include "interface.h"
//#include "../../Middlewares/ST/STM32_WPAN/ble/core/auto/ble_types.h"
//#include "../../STM32_WPAN/app/custom_app.h"
//#include "../../STM32_WPAN/app/custom_stm.h"
//#include "../TCAL9538/TCAL9538.hpp"

gpio_output_status[11] = {
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
		0,
};


struct gpio_pin gpio_input_pins[12] = {
		[SWITCH_1_Q] = { .expander=0, .pin=GPIO_PIN_5 },
		[SWITCH_2_Q] = { .expander=1, .pin=3 },
		[SWITCH_3_Q] = { .expander=1, .pin=2 },
		[SWITCH_4_Q] = { .expander=2, .pin=3 },
		[SWITCH_5_Q] = { .expander=2, .pin=2 },
		[SWITCH_6_Q] = { .expander=3, .pin=GPIO_PIN_8 },
		[SWITCH_1_PG] = { .expander=0, .pin=GPIO_PIN_3 },
		[SWITCH_2_PG] = { .expander=1, .pin=4 },
		[SWITCH_3_PG] = { .expander=1, .pin=1 },
		[SWITCH_4_PG] = { .expander=2, .pin=4 },
		[SWITCH_5_PG] = { .expander=2, .pin=1 },
		[SWITCH_6_PG] = { .expander=0, .pin=GPIO_PIN_4 },
};



struct gpio_pin gpio_output_pins[11] = {
		[SWITCH_1] = { .expander=0, .pin=GPIO_PIN_12 },
		[SWITCH_2] = { .expander=1, .pin=5 },
		[SWITCH_3] = { .expander=1, .pin=0 },
		[SWITCH_4] = { .expander=2, .pin=5 },
		[SWITCH_5] = { .expander=2, .pin=0 },
		[SWITCH_6] = { .expander=0, .pin=GPIO_PIN_11 },
		[RED_LED] = { .expander=1, .pin=6 },
		[ORANGE_LED] = { .expander=1, .pin=7 },
		[GREEN_LED] = { .expander=2, .pin=6 },
		[BLUE_LED] = { .expander=2, .pin=7},
		[CLOCK] = { .expander=0, .pin=GPIO_PIN_0 },
};


int bluetooth_status = 0;

char battery_voltage = 0;


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


