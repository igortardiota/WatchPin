------------------------------------
----WatchPin library for Arduino----
------------------------------------

Written by Igor Tardiota on 09/2012. (igor_tardiota@alice.it)

WatchPin is a library that shows to the user, information
about pins and ports of the microcontroller.
	
This library support microcontrollers of Arduino and someone
of Atmel. For more info see "Supported Microcontrollores" paragraph


-----How library works-----

To use this library, you must first include it in the sketch:

#include <WatchPin.h>

Then you need to create an istance of library:

WatchPin nameYouWantOfIstance;  (example WatchPin wp;)

Finally set all other things (void setup, void loop, ecc.)

Functions of library are:

pinState(pin);
pinDirection(pin);
pinIsPWM(pin);
pinPWM(pin);
portState(port);
portDirection(port);
pinIsAnalogic(pin);
listPorts();

***************
*pinState(pin)*
***************
returns LOW or HIGH (0 or 1);
write in parentheses the number of pin
for example: nameYouWantOfIstance.pinState(4);

*******************
*pinDirection(pin)*
*******************
returns INPUT or OUTPUT (0 or 1);
write in parentheses the number of pin
for example: nameYouWantOfIstance.pinDirection(4);

***************
*pinIsPWM(pin)*
***************
returns false or true (0 or 1);
write in parentheses the number of pin
for example: nameYouWantOfIstance.pinIsPWM(4);

*************
*pinPWM(pin)*
*************
returns pwm's value of pin or 0 if pin isn't pwm.
write in parentheses the number of pin
for example: nameYouWantOfIstance.pinPWM(3);

*****************
*portState(port)*
*****************
returns bits sequence(byte) of each pin status of port requested.
(if a bit of byte is 0 the relative pin is LOW, if 1 the relative pin is HIGH)
write in parentheses "PORT_A for PORTA","PORT_B for PORTB" and so on.
example: nameYouWantOfIstance.portState(PORT_B);

*********************
*portDirection(port)*
*********************
returns bits sequence(byte) of each pin direction of port requested.
(if a bit of byte is 0 the relative pin is INPUT, if 1 the relative pin is OUTPUT)
write in parentheses "PORT_A for PORTA","PORT_B for PORTB" and so on.
example: nameYouWantOfIstance.portDirection(PORT_B);

********************
*pinIsAnalogic(pin)*
********************
returns false or true (0 or 1);
write in parentheses the number of pin that you requst to see if it work as analogic or digital
for example: nameYouWantOfIstance.pinIsAnalogic(A0);

*************
*listPorts()*
*************
returns a string that contains all ports of microcontroller that you are using
example: Serial.print(nameYouWantOfIstance.listPorts());

-----Supported microcontrollers------
- Atmega644/1284
- Atmega8
- Atmega88/168/328
- Atmega640/1280/2560
- Atmega32U4

-----License-----

This library is free software; you can redistribute it and/or
modify it under the terms of the Creative Commons SA-NC-BY License.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
