#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

class LCD {

  private:

      LiquidCrystal_I2C* _lcd;

  public:
  
      LCD(LiquidCrystal_I2C* lcd) : _lcd(lcd) {}

      void begin() {
        _lcd->init();
        _lcd->backlight();
      }
      
      void showIdle() {
        _lcd->setCursor(0, 0);
        _lcd->print("ENTER PIN:      ");
        _lcd->setCursor(0, 1);
        _lcd->print("                ");
      }

      void updateStars(int position) {
          _lcd->setCursor(position, 1);
          _lcd->print("*");
        
      }

      void blockedSystem() {
        _lcd->clear();
        _lcd->setCursor(0, 0);
        _lcd->print("BLOCKED SYSTEM!");
        _lcd->setCursor(0, 1);
        _lcd->print("Wait 5 seconds..");
        delay(5000);
      }

      void showSuccess() {
        _lcd->print("Access Granted!");
      }

      void showError() {
        
        _lcd->setCursor(0, 0);
        _lcd->print("Wrong PIN!");
        
      }

      void showEmptyMessage() {
        _lcd->print("Cleared!");
      }

      void clear() {
        _lcd->clear();
      }



};

#endif