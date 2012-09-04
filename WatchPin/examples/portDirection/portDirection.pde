//include library
#include <WatchPin.h>

//create istance
WatchPin wp;

byte port_direction;

//void setup
void setup(){
  //write what do you want here, in this case we set all pin as OUTPUT
  for(int x=0;x<=13;x++){
    pinMode(x,OUTPUT); //chose mode that you want
  }
  
  //set port direction
  port_direction = wp.portDirection(PORT_D);
  
  //initialize serial @ 9600 baud
  delay(2000); //advice: put this pause before Serial.begin();
  Serial.begin(9600);
  
  //Print the direction of port
  Serial.println("Welcome to WatchPin library");
  Serial.print("Direction of PORTD = ");
  Serial.print(port_direction,BIN);
}

//void loop
void loop(){/*Nothing to do here*/}