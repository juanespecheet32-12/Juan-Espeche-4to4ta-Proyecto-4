#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
int tmp = 0;
int humedad = 0;
float temperatura = 0;
int celsius;
void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  Serial.begin(9600);
}

void loop()
{
  
  tmp = analogRead(A0);
  celsius = map(((tmp - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(celsius);
  humedad = analogRead(A1);
  if (humedad < 87){
    lcd.setCursor(0,0);
    lcd.print("La humedad es ");
    lcd.setCursor(0,1);
    lcd.print("menor al 10%");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La planta");
    lcd.setCursor(0, 1);
    lcd.print("necesita riego");
    delay(5000);
    lcd.clear();
  }else if(humedad > 306){
    lcd.setCursor(0,0);
    lcd.print("La humedad es:");
    lcd.setCursor(0, 1);
    lcd.print("mayor al 30%");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La planta no");
    lcd.setCursor(0, 1);
    lcd.print("necesita riego");
    delay(5000);
    lcd.clear();
  }else{
    lcd.setCursor(0,0);
    lcd.print("La humedad es: ");
    lcd.setCursor(0, 1);
    lcd.print(humedad);
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La planta");
    lcd.setCursor(0, 1);
    lcd.print("necesita riego");
    delay(5000);
    lcd.clear();
  }
  if(celsius = 0){
    lcd.setCursor(0,0);
    lcd.print("La temperatura");
    lcd.setCursor(0,1);
    lcd.print("es: ");
    lcd.print(celsius);
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La planta no");
    lcd.setCursor(0,1);
    lcd.print("necesita riego");
  }
}