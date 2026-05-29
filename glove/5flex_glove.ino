const int FLEX_PINS[5] = {A0, A1, A2, A3, A4};
const String FINGERS[5] = {"Thumb", "Index", "Middle", "Ring", "Pinky"};
const int SAMPLES = 10;
int raw[5];

int stableRead(int pin) {
  long sum = 0;
  for (int i = 0; i < SAMPLES; i++) {
    sum += analogRead(pin);
    delay(2);
  }
  return sum / SAMPLES;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Glove ready — stabilised");
}

void loop() {
  for (int i = 0; i < 5; i++) {
    raw[i] = stableRead(FLEX_PINS[i]);
  }

  Serial.print("Thumb:"); Serial.print(raw[0]);
  Serial.print("  Index:"); Serial.print(raw[1]);
  Serial.print("  Middle:"); Serial.print(raw[2]);
  Serial.print("  Ring:"); Serial.print(raw[3]);
  Serial.print("  Pinky:"); Serial.println(raw[4]);
}