#include <DS3232RTC.h> //http://github.com/JChristensen/DS3232RTC
#include <Time.h>

#include <Wire.h> 

#define BUZZER_PIN 11

// Refresh time
unsigned long previousMillis = 0;
int blinkState = 1;
const long interval = 250;
int previousSecond = 0;

void setup()
{
  Serial.begin(9600, SERIAL_8O1); // era beginSerial
  Wire.begin();

  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  //setTime(23, 35, 30, 13, 11, 2015);   //set the system time to 23h31m30s on 13Feb2009
  //RTC.set(now());                   //set the RTC from the system time
  //    if(timeStatus() != timeSet)
  //        Serial.println("Unable to sync with the RTC");
  //    else
  //        Serial.println("RTC has set the system time");

  DeleteDisplayVFD();
  Serial.write(0x1B);//Country Code
  Serial.write(0x52);//
  Serial.write(0x32);//Latin 2
  PositionCursorVFD(2, 1);
  Serial.print("Test FVD :)");
  Serial.write(0x03);
  delay(1000);
  
  DeleteDisplayVFD();
}

void loop()
{
  if (second() != previousSecond) { //Update VFD
    previousSecond = second();
    PositionCursorVFD(1, 1);
    BigTime(hour(), minute(), second(), 0);
    printDate(year(), month(), day(), 0);
  }
  //delay(50);
  SetTime();
}

void blinkBlink(int blinkPoz) {
  if (blinkPoz != 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (blinkState == 1) blinkState = 0;
      else blinkState = 1;
    }
  } else blinkState = 1;
}
