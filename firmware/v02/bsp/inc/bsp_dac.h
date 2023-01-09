#ifndef __BSP_DAC_H__
#define __BSP_DAC_H__

#include "stm32f1xx.h"

#define DAC1_GPIO_PORT   (GPIOA)
#define DAC1_GPIO_PIN    (GPIO_PIN_4)
#define DAC1_CHANNEL     (DAC_CHANNEL_1)

#define DAC2_GPIO_PORT   (GPIOA)
#define DAC2_GPIO_PIN    (GPIO_PIN_5)
#define DAC2_CHANNEL     (DAC_CHANNEL_2)

extern DAC_HandleTypeDef DAC1_Handler;

void DACx_Init(void);
void DACx_Set_Vol(uint16_t vol);

#endif
