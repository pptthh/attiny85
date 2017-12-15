const unsigned int kiIdo = 65535;
const byte beIdo = 1;
const int ledPin = 1;
unsigned long next;

void setup()
{
	pinMode(ledPin, OUTPUT);
}

void loop()
{
    unsigned long most = micros();
    if (most < next)
    	return;
    if (digitalRead(ledPin))
    {
    	next = most + kiIdo;
    	digitalWrite(ledPin, false);
    }
    else
    {
    	next = most + beIdo;
    	digitalWrite(ledPin, true);
    }
}

