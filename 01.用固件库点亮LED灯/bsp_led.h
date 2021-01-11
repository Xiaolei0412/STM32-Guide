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

#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else                       		\
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
  
/* 基本混色，后面高级用法使用PWM可混出全彩颜色,且效果更好 */

//红
#define LED_RED  \
					LED1(ON);\
					LED2(OFF)\
					LED3(OFF)

//绿
#define LED_GREEN		\
					LED1(OFF);\
					LED2(ON)\
					LED3(OFF)

//蓝
#define LED_BLUE	\
					LED1(OFF);\
					LED2(OFF)\
					LED3(ON)

					
//黄(红+绿)					
#define LED_YELLOW	\
					LED1(ON);\
					LED2(ON)\
					
//紫(红+蓝)
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF\
					LED3_ON

//青(绿+蓝)
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON\
					LED3_ON
					
//白(红+绿+蓝)
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON\
					LED3_ON
					
//黑(全部关闭)
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF\
					LED3_OFF
					
void LED_GPIO_Config(void);

#endif /* _BSP_LED_H */
