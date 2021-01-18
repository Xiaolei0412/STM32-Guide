//自己定义的宏 可读性更高
//容易修改 在这里修改参数 型号
#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f10x.h"

#define KEY1_GPIO_PORT  GPIOA                  /* GPIO端口 */
#define KEY1_GPIO_CLK   RCC_APB2Periph_GPIOA   /* GPIO端口时钟 */
#define KEY1_GPIO_PIN   GPIO_Pin_0             /* 连接到SCL时钟线的GPIO */

#define KEY2_GPIO_PORT  GPIOC                  /* GPIO端口 */
#define KEY2_GPIO_CLK   RCC_APB2Periph_GPIOC   /* GPIO端口时钟 */
#define KEY2_GPIO_PIN   GPIO_Pin_13             /* 连接到SCL时钟线的GPIO */



 /** 按键按下标置宏
	*  按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0
	*  若按键按下为低电平，把宏设置成KEY_ON=0 ，KEY_OFF=1 即可
	*/
#define KEY_ON   1
#define KEY_OFF  0


void KEY_GPIO_Config(void);
uint8_t Key_Scan( GPIO_TypeDef* GPIOx,uint16_t GPIO_PIN);
#endif /* _BSP_LED_H */


