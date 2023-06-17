#include "myfun.h"
#include "string.h"

/*******************************************************

        +------------------------------------+
        |振南电子 原创程序模块 公共函数部分  |
        +------------------------------------+

  此源码版权属 振南 全权享有，如欲引用，敬请署名并告知
        严禁随意用于商业目的，违者必究，后果自负
         振南电子 
             ->产品网站 http://www.znmcu.cn/
             ->产品论坛 http://bbs.znmcu.cn/
             ->产品网店 http://shop.znmcu.cn/
             ->产品咨询 QQ:987582714 MSN:yzn07@126.com
	                WW:yzn07				  
********************************************************/

/******************************************************************
 - 功能描述：延时函数
 - 隶属模块：公开函数模块
 - 函数属性：外部，用户可调用
 - 参数说明：time:time值决定了延时的时间长短           
 - 返回说明：无
 - 注：.....
 ******************************************************************/

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