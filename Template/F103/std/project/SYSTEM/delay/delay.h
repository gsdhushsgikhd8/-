#ifndef __DELAY_H				//�����Է�ֹ�ݹ����			
#define __DELAY_H

//=====һ��ͷ�ļ�=========
#include "stm32f10x.h"	


//=====������������=======
void DELAY_nms(int ms_time);	//1���Լ�д����ʱ����
void SysTick_Init(u8 SYSCLK);

void delay_us(u32 nus);			//2����ʱ΢�
void delay_ms(u16 nms);			//3����ʱ���

#endif /* __BEEP_H */
