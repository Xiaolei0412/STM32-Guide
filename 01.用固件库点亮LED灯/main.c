                                                                                                                                                               #include "bsp_led.h"

//声明一个延时函数
#define uint unsigned int
uint i,j;
void delay()               //延时1.2秒子程序
{
			for(i=1000;i>0;i--)
				for(j=2000;j>0;j--);
}
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();
	while(1)
	{
	 LED1(ON) ;
	 delay();
	 LED1(OFF);
		
 	 LED2(ON);
	 delay();
	 LED2(OFF);
		
   LED3(ON);
	 delay();
	 LED3(OFF);
		
	 //黄色
   LED_Y(ON);
	 delay();
	 LED_Y(OFF);
	}
}


