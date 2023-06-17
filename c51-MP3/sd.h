#ifndef _SD_H
#define _SD_H

//#include	"config.h"	


//�ӿڶ���

//sbit SD_SCL=P2^5; //SD��ͬ��ʱ��  ����
//sbit SD_SI =P2^3; //SD��ͬ������  ����
//sbit SD_CS =P2^2; //SD��Ƭѡ 	  ����
//sbit SD_SO =P2^4; //SD��ͬ������  ���
				   
#define DELAY_TIME 2000 //SD���ĸ�λ���ʼ��ʱSPI����ʱ����������ʵ�������޸���ֵ����������SD����λ���ʼ��ʧ��
#define TRY_TIME 100   //��SD��д������֮�󣬶�ȡSD���Ļ�Ӧ����������TRY_TIME�Σ������TRY_TIME���ж�������Ӧ��������ʱ��������д��ʧ��

//�����붨��
//-------------------------------------------------------------
#define INIT_CMD0_ERROR     0x01 //CMD0����
#define INIT_CMD1_ERROR     0x02 //CMD1����
#define WRITE_BLOCK_ERROR   0x03 //д�����
#define READ_BLOCK_ERROR    0x04 //�������
#define INIT_CMD8_ERROR	    0x05 //CMD8����
//-------------------------------------------------------------

unsigned char SD_Reset(); //SD����λ
unsigned char SD_Check_Version(); //���SD���İ汾
unsigned char SD_Init()	; //SD����ʼ��

unsigned char SD_Ready_Go(); //��SD������
void SD_spi_write(unsigned char x) ;
unsigned char SD_spi_read();


unsigned char SD_Write_Sector(unsigned long addr,unsigned char *buffer); //��buffer���ݻ������е�����д���ַΪaddr��������
unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer);	 //�ӵ�ַΪaddr�������ж�ȡ���ݵ�buffer���ݻ�������
unsigned char SD_Write_nSector(unsigned long nsec,unsigned long addr,unsigned char *buffer);

#endif