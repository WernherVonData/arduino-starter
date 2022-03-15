#include <Servo.h>

Servo my_servo;

const int piezo = A0;
const int switch_pin = 12;
const int red_led = 10;
const int green_led = 9;
const int yellow_led = 8;

int knock_val;
int switch_val;

const int quiet_knock = 10;
const int loud_knock = 100;

boolean locked = false;
int number_of_knocks = 0;

void setup() {
  my_servo.attach(3);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(switch_pin, INPUT);
  Serial.begin(9600);
  digitalWrite(green_led, HIGH);
  my_servo.write(0);
  Serial.println("The box is unlocked");
}

void loop() {
 if (locked == false) {
   switch_val = digitalRead(switch_pin);
   if (switch_val == HIGH) {
     locked = true;
     digitalWrite(green_led, LOW);
     digitalWrite(red_led, HIGH);
     my_servo.write(90);
     Serial.println("The box is locked");
     delay(1000);
   }
 }

 if (locked == true) {
   knock_val = analogRead(piezo);
   if (number_of_knocks < 3 && knock_val > 0) {
     if (checkForKnock(knock_val) == true) {
       number_of_knocks++;
     }
     Serial.print(3-number_of_knocks);
     Serial.println(" more knock to go...");
   }

   if (number_of_knocks >= 3) {
     locked = false;
     my_servo.write(0);
     delay(20);
     digitalWrite(green_led, HIGH);
     digitalWrite(red_led, LOW);
     Serial.println("The box is unlocked!");
     number_of_knocks = 0;
   }
 }
}

boolean checkForKnock(int value) {
  if (value > quiet_knock && value < loud_knock) {
    digitalWrite(yellow_led, HIGH);
    delay(50);
    digitalWrite(yellow_led, LOW);
    Serial.print("Valid knock of value: ");
    Serial.println(value);
    return true;
  } else {
    Serial.print("Bad knock value: ");
    Serial.println(value);
    return false;
  }
}