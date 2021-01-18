
#include "stm32f10x_it.h"
#include "bsp_exti.h"
#include "bsp_led.h"

void  EXTI0_IRQHandler(void)         //"startup_stm32f10x_hd.s"
{
	if( EXTI_GetITStatus( EXTI_Line0) != RESET )   //检查指定的EXTI行是否产生中断。
	{
  //如果产生中断则LED灯反转一次
	LED_G_TOGGLE;
	}
	EXTI_ClearITPendingBit( EXTI_Line0);            //清除EXTI的0位。
}

void EXTI15_10_IRQHandler(void)      //"startup_stm32f10x_hd.s"
{
	if( EXTI_GetITStatus( EXTI_Line13) != RESET )  //检查指定的EXTI行是否产生中断。
	{
	//如果产生中断则LED灯反转一次
	LED_G_TOGGLE;
	}
	EXTI_ClearITPendingBit(EXTI_Line13);          //清除EXTI的13位。

}

