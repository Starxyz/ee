#ifndef __ADC_H
#define __ADC_H	
#include "includes.h"	
#include "delay.h"

#define ch1   0x01
#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收	
extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	
//如果想串口中断接收，请不要注释以下宏定义
void Adc_Init(void); 				//ADC通道初始化
u16 Get_Adc(u8 ch); 				//获得某个通道值 
u16 Get_Adc_Average(u8 ch,u8 times);//得到某个通道给定次数采样的平均值  
void UartInit(u32 bound);
void Disp(void);
extern void DIS_Delayms(u16 Num);

#endif 

