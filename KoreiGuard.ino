const int fallPin = 2;         // Pushbutton to simulate fall
const int heartRatePin = A0;   // Potentiometer to simulate heart rate
const int fallLED = 13;        // LED for fall detection
const int heartLED = 11;       // LED for heart rate alert
const int piezoPin = 8;        // Piezo speaker

void setup() {
  pinMode(fallPin, INPUT_PULLUP);  // Button uses internal pull-up
  pinMode(fallLED, OUTPUT);
  pinMode(heartLED, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // === Fall Detection ===
  if (digitalRead(fallPin) == LOW) { // Button pressed
    digitalWrite(fallLED, HIGH);
    tone(piezoPin, 1000);  // Sound alarm at 1000 Hz
    Serial.println("Fall Detected!");
    delay(1000);
    digitalWrite(fallLED, LOW);
    noTone(piezoPin);
  }

  // === Heart Rate Monitoring ===
  int heartRateValue = analogRead(heartRatePin);
  Serial.print("Heart Rate (simulated): ");
  Serial.println(heartRateValue);

  if (heartRateValue < 300 || heartRateValue > 700) {
    digitalWrite(heartLED, HIGH);
    tone(piezoPin, 2000);  // Higher pitch for abnormal heart rate
    Serial.println("Abnormal Heart Rate Detected!");
    delay(1000);
    digitalWrite(heartLED, LOW);
    noTone(piezoPin);
  }

  delay(500);  // Short delay for stability
}
