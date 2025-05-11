#  Elderly Fall Detection & Heart Rate Alert System (Tinkercad Simulation)

This Arduino-based project simulates a simple healthcare alert system designed to detect falls and abnormal heart rates in elderly individuals. It includes both **visual (LED)** and **audible (piezo)** alerts. Built and tested using [Tinkercad Circuits](https://www.tinkercad.com/), it avoids the need for physical hardware while showcasing real-world IoT and embedded design skills.

---

## Components Used

| Component           | Purpose                         |
|--------------------|----------------------------------|
| Arduino Uno R3      | Microcontroller                 |
| Pushbutton          | Simulates a fall event          |
| Potentiometer       | Simulates heart rate variations |
| 2 x LEDs (Red, Blue)| Alert indicators (fall, heart)  |
| 2 x 220Ω Resistors  | LED current limiting            |
| Piezo Speaker       | Audible alert                   |
| Jumper wires        | Connections                     |


## Circuit Overview

![image](https://github.com/user-attachments/assets/fbeafcff-ff5d-49dc-8109-9c001ddc98b3)


##  How It Works

### Fall Detection
- **Pushbutton** simulates a fall
- **Blue LED (pin 13)** turns ON
- **Piezo speaker** buzzes at 1000 Hz
- Message printed: `"Fall Detected!"`

### Heart Rate Monitoring
- **Potentiometer** mimics analog heart rate signal
- If value < 300 or > 700:
  - **Red LED (pin 11)** lights up
  - **Piezo buzzes at 2000 Hz**
  - Message printed: `"Abnormal Heart Rate Detected!"`

---

##  Code Logic Summary

if (digitalRead(fallPin) == LOW) {
  // Fall detected
  tone(piezoPin, 1000);
  digitalWrite(fallLED, HIGH);
  delay(1000);
  digitalWrite(fallLED, LOW);
  noTone(piezoPin);
}
int heartRate = analogRead(heartRatePin);
if (heartRate < 300 || heartRate > 700) {
  tone(piezoPin, 2000);
  digitalWrite(heartLED, HIGH);
  delay(1000);
  digitalWrite(heartLED, LOW);
  noTone(piezoPin);
}
## © 2025 [Aishani Datta]. This project is licensed under the MIT License.

## How To Run(in TinkerCad):
1. Open Tinkercad

2. Create a new circuit

3. Rebuild the setup based on the image above or watch this demo video: "https://youtu.be/hdb_0PXWnLE"

4. Paste the Arduino code into the Text mode of the Code editor

5. Click "Start Simulation"

6. Press the pushbutton / rotate potentiometer to test alerts

## Demo Screenshots:

1. Turning the knob of potentiometer towards left:
   Heart rate goes above normal, leading to read higher analog values
   ![image](https://github.com/user-attachments/assets/466e3d58-54f5-4d7e-b7df-1e74c688b522)
2. Turning the knob of potentiometer towards right:
   Heart rate goes below normal, leading to read lower analog values
   ![image](https://github.com/user-attachments/assets/14788890-7937-4416-b0ba-c78de270d3a5)
3. For Fall Detection, once the pushbutton is pressed, the fall gets detected, the blue LED lights up
   ![image](https://github.com/user-attachments/assets/a49697b3-e2ce-439f-bee1-0082317e564e)

   





