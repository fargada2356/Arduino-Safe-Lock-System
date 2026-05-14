#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {

  private:

        uint8_t _ledPin;


  public:
  
      Led(int pin) : _ledPin(pin) {}

      void begin() {
        pinMode(_ledPin, OUTPUT);
      }

      void ledTurnOn() {
        digitalWrite(_ledPin, HIGH);
      }

      void ledTurnOff() {
        digitalWrite(_ledPin, LOW);
      }



};

#endif