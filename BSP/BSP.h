#ifndef __BSP_H__
#define __BSP_H__

//+++++++++++++++++++++++++++ Type Declaration ++++++++++++++++++++++++++++++++++//
//!You should modify it for different c compiler.
typedef unsigned char       bool;


extern void BSP_Init(void);
extern void SysTick_Init(void);
extern void Driver_LedCont(bool sta);
extern void Driver_LedCont2(bool sta);
#endif

