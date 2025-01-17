/*
 * app.c
 *
 *  Created on: Jan 16, 2025
 *      Author: user
 */

#include "app.h"
#include <math.h>

//장치 선언
extern TIM_HandleTypeDef htim1;


// timer의 duty 변경
void setDuty1(uint8_t g, uint8_t r, uint8_t b) {
	htim1.Instance->CCR1 = g * 10;
	htim1.Instance->CCR2 = r * 10;
	htim1.Instance->CCR3 = b * 10;
}

void app() {
	// 타이머 장치 시장
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	while(1) {
		static int angleG = 0;
		static int angleR = 120;
		static int angleB = 240;
		angleG++;
		angleR++;
		angleB++;
		angleG %= 360;
		angleR %= 360;
		angleB %= 360;
		uint8_t valueSinG = sin(angleG * M_PI / 180) *50 + 49;
		uint8_t valueSinR = sin(angleR * M_PI / 180) *50 + 49;
		uint8_t valueSinB = sin(angleB* M_PI / 180) *50 + 49;
		setDuty1(valueSinG, valueSinR, valueSinB);
		HAL_Delay(10);
	}
}
