const int LEDPin = 13;
const int PIRPin = 2;
bool val = LOW;

void setup()
{
  pinMode(13 , OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(2);
  if (val == HIGH){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

  }
  else{
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);

  }
}