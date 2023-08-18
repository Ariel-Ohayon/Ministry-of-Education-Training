/*
 * LEDs connected to pins 7 - 12 (Positive Logic)
 */

void setup()
{
  for(int i=7;i<13;i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  Run();
  delay(1000);
}

void Run()
{
  static int val = 0b100000;
  for(int i=7;i<13;i++)
  {
    if( 1 << (i-7) == val)
    {
      digitalWrite(i,HIGH);
    }
    else
    {
      digitalWrite(i,LOW);
    }
  }
  val = val >> 1;
  if(val == 0)
  {
    val = 0b100000;
  }
}
