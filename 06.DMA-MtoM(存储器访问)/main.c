/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma_mtm.h"
void Systick_Delay_ms(uint32_t ms);

//在别的文件中被定义了，具有外部链接，这里必须使用extern再次声明。
extern const uint32_t aSRC_Const_Buffer[32];
extern uint32_t aDST_Buffer[32];

int main(void)
{	
	uint8_t status=0;
	
	/* LED 端口初始化 */
	LED_GPIO_Config();	 
  DMA_MTM_Config();
	
	LED_YELLOW;
	Systick_Delay_ms(3000);
	
	status = Buffercmp( aSRC_Const_Buffer,aDST_Buffer, 32);
	if(status == 0)
	{
		LED_RED;
	}
	else
	{
		LED_GREEN;
	}

}

void Systick_Delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	for(i=0;i<ms;i++)
	{
		while  (!((SysTick->CTRL) & (1<<16)));
	}
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}


/*********************************************END OF FILE**********************/
