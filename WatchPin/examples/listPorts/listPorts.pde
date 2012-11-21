//include library
#include <WatchPin.h>

//create istance
WatchPin wp;

//void setup
void setup(){
  //initialize serial @ 9600 baud
  delay(2000); //advice: put this pause before Serial.begin();
  Serial.begin(9600);
  
  //Print list of all ports
  Serial.println("Welcome to WatchPin library");
  Serial.println("List of ports in this microcontrollers:");
  Serial.print(wp.listPorts());
}

//void loop
void loop(){/*Nothing to do here*/}
