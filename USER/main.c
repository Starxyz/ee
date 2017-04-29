#include "includes.h"
#include "driver.h" 
#include "ili9341.h"
#include "stdlib.h"
#include "PROGBAR.h"
#include "draw.h"
#include "adc.h"
#include "WM.h"
//
#include <stddef.h>
#include <string.h>
#include "GUI.h"
#include "FRAMEWIN.h"
//static void  CallbackChild(WM_MESSAGE *pMsg)
//{
//	WM_HWIN hWin = (FRAMEWIN_Handle)(pMsg->hWin);
//	switch(pMsg->MsgId)
//	{
//		case WM_PAINT:
//			GUI_SetBkColor(GUI_BLUE);
//			GUI_SetColor(GUI_WHITE);
//			GUI_SetFont(&GUI_FontComic24B_ASCII);
//			GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
//			GUI_Clear();
//			GUI_DispStringHCenterAt("Child window", 
//															 WM_GetWindowSizeX(hWin)/2,
//															 WM_GetWindowSizeY(hWin)/2);
//			break;
//	}
//}
//static void DemoFramewin(void)
//{
//	FRAMEWIN_Handle hFrame = FRAMEWIN_Create("Frame window",
//																						NULL, WM_CF_SHOW,
//																						10, 10, 150, 60);
//	FRAMEWIN_SetFont(hFrame, &GUI_Font16B_ASCII);
//	FRAMEWIN_SetTextColor(hFrame, GUI_RED);
//	FRAMEWIN_SetBarColor(hFrame, 0, GUI_GREEN);
//	FRAMEWIN_SetTextAlign(hFrame, GUI_TA_HCENTER);
//	WM_CreateWindowAsChild(0, 0, 0, 0,hFrame, WM_CF_SHOW, CallbackChild, 0);
//}





/**/

//***************************************************************
// 深圳EU电子出品-版权所有-翻版必究
// EU-热爱嵌入式开发
// http://euse.taobao.com
//***************************************************************
//#include "GUI.h"
extern void GUIDEMO_main(void);
extern void DIS_Delayms(u16 Num);
void demo(){
		WM_HWIN win_id;
		win_id = CreateFramewin(WM_HBKWIN);
		
}
/*-------------------------------------------------------------------------------------------------------
  程序从这里执行												 
/-------------------------------------------------------------------------------------------------------*/
int main(void)
{
//测试ADC
// 	u16 adcx;
//	float temp;
	GUI_PID_STATE Point;
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
//		WM_HideWindow(win_id);//隐藏刚刚创建的窗口
//		GUI_Clear();		
////		WM_ShowWindow(win_id);
//		GUI_CURSOR_SetPosition(100,200); 
		demo();
//		WM_Exec();
		GUI_CURSOR_Show();
		while(1)
		{
//				GUIDEMO_main();
				GUI_TOUCH_Exec(); //???10ms????
				DIS_Delayms(10);
				GUI_TOUCH_GetState(&Point);
				GUI_CURSOR_SetPosition(Point.x,Point.y);
				WM_Exec();
				DIS_Delayms(10);

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

