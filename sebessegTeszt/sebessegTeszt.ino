const byte LED_PIN = 1;
boolean ledOn;
void setup()
{
//	pinMode(LED_PIN, OUTPUT);
}

void loop()
{
	digitalWrite(LED_PIN, true);
	digitalWrite(LED_PIN, false);
}
