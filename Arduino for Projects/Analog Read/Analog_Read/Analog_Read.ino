#define led 3
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop()
{
  unsigned int val = analogRead(A0);
  Serial.print(val);
  Serial.print(" , ");
  val = map(val,0,1023,0,255); // ניתן להפוך ערכים במוצא
  //val = ((float)val * 255) / 1023; // Full formula (255 - max output) (1023 - max input)
  analogWrite(led,val);
  Serial.println(val);
}
