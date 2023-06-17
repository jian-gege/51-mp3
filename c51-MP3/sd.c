#include "SD.h"
#include "string.h"
#include	"STC8A_SPI.h"

//bit is_init;  //�ڳ�ʼ����ʱ�����ô˱���Ϊ1,ͬ�����ݴ��䣨SPI�������

unsigned char addr_mode; //Ѱַ��ʽ��1Ϊ��Ѱַ��0Ϊ�ֽ�Ѱַ
unsigned char sd_ver; //SD���İ汾 0x05˵����SD1.0  0x01˵����SD2.0
//---------------------------------------------------------------

//unsigned char bdata _dat; //�����Ż�ģ��SPI���м�bdata���ͱ���������ȡ����λ
//sbit _dat7=_dat^7;
//sbit _dat6=_dat^6;
//sbit _dat5=_dat^5;
//sbit _dat4=_dat^4;
//sbit _dat3=_dat^3;
//sbit _dat2=_dat^2;
//sbit _dat1=_dat^1;
//sbit _dat0=_dat^0;





void delay(unsigned int time) 
{
 while(time--);
}

/******************************************************************
 - ������������һ��32λ�ı���datתΪ�ַ����������1234תΪ"1234"
 - ����ģ�飺��������ģ��
 - �������ԣ��ⲿ���û��ɵ���
 - ����˵����dat:��ת��long�͵ı���
             str:ָ���ַ������ָ�룬ת������ֽڴ���������           
 - ����˵������
 ******************************************************************/




void u32tostr(unsigned long dat,char *str) 
{
 char idata temp[20];
 unsigned char idata i=0,j=0;

 i=0;
 while(dat)
 {
  temp[i]=dat%10+0x30;
  i++;
  dat/=10;
 }
 j=i;
 for(i=0;i<j;i++)
 {
  str[i]=temp[j-i-1];
 }
 if(!i) {str[i++]='0';}
 str[i]=0;
}

/******************************************************************
 - ������������һ���ַ���תΪ32λ�ı���������"1234"תΪ1234
 - ����ģ�飺��������ģ��
 - �������ԣ��ⲿ���û��ɵ���
 - ����˵����str:ָ���ת�����ַ���           
 - ����˵����ת�������ֵ
 ******************************************************************/

unsigned long strtou32(char *str) 
{
 unsigned long idata temp=0;
 unsigned long idata fact=1;
 unsigned char idata len=strlen(str);
 unsigned char idata i;

 for(i=len;i>0;i--)
 {
  temp+=((str[i-1]-0x30)*fact);
  fact*=10;
 }
 return temp;
}















/******************************************************************
 - ����������IOģ��SPI������һ���ֽ�
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵����x��Ҫ���͵��ֽ�
 - ����˵�����޷���
 - ע������is_initΪ1ʱ��д���ٶȷ�������ʼ��SD��SPI�ٶȲ���̫��
 ******************************************************************/

void SD_spi_write(unsigned char x) 
{
	SPI_WriteByte(x);
// _dat=x;
// 
// SD_SI=_dat7;
// SD_SCL=0; 
// if(is_init) delay(DELAY_TIME); 
// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);

// SD_SI=_dat6;
// SD_SCL=0; 
// if(is_init) delay(DELAY_TIME); 
// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);

// SD_SI=_dat5;
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);

// SD_SI=_dat4;
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME); 
// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);

// SD_SI=_dat3;
// SD_SCL=0; 
// if(is_init) delay(DELAY_TIME); 
// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);

// SD_SI=_dat2;
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME); 
// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);

// SD_SI=_dat1;
// SD_SCL=0; 
// if(is_init) delay(DELAY_TIME); 
// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);

// SD_SI=_dat0;
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME);  
// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
}

/******************************************************************
 - ����������IOģ��SPI����ȡһ���ֽ�
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵������
 - ����˵�������ض������ֽ�
 ******************************************************************/

unsigned char SD_spi_read() //SPI��һ���ֽ�
{  
	return (SPI_ReadByte());
// SD_SO=1;

// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME); 
// _dat7=SD_SO; 

// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME);
// _dat6=SD_SO; 

// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME);
// _dat5=SD_SO; 

// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME);
// _dat4=SD_SO; 

// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME); 
// _dat3=SD_SO; 

// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME);
// _dat2=SD_SO; 

// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME);
// _dat1=SD_SO;

// SD_SCL=1;
// if(is_init) delay(DELAY_TIME);
// SD_SCL=0;
// if(is_init) delay(DELAY_TIME);
// _dat0=SD_SO; 
// 
// return (_dat);
}

/******************************************************************
 - ������������SD��д����
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵����SD����������6���ֽڣ�pcmd��ָ�������ֽ����е�ָ��
 - ����˵��������д���SD���Ļ�Ӧֵ�����ò��ɹ���������0xff
 ******************************************************************/

unsigned char SD_Write_Cmd(unsigned char *pcmd) 
{
 unsigned char temp,time=0;
 
 SD_CS=1;
 SD_spi_write(0xff); //��߼����ԣ����û�������ЩSD�����ܲ�֧��   
 SD_CS=0;

 SD_spi_write(pcmd[0]);
 SD_spi_write(pcmd[1]);
 SD_spi_write(pcmd[2]);
 SD_spi_write(pcmd[3]);
 SD_spi_write(pcmd[4]);
 SD_spi_write(pcmd[5]);

 do 
 {  
  temp = SD_spi_read();//һֱ����ֱ�������Ĳ���0xff��ʱ
  time++;
 }while((temp==0xff)&&(time<TRY_TIME)); 

 return(temp);
}

/******************************************************************
 - ������������λSD�����õ�CMD0��ʹ��SD���л���SPIģʽ
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵������
 - ����˵�������óɹ�������0x00�����򷵻�INIT_CMD0_ERROR (sdx.h���ж���)
 ******************************************************************/

unsigned char SD_Reset()
{
 unsigned char time,temp,i;
 unsigned char pcmd[] = {0x40,0x00,0x00,0x00,0x00,0x95}; 

// is_init=1; //is_init��Ϊ1����SPI�ٶ�������

 SD_CS=1;
 for(i=0;i<0x0f;i++) //��ʼʱ������Ҫ��������74��ʱ���źţ����Ǳ���ģ�����
 {
  SD_spi_write(0xff); //120��ʱ��
 }

 SD_CS=0;
 time=0;
 do
 { 
  temp=SD_Write_Cmd(pcmd);//д��CMD0
  time++;
  if(time==TRY_TIME) 
  { 
   return(INIT_CMD0_ERROR);//CMD0д��ʧ��
  }
 }while(temp!=0x01);

 SD_CS=1;
 SD_spi_write(0xff); //����SD���Ĳ���ʱ�������ﲹ8��ʱ�� 
 return 0;//����0,˵����λ�����ɹ�
}

/******************************************************************
 - �������������SD���汾��SD����ΪSD��SDHC��ͨ��CMD8�����жϣ�SD��
             SDHC�ĳ�ʼ���Լ�Ѱַ������������ͬ
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵������
 - ����˵����SD���İ汾�ţ�0x05ΪSD1.0 0x01ΪSD2.0
 ******************************************************************/

unsigned char SD_Check_Version() 
{
 unsigned char pcmd[]={0x48,0x00,0x00,0x01,0xaa,0x87}; //CMD8
 SD_CS=0;
 sd_ver=SD_Write_Cmd(pcmd);
 SD_CS=1; //�ر�Ƭѡ
 SD_spi_write(0xff); //����SD���Ĳ���ʱ�������ﲹ8��ʱ��
 return sd_ver;	//���ذ汾ֵ
}

/******************************************************************
 - ������������ʼ��SD����ʹ��CMD1
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵������
 - ����˵�������óɹ�������0x00�����򷵻�INIT_CMD1_ERROR (sd.h���ж���)
 ******************************************************************/

unsigned char SD_Init()	
{  
 unsigned char time,temp;
 unsigned char pcmd[] = {0x41,0x40,0x00,0x00,0x00,0xff};//��2���ֽ�Ϊ0x40  HCS��λ��˵������֧�ָ�������

 SD_CS=0;

 time=0;
 do
 { 
  temp=SD_Write_Cmd(pcmd);
  time++;
  if(time==TRY_TIME) 
  { 
   return(INIT_CMD1_ERROR);//CMD1д��ʧ��
  }
 }while(temp!=0);
   		 
// is_init=0; //��ʼ����ϣ���is_init����Ϊ0,Ϊ������Ժ�����ݴ����ٶ� 
   
 SD_CS=1;  //�ر�SD����Ƭѡ 

 SD_spi_write(0xff); //����SD���Ĳ���ʱ�������ﲹ8��ʱ��

 return(0); //����0,˵����ʼ�������ɹ�
}

/******************************************************************
 - ������������ȡSD����Ѱַ��ʽ
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵������
 - ����˵�������óɹ�������0x00�����򷵻�INIT_CMD1_ERROR (sd.h���ж���)
 ******************************************************************/

unsigned char SD_Get_Addr_Mode() //��ȡSD����Ѱַ��ʽ�����ֽ�Ѱַ�����ǿ�Ѱַ
{
 unsigned char pcmd[]={0x7a,0x00,0x00,0x00,0x00,0x00}; //CMD58  ��ȡOCR������
 SD_CS=0;
 SD_Write_Cmd(pcmd); //д��CMD58
 addr_mode=SD_spi_read();SD_spi_read();SD_spi_read();SD_spi_read(); //�����ζ�ȡ�ն�
 SD_CS=1;
 SD_spi_write(0xff); //����SD���Ĳ���ʱ�������ﲹ8��ʱ��
 return addr_mode&0x40;	//���ذ汾ֵ 
}

/******************************************************************
 - ������������SD�����������óɹ������ǾͿ��Զ�SD���������������Ķ�д��
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵������
 - ����˵�������óɹ�������0x00�����򷵻�INIT_CMD1_ERROR (sd.h���ж���)
 ******************************************************************/

unsigned char SD_Ready_Go()
{
 SD_Reset(); //��λSD����ʹ�����SPI�ӿ�ģʽ
 SD_Check_Version(); //���SD���汾����SD����SDHC
 SD_Get_Addr_Mode();
 return SD_Init();	 //��ʼ��SD��
} 

/****************************************************************************
 - ������������bufferָ���512���ֽڵ�����д�뵽SD����addr������
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵����addr:������ַ
             buffer:ָ�����ݻ�������ָ��
 - ����˵�������óɹ�������0x00�����򷵻�WRITE_BLOCK_ERROR (sd.h���ж���)
 - ע��SD����ʼ���ɹ��󣬶�д����ʱ��������SPI�ٶ������������Ч��
 ****************************************************************************/

unsigned char SD_Write_Sector(unsigned long addr,unsigned char *buffer)	//��SD���е�ָ����ַ������д��512���ֽڣ�ʹ��CMD24��24�����
{  
 unsigned char temp,time;
 unsigned char i=0;
 unsigned char pcmd[] = {0x58,0x00,0x00,0x00,0x00,0xff}; //��SD���е����飨512�ֽڣ�һ��������д�����ݣ���CMD24

 if(sd_ver==0x05 || !addr_mode) addr<<=9; //addr = addr * 512	�����ַ��������ַ��תΪ�ֽڵ�ַ �������������SD�����������Ϊ4G��

 *((unsigned long *)(pcmd+1))=addr;	//���ֽڵ�ַд�뵽CMD24�ֽ�������

 SD_CS=0;//��SD��Ƭѡ

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd);
  time++;
  if(time==TRY_TIME) 
  { 
   return(temp); //����д��ʧ��
  }
 }while(temp!=0); 

 for(i=0;i<10;i++) //����Ҫ��������ʱ���ź�
 {
  SD_spi_read();
 }
	
 SD_spi_write(0xfe);//д�뿪ʼ�ֽ� 0xfe���������Ҫд���512���ֽڵ�����	
	
 for(i=0;i<64;i++) //����������Ҫд���512���ֽ�д��SD��
 {
  SD_spi_write(*buffer++);
  SD_spi_write(*buffer++);
  SD_spi_write(*buffer++);
  SD_spi_write(*buffer++);
  SD_spi_write(*buffer++);
  SD_spi_write(*buffer++);
  SD_spi_write(*buffer++);
  SD_spi_write(*buffer++);
 }
  
 SD_spi_write(0xff); 
 SD_spi_write(0xff); //�����ֽڵ�CRCУ���룬���ù���
   
    
 temp=SD_spi_read();   //��ȡ����ֵ
 if((temp & 0x1F)!=0x05) //�������ֵ�� XXX00DELAY_TIME1 ˵�������Ѿ���SD��������
 {
  SD_CS=1;
  return(WRITE_BLOCK_ERROR); //д������ʧ��
 }
 
 while(SD_spi_read()!=0xff);//�ȵ�SD����æ�����ݱ������Ժ�SD��Ҫ����Щ����д�뵽�����FLASH�У���Ҫһ��ʱ�䣩
						 //æʱ����������ֵΪ0x00,��æʱ��Ϊ0xff

 SD_CS=1; //�ر�Ƭѡ

 SD_spi_write(0xff);//����SD���Ĳ���ʱ�������ﲹ8��ʱ��
 return(0);		 //����0,˵��д���������ɹ�
} 

/****************************************************************************
 - ������������ȡaddr������512���ֽڵ�bufferָ������ݻ�����
 - ����ģ�飺SD/SDHCģ��
 - �������ԣ��ڲ�
 - ����˵����addr:������ַ
             buffer:ָ�����ݻ�������ָ��
 - ����˵�������óɹ�������0x00�����򷵻�READ_BLOCK_ERROR (sd.h���ж���)
 - ע��SD����ʼ���ɹ��󣬶�д����ʱ��������SPI�ٶ������������Ч��
 ****************************************************************************/

unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer)//��SD����ָ�������ж���512���ֽڣ�ʹ��CMD17��17�����
{
 unsigned char j;
 unsigned char time,temp;
 unsigned char pcmd[]={0x51,0x00,0x00,0x00,0x00,0xff}; //CMD17���ֽ�����
   
 if(sd_ver==0x05 || !addr_mode) addr<<=9; //sector = sector * 512	   �����ַ��������ַ��תΪ�ֽڵ�ַ

 *((unsigned long *)(pcmd+1))=addr;	//���ֽڵ�ַд�뵽CMD24�ֽ�������

 SD_CS=0;//��Ƭѡ 

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd); //д��CMD17
  time++;
  if(time==TRY_TIME) 
  {
   return(READ_BLOCK_ERROR); //����ʧ��
  }
 }while(temp!=0); 
   			
 while (SD_spi_read() != 0xfe); //һֱ����������0xfeʱ��˵���������512�ֽڵ�������

 for(j=0;j<64;j++)	 //������д�뵽���ݻ�������
 {	
  *(buffer++)=SD_spi_read();
  *(buffer++)=SD_spi_read();
  *(buffer++)=SD_spi_read();
  *(buffer++)=SD_spi_read();
  *(buffer++)=SD_spi_read();
  *(buffer++)=SD_spi_read();
  *(buffer++)=SD_spi_read();
  *(buffer++)=SD_spi_read();
 }

 SD_spi_read();
 SD_spi_read();//��ȡ�����ֽڵ�CRCУ���룬���ù�������

 SD_CS=1;  //SD���ر�Ƭѡ 

 SD_spi_write(0xff);//����SD���Ĳ���ʱ�������ﲹ8��ʱ��

 return 0;
}

unsigned char SD_Write_nSector(unsigned long nsec,unsigned long addr,unsigned char *buffer)	
{  
 unsigned char temp,time;
 unsigned long i=0,j=0;
 unsigned char pcmd[] = {0x59,0x00,0x00,0x00,0x00,0xff};

 unsigned char *temp_buf=buffer;

 if(sd_ver==0x05 || !addr_mode) addr<<=9; 

 *((unsigned long *)(pcmd+1))=addr;

 SD_CS=0;//��SD��Ƭѡ

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd);
  time++;
  if(time==TRY_TIME) 
  { 
   return(temp); //����д��ʧ��
  }
 }while(temp!=0); 

 for(i=0;i<10;i++) //����Ҫ��������ʱ���ź�
 {
  SD_spi_read();
 }

 //==============================================================================

 for(j=0;j<nsec;j++)
 {
	
  SD_spi_write(0xfc);//д�뿪ʼ�ֽ� 0xfc���������Ҫд���512���ֽڵ�����	
	
  for(i=0;i<64;i++) //����������Ҫд���512���ֽ�д��SD��
  {
   SD_spi_write(*buffer++);
   SD_spi_write(*buffer++);
   SD_spi_write(*buffer++);
   SD_spi_write(*buffer++);
   SD_spi_write(*buffer++);
   SD_spi_write(*buffer++);
   SD_spi_write(*buffer++);
   SD_spi_write(*buffer++);
  }
  
  SD_spi_write(0xff); 
  SD_spi_write(0xff); //�����ֽڵ�CRCУ���룬���ù���
   
    
  temp=SD_spi_read();   //��ȡ����ֵ
  if((temp & 0x1F)!=0x05) //�������ֵ�� XXX00DELAY_TIME1 ˵�������Ѿ���SD��������
  {
   SD_CS=1;
   return(WRITE_BLOCK_ERROR); //д������ʧ��
  }
 
  while(SD_spi_read()!=0xff);//�ȵ�SD����æ�����ݱ������Ժ�SD��Ҫ����Щ����д�뵽�����FLASH�У���Ҫһ��ʱ�䣩
						 //æʱ����������ֵΪ0x00,��æʱ��Ϊ0xff
  buffer=temp_buf;
 }

 SD_spi_write(0xfd);

 while(SD_spi_read()!=0xff);

 SD_CS=1; //�ر�Ƭѡ

 SD_spi_write(0xff);//����SD���Ĳ���ʱ�������ﲹ8��ʱ��
 return(0);		 //����0,˵��д���������ɹ�
} 