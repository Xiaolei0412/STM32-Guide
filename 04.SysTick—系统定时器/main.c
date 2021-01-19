                                                                                                                                                               #include "bsp_led.h"
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_systick.h"

int main(void)
{
	/* LED ¶Ë¿Ú³õÊ¼»¯ */
	LED_GPIO_Config();
	while(1)
	{
	 LED1(ON) ;
	 Systick_Delay_ms(1000);
	 LED1(OFF);
		
 	 LED2(ON);
	 Systick_Delay_ms(1000);
	 LED2(OFF);
		
   LED3(ON);
	 Systick_Delay_ms(1000);
	 LED3(OFF);

	}
}


