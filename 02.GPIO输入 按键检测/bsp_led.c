//bsp： 板级支持包

#include "bsp_led.h"
#include "stm32f10x.h"


void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;                // "stm32f10x_gpio.h"
	//开时钟 进行配置
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK, ENABLE);   // "stm32f10x_rcc.h"
	
	GPIO_InitStruct.GPIO_Pin=LED1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);
		
	GPIO_InitStruct.GPIO_Pin = LED3_GPIO_PIN;
	GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);
	
		/* 关闭所有led灯	*/
	GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);     // "stm32f10x_gpio.h"
		/* 关闭所有led灯	*/ 
	GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);	   // "stm32f10x_gpio.h"
    /* 关闭所有led灯	*/
	GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);     // "stm32f10x_gpio.h"
}


