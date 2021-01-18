
#include "stm32f10x_it.h"
#include "bsp_exti.h"
#include "bsp_led.h"

void  EXTI0_IRQHandler(void)         //"startup_stm32f10x_hd.s"
{
	if( EXTI_GetITStatus( EXTI_Line0) != RESET )   //���ָ����EXTI���Ƿ�����жϡ�
	{
  //��������ж���LED�Ʒ�תһ��
	LED_G_TOGGLE;
	}
	EXTI_ClearITPendingBit( EXTI_Line0);            //���EXTI��0λ��
}

void EXTI15_10_IRQHandler(void)      //"startup_stm32f10x_hd.s"
{
	if( EXTI_GetITStatus( EXTI_Line13) != RESET )  //���ָ����EXTI���Ƿ�����жϡ�
	{
	//��������ж���LED�Ʒ�תһ��
	LED_G_TOGGLE;
	}
	EXTI_ClearITPendingBit(EXTI_Line13);          //���EXTI��13λ��

}

