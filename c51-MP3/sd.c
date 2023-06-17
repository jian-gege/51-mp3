#include "SD.h"
#include "string.h"
#include	"STC8A_SPI.h"

//bit is_init;  //在初始化的时候设置此变量为1,同步数据传输（SPI）会放慢

unsigned char addr_mode; //寻址方式，1为块寻址，0为字节寻址
unsigned char sd_ver; //SD卡的版本 0x05说明是SD1.0  0x01说明是SD2.0
//---------------------------------------------------------------

//unsigned char bdata _dat; //用于优化模拟SPI的中间bdata类型变量，方便取各个位
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
 - 功能描述：将一个32位的变量dat转为字符串，比如把1234转为"1234"
 - 隶属模块：公开函数模块
 - 函数属性：外部，用户可调用
 - 参数说明：dat:带转的long型的变量
             str:指向字符数组的指针，转换后的字节串放在其中           
 - 返回说明：无
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
 - 功能描述：将一个字符串转为32位的变量，比如"1234"转为1234
 - 隶属模块：公开函数模块
 - 函数属性：外部，用户可调用
 - 参数说明：str:指向待转换的字符串           
 - 返回说明：转换后的数值
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
 - 功能描述：IO模拟SPI，发送一个字节
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：x是要发送的字节
 - 返回说明：无返回
 - 注：其中is_init为1时，写的速度放慢，初始化SD卡SPI速度不能太高
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
 - 功能描述：IO模拟SPI，读取一个字节
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：无
 - 返回说明：返回读到的字节
 ******************************************************************/

unsigned char SD_spi_read() //SPI读一个字节
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
 - 功能描述：向SD卡写命令
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：SD卡的命令是6个字节，pcmd是指向命令字节序列的指针
 - 返回说明：命令写入后，SD卡的回应值，调用不成功，将返回0xff
 ******************************************************************/

unsigned char SD_Write_Cmd(unsigned char *pcmd) 
{
 unsigned char temp,time=0;
 
 SD_CS=1;
 SD_spi_write(0xff); //提高兼容性，如果没有这里，有些SD卡可能不支持   
 SD_CS=0;

 SD_spi_write(pcmd[0]);
 SD_spi_write(pcmd[1]);
 SD_spi_write(pcmd[2]);
 SD_spi_write(pcmd[3]);
 SD_spi_write(pcmd[4]);
 SD_spi_write(pcmd[5]);

 do 
 {  
  temp = SD_spi_read();//一直读，直到读到的不是0xff或超时
  time++;
 }while((temp==0xff)&&(time<TRY_TIME)); 

 return(temp);
}

/******************************************************************
 - 功能描述：复位SD卡，用到CMD0，使用SD卡切换到SPI模式
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：无
 - 返回说明：调用成功，返回0x00，否则返回INIT_CMD0_ERROR (sdx.h中有定义)
 ******************************************************************/

unsigned char SD_Reset()
{
 unsigned char time,temp,i;
 unsigned char pcmd[] = {0x40,0x00,0x00,0x00,0x00,0x95}; 

// is_init=1; //is_init置为1，让SPI速度慢下来

 SD_CS=1;
 for(i=0;i<0x0f;i++) //初始时，首先要发送最少74个时钟信号，这是必须的！！！
 {
  SD_spi_write(0xff); //120个时钟
 }

 SD_CS=0;
 time=0;
 do
 { 
  temp=SD_Write_Cmd(pcmd);//写入CMD0
  time++;
  if(time==TRY_TIME) 
  { 
   return(INIT_CMD0_ERROR);//CMD0写入失败
  }
 }while(temp!=0x01);

 SD_CS=1;
 SD_spi_write(0xff); //按照SD卡的操作时序在这里补8个时钟 
 return 0;//返回0,说明复位操作成功
}

/******************************************************************
 - 功能描述：检测SD卡版本，SD卡分为SD与SDHC，通过CMD8进行判断，SD与
             SDHC的初始化以及寻址方法都不尽相同
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：无
 - 返回说明：SD卡的版本号，0x05为SD1.0 0x01为SD2.0
 ******************************************************************/

unsigned char SD_Check_Version() 
{
 unsigned char pcmd[]={0x48,0x00,0x00,0x01,0xaa,0x87}; //CMD8
 SD_CS=0;
 sd_ver=SD_Write_Cmd(pcmd);
 SD_CS=1; //关闭片选
 SD_spi_write(0xff); //按照SD卡的操作时序在这里补8个时钟
 return sd_ver;	//返回版本值
}

/******************************************************************
 - 功能描述：初始化SD卡，使用CMD1
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：无
 - 返回说明：调用成功，返回0x00，否则返回INIT_CMD1_ERROR (sd.h中有定义)
 ******************************************************************/

unsigned char SD_Init()	
{  
 unsigned char time,temp;
 unsigned char pcmd[] = {0x41,0x40,0x00,0x00,0x00,0xff};//第2个字节为0x40  HCS置位，说明主机支持高容量卡

 SD_CS=0;

 time=0;
 do
 { 
  temp=SD_Write_Cmd(pcmd);
  time++;
  if(time==TRY_TIME) 
  { 
   return(INIT_CMD1_ERROR);//CMD1写入失败
  }
 }while(temp!=0);
   		 
// is_init=0; //初始化完毕，将is_init设置为0,为了提高以后的数据传输速度 
   
 SD_CS=1;  //关闭SD卡的片选 

 SD_spi_write(0xff); //按照SD卡的操作时序在这里补8个时钟

 return(0); //返回0,说明初始化操作成功
}

/******************************************************************
 - 功能描述：获取SD卡的寻址方式
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：无
 - 返回说明：调用成功，返回0x00，否则返回INIT_CMD1_ERROR (sd.h中有定义)
 ******************************************************************/

unsigned char SD_Get_Addr_Mode() //获取SD卡的寻址方式，是字节寻址，还是块寻址
{
 unsigned char pcmd[]={0x7a,0x00,0x00,0x00,0x00,0x00}; //CMD58  读取OCR的命令
 SD_CS=0;
 SD_Write_Cmd(pcmd); //写入CMD58
 addr_mode=SD_spi_read();SD_spi_read();SD_spi_read();SD_spi_read(); //后三次读取空读
 SD_CS=1;
 SD_spi_write(0xff); //按照SD卡的操作时序在这里补8个时钟
 return addr_mode&0x40;	//返回版本值 
}

/******************************************************************
 - 功能描述：让SD卡就绪，调用成功后，我们就可以对SD卡进行随心所欲的读写了
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：无
 - 返回说明：调用成功，返回0x00，否则返回INIT_CMD1_ERROR (sd.h中有定义)
 ******************************************************************/

unsigned char SD_Ready_Go()
{
 SD_Reset(); //复位SD卡，使其进入SPI接口模式
 SD_Check_Version(); //检查SD卡版本，是SD还是SDHC
 SD_Get_Addr_Mode();
 return SD_Init();	 //初始化SD卡
} 

/****************************************************************************
 - 功能描述：将buffer指向的512个字节的数据写入到SD卡的addr扇区中
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：addr:扇区地址
             buffer:指向数据缓冲区的指针
 - 返回说明：调用成功，返回0x00，否则返回WRITE_BLOCK_ERROR (sd.h中有定义)
 - 注：SD卡初始化成功后，读写扇区时，尽量将SPI速度提上来，提高效率
 ****************************************************************************/

unsigned char SD_Write_Sector(unsigned long addr,unsigned char *buffer)	//向SD卡中的指定地址的扇区写入512个字节，使用CMD24（24号命令）
{  
 unsigned char temp,time;
 unsigned char i=0;
 unsigned char pcmd[] = {0x58,0x00,0x00,0x00,0x00,0xff}; //向SD卡中单个块（512字节，一个扇区）写入数据，用CMD24

 if(sd_ver==0x05 || !addr_mode) addr<<=9; //addr = addr * 512	将块地址（扇区地址）转为字节地址 ［这里就限制了SD卡的最大容量为4G］

 *((unsigned long *)(pcmd+1))=addr;	//将字节地址写入到CMD24字节序列中

 SD_CS=0;//打开SD卡片选

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd);
  time++;
  if(time==TRY_TIME) 
  { 
   return(temp); //命令写入失败
  }
 }while(temp!=0); 

 for(i=0;i<10;i++) //这里要插入若干时钟信号
 {
  SD_spi_read();
 }
	
 SD_spi_write(0xfe);//写入开始字节 0xfe，后面就是要写入的512个字节的数据	
	
 for(i=0;i<64;i++) //将缓冲区中要写入的512个字节写入SD卡
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
 SD_spi_write(0xff); //两个字节的CRC校验码，不用关心
   
    
 temp=SD_spi_read();   //读取返回值
 if((temp & 0x1F)!=0x05) //如果返回值是 XXX00DELAY_TIME1 说明数据已经被SD卡接受了
 {
  SD_CS=1;
  return(WRITE_BLOCK_ERROR); //写块数据失败
 }
 
 while(SD_spi_read()!=0xff);//等到SD卡不忙（数据被接受以后，SD卡要将这些数据写入到自身的FLASH中，需要一个时间）
						 //忙时，读回来的值为0x00,不忙时，为0xff

 SD_CS=1; //关闭片选

 SD_spi_write(0xff);//按照SD卡的操作时序在这里补8个时钟
 return(0);		 //返回0,说明写扇区操作成功
} 

/****************************************************************************
 - 功能描述：读取addr扇区的512个字节到buffer指向的数据缓冲区
 - 隶属模块：SD/SDHC模块
 - 函数属性：内部
 - 参数说明：addr:扇区地址
             buffer:指向数据缓冲区的指针
 - 返回说明：调用成功，返回0x00，否则返回READ_BLOCK_ERROR (sd.h中有定义)
 - 注：SD卡初始化成功后，读写扇区时，尽量将SPI速度提上来，提高效率
 ****************************************************************************/

unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer)//从SD卡的指定扇区中读出512个字节，使用CMD17（17号命令）
{
 unsigned char j;
 unsigned char time,temp;
 unsigned char pcmd[]={0x51,0x00,0x00,0x00,0x00,0xff}; //CMD17的字节序列
   
 if(sd_ver==0x05 || !addr_mode) addr<<=9; //sector = sector * 512	   将块地址（扇区地址）转为字节地址

 *((unsigned long *)(pcmd+1))=addr;	//将字节地址写入到CMD24字节序列中

 SD_CS=0;//打开片选 

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd); //写入CMD17
  time++;
  if(time==TRY_TIME) 
  {
   return(READ_BLOCK_ERROR); //读块失败
  }
 }while(temp!=0); 
   			
 while (SD_spi_read() != 0xfe); //一直读，当读到0xfe时，说明后面的是512字节的数据了

 for(j=0;j<64;j++)	 //将数据写入到数据缓冲区中
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
 SD_spi_read();//读取两个字节的CRC校验码，不用关心它们

 SD_CS=1;  //SD卡关闭片选 

 SD_spi_write(0xff);//按照SD卡的操作时序在这里补8个时钟

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

 SD_CS=0;//打开SD卡片选

 time=0;
 do
 {  
  temp=SD_Write_Cmd(pcmd);
  time++;
  if(time==TRY_TIME) 
  { 
   return(temp); //命令写入失败
  }
 }while(temp!=0); 

 for(i=0;i<10;i++) //这里要插入若干时钟信号
 {
  SD_spi_read();
 }

 //==============================================================================

 for(j=0;j<nsec;j++)
 {
	
  SD_spi_write(0xfc);//写入开始字节 0xfc，后面就是要写入的512个字节的数据	
	
  for(i=0;i<64;i++) //将缓冲区中要写入的512个字节写入SD卡
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
  SD_spi_write(0xff); //两个字节的CRC校验码，不用关心
   
    
  temp=SD_spi_read();   //读取返回值
  if((temp & 0x1F)!=0x05) //如果返回值是 XXX00DELAY_TIME1 说明数据已经被SD卡接受了
  {
   SD_CS=1;
   return(WRITE_BLOCK_ERROR); //写块数据失败
  }
 
  while(SD_spi_read()!=0xff);//等到SD卡不忙（数据被接受以后，SD卡要将这些数据写入到自身的FLASH中，需要一个时间）
						 //忙时，读回来的值为0x00,不忙时，为0xff
  buffer=temp_buf;
 }

 SD_spi_write(0xfd);

 while(SD_spi_read()!=0xff);

 SD_CS=1; //关闭片选

 SD_spi_write(0xff);//按照SD卡的操作时序在这里补8个时钟
 return(0);		 //返回0,说明写扇区操作成功
} 