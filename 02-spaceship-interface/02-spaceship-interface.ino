int switchState = 0;

int redPin1 = 3;
int redPin2 = 4;
int greenPin = 5;

int buttonPin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(buttonPin);

  if (switchState == LOW) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, LOW);
  } else {    
    digitalWrite(redPin1, HIGH);
    digitalWrite(redPin2, LOW);
    digitalWrite(greenPin, LOW);

    delay(250);
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, HIGH);
    delay(250);
  }
}
