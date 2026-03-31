#include "key.h"

void KEY_Time()
{
	KEY[0].state=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	KEY[1].state=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	KEY[2].state=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
	KEY[3].state=HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	
	for(uint8_t i=0;i<4;i++)
	{
		switch(KEY[i].judge)
		{
			case 0:
				if(KEY[i].state==0)
				{
					KEY[i].judge=1;
				}
				break;
			case 1:
				if(KEY[i].state==0)
				{
					KEY[i].judge=2;
				}
				break;
			case 2:
				if(KEY[i].state==1)
				{
					KEY[i].shortpress=1;
					KEY[i].judge=0;
				}
				break;
			default:
				break;
		}
	}
}

void KEY_Proc()
{
	if(KEY[0].shortpress==1)
	{
		switch(lcd_state)
		{
			case 0:
				para_state=0;
				lcd_state=1;
				break;
			case 1:
				lcd_state=2;
				break;
			case 2:
				lcd_state=0;
				break;
			default:
				break;
		}
		KEY[0].shortpress=0;
	}
	if(lcd_state==0)
	{
		if(KEY[1].shortpress==1)
		{
			r37_count++;
			if(r37>=r37_min&&r37<=r37_max)
			{
				ld1_state=1;
				ld1_Tick=HAL_GetTick();
				r37_pass++;
			}
			KEY[1].shortpress=0;
		}
		
		if(KEY[2].shortpress==1)
		{
			r38_count++;
			if(r38>=r38_min&&r38<=r38_max)
			{
				ld2_state=1;
				ld2_Tick=HAL_GetTick();
				r38_pass++;
			}
			KEY[2].shortpress=0;
		}
	}
	
	if(lcd_state==1)
	{
		if(KEY[1].shortpress==1)
		{
			switch(para_state)
			{
				case 0:
				para_state=1;
				break;
			case 1:
				para_state=2;
				break;
			case 2:
				para_state=3;
				break;
			case 3:
				para_state=0;
				break;
			default:
				break;
			}
			KEY[1].shortpress=0;
		}
		
		if(KEY[2].shortpress==1)
		{
			
			switch(para_state)
			{
				case 0:
					r37_max+=0.2;
					if(r37_max>3.1)
					{
						r37_max=2.2;
					}
					r37_count=0;
					r37_pass=0;
					break;
				case 1:
					r37_min+=0.2;
					if(r37_min>2.1)
					{
						r37_min=1.2;
					}
					r37_count=0;
					r37_pass=0;
					break;
				case 2:
					r38_max+=0.2;
					if(r38_max>4.5)
					{
						r38_max=3.0;
					}
					r38_count=0;
					r38_pass=0;
					break;
				case 3:
					r38_min+=0.2;
					if(r38_min>2.9)
					{
						r38_min=1.4;
					}
					r38_count=0;
					r38_pass=0;
					break;
				default:
					break;
			}
			KEY[2].shortpress=0;
		}
		
		if(KEY[3].shortpress==1)
		{
			switch(para_state)
			{
				case 0:
					r37_max-=0.2;
					if(r37_max<2.1)
					{
						r37_max=3.0;
					}
					r37_count=0;
					r37_pass=0;
					break;
				case 1:
					r37_min-=0.2;
					if(r37_min<1.1)
					{
						r37_min=2.0;
					}
					r37_count=0;
					r37_pass=0;
					break;
				case 2:
					r38_max-=0.2;
					if(r38_max<2.9)
					{
						r38_max=4.4;
					}
					r38_count=0;
					r38_pass=0;
					break;
				case 3:
					r38_min-=0.2;
					if(r38_min<1.3)
					{
						r38_min=2.8;
					}
					r38_count=0;
					r38_pass=0;
					break;
				default:
					break;
			}
			KEY[3].shortpress=0;
		}
	}
	
	if(lcd_state==2)
	{
		if(KEY[3].shortpress==1)
		{
			r37_count=0;
			r37_pass=0;
			r38_count=0;
			r38_pass=0;
			KEY[3].shortpress=0;
		}

	}
	
}
