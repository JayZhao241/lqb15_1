#include "led.h"

void LED_Disp(uint8_t led_num,uint8_t led_state)
{
	static uint8_t led_control;
	if(led_state==1)
	{
		led_control|=(0x01<<(led_num-1));
	}
	if(led_state==0)
	{
		led_control&=~(0x01<<(led_num-1));
	}
	
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_All,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,(led_control<<8),GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
}
void LED_Proc()
{
	if(ld1_state==1)
	{
		LED_Disp(1,1);
		
		if(uwTick-ld1_Tick<1000)return;
		LED_Disp(1,0);
	}
	if(ld2_state==1)
	{
		LED_Disp(2,1);
		
		if(uwTick-ld2_Tick<1000)return;
		LED_Disp(2,0);
	}
	
	if(lcd_state==0)
	{
		LED_Disp(3,1);
	}
	else
	{
		LED_Disp(3,0);
	}
	
	if(lcd_state==1)
	{
		LED_Disp(4,1);
	}
	else
	{
		LED_Disp(4,0);
	}
	
	if(lcd_state==2)
	{
		LED_Disp(5,1);
	}
	else
	{
		LED_Disp(5,0);
	}
}
