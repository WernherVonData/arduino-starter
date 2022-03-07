const int control_pin1 = 2;
const int control_pin2 = 3;
const int enable_pin = 6;

const int direction_switch_pin = 4;
const int on_off_switch_state_switch_pin = 5;

const int potentiometer_pin = A0;

int on_off_switch_state = 0;
int previous_on_off_switch_state = 0;
int direction_switch_state = 0;
int previous_direction_switch_state = 0;

int motor_enabled = 0;
int motor_speed = 0;
int motor_direction = 1;

void setup() {
  Serial.begin(9600);
  pinMode(direction_switch_pin, INPUT);
  pinMode(on_off_switch_state_switch_pin, INPUT);
  pinMode(control_pin1, OUTPUT);
  pinMode(control_pin2, OUTPUT);
  pinMode(enable_pin, OUTPUT);
  digitalWrite(enable_pin, HIGH);
}

void loop() {
  on_off_switch_state = digitalRead(on_off_switch_state_switch_pin);
  delay(1);
  direction_switch_state = digitalRead(direction_switch_pin);
  motor_speed = analogRead(potentiometer_pin)/4;

  if (on_off_switch_state != previous_on_off_switch_state) {
    Serial.println("Check On/Off");
    if (on_off_switch_state == HIGH) {
      Serial.println("Change On/Off");
      motor_enabled = !motor_enabled;
    }
  }

  if (direction_switch_state != previous_direction_switch_state) {
    if (direction_switch_state == HIGH) {
      motor_direction = !motor_direction;
    }
  }

  if (motor_direction == 1) {
    digitalWrite(control_pin1, HIGH);
    digitalWrite(control_pin2, LOW);
  } else {
    digitalWrite(control_pin1, LOW);
    digitalWrite(control_pin2, HIGH);
  }
  Serial.print("Motor: ");
  Serial.println(motor_enabled);
  if (motor_enabled == 1) {
    Serial.print("Write on enable pin: ");
    Serial.println(motor_speed);
    analogWrite(enable_pin, motor_speed);
  } else {
    analogWrite(enable_pin, 0);
  }
  // Serial.print("Direction: ");
  // Serial.println(direction_switch_state);
  // Serial.print("On/off: ");
  // Serial.println(on_off_switch_state);
  // Serial.print("Motor: ");
  // Serial.println(motor_speed);

  previous_direction_switch_state = direction_switch_state;
  previous_on_off_switch_state = on_off_switch_state;
}
