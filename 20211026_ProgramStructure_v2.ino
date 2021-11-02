/*stages:
 * Maybe just 0,1,3,5 needed
0: Start to Tjunction
1: Tjunction to A
2: A to Tjunction
3: Tjuction to B
4: B to Tjunction
5: Tjunction to Start
*/ 
/*Other states:
Cup catched(Boolean / catch)
end of line(Boolean / in Movement code / results in turning or celebrating)

*/
//STATES 
int stage = 0;
bool cup = false;
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
// speeds
int velh = 155; //higher velocity = speed of fast motor
int vell = 80;  //lower velocity = speed of slow motor

// ULTRASONIC
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
float stopdistance = 70; // distance to the cup to stop the car

void setup() {

  
  // put your setup code here, to run once:
  
  //MOTORS
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


}

void loop() {

  if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH) // AVANZA
  {
    //Move both the Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 80);
    analogWrite (enB, 80);
  }

  else if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH)
  {
    //Tilt robot towards left by stopping the left wheel and moving the right one
    digitalWrite(MotorAip1,LOW);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 80);
    analogWrite (enB, 50);
   delay(100);
  }

  else if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==LOW && digitalRead(s7)==HIGH)
  {
    //Tilt robot towards right by stopping the right wheel and moving the left one
     digitalWrite(MotorAip1,LOW);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 50);
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
}//movement // move along the line TBD
   //move along line making sure the sensors don't change their state;use velocityvariable vel 
   //always sense for cup with ultrasonic sensor (maybe as interrupter)
   //check for t-junction with outer sensors and change stages respectively TBD : only left senses black -> turn left ; both sense black -> turn depending on cup status; right senses black: turn right if cup isn't found, keep straight if cup is found. set stageinteger as x
  if(digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==HIGH && stage==0) //tjunction &stage 0
  {
    turn90(); //turn left
    stage = 1;
  }
  if(digitalRead(s4)==HIGH && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW && stage==3) //tjunction &stage 3
  {
    //TBD drive straight for 1sec
    stage = 5;
  }
  if(digitalRead(s4)==LOW && digitalRead(s5)==LOW && digitalRead(s6)==LOW && digitalRead(s7)==LOW)//tjunction left or right (stage2)
  {
    if(cup==true)
    {
      turn_90(); //turn right
      stage = 5;
    }
    else
    {
      turn90(); //turn left
      stage = 3;
    }
  }
  if(digitalRead(s4)==HIGH && digitalRead(s5)==HIGH && digitalRead(s6)==HIGH && digitalRead(s7)==HIGH) //end of line detected
  { 
    //maybe check for cup now, if cup is behind this end   TBD
    // TBD brake
    if(cup == false)
    {
      turn180();
    }
    if(cup == true && stage = 5)
    {
      celebrate(); // celebrate being back at the start with the cup (requires cup and being in stage 5)
    } 
  }

//check distance with ultrasonic sensor TBD
  if(dist<stopdistance)
  {
    //maybe break TBD
    cup = pickup(); // pick up the cup by lowering the catchloop
    turn180(); // turn the robot by 180
  }
}


bool pickup() // pick up the cup
{
  bool gotit;
  //pickupcode  TBD
  gotit = true;
  return gotit;
}

void turn180() // turn around
{ //after picking up the cup or after detecting end of line
  // turn the wheels respectively and find the line again TBD
  stage++;
}
void turn90() //turn left
{
  // turn the wheels respectively and find the line again TBD
  stage++;
}
void turn_90() //turn right
{
  // turn the wheels respectively and find the line again TBD
  stage++;
}
void celebrate() //celebrate by TBD
{
  //TBD
  delay(100000)//shut off
}
