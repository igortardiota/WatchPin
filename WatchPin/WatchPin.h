/*
	WatchPin is a library that shows to the user, information
	about pins and ports of the microcontroller.
	
	This library support microcontrollers of Arduino and someone
	of Atmel. For more info about supported microcontroller please
	check the README.txt file.
	
	Written by Igor Tardiota on 09/2012. (igor_tardiota@alice.it)
	
	
	This library is free software; you can redistribute it and/or
	modify it under the terms of the Creative Commons SA-NC-BY License.
	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef WatchPin_h
#define WatchPin_h

//Library is compatible both with Arduino <=0023 and Arduino >=100
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//Each port is defined by its letter
#define PORT_A 1
#define PORT_B 2
#define PORT_C 3
#define PORT_D 4
#define PORT_E 5
#define PORT_F 6
#define PORT_G 7
#define PORT_H 8
#define PORT_J 10
#define PORT_K 11
#define PORT_L 12

#if defined (__AVR_ATmega32U4__)
#define NUM_DIGITAL_PINS 20
#endif

class WatchPin
{
	public:
		//public methods
		byte portState(uint8_t _port);
		byte portDirection(uint8_t _port);
		boolean pinState(uint8_t _pin);
		boolean pinDirection(uint8_t _pin);
		boolean pinIsPWM(uint8_t _pin);
		uint8_t pinPWM(uint8_t _pin);
	private:
		//private methods
		void refreshWatchPin();
		byte pinSM[NUM_DIGITAL_PINS][2];		
};
#endif