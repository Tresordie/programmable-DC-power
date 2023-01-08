#include "bsp_dac.h"

DAC_HandleTypeDef DAC_InitStructure;


void DACx_Init(void) {
    DAC_ChannelConfTypeDef DACCHx_Config;

    DAC_InitStructure.Instance = DAC;
    HAL_DAC_Init(&DAC_InitStructure);

    DACCHx_Config.DAC_Trigger = DAC_TRIGGER_NONE;
    DACCHx_Config.DAC_OutputBuffer = DAC_OUTPUTBUFFER_DISABLE;
    HAL_DAC_ConfigChannel(&DAC_InitStructure, &DACCHx_Config, DAC_CHANNEL_1);

    HAL_DAC_Start(&DAC_InitStructure, DAC_CHANNEL_1);
}


void HAL_DAC_MspInit(DAC_HandleTypeDef *DAC_InitStructure) {
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_DAC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_Initure.Pin = GPIO_PIN_4;
    GPIO_Initure.Mode = GPIO_MODE_ANALOG;
    GPIO_Initure.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_Initure);
}


void DACx_Set_Vol(uint16_t vol) {
    double temp = vol;
    temp /= 1000;
    temp = temp * 4096 / 3.3;
    HAL_DAC_SetValue(&DAC_InitStructure, DAC_CHANNEL_1, DAC_ALIGN_12B_R, temp);
}
