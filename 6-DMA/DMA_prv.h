/**
 * @author Abdelrahman Elhetamy
 * @file DMA_cfg.h
 * @brief DMA generic driver based on STM32F303RE(Cortex-M4)
 * @date July 2023
 */

#ifndef DMA_PRV_H_
#define DMA_PRV_H_

typedef struct
{
	volatile uint32 DMA_CCR;
	volatile uint32 DMA_CNDTR;
	volatile uint32 DMA_CPAR;
	volatile uint32 DMA_CMAR;
	volatile uint32 Reserved;
}DMA_type;



typedef struct
{
	volatile uint32 DMA_ISR;
	volatile uint32 DMA_IFCR;
	DMA_type DMA_Channel[7];
}DMA1_Channels;

#define			DMA1			((volatile DMA1_Channels *) (DMA1_BaseAddress))




typedef enum
{
	ISR_GIF1=0,
	ISR_TCIF1,
	ISR_HTIF1,
	ISR_TEIF1,
	ISR_GIF2,
	ISR_TCIF2,
	ISR_HTIF2,
	ISR_TEIF2,
	ISR_GIF3,
	ISR_TCIF3,
	ISR_HTIF3,
	ISR_TEIF3,
	ISR_GIF4,
	ISR_TCIF4,
	ISR_HTIF4,
	ISR_TEIF4,
	ISR_GIF5,
	ISR_TCIF5,
	ISR_HTIF5,
	ISR_TEIF5,
	ISR_GIF6,
	ISR_TCIF6,
	ISR_HTIF6,
	ISR_TEIF6,
	ISR_GIF7,
	ISR_TCIF7,
	ISR_HTIF7,
	ISR_TEIF7
}ISR_Bits;

typedef enum
{
	IFCR_CGIF1,
	IFCR_CTCIF1,
	IFCR_CHTIF1,
	IFCR_CTEIF1,
	IFCR_CGIF2,
	IFCR_CTCIF2,
	IFCR_CHTIF2,
	IFCR_CTEIF2,
	IFCR_CGIF3,
	IFCR_CTCIF3,
	IFCR_CHTIF3,
	IFCR_CTEIF3,
	IFCR_CGIF4,
	IFCR_CTCIF4,
	IFCR_CHTIF4,
	IFCR_CTEIF4,
	IFCR_CGIF5,
	IFCR_CTCIF5,
	IFCR_CHTIF5,
	IFCR_CTEIF5,
	IFCR_CGIF6,
	IFCR_CTCIF6,
	IFCR_CHTIF6,
	IFCR_CTEIF6,
	IFCR_CGIF7,
	IFCR_CTCIF7,
	IFCR_CHTIF7,
	IFCR_CTEIF7
}IFCR_Bits;

typedef enum
{
	CCRA_EN,
	CCRA_TCIE,
	CCRA_HTIE,
	CCRA_TEIE,
	CCRA_DIR,
	CCRA_CIRC,
	CCRA_PINC,
	CCRA_MINC,
	CCRA_PSIZE0,
	CCRA_PSIZE1,
	CCRA_MSIZE0,
	CCRA_MSIZE1,
	CCRA_PL0,
	CCRA_PL1,
	CCRA_MEM2MEM
}CCRA_Bits;

typedef enum
{
	NDT0,
	NDT1,
	NDT2,
	NDT3,
	NDT4,
	NDT5,
	NDT6,
	NDT7,
	NDT8,
	NDT9,
	NDT10,
	NDT11,
	NDT12,
	NDT13,
	NDT14,
	NDT15
}CNDTR_Bits;

typedef enum
{
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PA8,
	PA9,
	PA10,
	PA11,
	PA12,
	PA13,
	PA14,
	PA15,
	PA16,
	PA17,
	PA18,
	PA19,
	PA20,
	PA21,
	PA22,
	PA23,
	PA24,
	PA25,
	PA26,
	PA27,
	PA28,
	PA29,
	PA30,
	PA31
}CPAR_Bits;


typedef enum
{
	MA0,
	MA1,
	MA2,
	MA3,
	MA4,
	MA5,
	MA6,
	MA7,
	MA8,
	MA9,
	MA10,
	MA11,
	MA12,
	MA13,
	MA14,
	MA15,
	MA16,
	MA17,
	MA18,
	MA19,
	MA20,
	MA21,
	MA22,
	MA23,
	MA24,
	MA25,
	MA26,
	MA27,
	MA28,
	MA29,
	MA30,
	MA31
}CMAR_Bits;

#define 	CHANNEL_1		0u
#define 	CHANNEL_2		1u
#define 	CHANNEL_3		2u
#define 	CHANNEL_4		3u
#define 	CHANNEL_5		4u
#define 	CHANNEL_6		5u
#define 	CHANNEL_7		6u



#define	EIGHT_BIT			0u
#define	SIXTEEN_BIT			1u
#define	THIRTYTWO_BIT		2u

#endif /* DMA_PRV_H_ */
