#ifndef __DELAY_H				//定义以防止递归包含			
#define __DELAY_H

//=====一、头文件=========
#include "stm32f10x.h"	


//=====二、函数声明=======
void DELAY_nms(int ms_time);	//1、自己写的延时函数
void SysTick_Init(u8 SYSCLK);

void delay_us(u32 nus);			//2、延时微妙级
void delay_ms(u16 nms);			//3、延时毫妙级

#endif /* __BEEP_H */
