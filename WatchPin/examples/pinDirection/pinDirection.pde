//include library
#include <WatchPin.h>

//create istance
WatchPin wp;

//define your pin
#define myPin 3

boolean pin_direction;

//void setup
void setup(){
  //set myPin as output
  pinMode(myPin,OUTPUT); //chose mode that you want
  
  //set pin direction
  pin_direction = wp.pinDirection(myPin);
  
  //initialize serial @ 9600 baud
  delay(2000); //advice: put this pause before Serial.begin();
  Serial.begin(9600);
  
  //Print the direction of pin
  Serial.println("Welcome to WatchPin library");
  Serial.print("Direction of pin ");
  Serial.print(myPin);
  Serial.print(" = ");
  if(pin_direction==INPUT){
    Serial.print("INPUT");
  } else {
    Serial.print("OUTPUT");
  }
}

//void loop
void loop(){/*Nothing to do here*/}