const int sensorPin = A0;
const float environmentTemperature = 24.0; // temperature of the environemnt - you should adjust it 
const float analogPinNumberOfValues = 1024.0;
const float maxAnalogPinVoltage = 5.0;

void lightUp(int number_of_leds = 0) {
  int current_led_index = 0;
  for (int pinNumber = 2; pinNumber < 5; ++pinNumber) {
    if (current_led_index < number_of_leds) {
      digitalWrite(pinNumber, HIGH);
      current_led_index++;
    } else {
      digitalWrite(pinNumber, LOW);
    }
  }
}

void setup() {
  Serial.begin(9600); // Opens serial port with 9600 bit/s

  for (int pinNumber = 2; pinNumber < 5; ++pinNumber) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // Convert ADC (Analog to Digital Converter) reading to voltage
  float voltage = (sensorVal/analogPinNumberOfValues) * maxAnalogPinVoltage;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = (voltage - 0.5) * 100;
  Serial.print(", Temperature: ");
  Serial.println(temperature);

  if (temperature < environmentTemperature + 2) {
    lightUp(0);
  } else if (temperature >= environmentTemperature + 2 && temperature < environmentTemperature + 4) {
    lightUp(1); 
  } else if (temperature >= environmentTemperature + 4 && temperature < environmentTemperature + 6) {
    lightUp(2); 
  } else if (temperature >= environmentTemperature + 6) {
    lightUp(3); 
  }
  delay(1);
}
