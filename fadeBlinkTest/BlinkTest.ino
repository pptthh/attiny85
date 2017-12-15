const byte LED_PIN = 1;

boolean ledLevel;
byte ledOnTime;
byte ledOffTime;
byte counter;
unsigned long nextMicros;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  unsigned long currentMicros = micros();
  if (currentMicros > nextMicros)
  {
    if (ledLevel)
    {
      pulseCalc();
      nextMicros = currentMicros + ledOffTime * 128;
      ledLevel = false;
    }
    else
    {
      nextMicros = currentMicros + ledOnTime * 8;
      ledLevel = true;
    }
    digitalWrite(LED_PIN, ledLevel);
  }
}


void pulseCalc()
{
  ledOnTime = cos(2 * PI * (counter ++) / 255) * 127 + 127;
  ledOffTime = 0xFF - ledOnTime;
}

