//include library
#include <WatchPin.h>

//create istance
WatchPin wp;

//define your pin, in this case we use a pwm pin
#define myPin 3

boolean pin_isPwm;

//void setup
void setup(){
  //set myPin as output
  pinMode(myPin,OUTPUT); //in this case we use OUTPUT
  
  //set if pin is pwm or not
  pin_isPwm = wp.pinIsPWM(myPin);
  
  //initialize serial @ 9600 baud
  delay(2000); //advice: put this pause before Serial.begin();
  Serial.begin(9600);
  
  //Print if pin is pwm or not
  Serial.println("Welcome to WatchPin library");
  Serial.print("Pin ");
  Serial.print(myPin);
  if(pin_isPwm==false){
    Serial.print(" IS NOT PWM");
  } else {
    Serial.print(" IS PWM");
  }
}

//void loop
void loop(){/*Nothing to do here*/}