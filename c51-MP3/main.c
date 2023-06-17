#include "STC8A_GPIO.h"
#include "config.h"
#include "sd.h"
#include	"STC8A_NVIC.h"
#include  "STC8A_Switch.h"
#include	"STC8A_SPI.h"
#include  "znfat.h"
#include  "1003b.h"
#include "oled.h"
#include "bmp.h"


sbit  KEY_dowm = P0^2;//��һ��
sbit  KEY_up = P0^3; // ��һ��
sbit  KEY_stop = P0^4;//��ͣ
sbit  KEY_vol_up = P0^1; // ��������
sbit  KEY_vol_down= P0^5;//������С


unsigned int i=0,j=0;
unsigned int res;//�ļ����������ķ���ֵ
unsigned int len = 0;//���ļ��ж�ȡ�����ݳ���
char n=2;//ö���ļ��õ��ļ����
unsigned char vol_num=0x55;
struct znFAT_Init_Args Init_Args;  //�ļ���ʼ����������
struct FileInfo fileinfo;//�ļ���Ϣ����
unsigned char buf[320];//Ӧ�����ݻ�����
//						  unsigned int data_pointer;
//							unsigned char i;
//						  unsigned int uiCount;
unsigned char sign=0;					
							
void Delay1000ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 61;
	j = 225;
	k = 62;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay10us()		//@12.000MHz
{
	unsigned char i;

	i = 38;
	while (--i);
}

void Delay50ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 4;
	j = 12;
	k = 50;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



void	GPIO_config(void)
{
	P1_MODE_IO_PU(GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5);		//P1.0~P1.7 ����Ϊ׼˫���
	P2_MODE_IO_PU(GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5);
  P3_MODE_IO_PU(GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_5);	//P3.0~P3.7 ����Ϊ׼˫���
	P0_MODE_IO_PU(GPIO_Pin_1 | GPIO_Pin_2| GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5);
}
/***********************************************************************************/

void	SPI_config(void)   //����spi����ʼ��sd��ʹ��
{
	SPI_InitTypeDef		SPI_InitStructure;
	SPI_InitStructure.SPI_Enable    = ENABLE;						//SPI����    ENABLE, DISABLE
	SPI_InitStructure.SPI_SSIG      = ENABLE;						//Ƭѡλ     ENABLE, DISABLE
	SPI_InitStructure.SPI_FirstBit  = SPI_MSB;					//��λ����   SPI_MSB, SPI_LSB
	SPI_InitStructure.SPI_Mode      = SPI_Mode_Slave;		//����ѡ��   SPI_Mode_Master, SPI_Mode_Slave
	SPI_InitStructure.SPI_CPOL      = SPI_CPOL_Low;			//ʱ����λ   SPI_CPOL_High,   SPI_CPOL_Low
	SPI_InitStructure.SPI_CPHA      = SPI_CPHA_1Edge;		//���ݱ���   SPI_CPHA_1Edge,  SPI_CPHA_2Edge
	SPI_InitStructure.SPI_Speed     = SPI_Speed_64;			//SPI�ٶ�    SPI_Speed_4, SPI_Speed_16, SPI_Speed_64, SPI_Speed_128
	SPI_Init(&SPI_InitStructure);
	NVIC_SPI_Init(ENABLE,Priority_3);		//�ж�ʹ��, ENABLE/DISABLE; ���ȼ�(�͵���) Priority_0,Priority_1,Priority_2,Priority_3
	
	SPI_SW(SPI_P22_P23_P24_P25);	//SPI_P12_P13_P14_P15,SPI_P22_P23_P24_P25,SPI_P74_P75_P76_P77,SPI_P35_P34_P33_P32
	SD_CS = 1;//1_2
}

void	SPI_config2(void)  //��sd��ȡ����
{
	SPI_InitTypeDef		SPI_InitStructure;
	SPI_InitStructure.SPI_Enable    = ENABLE;						//SPI����    ENABLE, DISABLE
	SPI_InitStructure.SPI_SSIG      = ENABLE;						//Ƭѡλ     ENABLE, DISABLE
	SPI_InitStructure.SPI_FirstBit  = SPI_MSB;					//��λ����   SPI_MSB, SPI_LSB
	SPI_InitStructure.SPI_Mode      = SPI_Mode_Slave;		//����ѡ��   SPI_Mode_Master, SPI_Mode_Slave
	SPI_InitStructure.SPI_CPOL      = SPI_CPOL_Low;			//ʱ����λ   SPI_CPOL_High,   SPI_CPOL_Low
	SPI_InitStructure.SPI_CPHA      = SPI_CPHA_1Edge;		//���ݱ���   SPI_CPHA_1Edge,  SPI_CPHA_2Edge
	SPI_InitStructure.SPI_Speed     = SPI_Speed_2;			//SPI�ٶ�    SPI_Speed_4, SPI_Speed_16, SPI_Speed_64, SPI_Speed_128
	SPI_Init(&SPI_InitStructure);
	NVIC_SPI_Init(ENABLE,Priority_3);		//�ж�ʹ��, ENABLE/DISABLE; ���ȼ�(�͵���) Priority_0,Priority_1,Priority_2,Priority_3
	
	SPI_SW(SPI_P22_P23_P24_P25);	//SPI_P12_P13_P14_P15,SPI_P22_P23_P24_P25,SPI_P74_P75_P76_P77,SPI_P35_P34_P33_P32
	SD_CS = 1;//1_2
}

void	SPI_config3(void)		//����д��vs1003
{
	SPI_InitTypeDef		SPI_InitStructure;
	SPI_InitStructure.SPI_Enable    = ENABLE;						//SPI����    ENABLE, DISABLE
	SPI_InitStructure.SPI_SSIG      = ENABLE;						//Ƭѡλ     ENABLE, DISABLE
	SPI_InitStructure.SPI_FirstBit  = SPI_MSB;					//��λ����   SPI_MSB, SPI_LSB
	SPI_InitStructure.SPI_Mode      = SPI_Mode_Slave;		//����ѡ��   SPI_Mode_Master, SPI_Mode_Slave
	SPI_InitStructure.SPI_CPOL      = SPI_CPOL_Low;			//ʱ����λ   SPI_CPOL_High,   SPI_CPOL_Low
	SPI_InitStructure.SPI_CPHA      = SPI_CPHA_1Edge;		//���ݱ���   SPI_CPHA_1Edge,  SPI_CPHA_2Edge
	SPI_InitStructure.SPI_Speed     = SPI_Speed_4;			//SPI�ٶ�    SPI_Speed_4, SPI_Speed_16, SPI_Speed_64, SPI_Speed_128
	SPI_Init(&SPI_InitStructure);
	NVIC_SPI_Init(ENABLE,Priority_3);		//�ж�ʹ��, ENABLE/DISABLE; ���ȼ�(�͵���) Priority_0,Priority_1,Priority_2,Priority_3
	
	SPI_SW(SPI_P12_P13_P14_P15);	//SPI_P12_P13_P14_P15,SPI_P22_P23_P24_P25,SPI_P74_P75_P76_P77,SPI_P35_P34_P33_P32
	c_SPI_SO = 1;
	MP3_DREQ = 1;
}
/***********************************************************************************/


void main()
{
  n = EEPROM_Read(0);
	GPIO_config();//io�ڳ�ʼ��
	SPI_config();//spi��ʼ��
	EA=1;   // ���ж�ʹ�ܣ�Ӳ��spi��Ҫ�õ�
	SPI_SetMode(SPI_Mode_Master);   //Ӳ��spi����ģʽѡ��
	SD_Ready_Go();  //sd����ʼ��

	OLED_Init();	//oled ��ʼ��	
	OLED_Clear(); //����

	znFAT_Device_Init(); // znfat������ʼ������̨�豸���ã�
	znFAT_Select_Device(0,&Init_Args);//ѡ���豸

	res=znFAT_Init();  //�ѻ�ȡ�����ļ���Ϣ����res�ṹ���У�������ʱʹ��
			SPI_config3();
			SPI_SetMode(SPI_Mode_Master);
		
	//Mp3Reset();   //vs1003bӲ����λ
	Mp3SoftReset();
	 //VS1003B_Init();
			SPI_config2();
		  SPI_SetMode(SPI_Mode_Master);   //Ӳ��spi����ģʽѡ��
	
	while(1)
	{
	
	while(!znFAT_Open_File(&fileinfo,"/*.mp3",n++,1))  //��MP3�ļ���ö�ټ�һ
	{
		
				OLED_Clear();
				OLED_ShowCHinese(4,0,0);//��
				OLED_ShowCHinese(24,0,1);//��
				OLED_ShowCHinese(44,0,2);//��
				OLED_ShowCHinese(64,0,3);//��
				OLED_ShowCHinese(84,0,9);//��
				OLED_ShowCHinese(104,0,4);//:
				OLED_ShowCHinese(24,3,5);//��
				OLED_ShowCHinese(74,3,6);//��
				OLED_ShowNum(44,3,n,3,16);
				OLED_ShowCHinese(4,6,10);//��ǰ����
				OLED_ShowCHinese(24,6,11);
				OLED_ShowCHinese(44,6,12);
				OLED_ShowCHinese(64,6,13);
				OLED_ShowCHinese(84,6,4);//:
		OLED_ShowNum(94,6,100-vol_num*100/157 ,3,16);
		while(len=znFAT_ReadData(&fileinfo,fileinfo.File_CurOffset,320,buf)) //�����濨������ 
		{

			SPI_config3();
			 SPI_SetMode(SPI_Mode_Master);

						MP3_XDCS = 0; //vs1003bʹ��
						len/=32;
						for(i=0;i<len;i++)
						{
								MP3_DREQ=1;               //������д�����ݣ����ݶ�ȡ��ͣ
								while(! MP3_DREQ);        //����д������
								for(j=0;j<32;j++)
								{SPIPutChar(buf[i*32+j]);}        //����ѭ��д��vs1003b
						}
						MP3_XDCS=1;     //ʹ�ܹ�

	


				
		  
			if(KEY_vol_up==0){Delay50ms();if(vol_num>=0x4)vol_num-=0x2; Mp3SetVolume1(vol_num);	OLED_ShowNum(94,6,100-vol_num*100/157 ,3,16);}		
			if(KEY_vol_down==0){Delay50ms();if(vol_num<=0x99)vol_num+=0x2; Mp3SetVolume1(vol_num);	OLED_ShowNum(94,6,100-vol_num*100/157 ,3,16);}	
			KEY_dowm = 1;        //�����ж�д��ѭ���ڿ���ʱ�ж��Ƿ��и�  
						
						
						
						
						
			SPI_config2();
			SPI_SetMode(SPI_Mode_Master);	
			if(KEY_dowm==0){Delay50ms();if(KEY_dowm==0){if(n>2)n-=2;else n=0;	EEPROM_Delete(0); EEPROM_Change(0, n); break;}} //ǰһ��
			KEY_up = 1;
			if(KEY_up==0){Delay50ms();if(KEY_up==0){Delay50ms();if(KEY_up==0){EEPROM_Delete(0); EEPROM_Change(0, n); break;}}}//��һ��

							
							if(KEY_stop==0)
							{
								Delay50ms();
								if(KEY_stop==1)
								{
									OLED_Clear_12(); 
									OLED_ShowCHinese(44,0,7);//��ͣ��
									OLED_ShowCHinese(64,0,8);//
									OLED_ShowCHinese(84,0,9);//
									while(1)
									{
										if(KEY_stop==0){Delay50ms(); if(KEY_stop==1)break;}
										if(KEY_dowm==0){Delay50ms();if(KEY_dowm==1){sign=1;break;}} //ǰһ��
										if(KEY_up==0){Delay50ms();if(KEY_up==1){sign=2;break;}}//��һ��
									}
									if(sign==1){sign=0;if(n>2)n-=2;else n=0;	EEPROM_Delete(0); EEPROM_Change(0, n); break; }
									if(sign==2){sign=0;  EEPROM_Delete(0); EEPROM_Change(0, n); break; }
									Delay50ms();
									OLED_Clear_12();
									OLED_ShowCHinese(4,0,0);//��
									OLED_ShowCHinese(24,0,1);//��
									OLED_ShowCHinese(44,0,2);//��
									OLED_ShowCHinese(64,0,3);//��
									OLED_ShowCHinese(84,0,9);//��
									OLED_ShowCHinese(104,0,4);//:						
								}
							}
									//��ͣ
				

			
		}
	}

	n-=2;
	EEPROM_Delete(0);
	EEPROM_Change(0, n);
}
	
	

	

}