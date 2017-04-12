#include "includes.h"
#include "driver.h" 
#include "ili9341.h"
#include "stdlib.h"
#include "draw.h"
#include "adc.h"


//***************************************************************
// ����EU���ӳ�Ʒ-��Ȩ����-����ؾ�
// EU-�Ȱ�Ƕ��ʽ����
// http://euse.taobao.com
//***************************************************************
#include "GUI.h"
extern void GUIDEMO_main(void);
extern void DIS_Delayms(u16 Num);
/*-------------------------------------------------------------------------------------------------------
  ���������ִ��												 
/-------------------------------------------------------------------------------------------------------*/
int main(void)
{
//����ADC
// 	u16 adcx;
//	float temp;	
	delay_init(168);	
	Adc_Init();
		//������ʼ��
		BSP_Init();
		//GUIģ���ʼ��
		GUI_Init();
		//������Ļ����
		Driver_LcdBacklight(True);
		//�����δ�ʱ��
		SysTick_Init();
		//GUI����
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

