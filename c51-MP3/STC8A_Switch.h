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

#ifndef	__SWITCH_H
#define	__SWITCH_H

#include "type_def.h"
#include "stc8a8k64d4.h"

//========================================================================
//                            功能脚切换设置
//========================================================================

#define  UART1_SW(Pin)				P_SW1 = (P_SW1 & 0x3F) | (Pin << 6)
#define  PCA_SW(Pin)					P_SW1 = (P_SW1 & 0xCF) | (Pin << 4)
#define  SPI_SW(Pin)					P_SW1 = (P_SW1 & 0xF3) | (Pin << 2)
#define  I2C_SW(Pin)					P_SW2 = (P_SW2 & 0xCF) | (Pin << 4)
#define  COMP_SW(Pin)					P_SW2 = (P_SW2 & 0xF7) | (Pin << 3)
#define  UART4_SW(Pin)				P_SW2 = (P_SW2 & 0xFB) | (Pin << 2)
#define  UART3_SW(Pin)				P_SW2 = (P_SW2 & 0xFD) | (Pin << 1)
#define  UART2_SW(Pin)				P_SW2 = (P_SW2 & 0xFE) | (Pin)

#define  PWM15_PWM0_SW(Pin)		{EAXSFR(); PWM0CR = (PWM0CR & ~0x18) | (Pin << 3); EAXRAM();}
#define  PWM15_PWM1_SW(Pin)		{EAXSFR(); PWM1CR = (PWM1CR & ~0x18) | (Pin << 3); EAXRAM();}
#define  PWM15_PWM2_SW(Pin)		{EAXSFR(); PWM2CR = (PWM2CR & ~0x18) | (Pin << 3); EAXRAM();}
#define  PWM15_PWM3_SW(Pin)		{EAXSFR(); PWM3CR = (PWM3CR & ~0x18) | (Pin << 3); EAXRAM();}
#define  PWM15_PWM4_SW(Pin)		{EAXSFR(); PWM4CR = (PWM4CR & ~0x18) | (Pin << 3); EAXRAM();}
#define  PWM15_PWM5_SW(Pin)		{EAXSFR(); PWM5CR = (PWM5CR & ~0x18) | (Pin << 3); EAXRAM();}
#define  PWM15_PWM6_SW(Pin)		{EAXSFR(); PWM6CR = (PWM6CR & ~0x18) | (Pin << 3); EAXRAM();}
#define  PWM15_PWM7_SW(Pin)		{EAXSFR(); PWM7CR = (PWM7CR & ~0x18) | (Pin << 3); EAXRAM();}

#define  MCLKO_SW(Pin)				{EAXSFR(); MCLKOCR = (MCLKOCR & 0x7F) | (Pin << 7); EAXRAM();}
#define  T3T4SEL_SW(Pin)			{EAXSFR(); T3T4PIN = (T3T4PIN & 0xFE) | (Pin); EAXRAM();}

#define  LCM_CTRL_SW(Pin)			{EAXSFR(); LCMIFCFG2 = (LCMIFCFG2 & ~0x60) | (Pin << 5); EAXRAM();}
#define  LCM_DATA_SW(Pin)			{EAXSFR(); LCMIFCFG = (LCMIFCFG & ~0x0C) | (Pin << 2); EAXRAM();}

//========================================================================
//                              定义声明
//========================================================================

#define	LCM_CTRL_P41_P44_P43	0
#define	LCM_CTRL_P41_P37_P36	1
#define	LCM_CTRL_P41_P42_P40	2
#define	LCM_CTRL_P40_P37_P36	3

#define	LCM_D8_NA_P2	0
#define	LCM_D8_NA_P6	1

#define	LCM_D16_P2_P0	0
#define	LCM_D16_P6_P2	1
#define	LCM_D16_P2_P7	2
#define	LCM_D16_P6_P7	3

#define	UART1_SW_P30_P31	0
#define	UART1_SW_P36_P37	1
#define	UART1_SW_P16_P17	2
#define	UART1_SW_P43_P44	3

#define	UART2_SW_P10_P11	0
#define	UART2_SW_P40_P42	1
#define	UART3_SW_P00_P01	0
#define	UART3_SW_P50_P51	1
#define	UART4_SW_P02_P03	0
#define	UART4_SW_P52_P53	1

#define	I2C_P14_P15				0
#define	I2C_P24_P25				1
#define	I2C_P76_P77				2
#define	I2C_P33_P32				3

#define	CMP_OUT_P34				0
#define	CMP_OUT_P41				1

#define	PCA_P12_P17_P16_P15_P14		0
#define	PCA_P22_P23_P24_P25_P26		1
#define	PCA_P74_P70_P71_P72_P73		2
#define	PCA_P35_P33_P32_P31_P30		3

#define	SPI_P12_P13_P14_P15		0
#define	SPI_P22_P23_P24_P25		1
#define	SPI_P74_P75_P76_P77		2
#define	SPI_P35_P34_P33_P32		3

#define	T3T4_P04_P05_P06_P07	0
#define	T3T4_P00_P01_P02_P03	1

#define	MCLKO_SW_P54			0
#define	MCLKO_SW_P16			1

#define	PWM15_SW_P2				0
#define	PWM15_SW_P1				1
#define	PWM15_SW_P6				2

#endif
