#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Servo.h>
#include <Arduino.h>

class ServoMotor {

  private:

      int servoPin = 10;
      bool isLocked = true;
      Servo myServo;

  public:

      ServoMotor(int pin) : servoPin(pin) {}

      void begin() {
        myServo.attach(servoPin);
      }

      void servoUnlock() {
        myServo.write(90);
        isLocked = false;
      }

      void servoLock() {
        myServo.write(0);
        isLocked = true;
      }


};


#endif