
#include "stm32f10x_it.h"
#include "bsp_usart.h"

void USART1_IRQHandler (void)
{
	uint8_t uctemp;
	if( USART_GetITStatus(USART1,USART_IT_RXNE) != RESET )
	{
		uctemp == USART_ReceiveData(USART1);
		USART_SendData(USART1, uctemp);
	}
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
