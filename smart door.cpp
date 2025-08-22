𝕸𝖆𝖘, [12/8/2024 2:44 PM]
// LCD1602 to Arduino Uno connection example
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
#include <Servo.h>
Servo servo;
#include <SoftwareSerial.h>
SoftwareSerial fingerPrint(2, 3);
#include <Adafruit_Fingerprint.h>
//RTC
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;
DateTime now;
//eeprom
#include <AT24Cxx.h>
#define i2c_address 0x50
AT24Cxx eep(i2c_address, 512); // Initilaize using AT24CXX(i2c_address, size of eeprom in KB).
uint8_t log_number=0;
int address = (log_number+1) * 8;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
uint8_t id;
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&fingerPrint);
int angle ;
int mahdi_in=0;
int ali_in=0;
int getFingerprintIDez();
void setup() {
 log_number = eep.read(0);
  servo.attach(5);
  //servo.write(angle);
  lcd.begin(20, 4);
  // you can now interact with the LCD, e.g.:
  
  lcd.print("Smart Door");
  finger.begin(57600);
  Serial.begin(9600);
  lcd.clear();
  lcd.print(" Finding Module ");
  lcd.setCursor(0,1);
  delay(2000);
  if (finger.verifyPassword()) 
    {
    Serial.println("Found fingerprint sensor!");
    lcd.clear();
    lcd.print(" Module Found  ");
    delay(2000);
  } 
  else
  {
  Serial.println("Did not find fingerprint sensor :(");
  lcd.clear();
  lcd.print("Module Not Found");
  lcd.setCursor(0,1);
  lcd.print("Check Connections");
}

   if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
 
  if (!rtc.isrunning()) {
    Serial.println("RTC lost power, lets set the time!");
     
    // Comment out below lines once you set the date & time.
    // Following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(DATE), F(TIME)));
     
    // Following line sets the RTC with an explicit date & time
    // for example to set January 27 2017 at 12:56 you would call:
    // rtc.adjust(DateTime(2017, 1, 27, 12, 56, 0));
  }
 }

void loop() {
     
  for(int i=0;i<5;i++) { lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,1);
    lcd.print("                    ");
     lcd.setCursor(0,0);
      lcd.print("Place Finger");
       delay(2000); 
       int result=getFingerprintIDez();
        if(result>=0)
    {   
        now = rtc.now();

𝕸𝖆𝖘, [12/8/2024 2:44 PM]
lcd.setCursor(0,0);
        lcd.print("                    ");
        lcd.setCursor(0,1);
        lcd.print("                    ");
        lcd.setCursor(0,0);
        lcd.print("    Allowed    ");
        lcd.setCursor(0,1);
        if(finger.fingerID==1){
          
          mahdi_in=mahdi_in+1;
          mahdi_in=mahdi_in%2;
          lcd.print("                    ");
          if(mahdi_in==1){
            lcd.setCursor(0,1);
            lcd.print("welcome Mahdi!");
            lcd.setCursor(0,2);
            lcd.print("                    ");
            lcd.setCursor(0,2);
            lcd.print("Mahdi is IN!");
          
            Serial.println("Mahdi Date & Time:IN ");
            Serial.print(now.year(), DEC);
            Serial.print('/');
            Serial.print(now.month(), DEC);
            Serial.print('/');
            Serial.print(now.day(), DEC);
            Serial.print(" (");
            Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
            Serial.print(") ");
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();
            Serial.println(log_number);
            eep.update(address++, 1); // id
            eep.update(address++, 1); // in / out
            eep.update(address++, (uint8_t)(now.year()%100)); // year
            eep.update(address++, (uint8_t)(now.month())); // month
            eep.update(address++, (uint8_t)(now.day())); // day
            eep.update(address++, (uint8_t)(now.hour())); // hour
            eep.update(address++, (uint8_t)(now.minute())); // minute
            eep.update(address++, (uint8_t)(now.second())); // second
            log_number++;
            eep.update(0, log_number); // second
            if (address == eep.length()) {
              address = 0;
            }
          }
          else{
            lcd.setCursor(0,0);
            lcd.print("                    ");
            lcd.setCursor(0,0);
            lcd.print("BYE Mahdi!");
            lcd.setCursor(0,2);
            lcd.print("                    ");
            lcd.setCursor(0,2);
            lcd.print("Mahdi is OUT!");
            Serial.println("Mahdi Date & Time:OUT ");
            Serial.print(now.year(), DEC);
            Serial.print('/');
            Serial.print(now.month(), DEC);
            Serial.print('/');
            Serial.print(now.day(), DEC);
            Serial.print(" (");
            Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
            Serial.print(") ");
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();
            Serial.println(log_number);
            eep.update(address++, 1); // id
            eep.update(address++, 0); // in / out
            eep.update(address++, (uint8_t)(now.year()%100)); // year
            eep.update(address++, (uint8_t)(now.month())); // month
            eep.update(address++, (uint8_t)(now.day())); // day
            eep.update(address++, (uint8_t)(now.hour())); // hour
            eep.update(address++, (uint8_t)(now.minute())); // minute
            eep.update(address++, (uint8_t)(now.second())); // second
            log_number++;
            eep.update(0, log_number); // second
            if (address == eep.length()) {
              address = 0;
            }
          }
        }
        if(finger.fingerID==2){
          
          ali_in=ali_in+1;
          ali_in=ali_in%2;
          lcd.print("                    ");
          if(ali_in==1){
            lcd.setCursor(0,1);
            lcd.print("welcome Ali!");
            lcd.setCursor(0,3);
            lcd.print("Ali is IN!");
            Serial.println("ali Date & Time:IN ");
            Serial.print(now.year(), DEC);
            Serial.print('/');
            Serial.print(now.month(), DEC);
            Serial.print('/');

𝕸𝖆𝖘, [12/8/2024 2:44 PM]
Serial.print(now.day(), DEC);
            Serial.print(" (");
            Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
            Serial.print(") ");
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();
            Serial.println(log_number);
            eep.update(address++, 2); // id
            eep.update(address++, 1); // in / out
            eep.update(address++, (uint8_t)(now.year()%100)); // year
            eep.update(address++, (uint8_t)(now.month())); // month
            eep.update(address++, (uint8_t)(now.day())); // day
            eep.update(address++, (uint8_t)(now.hour())); // hour
            eep.update(address++, (uint8_t)(now.minute())); // minute
            eep.update(address++, (uint8_t)(now.second())); // second
            log_number++;
            eep.update(0, log_number); // second
            if (address == eep.length()) {
              address = 0;
            }
          }
          else{
            lcd.setCursor(0,0);
            lcd.print("                    ");
            lcd.setCursor(0,0);
            lcd.print("BYE Ali!");
            lcd.setCursor(0,3);
            lcd.print("Ali is OUT!");
            Serial.println("ali Date & Time:OUT ");
            Serial.print(now.year(), DEC);
            Serial.print('/');
            Serial.print(now.month(), DEC);
            Serial.print('/');
            Serial.print(now.day(), DEC);
            Serial.print(" (");
            Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
            Serial.print(") ");
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();
            Serial.println(log_number);
            eep.update(address++, 2); // id
            eep.update(address++, 0); // in / out
            eep.update(address++, (uint8_t)(now.year()%100)); // year
            eep.update(address++, (uint8_t)(now.month())); // month
            eep.update(address++, (uint8_t)(now.day())); // day
            eep.update(address++, (uint8_t)(now.hour())); // hour
            eep.update(address++, (uint8_t)(now.minute())); // minute
            eep.update(address++, (uint8_t)(now.second())); // second
            log_number++;
            eep.update(0, log_number); // second
            if (address == eep.length()) {
              address = 0;
            }
          }
        }
        
        servo.write(0);
        delay(5000);
        servo.write(180);
        delay(1000);

        lcd.setCursor(0,1);
        lcd.print("  Gate Closed   ");
        return;
     }
 
}
}
int getFingerprintIDez()
{
  uint8_t p = finger.getImage();
   
  if (p != FINGERPRINT_OK)  
  return -1;
 
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  
  return -1;
 
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)
  {
    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,1);
    lcd.print("                    ");
    lcd.setCursor(0,0);
   lcd.print("Finger Not Found");
   lcd.setCursor(0,1);
   lcd.print("Try Again");
   delay(2000);  
  return -1;
  }
  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(finger.fingerID); 
  return finger.fingerID; 
}.