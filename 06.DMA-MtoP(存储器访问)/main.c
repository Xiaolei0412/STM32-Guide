#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma_mtp.h"

void Systick_Delay_us(uint32_t us);
extern uint8_t BufferSize[5000];

int main(void)
{	
	uint16_t i;
	LED_GPIO_Config();
	USART_Config();
	
	//（开启串口发送DMA请求）。
	DMA_MTP_Config();        // "bsp_dma_mtp.c"
	USART_DMACmd(USART1, USART_DMAReq_Tx,ENABLE);   //"stm32f10x_usart.c"
	
	for(i=0;i<5000;i++)
	{
		BufferSize[i] = 'p';
	}
		
	while (1)
	{
		LED_RED;
		Systick_Delay_us(1000);
	}
}

void Systick_Delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72000);
	for(i=0;i<us;i++)
	{
		while(!((SysTick->CTRL) & (1<<16)));
	}
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}

