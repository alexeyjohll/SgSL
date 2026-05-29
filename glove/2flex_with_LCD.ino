#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int FLEX_PIN_1 = A0;
const int FLEX_PIN_2 = A1;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Flex ready...");
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  int raw1 = analogRead(FLEX_PIN_1);
  int raw2 = analogRead(FLEX_PIN_2);

  float v1 = raw1 * (5.0 / 1023.0);
  float v2 = raw2 * (5.0 / 1023.0);

  lcd.setCursor(0, 0);
  lcd.print("F1: ");
  lcd.print(v1, 2);
  lcd.print("V  ");

  lcd.setCursor(0, 1);
  lcd.print("F2: ");
  lcd.print(v2, 2);
  lcd.print("V  ");

  Serial.print("F1: "); Serial.print(v1, 2);
  Serial.print("V  F2: "); Serial.println(v2, 2);

  delay(200);
}
