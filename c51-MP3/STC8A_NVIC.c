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

#include	"STC8A_NVIC.h"

//========================================================================
// 函数: NVIC_Timer0_Init
// 描述: Timer0嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer0_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer0_Interrupt(State);
	if(Priority <= Priority_3) Timer0_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_Timer1_Init
// 描述: Timer1嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer1_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer1_Interrupt(State);
	if(Priority <= Priority_3) Timer1_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_Timer2_Init
// 描述: Timer2嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, NULL.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer2_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer2_Interrupt(State);
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_Timer3_Init
// 描述: Timer3嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, NULL.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer3_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer3_Interrupt(State);
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_Timer4_Init
// 描述: Timer4嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, NULL.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer4_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer4_Interrupt(State);
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_INT0_Init
// 描述: INT0嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT0_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT0_Interrupt(State);
	if(Priority <= Priority_3) INT0_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_INT1_Init
// 描述: INT1嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT1_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT1_Interrupt(State);
	if(Priority <= Priority_3) INT1_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_INT2_Init
// 描述: INT2嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, NULL.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT2_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT2_Interrupt(State);
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_INT3_Init
// 描述: INT3嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, NULL.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT3_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT3_Interrupt(State);
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_INT4_Init
// 描述: INT4嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, NULL.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT4_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT4_Interrupt(State);
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_ADC_Init
// 描述: ADC嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_ADC_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) ADC_Interrupt(State);
	if(Priority <= Priority_3) ADC_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_CMP_Init
// 描述: 比较器嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, RISING_EDGE/FALLING_EDGE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_CMP_Init(u8 State, u8 Priority)
{
	if(State & RISING_EDGE)	CMPCR1 |= PIE;			//允许上升沿中断
	else	CMPCR1 &= ~PIE;			//禁止上升沿中断
	if(State & FALLING_EDGE)	CMPCR1 |= NIE;		//允许下降沿中断
	else	CMPCR1 &= ~NIE;			//禁止上升沿中断
	if(Priority <= Priority_3) CMP_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_I2C_Init
// 描述: I2C嵌套向量中断控制器初始化.
// 参数: Mode:     模式, I2C_Mode_Master/I2C_Mode_Slave.
// 参数: State:    中断使能状态, I2C_Mode_Master: ENABLE/DISABLE.
//                              I2C_Mode_Slave: I2C_ESTAI/I2C_ERXI/I2C_ETXI/I2C_ESTOI/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_I2C_Init(u8 Mode, u8 State, u8 Priority)
{
	if(Mode > 1) return FAIL;
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	if(Mode == 1)	//I2C_Mode_Master
	{
		I2C_Master_Inturrupt(State);
	}
	else if(Mode == 0)	//I2C_Mode_Slave
	{
		I2CSLCR = (I2CSLCR & ~0x78) | State;
	}
//	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	if(Priority <= Priority_3) CMP_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_UART1_Init
// 描述: UART1嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_UART1_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) UART1_Interrupt(State);
	if(Priority <= Priority_3) UART1_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_UART2_Init
// 描述: UART2嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_UART2_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) UART2_Interrupt(State);
	if(Priority <= Priority_3) UART2_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_UART3_Init
// 描述: UART3嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_UART3_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) UART3_Interrupt(State);
	if(Priority <= Priority_3) UART3_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_UART4_Init
// 描述: UART4嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_UART4_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) UART4_Interrupt(State);
	if(Priority <= Priority_3) UART4_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_SPI_Init
// 描述: SPI嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_SPI_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) SPI_Interrupt(State);
	if(Priority <= Priority_3) SPI_Priority(Priority);
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_PCA_Init
// 描述: PCA嵌套向量中断控制器初始化.
// 参数: Channel:  通道, PCA0/PCA1/PCA2/PCA_Counter.
// 参数: State:    中断使能状态, PCA_ECOM/PCA_CCAPP/PCA_CCAPN/PCA_MAT/PCA_TOG/PCA_PWM/PCA_ECCF/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2020-09-29
//========================================================================
u8 NVIC_PCA_Init(u8 Channel, u8 State, u8 Priority)
{
//	if(Channel > PCA_Counter) return FAIL;
	if(Priority <= Priority_3) PCA_Priority(Priority);
	switch(Channel)
	{
		case 0:		//PCA0
			CCAPM0 = State;
		break;

		case 1:		//PCA1
			CCAPM1 = State;
		break;

		case 2:		//PCA2
			CCAPM2 = State;
		break;

		case 3:		//PCA3
			EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
			CCAPM3 = State;
			EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
		break;

		case 4:		//PCA_Counter
			CMOD = (CMOD  & ~1) | (State & 1);
		break;
	}
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_ADC_Init
// 描述: BMM ADC嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_ADC_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_ADC_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_ADC_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_ADC_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_ADC_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_ADC_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_M2M_Init
// 描述: BMM M2M嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_M2M_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_M2M_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_M2M_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_M2M_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_M2M_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_M2M_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_SPI_Init
// 描述: BMM SPI嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-27
//========================================================================
u8 NVIC_BMM_SPI_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_SPI_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_SPI_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_SPI_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_SPI_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_SPI_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_UART1_Tx_Init
// 描述: BMM UART1 Tx嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_UART1_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_UR1T_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_UR1T_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_UR1T_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_UR1T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_UR1T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_UART1_Rx_Init
// 描述: BMM UART1 Rx嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_UART1_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_UR1R_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_UR1R_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_UR1R_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_UR1R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_UR1R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_UART2_Tx_Init
// 描述: BMM UART2 Tx嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_UART2_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_UR2T_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_UR2T_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_UR2T_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_UR2T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_UR2T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_UART2_Rx_Init
// 描述: BMM UART2 Rx嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_UART2_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_UR2R_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_UR2R_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_UR2R_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_UR2R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_UR2R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_UART3_Tx_Init
// 描述: BMM UART3 Tx嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_UART3_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_UR3T_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_UR3T_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_UR3T_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_UR3T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_UR3T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_UART3_Rx_Init
// 描述: BMM UART3 Rx嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_UART3_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_UR3R_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_UR3R_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_UR3R_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_UR3R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_UR3R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_UART4_Tx_Init
// 描述: BMM UART4 Tx嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_UART4_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_UR4T_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_UR4T_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_UR4T_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_UR4T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_UR4T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_UART4_Rx_Init
// 描述: BMM UART4 Rx嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_UART4_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_UR4R_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_UR4R_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_UR4R_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_UR4R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_UR4R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_BMM_LCM_Init
// 描述: BMM LCM嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_BMM_LCM_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	BMM_LCM_CFG &= ~0x0f;
	if(Priority <= Priority_3) BMM_LCM_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) BMM_LCM_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		BMM_LCM_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		BMM_LCM_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

//========================================================================
// 函数: NVIC_LCM_Init
// 描述: LCM嵌套向量中断控制器初始化.
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
u8 NVIC_LCM_Init(u8 State, u8 Priority)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
	LCMIFCFG &= ~0x30;
	if(Priority <= Priority_3) LCMIFCFG |= Priority << 4;
	if(State == ENABLE)
		LCMIFCFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		LCMIFCFG &= ~0x80;		//bit7 0:Disable Interrupt
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
	return SUCCESS;
}

