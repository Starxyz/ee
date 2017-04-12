#include "draw.h"
#include "adc.h"
void DrawLine(void)
{
		I16 aY[320];
		u16 i;
		double j=0;
		for(i=0; i<GUI_COUNTOF(aY); i++,j+=0.05)
		{
			aY[i] = 20*(float)Get_Adc_Average(ch1,5)*(3.3/4096);
		}
		GUI_DrawGraph(aY, GUI_COUNTOF(aY), 0, 110); //方向是从左到右，从上到下
}
	
