#include<avr/io.h>
#include<util/delay.h>
void lcdInit();
void lcdData(char);
void lcdCmd(char);
void lcdMsg(char*);
void clear()
{
lcdCmd(0x01);
_delay_us(250);
}
void lcdMsg(char data[])
{
char charData=data[0];
int i;
for(i=1;charData!='\0';i++){
lcdData(charData);
charData=data[i];
}
}
void lcdInit(){
DDRA=0xff;
DDRC =0xff;
PORTC&=~(1<<PC1);
lcdCmd(0x38);        //Set 5x7 dots resolution
_delay_us(250);
lcdCmd(0x0E);        //Display on cursor on
_delay_us(250);
lcdCmd(0x01);        //move cursor by one left
_delay_us(250);
lcdCmd(0x06);        //Entry mode
_delay_us(250);
lcdCmd(0x80);        //set the lcd into home position
_delay_us(250);
}

void lcdCmd(char data){
PORTA = data;
PORTC&=~(1<<PC0);
PORTC|=(1<<PC2);
_delay_us(20);
PORTC&=~(1<<PC2);
_delay_us(250);
}

void lcdData(char data){
PORTA=data;
PORTC|=(1<<PC0);
PORTC|=(1<<PC2);
_delay_us(20);
PORTC&=~(1<<PC2);
_delay_us(250);
}
