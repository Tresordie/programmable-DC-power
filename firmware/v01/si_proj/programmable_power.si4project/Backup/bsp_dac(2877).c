#include "bsp_dac.h"

DAC_HandleTypeDef DAC_InitStructure;


/**
 * @brief   DAC configuration
 */
void DACx_Init(void) {
    DAC_ChannelConfTypeDef DACCHx_Config;

    DAC_InitStructure.Instance     = DAC;
    HAL_DAC_Init(&DAC_InitStructure);               // It will call HAL_DAC_MspInit()

    DACCHx_Config.DAC_Trigger      = DAC_TRIGGER_NONE;
    DACCHx_Config.DAC_OutputBuffer = DAC_OUTPUTBUFFER_DISABLE;
    HAL_DAC_ConfigChannel(&DAC_InitStructure, &DACCHx_Config, DAC1_CHANNEL);

    HAL_DAC_Start(&DAC_InitStructure, DAC1_CHANNEL);
}


/**
 * @brief   Initializes the DAC
 * @param  hdac: pointer to a DAC_HandleTypeDef structure
 */
void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac) {
    GPIO_InitTypeDef GPIO_InitStructure;

    __HAL_RCC_DAC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitStructure.Pin  = DAC1_GPIO_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStructure.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(DAC1_GPIO_PORT, &GPIO_InitStructure);
}


/**
 * @brief       set DAC output voltage
 * @param  vol: voltage value(unit: mv)
 */
void DACx_Set_Vol(uint16_t vol) {
    double temp = vol;
    temp       /= 1000;
    temp        = temp * 4096 / 3.3;
    HAL_DAC_SetValue(&DAC_InitStructure, DAC1_CHANNEL, DAC_ALIGN_12B_R, temp);
}
