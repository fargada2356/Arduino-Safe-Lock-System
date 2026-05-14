# Arduino-Safe-Lock-System
Smart safety system build with Arduino


## 🚀 Overview
This project implements a security interface. Unlike basic "if-else" tutorials, this system is built using **OOP** principles, making it highly modular and easy to scale.

## ✨ Key Features
- **Multi-Password Support:** Allows both Admin and User PINs.
- **Security Lockout:** Automatically disables input for 30 seconds after 3 failed attempts.
- **Visual & Audio Interface:** Real-time feedback via I2C LCD, RGB/Dual LEDs, and an active buzzer.
- **Clean Architecture:** Separated concerns using dedicated classes for Hardware Management and Security Logic.

## 🛠️ Hardware Requirements
- **Microcontroller:** Arduino Uno R3
- **Input:** 4x4 Matrix Keypad
- **Output:** I2C LCD (16x2), SG90 Servo Motor
- **Indicators:** Active Buzzer, Green LED (Pin 11), Red LED (Pin 13)
- **Power:** 9V Battery with DC Barrel Jack

## 🔌 Pin Mapping
| Component | Arduino Pin | Type |
| :--- | :--- | :--- |
| **I2C LCD** | SDA (A4), SCL (A5) | I2C |
| **Keypad (4x4)** | D2, D3, D4, D5, D6, D7, D8, D9 | Digital |
| **Servo Motor** | D10 | PWM |
| **Green LED** | D11 | Output |
| **Buzzer** | D12 | PWM/Output |
| **Red LED** | D13 | Output |

## 📁 Project Structure
The code is organized into the `src/` directory for better maintainability:
- `LockSystem.h`: Manages PIN validation and input buffers.
- `KeypadManager.h`: Handles debounced matrix keypad input.
- `LCD.h`: Controls UI states and menu rendering.
- `ServoMotor.h`: Encapsulates lock/unlock physical mechanics.
- `Buzzer.h / LED.h`: Hardware abstraction layers for indicators.

## 🔧 Setup & Installation
1. Clone the repository.
2. Open `main.ino` in Arduino IDE.
3. Install `LiquidCrystal_I2C` and `Keypad` libraries if prompted.
4. Upload to your board and enjoy!

## 📜 License
This project is licensed under the MIT License - see the LICENSE file for details.
