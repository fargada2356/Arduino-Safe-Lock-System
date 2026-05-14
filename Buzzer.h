#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {

  private:

       int _buzzerPin = 12;
   
  public: 
  
      Buzzer(int pin) : _buzzerPin(pin) {}

      void begin() {
        pinMode(_buzzerPin, OUTPUT);
      }

      void playSuccessSound() { // high freq sound ~ success
        tone(_buzzerPin, 1000);
        delay(150);
        tone(_buzzerPin, 1500);
        delay(150);
        tone(_buzzerPin, 2000);
        delay(200);
        noTone(_buzzerPin);
      }

      void playKeyClick() {
        tone(_buzzerPin, 400);
        delay(50);
        noTone(_buzzerPin);
      }

      void playErrorSound() { // low freq sound ~ sads
        tone(_buzzerPin, 200);
        delay(300);
        tone(_buzzerPin, 150);
        delay(500);
        noTone(_buzzerPin);
      }

      void blockAlarmSound() { // zvuk pri greshka / error sound
        for(int i = 0; i < 3; i++) {
          tone(_buzzerPin, 800);
          delay(200);
          tone(_buzzerPin, 500);
          delay(200);
        }
        noTone(_buzzerPin);
      }

      void lowToneSound() {
        tone(_buzzerPin, 200);
        delay(100);
        noTone(_buzzerPin);
      }

};


#endif