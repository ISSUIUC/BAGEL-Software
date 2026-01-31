#include "interface.h"


uint8_t interface_init(UART_HandleTypeDef * huart1){
	my_huart = huart1;
	return 0;
}

uint8_t interface_send(uint8_t * data, uint16_t len){
	HAL_UART_Transmit(my_huart, data, len, 1000);
	return 0;
}

void led_struct_init(void) {
	status.led1_status = 0;
	status.led2_status = 0;
}

int update_led(int led_num, int newStatus) {
	if (led_num == 1) {
		status.led1_status = newStatus;
	} else if (led_num == 2) {
		status.led2_status = newStatus;
	}
	return 0;
}


int toggle_led(int led_num) {
	if (led_num == 1) {
		status.led1_status = !status.led1_status;
	}
}
