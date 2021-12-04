const int greenLEDPin=11;
const int blueLEDPin=10;
const int redLEDPin=9;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorPin);
  delay(5); // Analog reading takes time
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw sensor values red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.print(blueSensorValue);

  //Sensor reads data on 10bits, but we can write on the PWM only on 8 bits, so now we are scaling down the values
  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("   Mapped to PWM sensor values red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);
  Serial.print("\n");

  //Send the value over the PWM to the RGB led
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
