//自己定义的宏 可读性更高
//容易修改 在这里修改参数 型号
#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"

#define LED1_GPIO_PORT   GPIOB                  /* GPIO端口 */
#define LED1_GPIO_CLK   RCC_APB2Periph_GPIOB   /* GPIO端口时钟 */
#define LED1_GPIO_PIN   GPIO_Pin_5             /* 连接到SCL时钟线的GPIO */

#define LED2_GPIO_PORT   GPIOB                  /* GPIO端口 */
#define LED2_GPIO_CLK   RCC_APB2Periph_GPIOB   /* GPIO端口时钟 */
#define LED2_GPIO_PIN   GPIO_Pin_0             /* 连接到SCL时钟线的GPIO */

#define LED3_GPIO_PORT   GPIOB                  /* GPIO端口 */
#define LED3_GPIO_CLK   RCC_APB2Periph_GPIOB   /* GPIO端口时钟 */
#define LED3_GPIO_PIN   GPIO_Pin_1             /* 连接到SCL时钟线的GPIO */

#define ON   0
#define OFF  1

#define LED_ALL(a) if(a) {LED1(OFF);LED2(OFF);LED3(OFF);} else {LED1(ON);LED2(ON);LED3(ON);}

#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)
 
#define LED_Y(a)  if(a) {LED1(OFF);LED2(OFF);LED3(OFF); }  else {LED1(ON);LED2(ON);LED3(OFF);}

#define LED1_TOGGLE	 {LED1_GPIO_PORT->ODR  ^= LED1_GPIO_PIN;} 
#define LED2_TOGGLE	 {LED2_GPIO_PORT->ODR  ^= LED2_GPIO_PIN;}


void LED_GPIO_Config(void);

#endif /* _BSP_LED_H */
