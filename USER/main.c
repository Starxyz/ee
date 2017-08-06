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

#include "key.h"
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
// ����EU���ӳ�Ʒ-��Ȩ����-����ؾ�
// EU-�Ȱ�Ƕ��ʽ����
// http://euse.taobao.com
//***************************************************************
//#include "GUI.h"
extern void GUIDEMO_main(void);
//extern void DIS_Delayms(u16 Num);
void demo(){
GUI_MEMDEV_Handle hMem = GUI_MEMDEV_Create(0,0,320,240);
GUI_MEMDEV_Select(hMem);
//GUI_SetFont(&GUI_Font32B_ASCII);
GUI_DispString("Text is good to read h \n eadsaldkasdk");
GUI_MEMDEV_CopyToLCDAA(hMem);
		
}
/*-------------------------------------------------------------------------------------------------------
  ���������ִ��												 
/-------------------------------------------------------------------------------------------------------*/
int main(void)
{
		u8 len, t;
//		GUI_PID_STATE Point;
		delay_init(168);	
		Adc_Init();
	
		UartInit(9600);

		//������ʼ��
		BSP_Init();
		//GUIģ���ʼ��
		GUI_Init();
		//������Ļ����
		Driver_LcdBacklight(True);
		//�����δ�ʱ��
		SysTick_Init();
		//GUI����	
//		WM_HideWindow(win_id);//���ظոմ����Ĵ���
//		GUI_Clear();		
////		WM_ShowWindow(win_id);
//		GUI_CURSOR_SetPosition(100,200); 
//		demo();
//		WM_Exec();
		KEY_Init();
		GUI_CURSOR_Show();
		while(1)
		{
//				GUIDEMO_main();
				//Run();
				GUI_DispDec(key(),2);
				DIS_Delayms(1000);
//				if(USART_RX_STA&0x8000)
//				{					   
//					len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
//					for(t=0;t<len;t++)
//					{
//						USART_SendData(USART1, USART_RX_BUF[t]);         //�򴮿�1��������
//						while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
//						if(USART_RX_BUF[t]=='D')
//							Run();
//					}
//					USART_RX_STA=0;
//				}else
//				{
//					delay_ms(10);   
//				}
//				GUI_TOUCH_Exec(); //???10ms????
//				DIS_Delayms(1000);
//			USART_SendData(USART1, 'D');
//			while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
//				GUI_TOUCH_GetState(&Point);
//				GUI_CURSOR_SetPosition(Point.x,Point.y);
//				DIS_Delayms(100);
//				WM_Exec();
//				DIS_Delayms(1000);
//				GUI_Exec();
//				GUI_Clear();
//				DIS_Delayms(2000);//remain for a while

		}
}

/*-------------------------------------------------------------------------------------------------------
*  ��ʾ��ʱ												 
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

