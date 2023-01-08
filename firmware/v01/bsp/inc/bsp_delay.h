#ifndef __BSP_DELAY_H__
#define __BSP_DELAY_H__

#include "stm32f1xx.h"

void delay_init(uint8_t SYSCLK);
void delay_us(uint32_t nus);
void delay_ms(uint16_t nms);

#endif

