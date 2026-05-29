// LED Blink — 500ms delay
// Works with built-in LED (pin 13) on most Arduino boards

const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED on
  delay(500);                   // wait 500ms
  digitalWrite(LED_PIN, LOW);   // LED off
  delay(500);                   // wait 500ms
}
