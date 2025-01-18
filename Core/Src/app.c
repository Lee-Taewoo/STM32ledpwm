/*
 * app.c
 *
 *  Created on: Jan 16, 2025
 *      Author: user
 */

#include "app.h"
#include "uart.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

//장치 선언
extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart2;


// timer의 duty 변경
void setDuty(uint8_t g, uint8_t r, uint8_t b) {
	htim1.Instance->CCR1 = g * 10;
	htim1.Instance->CCR2 = r * 10;
	htim1.Instance->CCR3 = b * 10;
}

uint8_t value[3];

// R050G080B100
void app() {
	// 타이머 장치 시장
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	// uart 장치 수신 활성화
	initUart(&huart2);
	while(1) {
		char *msg = getMessage();
		if (strlen(msg) >= 12) {
			if (msg[0] == 'G' && msg[4] == 'R' && msg[8] == 'B') {
				value[0] = atoi(&msg[1]);
				value[1] = atoi(&msg[5]);
				value[2] = atoi(&msg[9]);
				setDuty(value[0], value[1], value[2]);
			}
		}
	}
}
