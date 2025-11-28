#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
float tmp = 0;
int humedad = 0;
float temperatura = 0;
float celsius;

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
  tmp = analogRead(A0);
  celsius = map(((tmp - 20) * 3.04),0,1023,-40,125);
  celsius = celsius + 39;
  Serial.println(celsius);
  humedad = analogRead(A1);
  if(celsius > 32 && humedad < 306){
    lcd.setCursor(0,0);
    lcd.print("La temperatura");
    lcd.setCursor(0,1);
    lcd.print("es: ");
    lcd.print(celsius);
    lcd.print(" C");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La humedad es:");
    lcd.setCursor(0, 1);
    lcd.print("menor al 30%");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La planta");
    lcd.setCursor(0,1);
    lcd.print("necesita riego");
    delay(5000);
    lcd.clear();
  }
  else if(celsius < 32 && humedad > 306){
    lcd.setCursor(0,0);
    lcd.print("La temperatura");
    lcd.setCursor(0,1);
    lcd.print("es: ");
    lcd.print(celsius);
    lcd.print(" C");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La humedad es ");
    lcd.setCursor(0,1);
    lcd.print("mayor al 30%");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La temperatura");
    lcd.setCursor(0,1);
    lcd.print("es estable");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("La planta no");
    lcd.setCursor(0, 1);
    lcd.print("necesita Riego");
    delay(5000);
    lcd.clear();
  }else if(celsius > 32 && humedad > 306){
    lcd.setCursor(0,0);
    lcd.print("La temperatura");
    lcd.setCursor(0,1);
    lcd.print("es: ");
    lcd.print(celsius);
    lcd.print(" C");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La humedad es:");
    lcd.setCursor(0, 1);
    lcd.print("mayor al 30%");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La temperatura");
    lcd.setCursor(0,1);
    lcd.print("es estable");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("La planta no");
    lcd.setCursor(0, 1);
    lcd.print("necesita Riego");
    delay(5000);
    lcd.clear();
  }else if(celsius < 32 && humedad < 306){
    lcd.setCursor(0,0);
    lcd.print("La temperatura");
    lcd.setCursor(0,1);
    lcd.print("es: ");
    lcd.print(celsius);
    lcd.print(" C");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La humedad es ");
    lcd.setCursor(0,1);
    lcd.print("menor al 30%");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("La planta");
    lcd.setCursor(0,1);
    lcd.print("necesita riego");
    delay(5000);
    lcd.clear();
  }
}