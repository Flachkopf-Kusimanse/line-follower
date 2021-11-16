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
    int turntime=1250;
    int turn180time=1500;
    int distance;
    float stopdistance = 10;
    //velocity (straight,tilt-high, tilt-low,turning-high, turning-low, turning 180, turning 180 other direction)
    int vels = 80;// ok
    int velth = 80;// ok
    int veltl = 60; // ok
    int veltuh = 120; //turn 90
    int veltul = 30; //turn 90
    int veltu=90; //turn 180
    int veltua=120; //turn 180
    #define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
    #define trigPin 1 //attach pin D1 Arduino to pin Trig of HC-SR04
    long duration; // variable for the duration of sound wave travel
    int stage =0;
    bool cup = false;
    // Servo motor
    #include <Servo.h>
    Servo myservo;
    unsigned long startingMillis = 0;
    unsigned long currentMillis;
    unsigned long runMillis = 3000;
    



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

       //ULTRASONIC
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT      
      pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

    
      // servo motor
      myservo.attach(10); //attaches the servo on pin 10
      Serial.begin(9600);
}

void loop() {

    
       digitalWrite(trigPin, LOW);
       delayMicroseconds(2);
       digitalWrite(trigPin, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigPin, LOW);
       duration = pulseIn(echoPin, HIGH);
       distance = duration * 0.034 / 2;
        Serial.println(distance);

  if(distance>stopdistance)
 {

    if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)  //GO STRAIGHT
      {
        //Move both the Motors
        digitalWrite(MotorAip1,HIGH);
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, vels);
        analogWrite (enB, vels);
      }
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) // TILT LEFT
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
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) //TILT RIGHT
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

      //T- JUNCTION (TURN LEFT 90 DEGREES)
       else if((digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH && stage ==0) || (digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH && stage ==0) || (digitalRead(s4)==LOW && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW && stage ==0) || (digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW && stage ==0)|| (digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW && stage ==0))
      {
        digitalWrite(MotorAip1,HIGH); 
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltul);
        analogWrite (enB, veltuh);

        stage=1;
        
          if (digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) 
        {
          //Move both the Motors
          digitalWrite(MotorAip1,HIGH);
          digitalWrite(MotorAip2,LOW);
          digitalWrite(MotorBip1,LOW);
          digitalWrite(MotorBip2,LOW);
          analogWrite (enA, vels);
          analogWrite (enB, vels);
        }
      }


      //END OF LINE: NO CUP (TURN 180 DEGREES)
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) 
      {
        
        //Tilt robot towards right by stopping the right wheel and moving the left one
        digitalWrite(MotorAip1,LOW);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltua);
        analogWrite (enB, veltu);
        
        if (digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) 
        {
          //Move both the Motors
          digitalWrite(MotorAip1,HIGH);
          digitalWrite(MotorAip2,LOW);
          digitalWrite(MotorBip1,LOW);
          digitalWrite(MotorBip2,LOW);
          analogWrite (enA, vels);
          analogWrite (enB, vels);
        }
        else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW)
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
        stage=0;
      }

      
 }

//REVISAR
 else {
      //cup = pickup(); // pick up the cup by lowering the catchloop

      //TURN 180
        digitalWrite(MotorAip1,LOW);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltua);
        analogWrite (enB, veltu);
        
        if (digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) 
        {
          //Move both the Motors
          digitalWrite(MotorAip1,HIGH);
          digitalWrite(MotorAip2,LOW);
          digitalWrite(MotorBip1,LOW);
          digitalWrite(MotorBip2,LOW);
          analogWrite (enA, vels);
          analogWrite (enB, vels);
        }
        else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW)
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
        stage=2;

        
    
      if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) // TILT LEFT
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
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) //TILT RIGHT
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


        
        //T-JUNCTION: CUP (TURN RIGHT 90 DEGREES)
      else if((digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==LOW && stage ==2) ||(digitalRead(s4)==LOW && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW && stage ==2) || (digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW && stage ==2)|| (digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW && stage ==2)||(digitalRead(s4)==LOW && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH && stage ==2))
      {
        digitalWrite(MotorAip1,HIGH); 
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltuh);
        analogWrite (enB, veltul);

        stage++;
        
          if (digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) 
        {
          //Move both the Motors
          digitalWrite(MotorAip1,HIGH);
          digitalWrite(MotorAip2,LOW);
          digitalWrite(MotorBip1,LOW);
          digitalWrite(MotorBip2,LOW);
          analogWrite (enA, vels);
          analogWrite (enB, vels);
        }
      }
  
 }
}

       
  
    


bool pickup() // pick up the cup
    {
      bool gotit;
      //pickupcode  TBD
      currentMillis = millis();
      if(currentMillis-startingMillis>=runMillis){ 
      myservo.write(88); //stoprotate 
      } else {
      myservo.write(75); //rotate
      }
      
      gotit = true;
      return gotit;
    }









  
