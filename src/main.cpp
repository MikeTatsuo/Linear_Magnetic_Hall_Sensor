#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define DIGITAL_PIN 3
#define ANALOG_PIN A0

void setup() {
  pinMode(DIGITAL_PIN, INPUT);
  pinMode(ANALOG_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Linear Magnetic Hall");

  lcd.setCursor(0, 2);
  lcd.print("Switch:");

  lcd.setCursor(0, 3);
  lcd.print("Value:");
}

void loop() {
  lcd.setCursor(8, 2);
  if (digitalRead(DIGITAL_PIN)) {
    lcd.print("CLOSED");
  } else {
    lcd.print("OPEN  ");
  }

  lcd.setCursor(7, 3);
  lcd.print(analogRead(ANALOG_PIN));
  lcd.print("    ");
  
  delay(100);
}