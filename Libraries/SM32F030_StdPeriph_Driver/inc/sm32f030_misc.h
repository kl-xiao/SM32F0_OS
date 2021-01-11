/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SM32F030_MISC_H
#define __SM32F030_MISC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sm32f030.h"

/** @addtogroup SM32F030_StdPeriph_Driver
  * @{
  */

/** @addtogroup MISC
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/**  
  *
@verbatim   

@endverbatim
*/

/* Exported constants --------------------------------------------------------*/

/** @defgroup MISC_Exported_Constants
  * @{
  */



/** @defgroup MISC_SysTick_clock_source 
  * @{
  */

#define SysTick_CLKSource_SystemClk_Div2    ((uint32_t)0xFFFFFFFB)
#define SysTick_CLKSource_SystemClk         ((uint32_t)0x00000004)
#define CNF_SYSTICK_CLK_SOURCE(SOURCE) (((SOURCE) == SysTick_CLKSource_SystemClk) || \
                                        ((SOURCE) == SysTick_CLKSource_SystemClk_Div2))
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 

#define delay_us(x) SysTick_Delay_us(x)
#define delay_ms(x) SysTick_Delay_ms(x)

void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);

void SysTick_Delay_us(uint32_t nus);
void SysTick_Delay_ms(uint32_t nms);

#ifdef __cplusplus
}
#endif

#endif /* __SM32F030_MISC_H */

/**
  * @}
  */

/**
  * @}
  */

