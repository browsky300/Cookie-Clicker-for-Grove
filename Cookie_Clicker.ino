#include <Wire.h>
#include <rgb_lcd.h>

rgb_lcd lcd;

const int pinButton = 4;
volatile int timesClicked = 0;
volatile int clickWeight = 1;

void setup() {
  pinMode(pinButton, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(255, 128, 0);
  lcd.print("Cookie Clicker");
  lcd.setCursor(0, 1);
  lcd.print(timesClicked);
}

void loop() {
  lcd.setCursor(14, 1);
  lcd.print("x");
  lcd.setCursor(15, 1);
  lcd.print(clickWeight);
  if(digitalRead(pinButton)) {
  timesClicked = timesClicked + clickWeight;
  lcd.setCursor(0, 1);
  lcd.print(timesClicked);
  lcd.setCursor(14, 1);
  lcd.print("x");
  lcd.setCursor(15, 1);
  lcd.print(clickWeight);
  while(digitalRead(pinButton)) {}
  }
  if(timesClicked == 100) {
    clickWeight = 2;
  }
  if(timesClicked == 1000) {
    clickWeight = 3;
  }
  if(timesClicked == 10000) {
    clickWeight = 4;
  }
}
