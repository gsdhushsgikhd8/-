#include "stm32f10x.h"
#include "delay.h"
#include "oled.h"
#include "u8x8.h"
#include "u8g2.h"
int t=0;
	u8g2_t u8g2;
	uint8_t u8x8_stm32_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8,U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int,U8X8_UNUSED void *arg_ptr);
	void draw(u8g2_t *u8g2);

int main(void){
	SysTick_Init(72);//���һ��Ҫ��
	u8g2_Setup_ssd1306_128x64_noname_f(&u8g2,U8G2_R0,u8x8_byte_4wire_sw_spi,u8x8_stm32_gpio_and_delay);
	u8g2_InitDisplay(&u8g2);
	u8g2_SetPowerSave(&u8g2, 0);
	
while(1){
u8g2_FirstPage(&u8g2);
    do
    {
            draw(&u8g2);
    } while (u8g2_NextPage(&u8g2));
}
}
uint8_t u8x8_stm32_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8,U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int,U8X8_UNUSED void *arg_ptr)
{
  switch (msg)
  {
	 
		case U8X8_MSG_GPIO_SPI_DATA:
			(arg_int)?GPIO_SetBits(GPIOA,GPIO_Pin_7):GPIO_ResetBits(GPIOA,GPIO_Pin_7);
			break;
		case U8X8_MSG_GPIO_SPI_CLOCK:
			(arg_int)?GPIO_SetBits(GPIOA,GPIO_Pin_5):GPIO_ResetBits(GPIOA,GPIO_Pin_5);
			break;
		case U8X8_MSG_GPIO_AND_DELAY_INIT:
					OLED_Init();
					delay_ms(10);
			break;
		case U8X8_MSG_DELAY_MILLI:
			delay_ms(arg_int);
			break;
			case U8X8_MSG_GPIO_CS:
				(arg_int)?GPIO_SetBits(GPIOA,GPIO_Pin_4):GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		case U8X8_MSG_GPIO_DC:
					(arg_int)?GPIO_SetBits(GPIOA,GPIO_Pin_6):GPIO_ResetBits(GPIOA,GPIO_Pin_6);
			break;
		case U8X8_MSG_GPIO_RESET:
					(arg_int)?GPIO_SetBits(GPIOA,GPIO_Pin_3):GPIO_ResetBits(GPIOA,GPIO_Pin_3);
			break;
  }
  return 1;
}
void draw(u8g2_t *u8g2)
{
u8g2_SetFontMode(u8g2, 1);  // Transparent
    u8g2_SetFontDirection(u8g2, 0);
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf);
    u8g2_DrawStr(u8g2, 0, 20, "U");
    
    u8g2_SetFontDirection(u8g2, 1);
    u8g2_SetFont(u8g2,  u8g2_font_inb24_mf);
    u8g2_DrawStr(u8g2, 21,8,"8");
        
    u8g2_SetFontDirection(u8g2, 0);
    u8g2_SetFont(u8g2, u8g2_font_wqy12_t_chinese1);
   	u8g2_DrawUTF8(u8g2,10,50,"你好,world");
    
    u8g2_DrawHLine(u8g2, 2, 35, 47);
    u8g2_DrawHLine(u8g2, 3, 36, 47);
    u8g2_DrawVLine(u8g2, 45, 32, 12);
    u8g2_DrawVLine(u8g2, 46, 33, 12);
}
