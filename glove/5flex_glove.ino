const int FLEX_PINS[5] = {A0, A1, A2, A3, A4};
const String FINGERS[5] = {"Thumb", "Index", "Middle", "Ring", "Pinky"};
int raw[5];

void setup() {
  Serial.begin(9600);
  Serial.println("Glove ready — all 5 fingers");
}

void loop() {
  for (int i = 0; i < 5; i++) {
    raw[i] = analogRead(FLEX_PINS[i]);
  }

  Serial.print("Thumb:"); Serial.print(raw[0]);
  Serial.print("  Index:"); Serial.print(raw[1]);
  Serial.print("  Middle:"); Serial.print(raw[2]);
  Serial.print("  Ring:"); Serial.print(raw[3]);
  Serial.print("  Pinky:"); Serial.println(raw[4]);

  delay(200);
}
