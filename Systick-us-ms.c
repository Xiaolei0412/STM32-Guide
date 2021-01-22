#include "bsp_systick.h"
#include "core_cm3.h"

//--------------------微秒级延时-------------------//
void Systick_Delay_us(uint32_t us)   //"core_cm3.h"
{
	uint32_t i;
	SysTick_Config(72);              //"core_cm3.h"
	for(i=0;i<us;i++)
	{
		while  (!((SysTick->CTRL) & (1<<16)));
	}
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}
//--------------------毫秒级延时-------------------//
void Systick_Delay_ms(uint32_t ms)   //"core_cm3.h"
{
	uint32_t i;
	SysTick_Config(72000);           //"core_cm3.h"
	for(i=0;i<ms;i++)
	{
		while  (!((SysTick->CTRL) & (1<<16)));
	}
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}