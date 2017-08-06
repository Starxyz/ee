#include "draw.h"
#include "adc.h"
#include "gui.h"
#include "button.h"
#include "guidemo.h"
#include "key.h"
void flag(char i)   //prove your program not die
{
		if(i)
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_0);
			GPIO_ResetBits(GPIOD,GPIO_Pin_3);		
		}
		else
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_0);
			GPIO_SetBits(GPIOD,GPIO_Pin_3);		
		}	
			
}
static void Button(void)
{
	BUTTON_Handle hButton1, hButton2, hButton3;
	GUI_PID_STATE Point;
	int Key = 0;
	char status=0;
	float value;
	GUI_Init();
	GUI_SetFont(&GUI_Font8x16);
	GUI_DispStringHCenterAt("Click on button...", 160,0);
	hButton1 = BUTTON_Create(10 , 20, 90, 40, GUI_ID_OK, WM_CF_SHOW);
	hButton2 = BUTTON_Create(105, 20, 90, 40, GUI_KEY_UP, WM_CF_SHOW);
	hButton3 = BUTTON_Create(200, 20, 90, 40, GUI_KEY_DOWN, WM_CF_SHOW);
	BUTTON_SetText(hButton1, "Display");
	BUTTON_SetText(hButton2, "up");
	BUTTON_SetText(hButton3, "down");
	
	while(1)
	{
		status=!status;
		flag(status);		//shows that program is running
		value = (float)Get_Adc_Average(ch1,10)*(3.3/4095);
		GUI_DispFloat(value,6);
		
		Key = GUI_WaitKey();
		
		switch(Key)
		{
			case GUI_ID_OK:
				GUI_Clear();				
				GUI_FillRect(10, 60, 300, 220);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawLine(15, 65, 15, 220);//draw xy
				GUI_DrawLine(15, 150, 300, 150);
				GUI_SetColor(GUI_RED);
				DrawLine();
				GUI_SetColor(GUI_WHITE);
				break;
			case GUI_KEY_UP:
				GUI_Clear();				
				GUI_FillRect(10,60,300,220);
				GUI_Clear();
				GUI_SetColor(GUI_WHITE);			
				GUI_FillRect(10,60,300,220);
				GUI_SetColor(GUI_WHITE);
				
//				USART_SendData(USART1, 'U');
//				while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
				break;
			case GUI_KEY_DOWN:
				GUI_Clear();
				GUI_FillRect(10,60,300,220);
//				USART_SendData(USART1, 'D');
//				while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
				break;
			default:;
				
		}
		GUI_TOUCH_Exec(); //???10ms????
		DIS_Delayms(1000);
		GUI_TOUCH_GetState(&Point);
		GUI_CURSOR_SetPosition(Point.x,Point.y);
	}
	


}

void DrawLine(void)
{
		I16 aY[280];
		u16 i;

		for(i=0; i<GUI_COUNTOF(aY); i++)
		{
//			if(USART_RX_STA&0x8000)
//			{
//				USART_RX_STA=0;				
				aY[i] = 10*(float)Get_Adc_Average(ch1,10)*(3.3/4095);
//				USART_SendData(USART1, 'y');
//				while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
//			}	
//			else i--;
		}
		GUI_DrawGraph(aY, GUI_COUNTOF(aY), 15, 150); //方向是从左到右，从上到下
}

void Run(void)
{

	Button();
}


static void Disp_data()
{
		u8 len;

		u32  Freq;	
		u32  Step;
	u32 data;
		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度

				
			data = (USART_RX_BUF[2]<<24) + (USART_RX_BUF[3]<<16) + 
							(USART_RX_BUF[4]<<8) + (USART_RX_BUF[5]) ;
			Freq = data / 1000;
			
			Step = ((USART_RX_BUF[6]<<24) + (USART_RX_BUF[7]<<16) + 
							(USART_RX_BUF[8]<<8) + (USART_RX_BUF[9])) / 1000 ;
			GUI_SetColor(GUI_WHITE);
			GUI_FillRect(10,60,300,220);

			GUI_DispStringAt("Freq: ", 10, 80);
			GUI_DispDec(Freq, 5);
			GUI_DispString(" kHz");
			GUI_DispStringAt("Step: ", 10, 100);
			GUI_DispDec(Step, 5);
			GUI_DispString(" kHz");
//			GUI_DispHex(FreqH, 5);
			
//			GUI_DispChar(FreqH);
			USART_RX_STA=0;
		}
//		else 
//		{
//			GUI_SetColor(GUI_WHITE);
//			GUI_FillRect(10,60,300,220);
//			GUI_DispStringAt("FreqL: ", 10, 80);
//			GUI_DispChar(FreqL);
//			
//			GUI_DispStringAt("FreqH: ", 10, 100);
//			GUI_DispChar(FreqH);
//		}
		
		
		
		

	
}
void Disp()
{
	Disp_data();
}



//example

