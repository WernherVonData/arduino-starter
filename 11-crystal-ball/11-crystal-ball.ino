#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int switch_pin = 13;
int switch_state = 0;
int previous_switch_state = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switch_pin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal ball");
}

void loop() {
  switch_state = digitalRead(switch_pin);
  if (switch_state != previous_switch_state) {
    if (switch_state == LOW) {
      reply = random(3);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The ball says:");
      lcd.setCursor(0,1);
      switch (reply)
      {
      case 0:
        lcd.print("Yes");
        break;
      case 1:
        lcd.print("No");
        break;
      case 2:
        lcd.print("42");
        break;
      
      default:
        break;
      }
    }
  }
  previous_switch_state = switch_state;
}