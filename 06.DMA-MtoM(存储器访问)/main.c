/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma_mtm.h"
void Systick_Delay_ms(uint32_t ms);

//�ڱ���ļ��б������ˣ������ⲿ���ӣ��������ʹ��extern�ٴ�������
extern const uint32_t aSRC_Const_Buffer[32];
extern uint32_t aDST_Buffer[32];

int main(void)
{	
	uint8_t status=0;
	
	/* LED �˿ڳ�ʼ�� */
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
