#ifndef KEYPADMANAGER_H
#define KEYPADMANAGER_H

#include <Arduino.h>
#include <Keypad.h>

class KeyPad {

  private:

      static const byte ROWS = 4; 
      static const byte COLS = 4; 

      char keys[ROWS][COLS] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
      };

      byte rowPins[ROWS] = {9, 8, 7, 6};
      byte colPins[COLS] = {5, 4, 3, 2};

      Keypad _kpd;

  public:
  
      KeyPad() : _kpd(makeKeymap(keys), rowPins, colPins, ROWS, COLS) {}
      
      char getPressedKey() {
        return _kpd.getKey();
      }


};

#endif