#include "bsp_delay.h"

static uint32_t fac_us = 0;


/**
 * @brief   delay function initialization
 * @param  SYSCLK: time base for 1 us
 */
void delay_init(uint8_t SYSCLK) {
    // Systick frequency set as HCLK
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

    fac_us = SYSCLK;
}


/**
 * @brief   delay function for n microseconds
 * @param  nus: number of microseconds, range is 0~190887435us(2^32/fac_us @fac_us = 22.5)
 */
void delay_us(uint32_t nus) {
    uint32_t ticks;
    uint32_t told, tnow, tcnt = 0;
    uint32_t reload = SysTick->LOAD;
    ticks = nus * fac_us;
    told = SysTick->VAL;
    while (1) {
        tnow = SysTick->VAL;
        if (tnow != told) {
            if (tnow < told)
                tcnt += told - tnow;
            else
                tcnt += reload - tnow + told;
            told = tnow;
            if (tcnt >= ticks)
                break;
        }
    }
}


/**
 * @brief delay function for n milliseconds
 * @param  nms: number of milliseconds
 */
void delay_ms(uint16_t nms) {
    uint32_t i;
    for (i = 0; i < nms; i++)
        delay_us(1000);
}
