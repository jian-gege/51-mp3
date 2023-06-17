/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ���Ҫ�ڳ�����ʹ�ô˴���,���ڳ�����ע��ʹ����STC�����ϼ�����            */
/*---------------------------------------------------------------------*/

#ifndef	__NVIC_H
#define	__NVIC_H

#include	"config.h"

//========================================================================
//                              ��������
//========================================================================

#define	FALLING_EDGE		1		//�����½����ж�
#define	RISING_EDGE			2		//�����������ж�

//========================================================================
//                              ��ʱ���ж�����
//========================================================================

#define 	Timer0_Interrupt(n)		(n==0?(ET0 = 0):(ET0 = 1))				/* Timer0�ж�ʹ�� */
#define 	Timer1_Interrupt(n)		(n==0?(ET1 = 0):(ET1 = 1))				/* Timer1�ж�ʹ�� */
#define 	Timer2_Interrupt(n)		IE2 = (IE2 & ~0x04) | (n << 2)			/* Timer2�ж�ʹ�� */
#define 	Timer3_Interrupt(n)		IE2 = (IE2 & ~0x20) | (n << 5)			/* Timer3�ж�ʹ�� */
#define 	Timer4_Interrupt(n)		IE2 = (IE2 & ~0x40) | (n << 6)			/* Timer4�ж�ʹ�� */

//========================================================================
//                             �ⲿ�ж�����
//========================================================================

#define 	INT0_Interrupt(n)		(n==0?(EX0 = 0):(EX0 = 1))			/* INT0�ж�ʹ�� */
#define 	INT1_Interrupt(n)		(n==0?(EX1 = 0):(EX1 = 1))			/* INT1�ж�ʹ�� */
#define 	INT2_Interrupt(n)		INT_CLKO = (INT_CLKO & ~0x10) | (n << 4)			/* INT2�ж�ʹ�� */
#define 	INT3_Interrupt(n)		INT_CLKO = (INT_CLKO & ~0x20) | (n << 5)			/* INT3�ж�ʹ�� */
#define 	INT4_Interrupt(n)		INT_CLKO = (INT_CLKO & ~0x40) | (n << 6)			/* INT4�ж�ʹ�� */

//========================================================================
//                              ADC�ж�����
//========================================================================

#define 	ADC_Interrupt(n)		(n==0?(EADC = 0):(EADC = 1))	/* ADC�жϿ��� */

//========================================================================
//                              SPI�ж�����
//========================================================================

#define 	SPI_Interrupt(n)				IE2 = (IE2 & ~0x02) | (n << 1)				/* SPI�ж�ʹ�� */

//========================================================================
//                              UART�ж�����
//========================================================================

#define		UART1_Interrupt(n)	(n==0?(ES = 0):(ES = 1))					/* UART1�ж�ʹ�� */
#define		UART1_RxEnable(n)	(n==0?(REN = 0):(REN = 1))					/* UART1����ʹ�� */

#define		UART2_Interrupt(n)	IE2 = (IE2 & ~0x01) | (n)					/* UART2�ж�ʹ�� */
#define		UART2_RxEnable(n)	S2CON = (S2CON & ~0x10) | (n << 4)	/* UART2����ʹ�� */

#define		UART3_Interrupt(n)	IE2 = (IE2 & ~0x08) | (n << 3)		/* UART3�ж�ʹ�� */
#define		UART3_RxEnable(n)	S3CON = (S3CON & ~0x10) | (n << 4)	/* UART3����ʹ�� */

#define		UART4_Interrupt(n)	IE2 = (IE2 & ~0x10) | (n << 4)		/* UART4�ж�ʹ�� */
#define		UART4_RxEnable(n)	S4CON = (S4CON & ~0x10) | (n << 4)	/* UART4����ʹ�� */

//========================================================================
//                              I2C�ж�����
//========================================================================

#define		I2C_Master_Inturrupt(n)	(n==0?(I2CMSCR &= ~0x80):(I2CMSCR |= 0x80))	//0����ֹ I2C ���ܣ�1��ʹ�� I2C ����

//========================================================================
//                            �ж����ȼ�����
//========================================================================

//����2�ж����ȼ�����
#define 	UART2_Priority(n)			do{if(n == 0) IP2H &= ~PS2H, IP2 &= ~PS2; \
																if(n == 1) IP2H &= ~PS2H, IP2 |= PS2; \
																if(n == 2) IP2H |= PS2H, IP2 &= ~PS2; \
																if(n == 3) IP2H |= PS2H, IP2 |= PS2; \
															}while(0)
//SPI�ж����ȼ�����
#define 	SPI_Priority(n)				do{if(n == 0) IP2H &= ~PSPIH, IP2 &= ~PSPI; \
																if(n == 1) IP2H &= ~PSPIH, IP2 |= PSPI; \
																if(n == 2) IP2H |= PSPIH, IP2 &= ~PSPI; \
																if(n == 3) IP2H |= PSPIH, IP2 |= PSPI; \
															}while(0)
//�ⲿ�ж�4�ж����ȼ�����
#define 	INT4_Priority(n)				do{if(n == 0) IP2H &= ~PX4H, IP2 &= ~PX4; \
																if(n == 1) IP2H &= ~PX4H, IP2 |= PX4; \
																if(n == 2) IP2H |= PX4H, IP2 &= ~PX4; \
																if(n == 3) IP2H |= PX4H, IP2 |= PX4; \
															}while(0)
//�Ƚ����ж����ȼ�����
#define 	CMP_Priority(n)				do{if(n == 0) IP2H &= ~PCMPH, IP2 &= ~PCMP; \
																if(n == 1) IP2H &= ~PCMPH, IP2 |= PCMP; \
																if(n == 2) IP2H |= PCMPH, IP2 &= ~PCMP; \
																if(n == 3) IP2H |= PCMPH, IP2 |= PCMP; \
															}while(0)
//I2C�ж����ȼ�����
#define 	I2C_Priority(n)				do{if(n == 0) IP2H &= ~PI2CH, IP2 &= ~PI2C; \
																if(n == 1) IP2H &= ~PI2CH, IP2 |= PI2C; \
																if(n == 2) IP2H |= PI2CH, IP2 &= ~PI2C; \
																if(n == 3) IP2H |= PI2CH, IP2 |= PI2C; \
															}while(0)
//��ǿ��PWM�ж����ȼ�����
#define 	PWM_Priority(n)				do{if(n == 0) IP2H &= ~PPWMH, IP2 &= ~PPWM; \
																if(n == 1) IP2H &= ~PPWMH, IP2 |= PPWM; \
																if(n == 2) IP2H |= PPWMH, IP2 &= ~PPWM; \
																if(n == 3) IP2H |= PPWMH, IP2 |= PPWM; \
															}while(0)
//��ǿ��PWM�쳣����ж����ȼ�����
#define 	PWMFD_Priority(n)			do{if(n == 0) IP2H &= ~PPWMFDH, IP2 &= ~PPWMFD; \
																if(n == 1) IP2H &= ~PPWMFDH, IP2 |= PPWMFD; \
																if(n == 2) IP2H |= PPWMFDH, IP2 &= ~PPWMFD; \
																if(n == 3) IP2H |= PPWMFDH, IP2 |= PPWMFD; \
															}while(0)
//����3�ж����ȼ�����
#define 	UART3_Priority(n)			do{if(n == 0) IP3H &= ~PS3H, IP3 &= ~PS3; \
																if(n == 1) IP3H &= ~PS3H, IP3 |= PS3; \
																if(n == 2) IP3H |= PS3H, IP3 &= ~PS3; \
																if(n == 3) IP3H |= PS3H, IP3 |= PS3; \
															}while(0)
//����4�ж����ȼ�����
#define 	UART4_Priority(n)			do{if(n == 0) IP3H &= ~PS4H, IP3 &= ~PS4; \
																if(n == 1) IP3H &= ~PS4H, IP3 |= PS4; \
																if(n == 2) IP3H |= PS4H, IP3 &= ~PS4; \
																if(n == 3) IP3H |= PS4H, IP3 |= PS4; \
															}while(0)

//�ⲿ�ж�0�ж����ȼ�����
#define 	INT0_Priority(n)			do{if(n == 0) IPH &= ~PX0H, PX0 = 0; \
																if(n == 1) IPH &= ~PX0H, PX0 = 1; \
																if(n == 2) IPH |= PX0H, PX0 = 0; \
																if(n == 3) IPH |= PX0H, PX0 = 1; \
															}while(0)
//�ⲿ�ж�1�ж����ȼ�����
#define 	INT1_Priority(n)			do{if(n == 0) IPH &= ~PX1H, PX1 = 0; \
																if(n == 1) IPH &= ~PX1H, PX1 = 1; \
																if(n == 2) IPH |= PX1H, PX1 = 0; \
																if(n == 3) IPH |= PX1H, PX1 = 1; \
															}while(0)
//��ʱ��0�ж����ȼ�����
#define 	Timer0_Priority(n)		do{if(n == 0) IPH &= ~PT0H, PT0 = 0; \
																if(n == 1) IPH &= ~PT0H, PT0 = 1; \
																if(n == 2) IPH |= PT0H, PT0 = 0; \
																if(n == 3) IPH |= PT0H, PT0 = 1; \
															}while(0)
//��ʱ��1�ж����ȼ�����
#define 	Timer1_Priority(n)		do{if(n == 0) IPH &= ~PT1H, PT1 = 0; \
																if(n == 1) IPH &= ~PT1H, PT1 = 1; \
																if(n == 2) IPH |= PT1H, PT1 = 0; \
																if(n == 3) IPH |= PT1H, PT1 = 1; \
															}while(0)
//����1�ж����ȼ�����
#define 	UART1_Priority(n)			do{if(n == 0) IPH &= ~PSH, PS = 0; \
																if(n == 1) IPH &= ~PSH, PS = 1; \
																if(n == 2) IPH |= PSH, PS = 0; \
																if(n == 3) IPH |= PSH, PS = 1; \
															}while(0)
//ADC�ж����ȼ�����
#define 	ADC_Priority(n)				do{if(n == 0) IPH &= ~PADCH, PADC = 0; \
																if(n == 1) IPH &= ~PADCH, PADC = 1; \
																if(n == 2) IPH |= PADCH, PADC = 0; \
																if(n == 3) IPH |= PADCH, PADC = 1; \
															}while(0)
//��ѹ����ж����ȼ�����
#define 	LVD_Priority(n)				do{if(n == 0) IPH &= ~PLVDH, PADC = 0; \
																if(n == 1) IPH &= ~PLVDH, PADC = 1; \
																if(n == 2) IPH |= PLVDH, PADC = 0; \
																if(n == 3) IPH |= PLVDH, PADC = 1; \
															}while(0)
//CCP/PCA/PWM�ж����ȼ�����
#define 	PCA_Priority(n)				do{if(n == 0) IPH &= ~PPCAH, PPCA = 0; \
																if(n == 1) IPH &= ~PPCAH, PPCA = 1; \
																if(n == 2) IPH |= PPCAH, PPCA = 0; \
																if(n == 3) IPH |= PPCAH, PPCA = 1; \
															}while(0)


//========================================================================
//                           �ⲿ�����ͱ�������
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

