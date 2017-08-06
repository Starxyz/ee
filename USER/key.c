#include "key.h"
#include "delay.h"

void KEY_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOG, ENABLE);//GPIOF??
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_4|GPIO_Pin_6; //4?????
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//??????
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//????
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//????
  GPIO_Init(GPIOF, &GPIO_InitStructure);//???GPIOF0,2,4,6
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7; //4?????
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; //?????
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//??
  GPIO_Init(GPIOG, &GPIO_InitStructure);//???GPIOG4 5 6 7
 
} 

int key(void)  //???????????KeyVal,??????,???????????
{
	int KeyVal=0;	 //keyVal?????????
	GPIO_SetBits(GPIOF,GPIO_Pin_0 | GPIO_Pin_2| GPIO_Pin_4| GPIO_Pin_6);//GPIOF0,2,4,6??,???????	
	if((GPIOG->IDR & 0x00F0)==0x0000)  //??,PG4,5,6,7??0,?????????,????-1.
		return -1;
	else
		{
		delay_ms(10);//??10ms????  消抖
		if((GPIOG->IDR & 0x00F0)==0x0000)  //??,??10ms?,PE0,2,4,6???0,????????????????.
		return -1;
		}

		
	GPIO_Write(GPIOF,(GPIOF->ODR & 0xff00 | 0x0040));	//?PF6,?????1.   
	switch(GPIOG->IDR & 0x00F0)		                //?PE0,2,4,6??????,?????????
	{//对应0246引脚
		case 0x0001: KeyVal=1;	break;
		case 0x0004: KeyVal=2;	break;
		case 0x0010: KeyVal=3;	break;
		case 0x0040: KeyVal=4;	break;
	}
//		while((GPIOG->IDR & 0x00F0)!=0x0000)
//		delay_us(1);
	
	
	GPIO_Write(GPIOF,(GPIOF->ODR & 0xff00|0x0010));	//?PF4,?????1.
	switch(GPIOG->IDR & 0x00F0)		                //?PE0,2,4,6??????,?????????
	{
		case 0x0001: KeyVal=5;	break;
		case 0x0004: KeyVal=6;	break;
		case 0x0010: KeyVal=7;	break;
		case 0x0040: KeyVal=8;	break;
	}
//		while((GPIOG->IDR & 0x00F0)!=0x0000)		//松手检测
//		delay_us(1);

	GPIO_Write(GPIOF,(GPIOF->ODR & 0xff00|0x0004));	//?PF2,?????1.
	switch(GPIOG->IDR & 0x00F0)		                //?PE0,2,4,6??????,?????????
	{
		case 0x0001: KeyVal=9;	break;
		case 0x0004: KeyVal=10;	break;
		case 0x0010: KeyVal=11;	break;
		case 0x0040: KeyVal=12;	break;
	}
//		while((GPIOG->IDR & 0x00F0)!=0x0000)		//????
//		delay_us(1);
		
	GPIO_Write(GPIOF,(GPIOF->ODR & 0xff00|0x0001));	//?PF0,?????1.
	switch(GPIOG->IDR & 0x00F0)		               //?PE0,2,4,6??????,?????????
	{
		case 0x0001: KeyVal=13;	break;
		case 0x0004: KeyVal=14;	break;
		case 0x0010: KeyVal=15;	break;
		case 0x0040: KeyVal=16;	break;
	}
//	while((GPIOG->IDR & 0x00F0)!=0x0000)			//????
//		delay_us(1);
	return KeyVal;		
}


















