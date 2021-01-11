//bsp： 板级支持包

#include "bsp_led.h"
#include "stm32f10x.h"


void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//开时钟 进行配置
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=LED1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);
		
	GPIO_InitStruct.GPIO_Pin = LED3_GPIO_PIN;
	GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);
	

	
	
	
	
}


