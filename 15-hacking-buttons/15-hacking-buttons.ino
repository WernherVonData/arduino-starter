const int opto_pin = 2;
void setup() {
  pinMode(opto_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(opto_pin, HIGH);
  Serial.println("HIGH");
  delay(5000);
  digitalWrite(opto_pin, LOW);
  Serial.println("LOW");
  delay(5000);
}