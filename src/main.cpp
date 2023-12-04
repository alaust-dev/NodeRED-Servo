#include <Arduino.h>
#include <Servo.h>
#include <WString.h>

Servo myservo;
int pos = 90;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(pos);
}

void loop() {
  if (Serial.available() > 0) { 
    String receivedString = Serial.readStringUntil('\n');
    myservo.write(receivedString.toInt());
    Serial.println("Position " + receivedString);
  }
}
