Interfacing of LCD
LCD is connected in 8bit mode. 8bit data bus is connected to PORTA and 3 control pins are connected PORTC PIN0,1,2.
Library can be seen in lcd.c.
It has main string function interfaced.
just initialize the lcdInit() once and to send data use lcdMsg(String); function.
dont forget to include lcd.c
