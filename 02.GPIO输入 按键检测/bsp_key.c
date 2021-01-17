//在这里写函数

#include "bsp_key.h"

//配置函数
void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//开时钟 进行配置
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE); // "stm32f10x_rcc.h"
	 
	GPIO_InitStruct.GPIO_Pin=KEY1_GPIO_PIN;            // "stm32f10x_gpio.h"
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;   // "stm32f10x_gpio.h"
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_InitStruct.GPIO_Pin = KEY2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; 

	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStruct);	    // "stm32f10x_gpio.h"
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);      // "stm32f10x_gpio.h"
}

//按键扫描函数
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	 if( GPIO_ReadInputDataBit(GPIOx,  GPIO_Pin) == KEY_ON )    // "stm32f10x_gpio.h"
	 {
		  while( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);
				return KEY_ON;
	 }
	 else 
		 return KEY_OFF;
}