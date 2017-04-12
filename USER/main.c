#include "includes.h"
#include "driver.h" 
#include "ili9341.h"
#include "stdlib.h"
#include "draw.h"
#include "adc.h"


//***************************************************************
// 深圳EU电子出品-版权所有-翻版必究
// EU-热爱嵌入式开发
// http://euse.taobao.com
//***************************************************************
#include "GUI.h"
extern void GUIDEMO_main(void);
extern void DIS_Delayms(u16 Num);
/*-------------------------------------------------------------------------------------------------------
  程序从这里执行												 
/-------------------------------------------------------------------------------------------------------*/
int main(void)
{
//测试ADC
// 	u16 adcx;
//	float temp;	
	delay_init(168);	
	Adc_Init();
		//驱动初始化
		BSP_Init();
		//GUI模块初始化
		GUI_Init();
		//开启屏幕背光
		Driver_LcdBacklight(True);
		//启动滴答时钟
		SysTick_Init();
		//GUI运行
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();
		GUI_SetColor(GUI_BLACK);
//		DrawSin();
		while(1)
		{
//				GUIDEMO_main();
//				DIS_Delayms(10);
			  DrawLine();	
//			adcx=Get_Adc_Average(ch1,5);
//			GUI_DispDec(adcx,4);
//			temp=(float)adcx*(3.3/4096);          
//			adcx=temp;
//			GUI_DispFloat(temp,9);
//			GUI_DispString("\n");
//			temp-=adcx;                           
//			temp*=1000;                         
//			GUI_DispDec(temp,4);
			DIS_Delayms(2500);
			GUI_Clear();
			DIS_Delayms(2500);

		}
}

/*-------------------------------------------------------------------------------------------------------
*  显示延时												 
----------------------------------------------------------------------------------------------  ---------*/
void DIS_Delayms(u16 Num)
{
   	u16 Timer;
		while(Num--)
		{
		 	Timer = 25000;
			while(Timer--); 
		}
}			

