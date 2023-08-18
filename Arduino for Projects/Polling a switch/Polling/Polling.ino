#define sw 4
#define led 3
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(sw,INPUT_PULLUP);
}

void loop()
{
  bool x = !digitalRead(sw);
  digitalWrite(led,x);
  Serial.print("LED and SW state: ");
  Serial.println(x);
}
