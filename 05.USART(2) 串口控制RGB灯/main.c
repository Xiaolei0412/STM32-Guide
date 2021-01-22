#include "bsp_usart.h"                                                                                                                                                             #include "bsp_led.h"
#include "stm32f10x.h"
#include "bsp_led.h"
static void MessageShow(void);
int main(void)
{
	char ch;
	LED_GPIO_Config();
	USART_Config();
	
	//printf("串口控制RGB灯程序\n");
	MessageShow();
	
	while(1) 
	{
		ch = getchar(); //从键盘输入一个字符型数据，把值赋给变量ch
		printf("接收到字符%c\n",ch);  //无论ch变量是什么都将它以字符形式输出
		
		switch(ch)
		{
			case'1':LED1(ON);
				break;
			case'2':LED2(ON);
			  break;
			case'3':LED3(ON);
			  break;
			default: MessageShow(); //如果输入错误就关灯并打印
			  break;
		}
	}
}

static void MessageShow(void)
{
  printf("\r\n   这是一个通过串口通信指令控制RGB彩灯实验 \n");
  printf("使用  USART  参数为：%d 8-N-1 \n",115200);
  printf("开发板接到指令后控制RGB彩灯颜色，指令对应如下：\n");
  printf("   指令   ------ 彩灯颜色 \n");
  printf("     1    ------    红 \n");
  printf("     2    ------    绿 \n");
  printf("     3    ------    蓝 \n");
	LED_ALL(OFF);
}
	

