//include library
#include <WatchPin.h>

//create istance
WatchPin wp;

//define your pin, in this case we use a pwm pin
#define myPin 3

boolean pin_PWM;

//void setup
void setup(){
  //set myPin as output
  pinMode(myPin,OUTPUT); //chose mode that you want
  analogWrite(myPin,170); //write the value that you want
  //set pin direction
  pin_PWM = wp.pinPWM(myPin);
  
  //initialize serial @ 9600 baud
  delay(2000); //advice: put this pause before Serial.begin();
  Serial.begin(9600);
  
  //Print the pwm value of pin
  Serial.println("Welcome to WatchPin library");
  Serial.print("Pwm value of pin ");
  Serial.print(myPin);
  Serial.print(" = ");
  Serial.print(pin_PWM);
}

//void loop
void loop(){/*Nothing to do here*/}