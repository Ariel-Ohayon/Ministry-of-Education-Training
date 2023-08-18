#define Trig 8
#define Echo 7
#define v 0.0343

/*
 * 
 * x = v*t
 * 
 * v = 343[meters/second] : sound velocity
 * 
 * v[centimeters/MicroSeconds]: v = 343[meters/second] = 343 [100centimeters/second] = 34300[centimeters/second] = 
 * 34300[centimeters/1000000MicroSecond] = 34300/1000000 [centimeters/MicroSecond] = 0.0343 [centimeters/MicroSeconds]
 * 
 *  ==========================================
 *  || v = 0.0343[centimeters/MicroSeconds] ||
 *  ==========================================
 *  
 *  distance = x/2
 *  
 *  distance = (v * t) / 2 = t * (v/2) = t * 0.01715
 *  
 *      1
 *   ------- = 58.3 [sec / meters]
 *   0.01715
 */

void setup()
{
  Serial.begin(9600);
  
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  
  digitalWrite(Trig,LOW); // Define initial value Logic '0' for trig pin
}

void loop()
{
  long x = Drv_Ultrasonic_Read();
  Serial.print(x);
  Serial.println("[cm]");
  delay(500);
}

long Drv_Ultrasonic_Read()
{
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  
  long t = pulseIn(Echo,HIGH);
  if(t > 25000)//25msec
  {
    return -1;
  }
  long distance = ( t * 0.01715 );
  return distance;
}
