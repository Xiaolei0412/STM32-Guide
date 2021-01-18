#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_key.h"

//����һ����ʱ����
#define uint unsigned int
uint i,j;
void delay()               //��ʱ0.2���ӳ���
{
			for(i=1000;i>0;i--)
				for(j=2000;j>0;j--);
}
int main(void)
{
	/* LED �˿ڳ�ʼ�� */
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


