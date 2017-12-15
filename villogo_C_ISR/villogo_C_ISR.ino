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
	WDTCR = 1 << WDIE ;//| 1 << WDP2 | 1 << WDP1 | 1 << WDP0;

	sei();  // Enable interrupts
	while(true){}

	return 0;
}

void nextState(void)
{
	switch(counter++)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			ddrb = 0;
			portb = 0;
			break;
	
		case 8:
		case 9:
		case 10:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
			ddrb = 0;
			portb = 2;
			break;
		
		case 11:
		case 21:
			ddrb = 2;
			portb = 2;
			break;
		
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 38:
		case 39:
		case 40:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
		case 46:
		case 47:
		case 48:
		case 49:
		case 50:
			ddrb = 0;
			portb = 0;
			break;
	
		default:
			counter = 0;
	}
}

ISR(WDT_vect)
{
	DDRB	=	ddrb;
	PORTB	=	portb;
	nextState();
}
