#include "EEPROM.h"

void EEPROM_OFF();     //�ر�IAP���ܺ���
char EEPROM_Read(int addr);  //��ȡEEPROM���ݺ���
void EEPROM_Change(int addr, char dat); //����EEPROM���ݺ���
void EEPROM_Delete(int addr);  //���EEPROM���ݺ���




void EEPROM_OFF()
{
    IAP_CONTR = 0;                              //�ر�IAP����
    IAP_CMD = 0;                                //�������Ĵ���
    IAP_TRIG = 0;                               //��������Ĵ���
    IAP_ADDRH = 0x80;                           //����ַ���õ���IAP����
    IAP_ADDRL = 0;
}

char EEPROM_Read(int addr)
{
    char dat;

    IAP_CONTR = 0x80;                         //ʹ��IAP
	  IAP_TPS = Main_Fosc_MHZ;
    IAP_CMD = 1;                                //����IAP������
    IAP_ADDRL = addr;                           //����IAP�͵�ַ
    IAP_ADDRH = addr >> 8;                      //����IAP�ߵ�ַ
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();
    dat = IAP_DATA;                             //��IAP����
    EEPROM_OFF();                                  //�ر�IAP����

    return dat;
}

void EEPROM_Change(int addr, char dat)
{
    IAP_CONTR = 0x80;                         //ʹ��IAP
		IAP_TPS = Main_Fosc_MHZ;
    IAP_CMD = 2;                                //����IAPд����
    IAP_ADDRL = addr;                           //����IAP�͵�ַ
    IAP_ADDRH = addr >> 8;                      //����IAP�ߵ�ַ
    IAP_DATA = dat;                             //дIAP����
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();
    EEPROM_OFF();                                  //�ر�IAP����
}

void EEPROM_Delete(int addr)
{
    IAP_CONTR = 0x80;                         //ʹ��IAP
		IAP_TPS = Main_Fosc_MHZ;
    IAP_CMD = 3;                                //����IAP��������
    IAP_ADDRL = addr;                           //����IAP�͵�ַ
    IAP_ADDRH = addr >> 8;                      //����IAP�ߵ�ַ
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();                                    //
    EEPROM_OFF();                                  //�ر�IAP����
}