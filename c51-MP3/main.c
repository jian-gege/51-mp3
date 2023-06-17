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


sbit  KEY_dowm = P0^2;//上一首
sbit  KEY_up = P0^3; // 下一首
sbit  KEY_stop = P0^4;//暂停
sbit  KEY_vol_up = P0^1; // 声音调大
sbit  KEY_vol_down= P0^5;//声音调小


unsigned int i=0,j=0;
unsigned int res;//文件操作函数的返回值
unsigned int len = 0;//从文件中读取的数据长度
char n=2;//枚举文件用的文件编号
unsigned char vol_num=0x55;
struct znFAT_Init_Args Init_Args;  //文件初始化参数集合
struct FileInfo fileinfo;//文件信息集合
unsigned char buf[320];//应用数据缓冲区
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
	P1_MODE_IO_PU(GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5);		//P1.0~P1.7 设置为准双向口
	P2_MODE_IO_PU(GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5);
  P3_MODE_IO_PU(GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_5);	//P3.0~P3.7 设置为准双向口
	P0_MODE_IO_PU(GPIO_Pin_1 | GPIO_Pin_2| GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5);
}
/***********************************************************************************/

void	SPI_config(void)   //低速spi，初始化sd卡使用
{
	SPI_InitTypeDef		SPI_InitStructure;
	SPI_InitStructure.SPI_Enable    = ENABLE;						//SPI启动    ENABLE, DISABLE
	SPI_InitStructure.SPI_SSIG      = ENABLE;						//片选位     ENABLE, DISABLE
	SPI_InitStructure.SPI_FirstBit  = SPI_MSB;					//移位方向   SPI_MSB, SPI_LSB
	SPI_InitStructure.SPI_Mode      = SPI_Mode_Slave;		//主从选择   SPI_Mode_Master, SPI_Mode_Slave
	SPI_InitStructure.SPI_CPOL      = SPI_CPOL_Low;			//时钟相位   SPI_CPOL_High,   SPI_CPOL_Low
	SPI_InitStructure.SPI_CPHA      = SPI_CPHA_1Edge;		//数据边沿   SPI_CPHA_1Edge,  SPI_CPHA_2Edge
	SPI_InitStructure.SPI_Speed     = SPI_Speed_64;			//SPI速度    SPI_Speed_4, SPI_Speed_16, SPI_Speed_64, SPI_Speed_128
	SPI_Init(&SPI_InitStructure);
	NVIC_SPI_Init(ENABLE,Priority_3);		//中断使能, ENABLE/DISABLE; 优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
	
	SPI_SW(SPI_P22_P23_P24_P25);	//SPI_P12_P13_P14_P15,SPI_P22_P23_P24_P25,SPI_P74_P75_P76_P77,SPI_P35_P34_P33_P32
	SD_CS = 1;//1_2
}

void	SPI_config2(void)  //从sd卡取数据
{
	SPI_InitTypeDef		SPI_InitStructure;
	SPI_InitStructure.SPI_Enable    = ENABLE;						//SPI启动    ENABLE, DISABLE
	SPI_InitStructure.SPI_SSIG      = ENABLE;						//片选位     ENABLE, DISABLE
	SPI_InitStructure.SPI_FirstBit  = SPI_MSB;					//移位方向   SPI_MSB, SPI_LSB
	SPI_InitStructure.SPI_Mode      = SPI_Mode_Slave;		//主从选择   SPI_Mode_Master, SPI_Mode_Slave
	SPI_InitStructure.SPI_CPOL      = SPI_CPOL_Low;			//时钟相位   SPI_CPOL_High,   SPI_CPOL_Low
	SPI_InitStructure.SPI_CPHA      = SPI_CPHA_1Edge;		//数据边沿   SPI_CPHA_1Edge,  SPI_CPHA_2Edge
	SPI_InitStructure.SPI_Speed     = SPI_Speed_2;			//SPI速度    SPI_Speed_4, SPI_Speed_16, SPI_Speed_64, SPI_Speed_128
	SPI_Init(&SPI_InitStructure);
	NVIC_SPI_Init(ENABLE,Priority_3);		//中断使能, ENABLE/DISABLE; 优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
	
	SPI_SW(SPI_P22_P23_P24_P25);	//SPI_P12_P13_P14_P15,SPI_P22_P23_P24_P25,SPI_P74_P75_P76_P77,SPI_P35_P34_P33_P32
	SD_CS = 1;//1_2
}

void	SPI_config3(void)		//数据写入vs1003
{
	SPI_InitTypeDef		SPI_InitStructure;
	SPI_InitStructure.SPI_Enable    = ENABLE;						//SPI启动    ENABLE, DISABLE
	SPI_InitStructure.SPI_SSIG      = ENABLE;						//片选位     ENABLE, DISABLE
	SPI_InitStructure.SPI_FirstBit  = SPI_MSB;					//移位方向   SPI_MSB, SPI_LSB
	SPI_InitStructure.SPI_Mode      = SPI_Mode_Slave;		//主从选择   SPI_Mode_Master, SPI_Mode_Slave
	SPI_InitStructure.SPI_CPOL      = SPI_CPOL_Low;			//时钟相位   SPI_CPOL_High,   SPI_CPOL_Low
	SPI_InitStructure.SPI_CPHA      = SPI_CPHA_1Edge;		//数据边沿   SPI_CPHA_1Edge,  SPI_CPHA_2Edge
	SPI_InitStructure.SPI_Speed     = SPI_Speed_4;			//SPI速度    SPI_Speed_4, SPI_Speed_16, SPI_Speed_64, SPI_Speed_128
	SPI_Init(&SPI_InitStructure);
	NVIC_SPI_Init(ENABLE,Priority_3);		//中断使能, ENABLE/DISABLE; 优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
	
	SPI_SW(SPI_P12_P13_P14_P15);	//SPI_P12_P13_P14_P15,SPI_P22_P23_P24_P25,SPI_P74_P75_P76_P77,SPI_P35_P34_P33_P32
	c_SPI_SO = 1;
	MP3_DREQ = 1;
}
/***********************************************************************************/


void main()
{
  n = EEPROM_Read(0);
	GPIO_config();//io口初始化
	SPI_config();//spi初始化
	EA=1;   // 打开中断使能，硬件spi需要用到
	SPI_SetMode(SPI_Mode_Master);   //硬件spi主从模式选择
	SD_Ready_Go();  //sd卡初始化

	OLED_Init();	//oled 初始化	
	OLED_Clear(); //清屏

	znFAT_Device_Init(); // znfat驱动初始化（多台设备有用）
	znFAT_Select_Device(0,&Init_Args);//选择设备

	res=znFAT_Init();  //把获取到的文件信息放入res结构体中，方便随时使用
			SPI_config3();
			SPI_SetMode(SPI_Mode_Master);
		
	//Mp3Reset();   //vs1003b硬件复位
	Mp3SoftReset();
	 //VS1003B_Init();
			SPI_config2();
		  SPI_SetMode(SPI_Mode_Master);   //硬件spi主从模式选择
	
	while(1)
	{
	
	while(!znFAT_Open_File(&fileinfo,"/*.mp3",n++,1))  //打开MP3文件，枚举加一
	{
		
				OLED_Clear();
				OLED_ShowCHinese(4,0,0);//正
				OLED_ShowCHinese(24,0,1);//在
				OLED_ShowCHinese(44,0,2);//播
				OLED_ShowCHinese(64,0,3);//放
				OLED_ShowCHinese(84,0,9);//中
				OLED_ShowCHinese(104,0,4);//:
				OLED_ShowCHinese(24,3,5);//地
				OLED_ShowCHinese(74,3,6);//首
				OLED_ShowNum(44,3,n,3,16);
				OLED_ShowCHinese(4,6,10);//当前音量
				OLED_ShowCHinese(24,6,11);
				OLED_ShowCHinese(44,6,12);
				OLED_ShowCHinese(64,6,13);
				OLED_ShowCHinese(84,6,4);//:
		OLED_ShowNum(94,6,100-vol_num*100/157 ,3,16);
		while(len=znFAT_ReadData(&fileinfo,fileinfo.File_CurOffset,320,buf)) //读储存卡的数据 
		{

			SPI_config3();
			 SPI_SetMode(SPI_Mode_Master);

						MP3_XDCS = 0; //vs1003b使能
						len/=32;
						for(i=0;i<len;i++)
						{
								MP3_DREQ=1;               //不可以写入数据，数据读取暂停
								while(! MP3_DREQ);        //可以写入数据
								for(j=0;j<32;j++)
								{SPIPutChar(buf[i*32+j]);}        //数据循环写给vs1003b
						}
						MP3_XDCS=1;     //使能关

	


				
		  
			if(KEY_vol_up==0){Delay50ms();if(vol_num>=0x4)vol_num-=0x2; Mp3SetVolume1(vol_num);	OLED_ShowNum(94,6,100-vol_num*100/157 ,3,16);}		
			if(KEY_vol_down==0){Delay50ms();if(vol_num<=0x99)vol_num+=0x2; Mp3SetVolume1(vol_num);	OLED_ShowNum(94,6,100-vol_num*100/157 ,3,16);}	
			KEY_dowm = 1;        //按键判断写进循环内可随时判断是否切歌  
						
						
						
						
						
			SPI_config2();
			SPI_SetMode(SPI_Mode_Master);	
			if(KEY_dowm==0){Delay50ms();if(KEY_dowm==0){if(n>2)n-=2;else n=0;	EEPROM_Delete(0); EEPROM_Change(0, n); break;}} //前一首
			KEY_up = 1;
			if(KEY_up==0){Delay50ms();if(KEY_up==0){Delay50ms();if(KEY_up==0){EEPROM_Delete(0); EEPROM_Change(0, n); break;}}}//后一首

							
							if(KEY_stop==0)
							{
								Delay50ms();
								if(KEY_stop==1)
								{
									OLED_Clear_12(); 
									OLED_ShowCHinese(44,0,7);//暂停中
									OLED_ShowCHinese(64,0,8);//
									OLED_ShowCHinese(84,0,9);//
									while(1)
									{
										if(KEY_stop==0){Delay50ms(); if(KEY_stop==1)break;}
										if(KEY_dowm==0){Delay50ms();if(KEY_dowm==1){sign=1;break;}} //前一首
										if(KEY_up==0){Delay50ms();if(KEY_up==1){sign=2;break;}}//后一首
									}
									if(sign==1){sign=0;if(n>2)n-=2;else n=0;	EEPROM_Delete(0); EEPROM_Change(0, n); break; }
									if(sign==2){sign=0;  EEPROM_Delete(0); EEPROM_Change(0, n); break; }
									Delay50ms();
									OLED_Clear_12();
									OLED_ShowCHinese(4,0,0);//正
									OLED_ShowCHinese(24,0,1);//在
									OLED_ShowCHinese(44,0,2);//播
									OLED_ShowCHinese(64,0,3);//放
									OLED_ShowCHinese(84,0,9);//中
									OLED_ShowCHinese(104,0,4);//:						
								}
							}
									//暂停
				

			
		}
	}

	n-=2;
	EEPROM_Delete(0);
	EEPROM_Change(0, n);
}
	
	

	

}