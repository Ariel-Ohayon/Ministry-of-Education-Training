// C++ code
//
void setup()
{
  for(int pinNum = 2; pinNum <= 7 ; pinNum++)
  {
    pinMode(pinNum, OUTPUT);
  }
  
}

void loop()
{
  for(int pinNum = 2; pinNum <= 7 ; pinNum++)
  {
    digitalWrite(pinNum, HIGH);
    delay(50); // Wait for 1000 millisecond(s)
  }
  for(int pinNum = 7; pinNum >= 2 ; pinNum--)
  {
    digitalWrite(pinNum, LOW);
    delay(50); // Wait for 1000 millisecond(s)
  }
}
