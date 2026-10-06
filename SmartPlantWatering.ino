// Smart Plant Watering System
// Arduino UNO + Soil Moisture Sensor + Relay Module + Water Pump
// Relay module: LOW trigger

const int soilPin = A1;      // Soil sensor analog output
const int relayPin = 3;      // Relay IN pin

int soilValue = 0;
int threshold = 700;         // Adjust according to soil/sensor readings

void setup() {
  pinMode(relayPin, OUTPUT);

  // Relay is LOW-triggered, so HIGH keeps the pump OFF
  digitalWrite(relayPin, HIGH);

  Serial.begin(9600);

  delay(1000);

  Serial.println("Smart Plant Watering System");
  Serial.println("System ready. Insert sensor into soil.");
}

void loop() {
  // Read soil moisture sensor
  soilValue = analogRead(soilPin);

  Serial.print("Soil value = ");
  Serial.print(soilValue);

  // Dry soil
  if (soilValue < threshold) {
    // Turn pump ON
    digitalWrite(relayPin, LOW);

    Serial.println(" -> Dry: PUMP ON");
  }

  // Wet soil
  else {
    // Turn pump OFF
    digitalWrite(relayPin, HIGH);

    Serial.println(" -> Wet: PUMP OFF");
  }

  delay(2000);
}
