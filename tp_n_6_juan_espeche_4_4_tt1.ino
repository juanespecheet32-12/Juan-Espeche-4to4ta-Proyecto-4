#include <Servo.h>
bool adelan;
bool atra; 
int grados = 0;
Servo servoBase;
Servo servoBase2;

void setup()
{
  servoBase.attach(A0);
  servoBase2.attach(A1);
  servoBase.write(0);
  servoBase2.write(0);
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop()
{
  adelan = digitalRead(13);
  atra = digitalRead(12);
  if (adelan==LOW){
    avanza();
  }
  if (atra==LOW){
    atrasas();
  }
  Serial.print(adelan);
  Serial.print("");
  Serial.println(atra);
  delay(300);
}
void avanza()
{
  grados= grados + 10;
  servoBase.write(grados);
  servoBase2.write(grados);
  delay(100);
}
void atrasas()
{
  grados= grados - 10;
  servoBase.write(grados);
  servoBase2.write(grados);
  delay(100);
  if (grados < 0){
    grados = 0;
  }
  delay(100);
}
