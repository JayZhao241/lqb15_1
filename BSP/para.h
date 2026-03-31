#include "stm32g4xx_hal.h"

// LED
extern uint8_t ld1_state,ld2_state;
extern uint32_t ld1_Tick,ld2_Tick;

// KEY
typedef struct{
	uint8_t state;
	uint8_t judge;
	uint8_t shortpress;
}KEY_T;
extern KEY_T KEY[4];
	
extern uint16_t r37_count,r37_pass;
extern uint16_t r38_count,r38_pass;
extern uint8_t para_state;

// LCD
extern uint8_t lcd_state;
extern float r37_max;
extern float r37_min;
extern float r38_max;
extern float r38_min;
extern float PR37,PR38;
extern float r37,r38;
