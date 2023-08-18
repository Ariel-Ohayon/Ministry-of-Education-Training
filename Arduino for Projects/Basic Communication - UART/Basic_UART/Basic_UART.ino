#define led 3

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  char temp;
  if(Serial.available() > 0)
  {
    temp = Serial.read(); // Read 1 char
  }
  if(temp == '1')
  {
    digitalWrite(led,HIGH);
  }
  else if(temp == '0')
  {
    digitalWrite(led,LOW);
  }
}

// Have to connect GND between the two MCUs
