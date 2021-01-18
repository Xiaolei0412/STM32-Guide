//�Լ�����ĺ� �ɶ��Ը���
//�����޸� �������޸Ĳ��� �ͺ�
#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f10x.h"

#define KEY1_GPIO_PORT  GPIOA                  /* GPIO�˿� */
#define KEY1_GPIO_CLK   RCC_APB2Periph_GPIOA   /* GPIO�˿�ʱ�� */
#define KEY1_GPIO_PIN   GPIO_Pin_0             /* ���ӵ�SCLʱ���ߵ�GPIO */

#define KEY2_GPIO_PORT  GPIOC                  /* GPIO�˿� */
#define KEY2_GPIO_CLK   RCC_APB2Periph_GPIOC   /* GPIO�˿�ʱ�� */
#define KEY2_GPIO_PIN   GPIO_Pin_13             /* ���ӵ�SCLʱ���ߵ�GPIO */



 /** �������±��ú�
	*  ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
	*  ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
	*/
#define KEY_ON   1
#define KEY_OFF  0


void KEY_GPIO_Config(void);
uint8_t Key_Scan( GPIO_TypeDef* GPIOx,uint16_t GPIO_PIN);
#endif /* _BSP_LED_H */


