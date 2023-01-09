#ifndef __BSP_TIM_H__
#define __BSP_TIM_H__

#include "stm32f1xx.h"

extern TIM_HandleTypeDef TIM_TimeBaseStructure;

/* ��ʱ�� */
#define ADVANCE_TIM                             TIM8
#define ADVANCE_TIM_CLK_ENABLE()                __HAL_RCC_TIM8_CLK_ENABLE()

/*      TIM1ͨ��1�������                             */
#define ADVANCE_OCPWM_PIN                       GPIO_PIN_6
#define ADVANCE_OCPWM_GPIO_PORT                 GPIOC
#define ADVANCE_OCPWM_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOC_CLK_ENABLE()

/*      TIM1ͨ��1�����������                           */
#define ADVANCE_OCNPWM_PIN                      GPIO_PIN_7
#define ADVANCE_OCNPWM_GPIO_PORT                GPIOA
#define ADVANCE_OCNPWM_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()


void TIMx_Configuration(void);
void TIM_SetTIM8Compare1(uint32_t compare);

#endif
