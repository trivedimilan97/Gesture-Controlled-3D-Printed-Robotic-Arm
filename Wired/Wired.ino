//Define sensors and servos

#include <Servo.h> //Includes servo library

Servo finger1, finger2, finger3, finger4, finger5;

int servoPin1 = 2;
int servoPin2 = 3;
int servoPin3 = 4;
int servoPin4 = 5;
int servoPin5 = 6;

int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
int flexPin5 = A4;

void setup()
{
  //Attach the servo objects to their respective pins
  finger1.attach(servoPin1);
  finger2.attach(servoPin2);
  finger3.attach(servoPin3);
  finger4.attach(servoPin4);
  finger5.attach(servoPin5);
  
  /* set each servo pin to output; I'm not acutally sure if this is
  even necessary, but I did just in case it is */
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
  pinMode(servoPin4, OUTPUT);
  pinMode(servoPin5, OUTPUT);
  
  //Set each flex sensor pin to input: this is necessary
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
  pinMode(flexPin5, INPUT);
  
  
}

void loop()
{
  //Defines analog input variables
  int flex1 = analogRead(flexPin1);
  int flex2 = analogRead(flexPin2);
  int flex3 = analogRead(flexPin3);
  int flex4 = analogRead(flexPin4);
  int flex5 = analogRead(flexPin5);
  
  /* Defines "pos" variables as being proportional to the flex inputs.
  The 400 to 700 value range seemed adequate for my sensors, but you can change
  yours accordingly. */
  int pos1 = map(flex1, 800, 900, 0, 180);
  pos1 = constrain(pos1, 0, 180);
  int pos2 = map(flex2, 800, 900, 0, 180);
  pos2 = constrain(pos2, 0, 180);
  int pos3 = map(flex3, 800, 900, 0, 180);
  pos3 = constrain(pos3, 0, 180);
  int pos4 = map(flex4, 800, 900, 0, 180);
  pos4 = constrain(pos4, 0, 180);
  int pos5 = map(flex5, 800, 900, 0, 180);
  pos5 = constrain(pos5, 0, 180);
  
  //Tells servos to move by the amount specified in the "pos" variables
  finger1.write(pos1);
  finger2.write(pos2);
  finger3.write(pos3);
  finger4.write(pos4);
  finger5.write(pos5);
}
