#ifndef __BSP_DMA_H
#define	__BSP_DMA_H

#include "stm32f10x.h"

// Ҫ���͵����ݴ�С
#define BUFFER_SIZE     32

#define  MTM_DMA_CLK       RCC_AHBPeriph_DMA1
#define  MTM_DMA_CHANNEL   DMA1_Channel6
#define  MTM_DMA_FLAG_TC   DMA1_FLAG_TC6


#endif /* __BSP_DMA_H */