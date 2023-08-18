#include <Servo.h>
#define Trig 10
#define Echo 9
#define SW 2

Servo servo1;

void setup()
{
  Serial.begin(9600);
  servo1.attach(12);
  servo1.write(0);
  Drv_LED_init();
  Drv_Ultrasonic_init();
  pinMode(SW,INPUT_PULLUP);

  // Configure the interrupt
  attachInterrupt(digitalPinToInterrupt(2),Interrupt_SW,FALLING);
}

void loop()
{
  long distance = Drv_Ultrasonic_Read();
  Serial.println(distance);
  Drv_LED(distance/5);
  // Send distance through Serial Port
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println("[cm]");
  if(distance <= 25)
  {
    servo1.write(90);
    delay(500);
  }
  else
  { 
     servo1.write(0);
     delay(500);
  }
 }
  
void Drv_LED_init()
{
  for(int i=3;i<=8;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
}

void Drv_LED(int val)
{
  for(int i=3;i<=8;i++)
  {
    if(i-1 <= val)
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
  
  delay(60);
  
  return (distance * 0.01715);
}

void Interrupt_SW()
{
  static bool val=0;
  delay(100);
  Serial.println(val);
  while(!digitalRead(SW))
  {
    if(val == 0)
    {
      servo1.write(0);
    }
    else
    {
      servo1.write(90);
    }
    for(int i=3;i<=8;i++)
    {
      digitalWrite(i,HIGH);
      delay(10000);
    }
    for(int i=3;i<=8;i++)
    {
      digitalWrite(i,LOW);
      delay(10000);
    }
  }
  val ^= 1;
}
