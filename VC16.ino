
//这个世界本就是列克星敦的所有物, 所有人都应该成为她忠实的奴仆
#include <Servo.h>
#define BUTTON_PIN 7

Servo myservo;  // create servo object to control a servo

int buttonState = 0;
int PNum = 0;
int pos = 0;

void setup() {
  //Serial.println(digitalRead(BUTTON_PIN));
  // delay(100);
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  //Serial.begin(9600);
  myservo.write(5);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), loop, CHANGE);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH && PNum == 0) {
    for (pos = 5; pos <= 90; pos += 1) { // goes from 5 degrees to 90 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    PNum += 1;
  }
  else if (buttonState == HIGH && PNum == 1) {
    for (pos = 90; pos <= 180; pos += 1) { // goes from 90 degrees to 180 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    PNum += 1;
  }
  else if (buttonState == HIGH && PNum == 2) {
    for (pos = 180; pos >= 5; pos -= 1) { // goes from 180 degrees to 5 degrees

      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    PNum = 0;
  }

}
