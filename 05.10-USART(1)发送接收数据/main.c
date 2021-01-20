#include "bsp_usart.h"   
#include "stm32f10x.h"

int main(void)
{
	//uint8_t a[10] = {1,2,3,4,5,6,7,8,9,10 };
	USART_Config();
	//SendByte(USART1, 'Z');
	//SendHalfWorrd(USART1, 0xff56);
	//SendArray(USART1 ,a ,10);
  //SendStr(USART1 ,"李东岳\n" );
	printf("李东岳李东岳李东岳李东岳LSP\n");
	
	while(1) 
	{

	}
}


