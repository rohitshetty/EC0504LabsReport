msp430-gcc -Os -Wall -g -mmcu=msp430x2013 -c test.c
msp430-gcc -g -mmcu=msp430x2013 -o test.elf test.o
sudo mspdebug uif 'erase' 'load test.elf' 'exit'


After testing this. 
Change the flag of compile and upload files to executables.
and now to compile just pass 
./compile filename
./upload filename
