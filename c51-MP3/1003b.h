#include <STC8a8k64d4.H>


//#define uint8 unsigned char
sbit  MP3_XRESET  = P3^2;
#define Mp3PutInReset()  { MP3_XRESET = 0; }
#define Mp3ReleaseFromReset()  { MP3_XRESET =1; }
sbit MP3_XCS = P3^3;
#define Mp3SelectControl()  { MP3_XCS = 0; }
#define Mp3DeselectControl()  { MP3_XCS = 1; }
sbit MP3_XDCS  = P1^1;
#define Mp3SelectData()		{ MP3_XDCS = 0; }
#define Mp3DeselectData()	{ MP3_XDCS = 1; }
sbit MP3_DREQ = P3^5;
sbit c_SPI_SI = P1^3;
sbit c_SPI_SO = P1^4;
sbit c_SPI_CLK = P1^5;






//vs1003相关宏定义 
#define VS_WRITE_COMMAND 0x02
#define VS_READ_COMMAND 0x03
#define SPI_MODE        0x0   
#define SPI_STATUS      0x1   
#define SPI_BASS        0x2   
#define SPI_CLOCKF      0x3   
#define SPI_DECODE_TIME 0x4   
#define SPI_AUDATA      0x5   
#define SPI_WRAM        0x6   
#define SPI_WRAMADDR    0x7   
#define SPI_HDAT0       0x8   
#define SPI_HDAT1       0x9   
#define SPI_AIADDR      0xa   
#define SPI_VOL         0xb   
#define SPI_AICTRL0     0xc   
#define SPI_AICTRL1     0xd   
#define SPI_AICTRL2     0xe   
#define SPI_AICTRL3     0xf   
#define SM_DIFF         0x01   
#define SM_JUMP         0x02   
#define SM_RESET        0x04   
#define SM_OUTOFWAV     0x08   
#define SM_PDOWN        0x10   
#define SM_TESTS        0x20   
#define SM_STREAM       0x40   
#define SM_PLUSV        0x80   
#define SM_DACT         0x100   
#define SM_SDIORD       0x200   
#define SM_SDISHARE     0x400   
#define SM_SDINEW       0x800   
#define SM_ADPCM        0x1000   
#define SM_ADPCM_HP     0x2000 


void Mp3SetVolume1(unsigned char num);

#define Mp3SetVolume(leftchannel,rightchannel){Mp3WriteRegister(11,(leftchannel),(rightchannel));}//音量设置 
		
		 
void  MSPI_Init(void);  //SPI初始化
void  InitPortVS1003(void);//LPC213x与vs1003的接口的初始化
void  SPIPutChar(unsigned char c);//通过SPI发送一个字节的数据
void  Mp3SoftReset(void);//vs1003的软件复位	
void  Mp3Reset(void);//vs1003的硬件复位
void  VsSineTest(void);//vs1003的正弦测试
void  Mp3WriteRegister(unsigned char addressbyte,unsigned char highbyte,unsigned char lowbyte);//写vs1003寄存器
unsigned int Mp3ReadRegister(unsigned char addressbyte);//读vs1003寄存器
void TestVS1003B(void);
void VS1003B_SoftReset(void);
void VS1003B_WriteDAT(unsigned char dat);
void VS1003B_Fill2048Zero();

//开启环绕声
void VS1003B_SetVirtualSurroundOn(void);

//关闭环绕声
void VS1003B_SetVirtualSurroundOff(void);

//增强重音
//入口参数	1.强度0-15
//			2.频率0-15 (X10Hz)
//void VS1003B_SetBassEnhance(uchar ucValue, ucFrequencyID);