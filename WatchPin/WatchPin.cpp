/*
  Please read README.txt
*/

//include WatchPin header
#include "WatchPin.h"

char* PROGMEM stringPorts[] = {
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  "PORT_A\nPORT_B\nPORT_C\nPORT_D\nPORT_E\nPORT_F\nPORT_G\nPORT_H\nPORT_J\nPORT_K\nPORT_L\n",
#elif defined(__AVR_ATmega32U4__)
  "PORT_B\nPORT_C\nPORT_D\nPORT_E\nPORT_F\n",
#elif defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644P__)
  "PORT_A\nPORT_B\nPORT_C\nPORT_D\n",
#else
  "PORT_B\nPORT_C\nPORT_D\n",
#endif
};

uint8_t PROGMEM uPorts[] = {
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  PORT_A,
  PORT_B,
  PORT_C,
  PORT_D,
  PORT_E,
  PORT_F,
  PORT_G,
  PORT_H,
  PORT_J,
  PORT_K,
  PORT_L,
#elif defined(__AVR_ATmega32U4__)
  PORT_B,
  PORT_C,
  PORT_D,
  PORT_E,
  PORT_F,
#elif defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644P__)
  PORT_A,
  PORT_B,
  PORT_C,
  PORT_D,
#else
  PORT_B,
  PORT_C,
  PORT_D,
#endif
};

uint8_t WatchPin::portState(uint8_t _port){
	return *portInputRegister(_port);			//return state of port requested
}

uint8_t WatchPin::portDirection(uint8_t _port){
	return *portModeRegister(_port);			//return direction of port requested
}

boolean WatchPin::pinState(uint8_t _pin){
  uint8_t bit = digitalPinToBitMask(_pin);			//bitmask of pin requested
  uint8_t port = digitalPinToPort(_pin);			//port of pin requested
  return ((*portInputRegister(port) & bit) == 0) ? 0:1;		//return state of pin requested
}

boolean WatchPin::pinDirection(uint8_t _pin){
  uint8_t bit = digitalPinToBitMask(_pin);			//bitmask of pin requested
  uint8_t port = digitalPinToPort(_pin);			//port of pin requested
  return ((*portModeRegister(port) & bit) == 0) ? 0:1;		//return direction of pin requested
}

boolean WatchPin::pinIsPWM(uint8_t _pin){
  return (digitalPinToTimer(_pin)==0) ? false:true;		//return TRUE if pin requested is PWM, FALSE if not
}

uint8_t WatchPin::pinPWM(uint8_t _pin){				//if  pin is pwm return its value, if not return 0
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

boolean WatchPin::pinIsAnalogic(uint8_t _pin){
  uint8_t bit = digitalPinToBitMask(_pin);			//bitmask of pin requested
  uint8_t port = digitalPinToPort(_pin);			//port of pin requested

//if pin requested is I/O return false else return if analogic pin requested is working as analog or digital
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  if (_pin < 54){
    return false;
  }else{
    return ((*portModeRegister(port) & bit)==0) ? true:false;
  }
#elif defined(__AVR_ATmega32U4__)
  if (_pin < 18){
    return false;
  }else{
    return ((*portModeRegister(port) & bit)==0) ? true:false;
  }
#elif defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644P__)
  if (_pin < 24){
    return false;
  }else{
    return ((*portModeRegister(port) & bit)==0) ? true:false;
  }
#else
  if (_pin < 14){
    return false;
  }else{
    return ((*portModeRegister(port) & bit)==0) ? true:false;
  }
#endif
}

char* WatchPin::listPorts(){  //return array that contains a string with all ports of uController
  return *stringPorts;
}  