#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_key.h"

//声明一个延时函数
#define uint unsigned int
uint i,j;
void delay()               //延时0.2秒子程序
{
			for(i=1000;i>0;i--)
				for(j=2000;j>0;j--);
}
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();
	KEY_GPIO_Config();
	
	//LED_ALL(OFF);

	while(1)
	{
		if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON )
		{
		  LED1_TOGGLE;
		}
		if(Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON )
		{
		  LED2_TOGGLE;
		}
	}
}


