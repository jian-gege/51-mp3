#include "config.h"

extern void EEPROM_OFF();     //�ر�IAP���ܺ���

extern char EEPROM_Read(int addr);  //��ȡEEPROM���ݺ���,��ʼ��ʱ�û�EEPROM��С����ѡ��4K���ɴ�512��char�ͱ��������þ���
/*
ȡֵ��addr:Ҫ��ȡ�Ĵ洢��ַ     ȡֵ��Χ��0x0000 - 0x0200��Ҳ����ʮ��������0-512��һ����ַ���Դ洢һ��char������
*/
extern void EEPROM_Change(int addr, char dat); //����EEPROM���ݺ���
/*
ȡֵ��addr:Ҫ���ĵĴ洢��ַ     ȡֵ��Χ��0x0000 - 0x0200��Ҳ����ʮ��������0-512��һ����ַ���Դ洢һ��char������
ȡֵ��dat:Ҫ���ĵ�����
*/
extern void EEPROM_Delete(int addr);  //���EEPROM���ݺ���
/*
ȡֵ��addr:Ҫ����Ĵ洢��ַ     ע�⣺�����ĵ�ַ������Ĭ��Ϊ0xff��
*/
