#include "EEPROM.h"

void EEPROM_OFF();     //关闭IAP功能函数
char EEPROM_Read(int addr);  //读取EEPROM数据函数
void EEPROM_Change(int addr, char dat); //更改EEPROM数据函数
void EEPROM_Delete(int addr);  //清空EEPROM数据函数




void EEPROM_OFF()
{
    IAP_CONTR = 0;                              //关闭IAP功能
    IAP_CMD = 0;                                //清除命令寄存器
    IAP_TRIG = 0;                               //清除触发寄存器
    IAP_ADDRH = 0x80;                           //将地址设置到非IAP区域
    IAP_ADDRL = 0;
}

char EEPROM_Read(int addr)
{
    char dat;

    IAP_CONTR = 0x80;                         //使能IAP
	  IAP_TPS = Main_Fosc_MHZ;
    IAP_CMD = 1;                                //设置IAP读命令
    IAP_ADDRL = addr;                           //设置IAP低地址
    IAP_ADDRH = addr >> 8;                      //设置IAP高地址
    IAP_TRIG = 0x5a;                            //写触发命令(0x5a)
    IAP_TRIG = 0xa5;                            //写触发命令(0xa5)
    _nop_();
    dat = IAP_DATA;                             //读IAP数据
    EEPROM_OFF();                                  //关闭IAP功能

    return dat;
}

void EEPROM_Change(int addr, char dat)
{
    IAP_CONTR = 0x80;                         //使能IAP
		IAP_TPS = Main_Fosc_MHZ;
    IAP_CMD = 2;                                //设置IAP写命令
    IAP_ADDRL = addr;                           //设置IAP低地址
    IAP_ADDRH = addr >> 8;                      //设置IAP高地址
    IAP_DATA = dat;                             //写IAP数据
    IAP_TRIG = 0x5a;                            //写触发命令(0x5a)
    IAP_TRIG = 0xa5;                            //写触发命令(0xa5)
    _nop_();
    EEPROM_OFF();                                  //关闭IAP功能
}

void EEPROM_Delete(int addr)
{
    IAP_CONTR = 0x80;                         //使能IAP
		IAP_TPS = Main_Fosc_MHZ;
    IAP_CMD = 3;                                //设置IAP擦除命令
    IAP_ADDRL = addr;                           //设置IAP低地址
    IAP_ADDRH = addr >> 8;                      //设置IAP高地址
    IAP_TRIG = 0x5a;                            //写触发命令(0x5a)
    IAP_TRIG = 0xa5;                            //写触发命令(0xa5)
    _nop_();                                    //
    EEPROM_OFF();                                  //关闭IAP功能
}