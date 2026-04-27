const int FLEX_PINS[4] = {A4, A3, A2, A1};
const String FINGERS[4] = {"Pinky", "Ring", "Middle", "Index"};
int raw[4];

void setup() {
  Serial.begin(9600);
  Serial.println("Glove ready — Middle, Ring, Pinky, Index");
}

void loop() {
  for (int i = 0; i < 4; i++) {
    raw[i] = analogRead(FLEX_PINS[i]);
  }

  Serial.print("Middle:"); Serial.print(raw[2]);
  Serial.print("  Ring:"); Serial.print(raw[1]);
  Serial.print("  Pinky:"); Serial.print(raw[0]);
  Serial.print("  Index:"); Serial.println(raw[3]);

  delay(200);
}
