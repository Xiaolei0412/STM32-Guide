                                                                                                                                                               #include "bsp_led.h"

//����һ����ʱ����
#define uint unsigned int
uint i,j;
void delay()               //��ʱ1.2���ӳ���
{
			for(i=1000;i>0;i--)
				for(j=2000;j>0;j--);
}
int main(void)
{
	/* LED �˿ڳ�ʼ�� */
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
		
	 //��ɫ
   LED_Y(ON);
	 delay();
	 LED_Y(OFF);
	}
}


