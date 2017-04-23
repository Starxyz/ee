#ifndef __DRAW_H__
#define __DRAW_H__
#include "includes.h"
#include "math.h"
#include "GUI.h"
#include "WM.h"
void DrawLine(void);
static void cbBackgroundWin(WM_MESSAGE* pMsg);
static void cbForegroundWin(WM_MESSAGE* pMsg);
void DemoRedraw1(void);
#endif

