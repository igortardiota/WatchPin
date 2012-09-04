//include library
#include <WatchPin.h>

//create istance
WatchPin wp;

//define your pin
#define myPin 3

boolean pin_state;

//void setup
void setup(){
  //write what do you wnat here, in this case we set myPin as output and as HIGH
  pinMode(myPin,OUTPUT); //chose mode that you want
  digitalWrite(myPin, HIGH);
  
  //set pin state
  pin_state = wp.pinState(myPin);
  
  //initialize serial @ 9600 baud
  delay(2000); //advice: put this pause before Serial.begin();
  Serial.begin(9600);
  
  //Print the state of pin
  Serial.println("Welcome to WatchPin library");
  Serial.print("State of pin ");
  Serial.print(myPin);
  Serial.print(" = ");
  if(pin_state==LOW){
    Serial.print("LOW");
  } else {
    Serial.print("HIGH");
  }
}

//void loop
void loop(){/*Nothing to do here*/}