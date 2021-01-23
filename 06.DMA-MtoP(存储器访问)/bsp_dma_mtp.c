#include "bsp_dma_mtp.h"
#include "stm32f10x_dma.h"

uint8_t BufferSize[5000];

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
  //NVIC_Config(); 
	//ʹ�ܴ��ڽ����ж�
	//USART_ITConfig(USART1, USART_IT_RXNE ,ENABLE);    //"stm32f10x_usart.h"
	//RXNE�������ݼĴ����ǿ�  1���յ����ݣ����Զ�����
	//ʹ�ܴ��ڣ�
	USART_Cmd(USART1, ENABLE);                        //"stm32f10x_usart.h"
}

//2-��ʼ��DMA����Ҫ������DMA��ʼ���ṹ�塣	

void DMA_MTP_Config(void)
{
	DMA_InitTypeDef DMA_Initstruct;         //"stm32f10x_dma.h"
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	DMA_Initstruct.DMA_PeripheralBaseAddr = (uint32_t)(USART1_BASE+0x04);  //�����ַ
	DMA_Initstruct.DMA_MemoryBaseAddr = (uint32_t)BufferSize;  //�洢����ַ
	DMA_Initstruct.DMA_DIR =  DMA_DIR_PeripheralDST;
	
	DMA_Initstruct.DMA_BufferSize = 5000;   //������Ŀ
	
	DMA_Initstruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable ;         //�����ַ����ģʽ
	DMA_Initstruct.DMA_MemoryInc = DMA_MemoryInc_Enable;                   //�洢����ַ����ģʽ
	DMA_Initstruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;   //�������ݿ��
	DMA_Initstruct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte ;          //�洢�����ݿ��
	DMA_Initstruct.DMA_Mode = DMA_Mode_Normal;                             //ģʽѡ��
	DMA_Initstruct.DMA_Priority = DMA_Priority_High ;                      //ͨ�����ȼ�
	DMA_Initstruct.DMA_M2M = DMA_M2M_Disable ;                             //SRAM to ���ڣ�
	
	DMA_Init(DMA1_Channel4, &DMA_Initstruct);                              //"stm32f10x_dma.h"
	DMA_ClearFlag(DMA1_FLAG_TC4);
	DMA_Cmd(DMA1_Channel4, ENABLE);
}	

/*-------�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����-------*/
int fputc(int ch,FILE*f)
{
	USART_SendData(USART1,(uint8_t) ch);                          //"stm32f10x_usart.h"
	/* �ȴ�������� */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET );
	return (ch);
}
