#ifndef __Driver__
#define __Driver__
/*--------------------------------------------------------------------------
// 文件名：Driver.h
// 描述：  系统驱动头文件
// 设计者：EU电子
// 创建日期：2013年11月10日
// 深圳EU电子出品-版权所有-翻版必究
// EU-热爱嵌入式开发
// http://euse.taobao.com
//-------------------------------------------------------------------------*/
typedef unsigned char       bool;
typedef unsigned char       u8;
typedef unsigned short      u16;

/*-------------------------------------------------------------------------------------------------------
*  向外接口	为应用层提供的接口										 
-------------------------------------------------------------------------------------------------------*/
//mcu
extern void Driver_MCU_Init(void);
//lcd
extern void Driver_LcdBacklight(bool sta);
extern void Driver_LcdReset(bool sta);
extern void Driver_LcdCS(bool sta);
extern void Driver_LcdRS(bool sta);
extern void Driver_LcdRD(bool sta);
extern void Driver_LcdWR(bool sta);
extern void Driver_LcdSendData(u16 Temp);
//spi
extern void Driver_SPION(void);
extern void Driver_SPIOFF(void);
extern void Driver_SPICSEN(void);
extern void Driver_SPICSUN(void);
extern void Driver_SPISend(u8 Data);
extern u8 Driver_SPIRecv(void);
//fsmc
extern void Driver_LcdFSMCON(void);
extern void Driver_LcdFSMCWriteReg(u16 Index);
extern void Driver_LcdFSMCWriteData(u16 Data);
extern u16 Driver_LcdFSMCReadData(void);
//Touch
extern void Driver_SPICS(bool sta);
extern void Driver_SPISCK(bool sta);
extern void Driver_SPIMOSI(bool sta);
extern bool Driver_SPIMISO(void);

#endif



