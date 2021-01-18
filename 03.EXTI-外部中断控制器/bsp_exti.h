#ifndef _BSP_EXTI_H
#define _BSP_EXTI_H

#include "stm32f10x.h"

//��KEY0 �� KEY13 ���ӵ���Ӧ���ж�ԴEXTI0 �� EXTI15��
#define LED_G_EXTI_PIN              GPIO_Pin_0
#define LED_G_EXTI_PORT             GPIOA
#define LED_G_EXTI_CLK              RCC_APB2Periph_GPIOA

#define LED_G_EXTI1_PIN              GPIO_Pin_13
#define LED_G_EXTI1_PORT             GPIOC
#define LED_G_EXTI1_CLK              RCC_APB2Periph_GPIOC

void EXTI_KEY_Config(void);

#endif /*_BSP_EXTI_H*/
