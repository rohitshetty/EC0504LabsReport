#define F_CPU 12000000UL
#include<avr/io.h>
#include "lcd.c"

void main(){
lcdInit();
while(1)
lcdMsg("Hello World");
}
