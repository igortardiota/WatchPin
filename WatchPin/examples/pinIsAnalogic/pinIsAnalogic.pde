//include library
#include <WatchPin.h>

//create istance
WatchPin wp;

//define your pin
#define myPin A0

//void setup
void setup(){
  //initialize serial @ 9600 baud
  delay(2000); //advice: put this pause before Serial.begin();
  Serial.begin(9600);
  
  //Print the direction of port
  Serial.println("Welcome to WatchPin library");
  Serial.print("Pin A0 is used as analogic: ");
  if(wp.pinIsAnalogic(myPin)==true){
    Serial.println("TRUE");
  }else{
    Serial.println("FALSE");
  }

  Serial.println("Now we set an analogic pin as digital output...");
  pinMode(myPin,OUTPUT);
  Serial.print("Now pin A0 is used as analogic: ");
  if(wp.pinIsAnalogic(myPin)==true){
    Serial.println("TRUE");
  }else{
    Serial.println("FALSE");
  }
}

//void loop
void loop(){/*Nothing to do here*/}
