// Black Line Follower 

int s4=4;      //izqda
int s5=5;    //medio izqda
int s6=6;   // medio dcha
int s7=7;   // dcha
// motor one
int enA = 3;    //Right motor, SpeedA
int MotorAip1=12;   // DirectionA
int MotorAip2=9;    // brakeA
// motor two
int enB = 11;    //Left motor
int MotorBip1=13;
int MotorBip2=8;

// ULTRASONIC
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement




void setup() 
{
  // put your setup code here, to run once:

pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT      //ULTRASONIC
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT


  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(s4,INPUT);
  pinMode(s5,INPUT);
  pinMode(s6,INPUT);
  pinMode(s7,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
}
void loop() 
{
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//   // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
//
// digitalWrite(trigPin, HIGH);
//
// delayMicroseconds(10);
//
// digitalWrite(trigPin, LOW);
//
// // Reads the echoPin, returns the sound wave travel time in microseconds
//
// duration = pulseIn(echoPin, HIGH);
//
// // Calculating the distance
//
// distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
//
//


  
//   if(distance==100) // distance? (ULTRASONIC)
//  {
//    //Stop both Motors
//    digitalWrite(MotorAip1,LOW);
//    digitalWrite(MotorAip2,LOW);
//    digitalWrite(MotorBip1,LOW);
//    digitalWrite(MotorBip2,LOW);
//   analogWrite (enA, 0);
//   analogWrite (enB, 0);
//  }

if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) // AVANZA
  {
    //Move both the Motors
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 100);
    analogWrite (enB, 100);
  }

  else if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH)
  {
    //Tilt robot towards left by stopping the left wheel and moving the right one
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 80);
    analogWrite (enB, 100);
   delay(100);
  }

  else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)
  {
    //Tilt robot towards right by stopping the right wheel and moving the left one
     digitalWrite(MotorAip1,HIGH);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 100);
   analogWrite (enB, 80);
   delay(100);
  }

  else
  {
    //Stop both the motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
   analogWrite (enB, 0);
  }
}
