/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序            */
/*---------------------------------------------------------------------*/

#ifndef	__NVIC_H
#define	__NVIC_H

#include	"config.h"

//========================================================================
//                              定义声明
//========================================================================

#define	FALLING_EDGE		1		//产生下降沿中断
#define	RISING_EDGE			2		//产生上升沿中断

//========================================================================
//                              定时器中断设置
//========================================================================

#define 	Timer0_Interrupt(n)		(n==0?(ET0 = 0):(ET0 = 1))				/* Timer0中断使能 */
#define 	Timer1_Interrupt(n)		(n==0?(ET1 = 0):(ET1 = 1))				/* Timer1中断使能 */
#define 	Timer2_Interrupt(n)		IE2 = (IE2 & ~0x04) | (n << 2)			/* Timer2中断使能 */
#define 	Timer3_Interrupt(n)		IE2 = (IE2 & ~0x20) | (n << 5)			/* Timer3中断使能 */
#define 	Timer4_Interrupt(n)		IE2 = (IE2 & ~0x40) | (n << 6)			/* Timer4中断使能 */

//========================================================================
//                             外部中断设置
//========================================================================

#define 	INT0_Interrupt(n)		(n==0?(EX0 = 0):(EX0 = 1))			/* INT0中断使能 */
#define 	INT1_Interrupt(n)		(n==0?(EX1 = 0):(EX1 = 1))			/* INT1中断使能 */
#define 	INT2_Interrupt(n)		INT_CLKO = (INT_CLKO & ~0x10) | (n << 4)			/* INT2中断使能 */
#define 	INT3_Interrupt(n)		INT_CLKO = (INT_CLKO & ~0x20) | (n << 5)			/* INT3中断使能 */
#define 	INT4_Interrupt(n)		INT_CLKO = (INT_CLKO & ~0x40) | (n << 6)			/* INT4中断使能 */

//========================================================================
//                              ADC中断设置
//========================================================================

#define 	ADC_Interrupt(n)		(n==0?(EADC = 0):(EADC = 1))	/* ADC中断控制 */

//========================================================================
//                              SPI中断设置
//========================================================================

#define 	SPI_Interrupt(n)				IE2 = (IE2 & ~0x02) | (n << 1)				/* SPI中断使能 */

//========================================================================
//                              UART中断设置
//========================================================================

#define		UART1_Interrupt(n)	(n==0?(ES = 0):(ES = 1))					/* UART1中断使能 */
#define		UART1_RxEnable(n)	(n==0?(REN = 0):(REN = 1))					/* UART1接收使能 */

#define		UART2_Interrupt(n)	IE2 = (IE2 & ~0x01) | (n)					/* UART2中断使能 */
#define		UART2_RxEnable(n)	S2CON = (S2CON & ~0x10) | (n << 4)	/* UART2接收使能 */

#define		UART3_Interrupt(n)	IE2 = (IE2 & ~0x08) | (n << 3)		/* UART3中断使能 */
#define		UART3_RxEnable(n)	S3CON = (S3CON & ~0x10) | (n << 4)	/* UART3接收使能 */

#define		UART4_Interrupt(n)	IE2 = (IE2 & ~0x10) | (n << 4)		/* UART4中断使能 */
#define		UART4_RxEnable(n)	S4CON = (S4CON & ~0x10) | (n << 4)	/* UART4接收使能 */

//========================================================================
//                              I2C中断设置
//========================================================================

#define		I2C_Master_Inturrupt(n)	(n==0?(I2CMSCR &= ~0x80):(I2CMSCR |= 0x80))	//0：禁止 I2C 功能；1：使能 I2C 功能

//========================================================================
//                            中断优先级定义
//========================================================================

//串口2中断优先级控制
#define 	UART2_Priority(n)			do{if(n == 0) IP2H &= ~PS2H, IP2 &= ~PS2; \
																if(n == 1) IP2H &= ~PS2H, IP2 |= PS2; \
																if(n == 2) IP2H |= PS2H, IP2 &= ~PS2; \
																if(n == 3) IP2H |= PS2H, IP2 |= PS2; \
															}while(0)
//SPI中断优先级控制
#define 	SPI_Priority(n)				do{if(n == 0) IP2H &= ~PSPIH, IP2 &= ~PSPI; \
																if(n == 1) IP2H &= ~PSPIH, IP2 |= PSPI; \
																if(n == 2) IP2H |= PSPIH, IP2 &= ~PSPI; \
																if(n == 3) IP2H |= PSPIH, IP2 |= PSPI; \
															}while(0)
//外部中断4中断优先级控制
#define 	INT4_Priority(n)				do{if(n == 0) IP2H &= ~PX4H, IP2 &= ~PX4; \
																if(n == 1) IP2H &= ~PX4H, IP2 |= PX4; \
																if(n == 2) IP2H |= PX4H, IP2 &= ~PX4; \
																if(n == 3) IP2H |= PX4H, IP2 |= PX4; \
															}while(0)
//比较器中断优先级控制
#define 	CMP_Priority(n)				do{if(n == 0) IP2H &= ~PCMPH, IP2 &= ~PCMP; \
																if(n == 1) IP2H &= ~PCMPH, IP2 |= PCMP; \
																if(n == 2) IP2H |= PCMPH, IP2 &= ~PCMP; \
																if(n == 3) IP2H |= PCMPH, IP2 |= PCMP; \
															}while(0)
//I2C中断优先级控制
#define 	I2C_Priority(n)				do{if(n == 0) IP2H &= ~PI2CH, IP2 &= ~PI2C; \
																if(n == 1) IP2H &= ~PI2CH, IP2 |= PI2C; \
																if(n == 2) IP2H |= PI2CH, IP2 &= ~PI2C; \
																if(n == 3) IP2H |= PI2CH, IP2 |= PI2C; \
															}while(0)
//增强型PWM中断优先级控制
#define 	PWM_Priority(n)				do{if(n == 0) IP2H &= ~PPWMH, IP2 &= ~PPWM; \
																if(n == 1) IP2H &= ~PPWMH, IP2 |= PPWM; \
																if(n == 2) IP2H |= PPWMH, IP2 &= ~PPWM; \
																if(n == 3) IP2H |= PPWMH, IP2 |= PPWM; \
															}while(0)
//增强型PWM异常检测中断优先级控制
#define 	PWMFD_Priority(n)			do{if(n == 0) IP2H &= ~PPWMFDH, IP2 &= ~PPWMFD; \
																if(n == 1) IP2H &= ~PPWMFDH, IP2 |= PPWMFD; \
																if(n == 2) IP2H |= PPWMFDH, IP2 &= ~PPWMFD; \
																if(n == 3) IP2H |= PPWMFDH, IP2 |= PPWMFD; \
															}while(0)
//串口3中断优先级控制
#define 	UART3_Priority(n)			do{if(n == 0) IP3H &= ~PS3H, IP3 &= ~PS3; \
																if(n == 1) IP3H &= ~PS3H, IP3 |= PS3; \
																if(n == 2) IP3H |= PS3H, IP3 &= ~PS3; \
																if(n == 3) IP3H |= PS3H, IP3 |= PS3; \
															}while(0)
//串口4中断优先级控制
#define 	UART4_Priority(n)			do{if(n == 0) IP3H &= ~PS4H, IP3 &= ~PS4; \
																if(n == 1) IP3H &= ~PS4H, IP3 |= PS4; \
																if(n == 2) IP3H |= PS4H, IP3 &= ~PS4; \
																if(n == 3) IP3H |= PS4H, IP3 |= PS4; \
															}while(0)

//外部中断0中断优先级控制
#define 	INT0_Priority(n)			do{if(n == 0) IPH &= ~PX0H, PX0 = 0; \
																if(n == 1) IPH &= ~PX0H, PX0 = 1; \
																if(n == 2) IPH |= PX0H, PX0 = 0; \
																if(n == 3) IPH |= PX0H, PX0 = 1; \
															}while(0)
//外部中断1中断优先级控制
#define 	INT1_Priority(n)			do{if(n == 0) IPH &= ~PX1H, PX1 = 0; \
																if(n == 1) IPH &= ~PX1H, PX1 = 1; \
																if(n == 2) IPH |= PX1H, PX1 = 0; \
																if(n == 3) IPH |= PX1H, PX1 = 1; \
															}while(0)
//定时器0中断优先级控制
#define 	Timer0_Priority(n)		do{if(n == 0) IPH &= ~PT0H, PT0 = 0; \
																if(n == 1) IPH &= ~PT0H, PT0 = 1; \
																if(n == 2) IPH |= PT0H, PT0 = 0; \
																if(n == 3) IPH |= PT0H, PT0 = 1; \
															}while(0)
//定时器1中断优先级控制
#define 	Timer1_Priority(n)		do{if(n == 0) IPH &= ~PT1H, PT1 = 0; \
																if(n == 1) IPH &= ~PT1H, PT1 = 1; \
																if(n == 2) IPH |= PT1H, PT1 = 0; \
																if(n == 3) IPH |= PT1H, PT1 = 1; \
															}while(0)
//串口1中断优先级控制
#define 	UART1_Priority(n)			do{if(n == 0) IPH &= ~PSH, PS = 0; \
																if(n == 1) IPH &= ~PSH, PS = 1; \
																if(n == 2) IPH |= PSH, PS = 0; \
																if(n == 3) IPH |= PSH, PS = 1; \
															}while(0)
//ADC中断优先级控制
#define 	ADC_Priority(n)				do{if(n == 0) IPH &= ~PADCH, PADC = 0; \
																if(n == 1) IPH &= ~PADCH, PADC = 1; \
																if(n == 2) IPH |= PADCH, PADC = 0; \
																if(n == 3) IPH |= PADCH, PADC = 1; \
															}while(0)
//低压检测中断优先级控制
#define 	LVD_Priority(n)				do{if(n == 0) IPH &= ~PLVDH, PADC = 0; \
																if(n == 1) IPH &= ~PLVDH, PADC = 1; \
																if(n == 2) IPH |= PLVDH, PADC = 0; \
																if(n == 3) IPH |= PLVDH, PADC = 1; \
															}while(0)
//CCP/PCA/PWM中断优先级控制
#define 	PCA_Priority(n)				do{if(n == 0) IPH &= ~PPCAH, PPCA = 0; \
																if(n == 1) IPH &= ~PPCAH, PPCA = 1; \
																if(n == 2) IPH |= PPCAH, PPCA = 0; \
																if(n == 3) IPH |= PPCAH, PPCA = 1; \
															}while(0)


//========================================================================
//                           外部函数和变量声明
//========================================================================

u8 NVIC_Timer0_Init(u8 State, u8 Priority);
u8 NVIC_Timer1_Init(u8 State, u8 Priority);
u8 NVIC_Timer2_Init(u8 State, u8 Priority);
u8 NVIC_Timer3_Init(u8 State, u8 Priority);
u8 NVIC_Timer4_Init(u8 State, u8 Priority);
u8 NVIC_INT0_Init(u8 State, u8 Priority);
u8 NVIC_INT1_Init(u8 State, u8 Priority);
u8 NVIC_INT2_Init(u8 State, u8 Priority);
u8 NVIC_INT3_Init(u8 State, u8 Priority);
u8 NVIC_INT4_Init(u8 State, u8 Priority);
u8 NVIC_ADC_Init(u8 State, u8 Priority);
u8 NVIC_SPI_Init(u8 State, u8 Priority);
u8 NVIC_CMP_Init(u8 State, u8 Priority);
u8 NVIC_I2C_Init(u8 Mode, u8 State, u8 Priority);
u8 NVIC_UART1_Init(u8 State, u8 Priority);
u8 NVIC_UART2_Init(u8 State, u8 Priority);
u8 NVIC_UART3_Init(u8 State, u8 Priority);
u8 NVIC_UART4_Init(u8 State, u8 Priority);
u8 NVIC_PCA_Init(u8 Channel, u8 State, u8 Priority);
u8 NVIC_BMM_ADC_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_M2M_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_SPI_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_LCM_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_UART1_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_UART1_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_UART2_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_UART2_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_UART3_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_UART3_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_UART4_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_BMM_UART4_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_LCM_Init(u8 State, u8 Priority);

#endif

