#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int FLEX_PINS[4] = {A0, A1, A2, A3};
int raw[4];

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    raw[i] = analogRead(FLEX_PINS[i]);
  }

  // Row 1: F1 and F2
  lcd.setCursor(0, 0);
  lcd.print("F1:");
  lcd.print(raw[0]);
  lcd.print(" F2:");
  lcd.print(raw[1]);
  lcd.print("  ");

  // Row 2: F3 and F4
  lcd.setCursor(0, 1);
  lcd.print("F3:");
  lcd.print(raw[2]);
  lcd.print(" F4:");
  lcd.print(raw[3]);
  lcd.print("  ");

  // Serial: useful for training data later
  Serial.print("F1:"); Serial.print(raw[0]);
  Serial.print(" F2:"); Serial.print(raw[1]);
  Serial.print(" F3:"); Serial.print(raw[2]);
  Serial.print(" F4:"); Serial.println(raw[3]);

  delay(200);
}
