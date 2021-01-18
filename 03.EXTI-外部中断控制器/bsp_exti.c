#include "bsp_exti.h"

void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;                  //"misc.h"
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);    //"misc.h"
	
  /* 配置中断源：按键1 */
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStruct);                        //"misc.h"
	
 /* 配置中断源：按键2，其他使用上面相关配置 */ 
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn  ;
	NVIC_Init(&NVIC_InitStruct);	

}


void EXTI_KEY_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	EXTI_InitTypeDef  EXTI_InitStruct; 
	
	EXTI_NVIC_Config();
//------------------KEY1的连接---------------------//
	//1-初始化要连接到EXTI的GPIO
	RCC_APB2PeriphClockCmd(LED_G_EXTI_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED_G_EXTI_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(LED_G_EXTI_PORT, &GPIO_InitStruct);	
	
	//2-初始化EXTI用于产生中断/事件
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);        // "stm32f10x_rcc.h"
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0); // "stm32f10x_gpio.h"
  EXTI_InitStruct.EXTI_Line = EXTI_Line0 ;                    //EXTI_Line：用于产生 中断/事件 线
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;            //EXTI_Mode：EXTI模式（中断/事件）
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;         //EXTI_Trigger：触发（上/下/上下）
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;                      //EXTI_LineCmd：使能或者失能（IMR/EMR）
	EXTI_Init(&EXTI_InitStruct);
	
//------------------KEY2的连接---------------------//
	RCC_APB2PeriphClockCmd(LED_G_EXTI1_CLK , ENABLE);            // "stm32f10x_rcc.h"
	GPIO_InitStruct.GPIO_Pin = LED_G_EXTI1_PIN;
	GPIO_Init(LED_G_EXTI1_PORT, &GPIO_InitStruct);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13); // "stm32f10x_gpio.h"
	EXTI_InitStruct.EXTI_Line = EXTI_Line13 ;                    //EXTI_Line：用于产生 中断/事件 线
  EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;             //EXTI_Mode：EXTI模式（中断/事件）
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;         //EXTI_Trigger：触发（上/下/上下）
  EXTI_InitStruct.EXTI_LineCmd = ENABLE;                       //EXTI_LineCmd：使能或者失能（IMR/EMR）
	EXTI_Init(&EXTI_InitStruct);
	
}
