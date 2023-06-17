#include "config.h"

extern void EEPROM_OFF();     //关闭IAP功能函数

extern char EEPROM_Read(int addr);  //读取EEPROM数据函数,初始化时用户EEPROM大小建议选择4K，可存512个char型变量，够用就行
/*
取值：addr:要读取的存储地址     取值范围：0x0000 - 0x0200，也可以十进制输入0-512，一个地址可以存储一个char型数据
*/
extern void EEPROM_Change(int addr, char dat); //更改EEPROM数据函数
/*
取值：addr:要更改的存储地址     取值范围：0x0000 - 0x0200，也可以十进制输入0-512，一个地址可以存储一个char型数据
取值：dat:要更改的数据
*/
extern void EEPROM_Delete(int addr);  //清空EEPROM数据函数
/*
取值：addr:要清除的存储地址     注意：清除完的地址内数据默认为0xff。
*/
