/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file EXTI_REG.h
 */

#ifndef EXTI_REG_H_
#define EXTI_REG_H_


#define EXTI_BaseAddress			(0x40010400)


#define EXTI_IMR1					*((volatile uint32 *)(EXTI_BaseAddress+0x00))
#define EXTI_EMR1					*((volatile uint32 *)(EXTI_BaseAddress+0x04))
#define EXTI_RSTR1					*((volatile uint32 *)(EXTI_BaseAddress+0x08))
#define EXTI_FTSR1					*((volatile uint32 *)(EXTI_BaseAddress+0x0C))
#define EXTI_SWIER1					*((volatile uint32 *)(EXTI_BaseAddress+0x10))
#define EXTI_PR1					*((volatile uint32 *)(EXTI_BaseAddress+0x14))
#define EXTI_IMR2					*((volatile uint32 *)(EXTI_BaseAddress+0x20))
#define EXTI_EMR2					*((volatile uint32 *)(EXTI_BaseAddress+0x24))
#define EXTI_RSTR2					*((volatile uint32 *)(EXTI_BaseAddress+0x28))
#define EXTI_FTSR2					*((volatile uint32 *)(EXTI_BaseAddress+0x2C))
#define EXTI_SWIER2					*((volatile uint32 *)(EXTI_BaseAddress+0x30))
#define EXTI_PR2					*((volatile uint32 *)(EXTI_BaseAddress+0x34))

#ifndef		SYSCFG_EXTICR1
#define		AFIO_BASE_ADD	     	(0x40010000)
#define		SYSCFG_EXTICR1			*((volatile uint32 *)(AFIO_BASE_ADD+0x08))
#define		SYSCFG_EXTICR2			*((volatile uint32 *)(AFIO_BASE_ADD+0x0C))
#define		SYSCFG_EXTICR3			*((volatile uint32 *)(AFIO_BASE_ADD+0x10))
#define		SYSCFG_EXTICR4			*((volatile uint32 *)(AFIO_BASE_ADD+0x14))
#endif



#endif /* EXTI_REG_H_ */
