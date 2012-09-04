/*
	Please check README.txt
*/

//include WatchPin header
#include "WatchPin.h"

byte pinSM[NUM_DIGITAL_PINS][2];									//array that contains the state and direction of each pin

void WatchPin::refreshWatchPin(void){								// storage direction&state of each pin
	for(uint8_t x=0;x<NUM_DIGITAL_PINS;x++){
  	uint8_t bit = digitalPinToBitMask(x);							// bitmask of pin requested
	uint8_t port = digitalPinToPort(x);								// port of pin requested
    pinSM[x][0] = ((*portModeRegister(port) & bit) == 0) ? 0:1;		// direction of pin requested
    pinSM[x][1] = ((*portInputRegister(port) & bit) == 0) ? 0:1;	// state of pin requested
 }  
}

uint8_t WatchPin::portState(uint8_t _port){
	return *portInputRegister(_port);								//return state of port requested
}

uint8_t WatchPin::portDirection(uint8_t _port){
	return *portModeRegister(_port);								//return direction of port requested
}

boolean WatchPin::pinState(uint8_t _pin){
	refreshWatchPin();												// refresh mode&state of all pin
	return pinSM[_pin][1];											// return state of pin requested
}

boolean WatchPin::pinDirection(uint8_t _pin){
	refreshWatchPin();												// refresh mode&state of all pin
	return pinSM[_pin][0];											// return direction of pin requested
}

boolean WatchPin::pinIsPWM(uint8_t _pin){
	return (digitalPinToTimer(_pin)==0) ? false:true;				//return TRUE if pin requested is PWM, FALSE if not
}

uint8_t WatchPin::pinPWM(uint8_t _pin){								//if  pin is pwm return its value, if not return 0
switch(digitalPinToTimer(_pin))
		{
			#if defined(TCCR0) && defined(COM00) && !defined(__AVR_ATmega8__)
			case TIMER0A:
				return OCR0;
				break;
			#endif

			#if defined(TCCR0A) && defined(COM0A1)
			case TIMER0A:
				return OCR0A;
				break;
			#endif

			#if defined(TCCR0A) && defined(COM0B1)
			case TIMER0B:
				return OCR0B;
				break;
			#endif

			#if defined(TCCR1A) && defined(COM1A1)
			case TIMER1A:
				return OCR1A;
				break;
			#endif

			#if defined(TCCR1A) && defined(COM1B1)
			case TIMER1B:
				return OCR1B;
				break;
			#endif

			#if defined(TCCR2) && defined(COM21)
			case TIMER2:
				return OCR2;
				break;
			#endif

			#if defined(TCCR2A) && defined(COM2A1)
			case TIMER2A:
				return OCR2A;
				break;
			#endif

			#if defined(TCCR2A) && defined(COM2B1)
			case TIMER2B:
				return OCR2B;
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3A1)
			case TIMER3A:
				return OCR3A;
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3B1)
			case TIMER3B:
				return OCR3B;
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3C1)
			case TIMER3C:
				return OCR3C;
				break;
			#endif

			#if defined(TCCR4A)
			case TIMER4A:
				return OCR4A;
				break;
			#endif
			
			#if defined(TCCR4A) && defined(COM4B1)
			case TIMER4B:
				return OCR4B;
				break;
			#endif

			#if defined(TCCR4A) && defined(COM4C1)
			case TIMER4C:
				return OCR4C;
				break;
			#endif
				
			#if defined(TCCR4C) && defined(COM4D1)
			case TIMER4D:				
				return OCR4D;
				break;
			#endif

							
			#if defined(TCCR5A) && defined(COM5A1)
			case TIMER5A:
				return OCR5A;
				break;
			#endif

			#if defined(TCCR5A) && defined(COM5B1)
			case TIMER5B:
				return OCR5B;
				break;
			#endif

			#if defined(TCCR5A) && defined(COM5C1)
			case TIMER5C:
				return OCR5C;
				break;
			#endif
			
			case NOT_ON_TIMER:
			 default:
			  return NOT_ON_TIMER;
			  break;
		}
}