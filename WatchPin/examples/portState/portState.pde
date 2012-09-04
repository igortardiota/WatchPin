//include library
#include <WatchPin.h>

//create istance
WatchPin wp;

byte port_state;

//void setup
void setup(){
  //chose what do you want here, in this case we set all pin as output and set them as HIGH
  for(int x=0;x<=13;x++){
    pinMode(x,OUTPUT);
	digitalWrite(x,HIGH);
  }
    
  //set port state
  port_state = wp.portState(PORT_D);  //chose port that you want
  
  //initialize serial @ 9600 baud
  delay(2000); //advice: put this pause before Serial.begin();
  Serial.begin(9600);
  
  //Print the state of port
  Serial.println("Welcome to WatchPin library");
  Serial.print("State of PORTD = ");
  Serial.print(port_state,BIN);
}

//void loop
void loop(){/*Nothing to do here*/}