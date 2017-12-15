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
#include <avr/io.h>
#include <avr/interrupt.h>

byte ddrb;
byte portb;
byte counter;
int main(void)
{
	// Enable watchdog for interrupt, 0.5s
	WDTCR = 1 << WDIE | 1 << WDP2 ;// | 1 << WDP1 | 1 << WDP0;

	PRR |= 15; //PRTIM1 PRTIM0 PRUSI PRADC
	
	sei();  // Enable interrupts
	
	MCUCR &= ~_BV(SM0);
	while(true)
	{
		MCUCR |= _BV(SM1);
		MCUCR |= _BV(SE);
//		set_sleep_mode(SLEEP_MODE_PWR_DOWN);
//		sleep_enable();
//		sleep_mode();
	}
}

void nextState(void)
{
	++counter;
	if (counter < 24)
	{
		portb = 2;
		ddrb = counter == 4 || counter == 16 ? 2 : 0;
	}
	else
	{
		if(counter > 127)
		{
			counter = 0;
		}
		ddrb = 0;
		portb = 0;
	}
}

ISR(WDT_vect)
{
	DDRB	=	ddrb;
	PORTB	=	portb;
	nextState();
}
