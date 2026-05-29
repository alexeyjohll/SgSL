const int FLEX_PINS[5] = {A0, A1, A2, A3, A4};
const String FINGERS[5] = {"Thumb", "Index", "Middle", "Ring", "Pinky"};
const int SAMPLES = 10;
const int MAX_SIGNS = 26;

int storedSigns[MAX_SIGNS][5];
char storedLabels[MAX_SIGNS];
int signCount = 0;

int stableRead(int pin) {
  long sum = 0;
  for (int i = 0; i < SAMPLES; i++) {
    sum += analogRead(pin);
    delay(2);
  }
  return sum / SAMPLES;
}

void readAllFingers(int vals[5]) {
  for (int i = 0; i < 5; i++) {
    vals[i] = stableRead(FLEX_PINS[i]);
  }
}

void saveSign(char label) {
  int vals[5];
  readAllFingers(vals);
  storedLabels[signCount] = label;
  for (int i = 0; i < 5; i++) {
    storedSigns[signCount][i] = vals[i];
  }
  signCount++;
  Serial.print(">>> Saved: "); Serial.println(label);
}

char recallSign() {
  int vals[5];
  readAllFingers(vals);
  int bestMatch = -1;
  long bestScore = 999999;
  for (int s = 0; s < signCount; s++) {
    long score = 0;
    for (int i = 0; i < 5; i++) {
      score += abs(vals[i] - storedSigns[s][i]);
    }
    if (score < bestScore) {
      bestScore = score;
      bestMatch = s;
    }
  }
  return bestMatch >= 0 ? storedLabels[bestMatch] : '?';
}

void setup() {
  Serial.begin(9600);
  Serial.println("Thumb,Index,Middle,Ring,Pinky");
  Serial.println("Commands: SA=save A, R=recall, L=list");
}

void loop() {
  // handle commands
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.startsWith("S") && input.length() == 2) {
      saveSign(input.charAt(1));
    } else if (input == "R") {
      Serial.print(">>> Detected: "); Serial.println(recallSign());
    } else if (input == "L") {
      Serial.print(">>> Saved: ");
      for (int i = 0; i < signCount; i++) {
        Serial.print(storedLabels[i]); Serial.print(" ");
      }
      Serial.println();
    }
    return;
  }

  // read and output
  int vals[5];
  readAllFingers(vals);

  // plotter format (comma separated)
  for (int i = 0; i < 5; i++) {
    Serial.print(vals[i]);
    if (i < 4) Serial.print(",");
  }
  Serial.println();

  // monitor format (labelled) — comment this out when using plotter
  // for (int i = 0; i < 5; i++) {
  //   Serial.print(FINGERS[i]); Serial.print(":"); Serial.print(vals[i]);
  //   if (i < 4) Serial.print("  ");
  // }
  // Serial.println();

  delay(100);
}