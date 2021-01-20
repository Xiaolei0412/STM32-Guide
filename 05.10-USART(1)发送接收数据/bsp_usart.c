#include "bsp_usart.h"

//中断配置（接收中断，中断优先级）
static void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_Initstruct;                //"misc.h"
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //"misc.h"
	NVIC_Initstruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority =1;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority =1;
	NVIC_Initstruct.NVIC_IRQChannelCmd  = ENABLE;
	
	NVIC_Init(&NVIC_Initstruct);
}


void USART_Config(void)
{
	GPIO_InitTypeDef  GPIO_Initstruct;      //"stm32f10x_gpio.h"
  USART_InitTypeDef USART_Initstruct;     //"stm32f10x_usart.h"

  //初始化串口需要用到的GPIO A9 发送 TX
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //"stm32f10x_rcc.h"
  GPIO_Initstruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Initstruct);
	
	//初始化串口需要用到的GPIO A10 接收 RX
  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_Initstruct.GPIO_Pin =  GPIO_Pin_10;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_Initstruct);
	
  //初始化串口，USART_InitTypeDef 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	USART_Initstruct.USART_BaudRate = 115200;                     //"stm32f10x_usart.h"
	USART_Initstruct.USART_WordLength = USART_WordLength_8b ;     //"stm32f10x_usart.h"
	USART_Initstruct.USART_StopBits = USART_StopBits_1;           //"stm32f10x_usart.h"
	USART_Initstruct.USART_Parity = USART_Parity_No;
	USART_Initstruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;
	USART_Init(USART1, &USART_Initstruct);
	
	//中断配置（接收中断，中断优先级）
  NVIC_Config(); 
	//使能串口接收中断
	USART_ITConfig(USART1, USART_IT_RXNE ,ENABLE);    //"stm32f10x_usart.h"
	//RXNE：读数据寄存器非空  1：收到数据，可以读出。
	//使能串口；
	USART_Cmd(USART1, ENABLE);                        //"stm32f10x_usart.h"
}

/*----------------------发送单个字符--------------------------------*/
void SendByte(USART_TypeDef* USARTx, uint8_t data)
{
	USART_SendData(USARTx,data);
	while( USART_GetFlagStatus(USARTx, USART_FLAG_TXE) ==RESET );
}

/*----------------------发送双个字符--------------------------------*/
void SendHalfWorrd(USART_TypeDef* USARTx, uint16_t data)
{
	uint8_t temp_h,temp_l;
	
	temp_h = (data&0xff00) >> 8 ;   //取得高八位
	temp_l = data&0xff ;            //取得低八位
	 
	USART_SendData(USARTx,temp_h);                   //"stm32f10x_usart.h"
	/* 等待发送完毕 */
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET );   //"stm32f10x_usart.h"
	
	USART_SendData(USARTx,temp_l);                  //"stm32f10x_usart.h"
	/* 等待发送完毕 */
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET );
}

/*----------------------发送8位数组--------------------------------*/
void SendArray(USART_TypeDef* USARTx , uint8_t *array ,uint8_t num )
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		SendByte(USARTx,array[i]);   //“前面自己写的”
	}
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET );

}

/*----------------------发送字符串--------------------------------*/
void SendStr(USART_TypeDef* USARTx ,uint8_t *str )
{
	uint8_t i=0;
	do
	{
		SendByte(USARTx,*(str+i));
		i++;
	}while( *(str+i) != '\0');
// '\0' 是字符串的结束符 ‘\0’转义字符的ASCII码值为0，它表示的是ASCII控制字符中空字符的含义
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET );
}

/*-------重定向c库函数printf到串口，重定向后可使用printf函数-------*/
int fputc(int ch,FILE*f)
{
	USART_SendData(USART1,(uint8_t) ch);                          //"stm32f10x_usart.h"
	/* 等待发送完毕 */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET );
	return (ch);
}

//---重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数---*/
int fgetc(FILE *f)
{
	/* 等待串口输入数据 */
	while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET); //"stm32f10x_usart.h"
	return (int)USART_ReceiveData(USART1);    
}