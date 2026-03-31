#include "para.h"

// LED
uint8_t ld1_state=0,ld2_state=0;
uint32_t ld1_Tick,ld2_Tick;

// KEY

KEY_T KEY[4];

uint16_t r37_count=0,r37_pass=0;
uint16_t r38_count=0,r38_pass=0;
uint8_t para_state=0;

// LCD
uint8_t lcd_state=0;
float r37_max=2.2;
float r37_min=1.2;
float r38_max=3.0;
float r38_min=1.4;
float PR37,PR38;
float r37,r38;
