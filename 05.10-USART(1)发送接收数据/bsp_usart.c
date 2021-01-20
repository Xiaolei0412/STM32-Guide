#include "bsp_usart.h"

//�ж����ã������жϣ��ж����ȼ���
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

  //��ʼ��������Ҫ�õ���GPIO A9 ���� TX
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //"stm32f10x_rcc.h"
  GPIO_Initstruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Initstruct);
	
	//��ʼ��������Ҫ�õ���GPIO A10 ���� RX
  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_Initstruct.GPIO_Pin =  GPIO_Pin_10;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_Initstruct);
	
  //��ʼ�����ڣ�USART_InitTypeDef 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	USART_Initstruct.USART_BaudRate = 115200;                     //"stm32f10x_usart.h"
	USART_Initstruct.USART_WordLength = USART_WordLength_8b ;     //"stm32f10x_usart.h"
	USART_Initstruct.USART_StopBits = USART_StopBits_1;           //"stm32f10x_usart.h"
	USART_Initstruct.USART_Parity = USART_Parity_No;
	USART_Initstruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;
	USART_Init(USART1, &USART_Initstruct);
	
	//�ж����ã������жϣ��ж����ȼ���
  NVIC_Config(); 
	//ʹ�ܴ��ڽ����ж�
	USART_ITConfig(USART1, USART_IT_RXNE ,ENABLE);    //"stm32f10x_usart.h"
	//RXNE�������ݼĴ����ǿ�  1���յ����ݣ����Զ�����
	//ʹ�ܴ��ڣ�
	USART_Cmd(USART1, ENABLE);                        //"stm32f10x_usart.h"
}

/*----------------------���͵����ַ�--------------------------------*/
void SendByte(USART_TypeDef* USARTx, uint8_t data)
{
	USART_SendData(USARTx,data);
	while( USART_GetFlagStatus(USARTx, USART_FLAG_TXE) ==RESET );
}

/*----------------------����˫���ַ�--------------------------------*/
void SendHalfWorrd(USART_TypeDef* USARTx, uint16_t data)
{
	uint8_t temp_h,temp_l;
	
	temp_h = (data&0xff00) >> 8 ;   //ȡ�ø߰�λ
	temp_l = data&0xff ;            //ȡ�õͰ�λ
	 
	USART_SendData(USARTx,temp_h);                   //"stm32f10x_usart.h"
	/* �ȴ�������� */
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET );   //"stm32f10x_usart.h"
	
	USART_SendData(USARTx,temp_l);                  //"stm32f10x_usart.h"
	/* �ȴ�������� */
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET );
}

/*----------------------����8λ����--------------------------------*/
void SendArray(USART_TypeDef* USARTx , uint8_t *array ,uint8_t num )
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		SendByte(USARTx,array[i]);   //��ǰ���Լ�д�ġ�
	}
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET );

}

/*----------------------�����ַ���--------------------------------*/
void SendStr(USART_TypeDef* USARTx ,uint8_t *str )
{
	uint8_t i=0;
	do
	{
		SendByte(USARTx,*(str+i));
		i++;
	}while( *(str+i) != '\0');
// '\0' ���ַ����Ľ����� ��\0��ת���ַ���ASCII��ֵΪ0������ʾ����ASCII�����ַ��п��ַ��ĺ���
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET );
}

/*-------�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����-------*/
int fputc(int ch,FILE*f)
{
	USART_SendData(USART1,(uint8_t) ch);                          //"stm32f10x_usart.h"
	/* �ȴ�������� */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET );
	return (ch);
}

//---�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���---*/
int fgetc(FILE *f)
{
	/* �ȴ������������� */
	while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET); //"stm32f10x_usart.h"
	return (int)USART_ReceiveData(USART1);    
}