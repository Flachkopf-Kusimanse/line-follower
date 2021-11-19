//IR SENSORS
    int s4=4;      //left
    int s5=5;    //medio izqda
    int s6=6;   // medio dcha
    int s7=7;   // right
    // MOTOR ONE
    int enA = 3;    //Right motor, SpeedA
    int MotorAip1=12;   // DirectionA
    int MotorAip2=9;    // brakeA
    // MOTOR TWO
    int enB = 11;    //Left motor
    int MotorBip1=13;
    int MotorBip2=8;
    //ULTRASONIC SENSOR
    int distance=100;
    float stopdistance = 10;
    #define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
    #define trigPin 1 //attach pin D1 Arduino to pin Trig of HC-SR04
    long duration; // variable for the duration of sound wave travel
    //velocity (straight,tilt-high, tilt-low,turning-high, turning-low, turning 180, turning 180 other direction)
    int vels = 85;// ok
    int velth = 85;// ok
    int veltl = 65; // ok
    int veltuh = 80; //turn 90
    int veltul = 35; //turn 90
    int veltu=80; //turn 180
    int veltua=92; //turn 180
    int veltsh = 120; 
    int veltsl = 70; 
    
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
        myservo.write(88); //stoprotate 
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
       Serial.println(stage);
       //Serial.println(cup);
if(cup==false)
{
  if(distance>stopdistance)
 {

    if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)  //GO STRAIGHT
      {
        gostraight();
      }
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) // TILT LEFT
      {
        tiltleft();
      }
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) //TILT RIGHT
      {
        tiltright();
      }

      //T- JUNCTION (TURN LEFT 90 DEGREES)
       else if((digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH && stage ==0) || (digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH && stage ==0) || (digitalRead(s4)==LOW && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW && stage ==0) || (digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW && stage ==0)|| (digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW && stage ==0))
      {
        turnleft();
        stage=1;
      }
      else if ((digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH && stage ==2 ) || (digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH && stage ==2 ) || (digitalRead(s4)==LOW && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW && stage ==2 ) || (digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW && stage ==2 )|| (digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW && stage ==2))
      {
        turnleft();
        stage=3;
      }


      //END OF LINE: NO CUP (TURN 180 DEGREES)
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) 
      {
        turn180();
         stage=2;
      }

      
 }

//REVISAR
 else if (distance<stopdistance && stage==1 ||  distance<stopdistance && stage==2)
 {

        pickup(); // pick up the cup by lowering the catchloop
        turn180();
        stage=4;
        cup=true;
      
 }
  else if( distance<stopdistance && stage==3)
 {

        pickup(); // pick up the cup by lowering the catchloop
        turn180();
        stage=5;
        cup=true;
  }
 
}
else 
{
  if ( stage==4)
 {    
      
      if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)  //GO STRAIGHT
      {
        gostraight();
      }

        
    
      if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) // TILT LEFT
      {
        tiltleft();
      }
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) //TILT RIGHT
      {
        tiltright;
      }


        
        //T-JUNCTION: CUP (TURN RIGHT 90 DEGREES)
      else if((digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==LOW ) ||(digitalRead(s4)==LOW && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW ) || (digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW )|| (digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW )||(digitalRead(s4)==LOW && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH ))
      {
        turnright();

        //stage=4;
        
          
      }
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH && stage==4)
      {
        stopmotors();
      }
  }
  else if ( stage==5)
 {    
      
      if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)  //GO STRAIGHT
      {
        gostraight();
      }

        
    
      if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) // TILT LEFT
      {
        tiltleft();
      }
    
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) //TILT RIGHT
      {
        tiltright;
      }


      
      else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH)
      {
        stopmotors();
      }
 }
}
 
}
//  if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)  //GO STRAIGHT
//      {
//        gostraight();
//      }
//
//        
//    
//  if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) // TILT LEFT
//  {
//    tiltleft();
//  }
//
//  else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) //TILT RIGHT
//  {
//    tiltright;
//  }
//  else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH && stage==4)
//      {
//        stopmotors();
//      }
// }




       
  
    


void pickup() // pick up the cup
    {

       //Stop both the Motors
      digitalWrite(MotorAip1,HIGH);
      digitalWrite(MotorAip2,HIGH);
      digitalWrite(MotorBip1,LOW);
      digitalWrite(MotorBip2,HIGH);
      delay(2000);
      myservo.write(99); //rotate
      delay(2000);
      myservo.write(88);
      //turn180();
    }


void gostraight() 
    { 
        //Move both the Motors
        digitalWrite(MotorAip1,HIGH);
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, vels);
        analogWrite (enB, vels);        
     
    }
    
void tiltleft() 
    {
        //Tilt robot towards left by stopping the left wheel and moving the right one
        digitalWrite(MotorAip1,HIGH);     
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltl);
        analogWrite (enB, velth);
        }
    
void tiltright() 
    {
       //Tilt robot towards right by stopping the right wheel and moving the left one
       digitalWrite(MotorAip1,HIGH);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
       digitalWrite(MotorAip2,LOW);
       digitalWrite(MotorBip1,LOW);
       digitalWrite(MotorBip2,LOW);
       analogWrite (enA, velth);
       analogWrite (enB, veltl);
    }

void turnleft() 
    {
        digitalWrite(MotorAip1,HIGH); 
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltul);
        analogWrite (enB, veltuh);
        
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
void turnright ()
  {
        digitalWrite(MotorAip1,HIGH); 
        digitalWrite(MotorAip2,LOW);
        digitalWrite(MotorBip1,LOW);
        digitalWrite(MotorBip2,LOW);
        analogWrite (enA, veltuh);
        analogWrite (enB, veltul);

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

void turn180 ()
  {
    //Tilt robot towards right by stopping the right wheel and moving the left one
            digitalWrite(MotorAip1,LOW);     
            digitalWrite(MotorAip2,LOW);
            digitalWrite(MotorBip1,LOW);
            digitalWrite(MotorBip2,HIGH);
            analogWrite (enA, veltua);

          if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH)
          {
            digitalWrite(MotorAip1,LOW);     
            digitalWrite(MotorAip2,LOW);
            digitalWrite(MotorBip1,LOW);
            digitalWrite(MotorBip2,HIGH);
            analogWrite (enA, veltua);
          }
        

          else if (digitalRead(s4)==LOW && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH||digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH||digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH )
          {
            digitalWrite(MotorAip1,LOW);     
            digitalWrite(MotorAip2,HIGH);
            digitalWrite(MotorBip1,LOW);
            digitalWrite(MotorBip2,LOW);
            analogWrite (enB, veltua);
          }
          else if (digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) 
        {
          //Move both the Motors
          digitalWrite(MotorAip1,HIGH);
          digitalWrite(MotorAip2,LOW);
          digitalWrite(MotorBip1,LOW);
          digitalWrite(MotorBip2,LOW);
          analogWrite (enA, vels);
          analogWrite (enB, vels);
        }
        else if (digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==LOW) 
        {
          //Move both the Motors
          digitalWrite(MotorAip1,HIGH);
          digitalWrite(MotorAip2,LOW);
          digitalWrite(MotorBip1,LOW);
          digitalWrite(MotorBip2,LOW);
          analogWrite (enA, veltsh);
          analogWrite (enB, veltsl);
        }
  }

void stopmotors()
  {
          //Stop both Motors
          digitalWrite(MotorAip1,HIGH);
          digitalWrite(MotorAip2,HIGH);
          digitalWrite(MotorBip1,LOW);
          digitalWrite(MotorBip2,HIGH);
          delay(2000);

  }







  
