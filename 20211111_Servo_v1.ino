#include <Servo.h>
Servo myservo;
int speedVal = 95;
unsigned long startingMillis = 0;
unsigned long currentMillis;
unsigned long runMillis = 2000;

void setup() {
  myservo.attach(10); //attaches the servo on pin 9 
}

void loop() {
  currentMillis = millis();
  if(currentMillis-startingMillis>=5000){ 
  myservo.write(89); //stoprotate 
  } else {
  myservo.write(75); //rotate
  }

  
}
