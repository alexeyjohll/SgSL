#include <LiquidCrystal_I2C.h>

// Most PCF8574T modules use address 0x27
// If nothing shows, try 0x3F instead
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int FLEX_PIN = A0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Flex Sensor");
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(FLEX_PIN);
  float voltage = raw * (5.0 / 1023.0);

  lcd.setCursor(0, 1);
  lcd.print("Raw:");
  lcd.print(raw);
  lcd.print("  V:");
  lcd.print(voltage, 1);
  lcd.print("    ");

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print("  Voltage: ");
  Serial.println(voltage, 2);

  delay(200);
}
