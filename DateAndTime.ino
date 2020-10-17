void SetTime() {
  if (getButton() == 5) {

    while (getButton() == 5) {}
    tone(11, 2637, 200);
    int iHour = hour();
    int iMinute = minute();
    int iSecond = second();
    int iYear = year();
    int iMonth = month();
    int iDay = day();

    int position = 1;
    while (getButton() != 5) {
      //tone(11,2637,200);
      //delay(1000);

      if (getButton() == 1) { //left (position)
        if (position == 0) position = 6;
        else position = position - 1;
        while (getButton() == 1) {} //waiting for the button to be released
      }
      if (getButton() == 4) { //right (position)
        if (position == 6) position = 0;
        else position = position + 1;
        while (getButton() == 4) {} //waiting for the button to be released
      }

      if (getButton() == 2) { //up
        if (position == 1) {
          if (iHour == 23) iHour = 1;
          else iHour = iHour + 1;
        }
        if (position == 2) {
          if (iMinute == 59) iMinute = 0;
          else iMinute = iMinute + 1;
        }
        if (position == 3) {
          if (iSecond == 59) iSecond = 0;
          else iSecond = iSecond + 1;
        }
        if (position == 4) {
          if (iYear == 2050) iYear = 2015;
          else iYear = iYear + 1;
        }
        if (position == 5) {
          if (iMonth == 12) iMonth = 1;
          else iMonth = iMonth + 1;
        }
        if (position == 6) {
          if (iDay == 31) iDay = 1;
          else iDay = iDay + 1;
        }
        while (getButton() == 2) {} //waiting for the button to be released
      }
      if (getButton() == 3) { //down
        if (position == 1) {
          if (iHour == 1) iHour = 23;
          else iHour = iHour - 1;
        }
        if (position == 2) {
          if (iMinute == 0) iMinute = 59;
          else iMinute = iMinute - 1;
        }
        if (position == 3) {
          if (iSecond == 0) iSecond = 59;
          else iSecond = iSecond - 1;
        }
        if (position == 4) {
          if (iYear == 2015) iYear = 2050;
          else iYear = iYear - 1;
        }
        if (position == 5) {
          if (iMonth == 1) iMonth = 12;
          else iMonth = iMonth - 1;
        }
        if (position == 6) {
          if (iDay == 1) iDay = 31;
          else iDay = iDay - 1;
        }
        while (getButton() == 3) {} //waiting for the button to be released
      }

      BigTime(iHour, iMinute, iSecond, position);
      printDate(iYear, iMonth, iDay, position);
    }
    while (getButton() == 5) {} //waiting for the button to be released
    if (position == 0) {
      setTime(iHour, iMinute, iSecond, iDay, iMonth, iYear);
      RTC.set(now());
      tone(11, 2637, 200);
    }
  }
}

void BigTime(int iHour, int iMinute, int iSecond, int blinkPos) //BIG clock!!!
{
  byte iHour1 = iHour / 10;
  byte iHour2 = iHour - iHour1 * 10;

  byte iMinute1 = iMinute / 10;
  byte iMinute2 = iMinute - iMinute1 * 10;

  blinkBlink(blinkPos); //blinking if blinkPos different from 0

  if (blinkState == 0 && blinkPos == 1) {
    BigClock(-1, 1);
    BigClock(-1, 5);
  } else {
    BigClock(iHour1, 1);
    BigClock(iHour2, 5);
  }

  PositionCursorVFD(2, 9);
  Serial.write(0x3A); //colon
  if (blinkState == 0 && blinkPos == 2) {
    BigClock(-1, 11);
    BigClock(-1, 15);
  } else {
    BigClock(iMinute1, 11);
    BigClock(iMinute2, 15);
  }

  PositionCursorVFD(3, 19);
  // Serial.write(0x3A);
  if (blinkState == 0 && blinkPos == 3) {
    Serial.write(0xFF);
    Serial.write(0xFF);
  } else {
    if (iSecond < 10) {
      Serial.print(0, DEC);
    };
    Serial.print(iSecond, DEC);
  }
}

void printDate(int iYear, int iMonth, int iDay, int blinkPos) {
  blinkBlink(blinkPos);
  PositionCursorVFD(4, 1);
  //Serial.write(0xF8);
  if (blinkState == 0 && blinkPos == 4) {
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  } else Serial.print(iYear);
  Serial.print("-");
  if (blinkState == 0 && blinkPos == 5) {
    Serial.write(0xFF);
    Serial.write(0xFF);
  } else {
    if (iMonth < 10) {
      Serial.print(0, DEC);
    };
    Serial.print(iMonth);
  }
  Serial.print("-");
  if (blinkState == 0 && blinkPos == 6) {
    Serial.write(0xFF);
    Serial.write(0xFF);
  } else {
    if (iDay < 10) {
      Serial.print(0, DEC);
    };
    Serial.print(iDay);
  }
}
