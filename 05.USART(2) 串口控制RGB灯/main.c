#include "bsp_usart.h"                                                                                                                                                             #include "bsp_led.h"
#include "stm32f10x.h"
#include "bsp_led.h"
static void MessageShow(void);
int main(void)
{
	char ch;
	LED_GPIO_Config();
	USART_Config();
	
	//printf("���ڿ���RGB�Ƴ���\n");
	MessageShow();
	
	while(1) 
	{
		ch = getchar(); //�Ӽ�������һ���ַ������ݣ���ֵ��������ch
		printf("���յ��ַ�%c\n",ch);  //����ch������ʲô���������ַ���ʽ���
		
		switch(ch)
		{
			case'1':LED1(ON);
				break;
			case'2':LED2(ON);
			  break;
			case'3':LED3(ON);
			  break;
			default: MessageShow(); //����������͹صƲ���ӡ
			  break;
		}
	}
}

static void MessageShow(void)
{
  printf("\r\n   ����һ��ͨ������ͨ��ָ�����RGB�ʵ�ʵ�� \n");
  printf("ʹ��  USART  ����Ϊ��%d 8-N-1 \n",115200);
  printf("������ӵ�ָ������RGB�ʵ���ɫ��ָ���Ӧ���£�\n");
  printf("   ָ��   ------ �ʵ���ɫ \n");
  printf("     1    ------    �� \n");
  printf("     2    ------    �� \n");
  printf("     3    ------    �� \n");
	LED_ALL(OFF);
}
	

