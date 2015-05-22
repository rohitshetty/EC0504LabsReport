#define F_CPU 12000000UL
#include<avr/io.h>
#include<util/delay.h>

void main(){
int i;
DDRA = 0xff;
PORTA = 0xff;
while(1){


PORTA =  ~PORTA ;

for(i=0;i<251;i++){
TCCR1B |= (1<<CS10);    //This sets prescaler to 1
while(TCNT1<12001);     //wait till timer reaches 12001 
TCNT1=0;

}
}

}
