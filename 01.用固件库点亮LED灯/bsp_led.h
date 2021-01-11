//�Լ�����ĺ� �ɶ��Ը���
//�����޸� �������޸Ĳ��� �ͺ�
#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"

#define LED1_GPIO_PORT   GPIOB                  /* GPIO�˿� */
#define LED1_GPIO_CLK   RCC_APB2Periph_GPIOB   /* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN   GPIO_Pin_5             /* ���ӵ�SCLʱ���ߵ�GPIO */

#define LED2_GPIO_PORT   GPIOB                  /* GPIO�˿� */
#define LED2_GPIO_CLK   RCC_APB2Periph_GPIOB   /* GPIO�˿�ʱ�� */
#define LED2_GPIO_PIN   GPIO_Pin_0             /* ���ӵ�SCLʱ���ߵ�GPIO */

#define LED3_GPIO_PORT   GPIOB                  /* GPIO�˿� */
#define LED3_GPIO_CLK   RCC_APB2Periph_GPIOB   /* GPIO�˿�ʱ�� */
#define LED3_GPIO_PIN   GPIO_Pin_1             /* ���ӵ�SCLʱ���ߵ�GPIO */

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
  
/* ������ɫ������߼��÷�ʹ��PWM�ɻ��ȫ����ɫ,��Ч������ */

//��
#define LED_RED  \
					LED1(ON);\
					LED2(OFF)\
					LED3(OFF)

//��
#define LED_GREEN		\
					LED1(OFF);\
					LED2(ON)\
					LED3(OFF)

//��
#define LED_BLUE	\
					LED1(OFF);\
					LED2(OFF)\
					LED3(ON)

					
//��(��+��)					
#define LED_YELLOW	\
					LED1(ON);\
					LED2(ON)\
					
//��(��+��)
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF\
					LED3_ON

//��(��+��)
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON\
					LED3_ON
					
//��(��+��+��)
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON\
					LED3_ON
					
//��(ȫ���ر�)
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF\
					LED3_OFF
					
void LED_GPIO_Config(void);

#endif /* _BSP_LED_H */
