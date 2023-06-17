/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ���Ҫ�ڳ�����ʹ�ô˴���,���ڳ�����ע��ʹ����STC�����ϼ�����            */
/*---------------------------------------------------------------------*/

#ifndef		__TYPE_DEF_H
#define		__TYPE_DEF_H

//========================================================================
//                               ���Ͷ���
//========================================================================

typedef unsigned char   u8;     //  8 bits 
typedef unsigned int    u16;    // 16 bits 
typedef unsigned long   u32;    // 32 bits 

typedef signed char     int8;   //  8 bits 
typedef signed int      int16;  // 16 bits 
typedef signed long     int32;  // 32 bits 

typedef unsigned char   uint8;  //  8 bits 
typedef unsigned int    uint16; // 16 bits 
typedef unsigned long   uint32; // 32 bits 



#define ulong unsigned long
//typedef signed char     int8_t;   //  8 bits 
//typedef signed int      int16_t;  // 16 bits 
//typedef signed long     int32_t;  // 32 bits 


//typedef unsigned char   uint8_t;  //  8 bits 
//typedef unsigned int    uint16_t; // 16 bits 
//typedef unsigned long   uint32_t; // 32 bits 



#define UINT8   unsigned char
#define UINT16  unsigned int
#define UINT32  unsigned long


#define INT8    char
#define INT16   int
#define INT32   long

#define ROM_TYPE_UINT8    unsigned char code
#define ROM_TYPE_UINT16   unsigned short  code
#define ROM_TYPE_UINT32   unsigned int  code
 

#define	TRUE	1
#define	FALSE	0

//=============================================================

#define	NULL	0

//========================================

#define	Priority_0			0	//�ж����ȼ�Ϊ 0 ������ͼ���
#define	Priority_1			1	//�ж����ȼ�Ϊ 1 �����ϵͼ���
#define	Priority_2			2	//�ж����ȼ�Ϊ 2 �����ϸ߼���
#define	Priority_3			3	//�ж����ȼ�Ϊ 3 ������߼���

#define ENABLE		1
#define DISABLE		0

#define SUCCESS		0
#define FAIL			-1


#endif
