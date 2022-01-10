#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// пины датчика
#define HC_TRIG 3
#define HC_ECHO 2

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
 
  pinMode(HC_TRIG, OUTPUT); // trig выход
  pinMode(HC_ECHO, INPUT);  // echo вход
}

float distFilt = 0;

void loop()
{
  float dist = getDist();   // получаем расстояние
  distFilt += (dist - distFilt) * 0.2;  // фильтруем  

  lcd.setCursor(10,0);
  lcd.print(dist);
  delay(500);
}

float getDist() {
  // импульс 10 мкс
  digitalWrite(HC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(HC_TRIG, LOW);
  // измеряем время ответного импульса
  uint32_t us = pulseIn(HC_ECHO, HIGH);
  // считаем расстояние и возвращаем
  return (us / 58.3);
}
