// ====================================
//					ATtiny
//					25/45/85
//					+--------+
//	(1)		pb5	  --+ o  Vcc +------------
//			PB3	  --+        +--	PB0
//			PB4	  --+        +--	PB1 - LED
//  ------------  --+ GND    +--	PB2
//				  	+--------+
// ====================================
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

//#include <avr/sleep.h>

volatile int timer_overflow_count = 0;

ISR(WDT_vect) {
   // Toggle Port B pin 1 output state
   PORTB ^= 1 << PB1;
}


int main(void)
{
    while (true)
    	loop();
    return (0);
}
void loop()
{
}

