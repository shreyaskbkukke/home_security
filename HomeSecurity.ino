int pirPin = 2;  // PIR sensor output pin
int buzzerPin = 3;  // Buzzer control pin
int pirState = LOW;  // Store PIR sensor state
int lastPirState = LOW;  // Store the previous PIR sensor state

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication for debugging
  Serial.println("System initialized.");
}

void loop() {
  pirState = digitalRead(pirPin);  // Read the PIR sensor state
  Serial.print("PIR State: ");
  Serial.println(pirState);
  
  if (pirState == HIGH && lastPirState == LOW) {
    // PIR sensor is triggered
    tone(buzzerPin, 1000);  // Turn the buzzer on at 1kHz
    Serial.println("Motion detected! Buzzer on.");
  } else {
    noTone(buzzerPin);  // Turn the buzzer off
    Serial.println("No motion detected. Buzzer off.");
  }
  
  lastPirState = pirState;  // Save the current PIR sensor state
  delay(500); // Delay to reduce serial monitor output
}
