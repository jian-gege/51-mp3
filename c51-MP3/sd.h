#ifndef _SD_H
#define _SD_H

//#include	"config.h"	


//接口定义

//sbit SD_SCL=P2^5; //SD卡同步时钟  输入
//sbit SD_SI =P2^3; //SD卡同步数据  输入
//sbit SD_CS =P2^2; //SD卡片选 	  输入
//sbit SD_SO =P2^4; //SD卡同步数据  输出
				   
#define DELAY_TIME 2000 //SD卡的复位与初始化时SPI的延时参数，根据实际速率修改其值，否则会造成SD卡复位或初始化失败
#define TRY_TIME 100   //向SD卡写入命令之后，读取SD卡的回应次数，即读TRY_TIME次，如果在TRY_TIME次中读不到回应，产生超时错误，命令写入失败

//错误码定义
//-------------------------------------------------------------
#define INIT_CMD0_ERROR     0x01 //CMD0错误
#define INIT_CMD1_ERROR     0x02 //CMD1错误
#define WRITE_BLOCK_ERROR   0x03 //写块错误
#define READ_BLOCK_ERROR    0x04 //读块错误
#define INIT_CMD8_ERROR	    0x05 //CMD8错误
//-------------------------------------------------------------

unsigned char SD_Reset(); //SD卡复位
unsigned char SD_Check_Version(); //检查SD卡的版本
unsigned char SD_Init()	; //SD卡初始化

unsigned char SD_Ready_Go(); //让SD卡就绪
void SD_spi_write(unsigned char x) ;
unsigned char SD_spi_read();


unsigned char SD_Write_Sector(unsigned long addr,unsigned char *buffer); //将buffer数据缓冲区中的数据写入地址为addr的扇区中
unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer);	 //从地址为addr的扇区中读取数据到buffer数据缓冲区中
unsigned char SD_Write_nSector(unsigned long nsec,unsigned long addr,unsigned char *buffer);

#endif