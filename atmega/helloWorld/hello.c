#include<avr/io.h>
#include<util/delay.h>

void main(){
DDRB=0xff;        h  //Turn the port into output mode
PORTB=0xff;         //Turn the port high
while(1){
PORTB=~PORTB;       //Toggle
_delay_ms(500);     //inbuilt delay routine in util/delay.
}
}
