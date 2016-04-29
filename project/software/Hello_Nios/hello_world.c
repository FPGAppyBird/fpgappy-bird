/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */
#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
int main()
{
printf("Hello from Nips II!\n");
int count = 0;
int state = 0;
int lastmax = 0;
int delay;
while(1) {
IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 1 << count);
delay = 0;
while(delay < 250000 ) {
delay++;
}
if(state == 0){
	count = (count+1) % 8;
}else{
	count = (count-1) % 8;
}

if(count > lastmax && state == 0){
	state = 1;
	lastmax = count;
}

if(count == 7){
	state = 1;
	lastmax = 0;
}

if(count == 0){
	state = 0;
}
}
return 0;
}
