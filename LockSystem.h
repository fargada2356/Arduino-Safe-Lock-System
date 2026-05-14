#ifndef LOCKSYSTEM_H
#define LOCKSYSTEM_H


#include <Arduino.h>

class Security {

  private:

      String masterPIN[2] = {"1234", "2356"};
      String inputBuffer = "";
      

  public:
  
      Security(String p1, String p2) : masterPIN{p1, p2} {}

      bool addToBuffer(char key) {
        Serial.print("natisnat klavish: ");
        Serial.println(key);
        if(key >= '0' && key <= '9' && inputBuffer.length() < 4) {
          inputBuffer += key;
          Serial.print("tekusht buffer: ");
          Serial.println(inputBuffer);
          return true;
        }
        Serial.println("Greshka: Nevaliden klavish ili pulen buffer");
        return false;
      }

      bool resetBuffer() {
        inputBuffer = "";
        return false;
      }

      bool checkPIN() {
        for(int i = 0; i < 2; i++) {
          if(inputBuffer == masterPIN[i]) return true;
        }
        return false;
      }

      int getBufferLength() {
        return inputBuffer.length();
      }


};


#endif