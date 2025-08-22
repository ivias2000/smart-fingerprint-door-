# Smart Door Access System with Fingerprint, RTC, EEPROM, and LCD  

## 📌 Overview  
This project implements a **smart door access system** using Arduino. The system integrates a **fingerprint sensor**, **servo motor (door lock)**, **LCD display**, **RTC (real-time clock)**, and **EEPROM** for logging entry/exit events. It identifies users, grants access, and stores timestamped logs for security tracking.  

## ✨ Features  
- 🔐 **Fingerprint Authentication** – Users are identified with an Adafruit Fingerprint Sensor.  
- ⏰ **Real-Time Clock (RTC)** – Logs accurate entry/exit time and date using DS1307.  
- 💾 **EEPROM Logging** – Stores user ID, action (IN/OUT), and timestamp in external EEPROM.  
- 📟 **LCD Display** – Provides real-time feedback (welcome messages, gate status, errors).  
- ⚙️ **Servo Motor Control** – Opens/closes the gate automatically on authentication.  
- 👥 **Multiple Users** – Example includes *Mahdi* and *Ali*, with separate IN/OUT tracking.  
- 📡 **Communication Protocols** – Utilizes I²C, UART, and GPIO for system integration.  

## 🛠 Hardware Requirements  
- Arduino Uno (or compatible board)  
- LCD1602 display (with I²C or parallel connection)  
- Servo motor (for door lock)  
- Adafruit Fingerprint Sensor  
- RTC module (DS1307)  
- EEPROM (AT24Cxx series, e.g. AT24C512)  
- Breadboard, jumper wires, power supply  

## 📂 Libraries Used  
Make sure to install these libraries in Arduino IDE:  
- `LiquidCrystal`  
- `Servo`  
- `SoftwareSerial`  
- `Adafruit_Fingerprint`  
- `RTClib`  
- `AT24Cxx`  

## ⚡ Setup & Installation  
1. Clone this repository:  
   ```bash
   git clone https://github.com/your-username/smart-door-fingerprint.git
   cd smart-door-fingerprint

<img width="1282" height="722" alt="image" src="https://github.com/user-attachments/assets/dda4d4ec-46ac-4f32-8bbc-782c5b768785" />


https://github.com/user-attachments/assets/d6098413-2a6d-4d63-ade1-4d06ef27ea38
🚪 How It Works

System starts and initializes modules (Fingerprint, RTC, EEPROM, LCD).

User places a finger on the sensor.

If recognized:

Displays Welcome <Name> on LCD.

Logs user ID, IN/OUT status, and timestamp in EEPROM.

Opens servo-controlled gate for 5 seconds.

If not recognized:

Displays Finger Not Found on LCD.

📊 Example Log Data (EEPROM)
User ID	Action	Date	Time
1 (Mahdi)	IN	2024/12/08	14:30:12
2 (Ali)	OUT	2024/12/08	14:45:50
🔮 Future Improvements

Support for more users with names stored in EEPROM.

Web or mobile app integration for remote monitoring.

SD card logging for larger history.

WiFi/IoT connectivity (ESP8266/ESP32).
