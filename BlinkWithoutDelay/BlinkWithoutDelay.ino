const byte LED_PIN = 1;
const byte MA_PIN = 2;
const byte MB_PIN = 3;
const byte MC_PIN = 4;
//const byte MD_PIN = 5;
//const byte ME_PIN = 0;

byte ledOnTime;
byte ledOffTime;
boolean counterDirection;
byte fazis;
unsigned long nextLed;
unsigned long next3F;

void setup()
{
  pinMode(LED_PIN, OUTPUT);

  pinMode(MA_PIN, OUTPUT);
  pinMode(MB_PIN, OUTPUT);
  pinMode(MC_PIN, OUTPUT);
//  pinMode(MD_PIN, OUTPUT);
//  pinMode(ME_PIN, OUTPUT);
}

void loop()
{
  unsigned long currentMicros = micros();
  checkLed(currentMicros);
  check3Fazis(currentMicros);
}

void check3Fazis(unsigned long currentMicros)
{
  if (currentMicros < next3F)
    return;

  !fazis ? fazis = 5 : -- fazis;
  next3F = currentMicros + 1000;
/*
T  0123456789ABCDEF0
A1 11000111000111000 
B2 01110001110001110
C4 00011100011100011
S  13268913268
*/
  digitalWrite(MA_PIN, fazis < 3);              // 012
  digitalWrite(MB_PIN, 1 < fazis && fazis < 5); // 234
  digitalWrite(MC_PIN, 3 < fazis && fazis < 1); // 450
}

void checkLed(unsigned long currentMicros)
{
  if (currentMicros < nextLed)
    return;
  if (digitalRead(LED_PIN))
  {
    nextLed = currentMicros + ledOffTime * 1024;
    digitalWrite(LED_PIN, false);
  }
  else
  {
    nextLed = currentMicros + ledOnTime;
    digitalWrite(LED_PIN, true);
    calulateOnOffTime();
  }
}

void calulateOnOffTime()
{
  if (counterDirection)
  {
    ledOnTime ++;
    if (!ledOnTime)
    {
      counterDirection = false;
      ledOnTime --;
    }
  }
  else
  {
    ledOnTime --;
    if (!ledOnTime)
    {
      counterDirection = true;
    }
  }
  ledOffTime = 0xFF - ledOnTime;
}
