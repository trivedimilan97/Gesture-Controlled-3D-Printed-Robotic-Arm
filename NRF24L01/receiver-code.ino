//Receiver Code (Hand) - Mert Arduino and Tech

#include <Servo.h>    //the library which helps us to control the servo motor
#include <SPI.h>      //the communication interface with the modem
#include "RF24.h"     //the library which helps us to control the radio modem

//define the servo name
Servo myServo1;
Servo myServo3;
Servo myServo4;
Servo myServo2;
Servo myServo5;

RF24 radio(9,10);     /*This object represents a modem connected to the Arduino. 
                      Arguments 9 and 10 are a digital pin numbers to which signals 
                      CE and CSN are connected.*/

const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem,that will receive data from the Arduino.

int msg[5];

void setup(){

  //define the servo input pins
  myServo1.attach(15); //A1
  myServo2.attach(16); //A2
  myServo3.attach(17); //A3
  myServo4.attach(18); //A4
  myServo5.attach(19); //A5
  
  radio.begin();                    //it activates the modem.
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data.
  radio.startListening();           //enable receiving data via modem
  }


void loop(){
  if(radio.available()){
    bool done = false;
    while (!done){
    done = radio.read(msg, sizeof(msg));

    myServo1.write(msg[2]); //A1
    myServo2.write(msg[4]); //A2
    myServo3.write(msg[3]); //A3
    myServo4.write(msg[1]); //A4
    myServo5.write(msg[0]); //A5
    }
  }
}
