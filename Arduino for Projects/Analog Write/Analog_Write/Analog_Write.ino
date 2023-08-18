#define pin 4
void setup()
{
  Serial.begin(9600);
  pinMode(pin,OUTPUT);
}

void loop()
{
  for(int i=0;i<255;i+=10)
  {
    analogWrite(pin,i);
    delay(50);
  }
  for(int i=255;i>=0;i-=10)
  {
    analogWrite(pin,i);
    delay(50);
  }
}
