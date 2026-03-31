#include "display.h"

void LCD_Proc()
{
	unsigned char lcd_str[30];
	r37=Get_r37();
	r38=Get_r38();
	
	
	// GOODS
	if(lcd_state==0)
	{
		sprintf((char*)lcd_str, "       GOODS        ");
		LCD_DisplayStringLine(Line1, (uint8_t*)lcd_str);
		
		sprintf((char*)lcd_str, "     R37:%.2fV        ", r37);
		LCD_DisplayStringLine(Line3, (uint8_t*)lcd_str);
		sprintf((char*)lcd_str, "     R38:%.2fV        ", r38);
		LCD_DisplayStringLine(Line4, (uint8_t*)lcd_str);
	}
	
	// STANDARD
	if(lcd_state==1)
	{
		sprintf((char*)lcd_str, "      STANDARD        ");
		LCD_DisplayStringLine(Line1, (uint8_t*)lcd_str);
		
		sprintf((char*)lcd_str, "    SR37:%.1f-%.1f        ", r37_max,r37_min);
		LCD_DisplayStringLine(Line3, (uint8_t*)lcd_str);
		sprintf((char*)lcd_str, "    SR38:%.1f-%.1f        ", r38_max,r38_min);
		LCD_DisplayStringLine(Line4, (uint8_t*)lcd_str);
	}
	
	// PASS
	if(lcd_state==2)
	{
		PR37=(r37_pass/r37_count)*100;
		PR38=(r38_pass/r38_count)*100;
		
		sprintf((char*)lcd_str, "        PASS        ");
		LCD_DisplayStringLine(Line1, (uint8_t*)lcd_str);
		
		sprintf((char*)lcd_str, "     PR37:%.1f%%        ", PR37);
		LCD_DisplayStringLine(Line3, (uint8_t*)lcd_str);
		sprintf((char*)lcd_str, "     PR38:%.1f%%        ", PR38);
		LCD_DisplayStringLine(Line4, (uint8_t*)lcd_str);
	}
}
