#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_exti.h"
void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	LED_GPIO_Config();
	EXTI_KEY_Config();
	
	while(1)
	{
		
	}
}


