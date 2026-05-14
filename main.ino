#include <Arduino.h>
#include "Buzzer.h"
#include "KeypadManager.h"
#include "LCD.h"
#include "LockSystem.h"
#include "LED.h"
#include "ServoMotor.h"
 
LiquidCrystal_I2C myLcd(0x27, 16, 2);
LCD myDisplay(&myLcd);

Security mySecurity("1234", "2356");
Led myPinSuccess(11);
Led myPinError(13);
Buzzer myBuzzer(12);
KeyPad myKeyPad;
ServoMotor myServo(10);

bool isSystemIdle = true;
byte wrongAttempts = 0;

void setup() {
Serial.begin(9600);
myDisplay.begin();
myPinSuccess.begin();
myPinError.begin();
myBuzzer.begin();
myServo.begin();
myKeyPad.getPressedKey();
}

void loop() {

  char key = myKeyPad.getPressedKey();



  if(key) {
    myDisplay.updateStars(0);

    if(isSystemIdle) {
      myDisplay.showIdle();
      isSystemIdle = false;
    }
  

    switch(key) {

      case '*': {
        // Clear logic
        mySecurity.resetBuffer();
        myDisplay.clear();
        myDisplay.showIdle();
        isSystemIdle = true;
        myBuzzer.lowToneSound();
        myPinSuccess.ledTurnOff();
        myPinError.ledTurnOff();
        break;
      }
      case '#': {
        myPinSuccess.ledTurnOff();
        myPinError.ledTurnOff();
        // Enter logic
        if (mySecurity.checkPIN()) {
          wrongAttempts = 0;
          myDisplay.clear();
          myDisplay.showSuccess();
          myPinSuccess.ledTurnOn();
          myBuzzer.playSuccessSound();
          myServo.servoUnlock();

          delay(3000);

          myServo.servoLock();
          myPinSuccess.ledTurnOff();
          mySecurity.resetBuffer();
          myDisplay.showIdle();
        }
        else {
          myDisplay.clear();
          myDisplay.showError();
          myBuzzer.playErrorSound();
          myPinError.ledTurnOn();
          mySecurity.resetBuffer();
          wrongAttempts++;
          delay(2000);
          myPinError.ledTurnOff();
          
          if (wrongAttempts >= 3) {
            myDisplay.clear();
            myBuzzer.blockAlarmSound();
            myDisplay.blockedSystem();
            wrongAttempts = 0;
            isSystemIdle = true;
          
     }

     myDisplay.clear();
     myDisplay.showIdle();
    }
        break;
      }

      default:

      if(isDigit(key)) {
        if(mySecurity.addToBuffer(key))  {
          myBuzzer.playKeyClick();
          int buffer = mySecurity.getBufferLength();
          myDisplay.updateStars(buffer - 1);
      }
    }
    break;
  }
    delay(200);
  }
}