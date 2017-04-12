/*
*********************************************************************************************************
*                                                uC/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              µC/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : GUI_TOUCH_X.C
Purpose     : Config / System dependent externals for GUI
---------------------------END-OF-HEADER------------------------------
*/
#include "prohead.h"
#include "GUI.h"
#include "GUI_X.h"
#include "LCDConf.h"

extern int Touch_GetSite(u16 *pRow, u16 *pColumn);

void GUI_TOUCH_X_ActivateX(void) {
}

void GUI_TOUCH_X_ActivateY(void) {
}

int  GUI_TOUCH_X_MeasureX(void) {
	u16 Row, Column;
	if(Touch_GetSite(&Row, &Column))
	{
			#if (LCD_DIR==1)
				return Column;
			#else
				return (319-Row);
			#endif
	}
  return -1;
}

int  GUI_TOUCH_X_MeasureY(void) {
	u16 Row, Column;
	if(Touch_GetSite(&Row, &Column))
	{
			#if (LCD_DIR==1)
				return Row;
			#else
				return Column;
			#endif
	}
  return -1;
}


