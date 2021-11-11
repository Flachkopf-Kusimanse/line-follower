 //MOTORS
    int s4=4;      //left
    int s5=5;    //medio izqda
    int s6=6;   // medio dcha
    int s7=7;   // right
    // motor one
    int enA = 3;    //Right motor, SpeedA
    int MotorAip1=12;   // DirectionA
    int MotorAip2=9;    // brakeA
    // motor two
    int enB = 11;    //Left motor
    int MotorBip1=13;
    int MotorBip2=8;
    int turntime=1700;
    int distance;
    float stopdistance = 5;
    //velocity (straight,tilt-high, tilt-low,turning-high, turning-low)
    int vels = 120;
    int velth = 120;
    int veltl = 70;
    int veltuh = 160;
    int veltul = 0;
  
     // ULTRASONIC
    #define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
    #define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
//    long duration; // variable for the duration of sound wave travel

    
void setup() {
  // put your setup code here, to run once:
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

//       //ULTRASONIC
//     pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT      
//     pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {
  // put your main code here, to run repeatedly:
// digitalWrite(trigPin, LOW);
// delayMicroseconds(2);
// digitalWrite(trigPin, HIGH);
// delayMicroseconds(10);
// digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
//duration = pulseIn(echoPin, HIGH);

// Calculating the distance
//distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)



  
  
if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) 
      {
        //Move both the Motors
        digitalWrite(MotorAip1,HIGH);
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, vels);
        analogWrite (enB, vels);
      }
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH)
      {
        //Tilt robot towards left by stopping the left wheel and moving the right one
        digitalWrite(MotorAip1,HIGH);     
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltl);
        analogWrite (enB, velth);
       delay(100);
      }
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)
      {
        //Tilt robot towards right by stopping the right wheel and moving the left one
         digitalWrite(MotorAip1,HIGH);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, velth);
       analogWrite (enB, veltl);
       delay(100);
      }

      else if(digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW)
      {
        for( int starttime = millis(); (millis()-starttime)<turntime;){
        digitalWrite(MotorAip1,HIGH); 
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltuh);
        analogWrite (enB, veltul);
        }
      }
       else if(digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH || digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)
      {
        for( int starttime = millis(); (millis()-starttime)<turntime;){
        digitalWrite(MotorAip1,HIGH); 
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltul);
        analogWrite (enB, veltuh);
        }
      }

//     else if (distance<stopdistance)
//      {
//        //Stop both the motors
//        digitalWrite(MotorAip1,LOW);
//        digitalWrite(MotorAip2,LOW);
//        digitalWrite(MotorBip1,LOW);
//        digitalWrite(MotorBip2,LOW);
//        analogWrite (enA, 0);
//        analogWrite (enB, 0);
//
//        for( int starttime = millis(); (millis()-starttime)<turn180time;)
//        {
//        digitalWrite(MotorAip1,LOW); 
//        digitalWrite(MotorAip2,HIGH);
//        digitalWrite(MotorBip1,LOW);
//        digitalWrite(MotorBip2,LOW);
//        analogWrite (enA, 50);
//        analogWrite (enB, 50);
//        }
//
//        
//       }
      
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
