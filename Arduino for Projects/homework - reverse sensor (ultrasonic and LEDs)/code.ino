#define Trig 9
#define Echo 8

void setup()
{
  Serial.begin(9600);
  Drv_LED_init();
  Drv_Ultrasonic_init();
}

void loop()
{
  long distance = Drv_Ultrasonic_Read();
  Drv_LED(distance / 5);
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println("[cm]");
}

void Drv_LED_init()
{
  for(int i = 2; i <= 7; i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
}

void Drv_LED(int val)
{
  for(int i = 2; i <= 7; i++)
  {
    if(i <= val)
    {
      digitalWrite(i,LOW);
    }
    else
    {
      digitalWrite(i,HIGH);
    }
  }
}

void Drv_Ultrasonic_init()
{
  pinMode(Trig,OUTPUT);
  digitalWrite(Trig,LOW);
  pinMode(Echo,INPUT);
}

long Drv_Ultrasonic_Read()
{
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  
  long distance = pulseIn(Echo,HIGH);
  
  return (distance * 0.01715);
}