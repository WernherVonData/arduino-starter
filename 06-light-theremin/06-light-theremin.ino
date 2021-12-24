int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int sensorPin = A0;
const int piezoPin = 2;

const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow= sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(piezoPin, pitch, 20);
  delay(10);
}
