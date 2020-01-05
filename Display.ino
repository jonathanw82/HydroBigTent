

void Display() {

  if (menuEntered == 1) {}
  else {
    // ~~~~~~~~~~~~~~~~~~~~~~~~~ LCD DISPLAY DATA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 1 Screen
    if (page == 1 && menuitem == 1 && menuEntered == 0 ) {


      if (currentTime - previousTime >= 2000 && marker == 0)
      {
        previousTime = currentTime;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Hydroponics Data"));
        lcd.setCursor(0, 1);
        lcd.print(F(" By Jon Wheway"));
        marker = marker + 1;
      }

      // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TIME AND DATE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 2 Screen
      if (currentTime - previousTime >= 2000 && marker == 1)
      {
        previousTime = currentTime;
        DateTime now = rtc.now();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Time & Date"));
        lcd.setCursor(0, 1);
        if (DaylightSaving == 1) {
          if (now.hour() == 00) {
            lcd.print("00");
            lcd.print(F(":"));
            lcd.print(now.minute());
            lcd.print(F(" "));
          }
          else {
            sprintf(dateBuffer, "%02u:%02u ", now.hour() - 1, now.minute());
            lcd.print(dateBuffer);
          }
        }
        if (DaylightSaving == 0) {
          sprintf(dateBuffer, "%02u:%02u ", now.hour(), now.minute());
          lcd.print(dateBuffer);
        }
        sprintf(dateBuffer, "%02u-%02u-%04u ", now.day(), now.month(), now.year());
        lcd.print(dateBuffer);
        marker = marker + 1;
      }

      // ~~~~~~~~~~~~~~~~~~~~~~~ AIR TEMPERATURE AND HUMIDITY ~~~~~~~~~~~~~~~~~~~~~ 3 Screen

      if (currentTime - previousTime >= 4000 && marker == 2)
      {
        previousTime = currentTime;
        /*
          Serial.println("Air Temp & Humid");
          Serial.print ("C=");
          Serial.println (temp);
          Serial.print ("H=");
          Serial.print (hum);
          Serial.println("%");
        */
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Air Temp & Humid"));
        lcd.setCursor(0, 1);
        lcd.print(F("C="));
        lcd.print(temp);
        lcd.print(F("  H="));
        lcd.print(hum);
        lcd.print(F("%"));
        marker = marker + 1;
      }



      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ WATER TEMPERATURE ~~~~~~~~~~~~~~~~~~~~~~~~~~~ 4 Screen

      if (currentTime - previousTime >= 4000 && marker == 3)
      {
        previousTime = currentTime;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Temp BigTank"));
        lcd.setCursor(0, 1);
        lcd.print(F("C="));
        lcd.print(SensorWater1TrueRead);           // Why "byIndex"? You can have more than one IC on the same bus 0 refers to the first IC on the wire

        marker = marker + 1;
      }

      if (currentTime - previousTime >= 4000 && marker == 4)
      {
        previousTime = currentTime;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Temp Tank 2"));
        lcd.setCursor(0, 1);
        lcd.print(F("C="));
        lcd.print(SensorWater2TrueRead);           // Why "byIndex"? You can have more than one IC on the same bus 0 refers to the first IC on the wire

        marker = marker + 1;
      }
      if (currentTime - previousTime >= 4000 && marker == 5)
      {
        previousTime = currentTime;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Temp Tank 3"));
        lcd.setCursor(0, 1);
        lcd.print(F("C="));
        lcd.print(SensorWater3TrueRead);           // Why "byIndex"? You can have more than one IC on the same bus 0 refers to the first IC on the wire

        marker = marker + 1;
      }

      if (currentTime - previousTime >= 4000 && marker == 6)
      {
        previousTime = currentTime;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Heat Mat Status "));
        lcd.setCursor(0, 1);
        if (HeatPadStatus == 1) {
          lcd.print(F("Heat Mat Off   "));
        }
        else {
          lcd.print(F("Active!   "));
        }
        marker = marker + 1;
      }


      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Light Cycle ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 5 Screen

      if (currentTime - previousTime >= 2000 && marker == 7)
      {
        previousTime = currentTime;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("  Light Cycle"));
        lcd.setCursor(0, 1);
        if (lightingHour == 0) {
          lcd.print(F("  Light off"));
        }
        if (lightingHour == 1) {
          lcd.print(F("    12 Hour"));
        }
        if (lightingHour == 2) {
          lcd.print(F("    14 Hour"));
        }
        if (lightingHour == 3) {
          lcd.print(F("    16 Hour"));
        }
        if (lightingHour == 4) {
          lcd.print(F("    18 Hour"));
        }
        marker = marker + 1;
      }

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Light Cycle ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 6 Screen

      if (currentTime - previousTime >= 2000 && marker == 8)
      {
        previousTime = currentTime;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Light Cycle VEG"));
        lcd.setCursor(0, 1);
        if (VeglightingHour == 0) {
          lcd.print(F("Veg Light off"));
        }
        if (VeglightingHour == 1) {
          lcd.print(F("    12 Hour"));
        }
        if (VeglightingHour == 2) {
          lcd.print(F("    14 Hour"));
        }
        if (VeglightingHour == 3) {
          lcd.print(F("    16 Hour"));
        }
        if (VeglightingHour == 4) {
          lcd.print(F("    18 Hour"));
        }
        marker = marker + 1;
      }

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Watering Duration ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 7 Screen

      if (currentTime - previousTime >= 2000 && marker == 9)
      {
        previousTime = currentTime;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F(" Water Duration "));
        lcd.setCursor(3, 1);

        int waterRangemin = 5;
        int waterRangemax = 90;
        int range = map (water, waterRangemin, waterRangemax, 0, 17);

        switch (range) {
          case 0:
            lcd.print (F("5 seconds"));
            break;
          case 1:
            lcd.print (F("10 seconds"));
            break;
          case 2:
            lcd.print (F("15 seconds"));
            break;
          case 3:
            lcd.print (F("20 seconds"));
            break;
          case 4:
            lcd.print (F("25 seconds"));
            break;
          case 5:
            lcd.print (F("30 seconds"));
            break;
          case 6:
            lcd.print (F("35 seconds"));
            break;
          case 7:
            lcd.print (F("40 seconds"));
            break;
          case 8:
            lcd.print (F("45 seconds"));
            break;
          case 9:
            lcd.print (F("50 seconds"));
            break;
          case 10:
            lcd.print (F("55 seconds"));
            break;
          case 11:
            lcd.print (F("60 seconds"));
            break;
          case 12:
            lcd.print (F("65 seconds"));
            break;
          case 13:
            lcd.print (F("70 seconds"));
            break;
          case 14:
            lcd.print (F("75 seconds"));
            break;
          case 15:
            lcd.print (F("80 seconds"));
            break;
          case 16:
            lcd.print (F("85 seconds"));
            break;
          case 17:
            lcd.print (F("90 seconds"));
            break;
        }
        marker = marker + 1;
      }
      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Watering Time ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 7 Screen

      if (currentTime - previousTime >= 2000 && marker == 10)
      {
        previousTime = currentTime;
        lcd.clear();
        if (WateringTime == 0) {
          lcd.setCursor(0, 0);
          lcd.print(F("   Water Time"));
          lcd.setCursor(0, 1);
          lcd.print(F(" Auto Water Off "));
        }
        else if (WateringTime == -1) {
          lcd.setCursor(0, 0);
          lcd.print(F("   Water Time"));
          lcd.setCursor(0, 1);
          lcd.print(F("  Constant ON "));
        }
        else {
          lcd.setCursor(0, 0);
          lcd.print(F("   Water Time"));
          lcd.setCursor(5, 1);

          int wateringTimemin = 1;
          int wateringTimemax = 24;
          int rangeFORwater = map (WateringTime, wateringTimemin, wateringTimemax, 0, 23);

          switch (rangeFORwater) {
            case 0:
              lcd.print (F("1:00"));
              break;
            case 1:
              lcd.print (F("2:00"));
              break;
            case 2:
              lcd.print (F("3:00"));
              break;
            case 3:
              lcd.print (F("4:00"));
              break;
            case 4:
              lcd.print (F("5:00"));
              break;
            case 5:
              lcd.print (F("6:00"));
              break;
            case 6:
              lcd.print (F("7:00"));
              break;
            case 7:
              lcd.print (F("8:00"));
              break;
            case 8:
              lcd.print (F("9:00"));
              break;
            case 9:
              lcd.print (F("10:00"));
              break;
            case 10:
              lcd.print (F("11:00"));
              break;
            case 11:
              lcd.print (F("12:00"));
              break;
            case 12:
              lcd.print (F("13:00"));
              break;
            case 13:
              lcd.print (F("14:00"));
              break;
            case 14:
              lcd.print (F("15:00"));
              break;
            case 15:
              lcd.print (F("16:00"));
              break;
            case 16:
              lcd.print (F("17:00"));
              break;
            case 17:
              lcd.print (F("18:00"));
              break;
            case 18:
              lcd.print (F("19:00"));
              break;
            case 19:
              lcd.print (F("20:00"));
              break;
            case 20:
              lcd.print (F("21:00"));
              break;
            case 21:
              lcd.print (F("22:00"));
              break;
            case 22:
              lcd.print (F("23:00"));
              break;
            case 23:
              lcd.print (F("24:00"));
              break;

          }
        }
        marker = marker = 0;
      }
      else if (marker > 11)
      {
        marker = 0;
      }
    }
  }

  if (menuEntered == 1) {
    if (menuitem == 1) {
      menuitem = 2;
    }
  }

  if (menuitem == 2 && page == 1 && menuEntered == 1) {
    lcd.setCursor(0, 0);
    lcd.print(F("Setup           "));
    lcd.setCursor(0, 1);
    lcd.print(F("Use UP & Down   "));
  }

  if ( menuitem == 3 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Lighting time   "));
    lcd.setCursor(0, 1);
    lcd.print(F("Click to Enter  "));
  }

  if (menuitem == 3 && page == 2 && menuEntered == 1) {
    lcd.setCursor(0, 0);
    lcd.print(F("   X 12 14 16 18"));
    lcd.setCursor(0, 1);
    lcd.print(lightingHour);
    lcd.setCursor(1, 1);
    lcd.print(F("  0  1  2  3  4"));
  }
  if ( menuitem == 4 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Lighting Veg    "));
    lcd.setCursor(0, 1);
    lcd.print(F("Click to Enter  "));
  }

  if (menuitem == 4 && page == 2 && menuEntered == 1) {
    lcd.setCursor(0, 0);
    lcd.print(F("   X 12 14 16 18"));
    lcd.setCursor(0, 1);
    lcd.print(VeglightingHour);
    lcd.setCursor(1, 1);
    lcd.print(F("  0  1  2  3  4"));
  }

  if (menuitem == 5 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Water Duration  "));
    lcd.setCursor(0, 1);
    lcd.print(F("Click to Enter  "));
  }

  if (menuitem == 5 && page == 2 && menuEntered == 1)
  {

    lcd.setCursor(0, 0);
    lcd.print(F("Set Duration    "));
    lcd.setCursor(0, 1);
    lcd.print(water);
    lcd.setCursor(2, 1);
    lcd.print(F(" Seconds      "));

    if (water < 10) {
      lcd.setCursor(1, 1);
      lcd.print(F(" "));
    }

  }
  if (menuitem == 6 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Watering Time       "));
    lcd.setCursor(0, 1);
    lcd.print(F("Click to enter      "));
  }
  if (menuitem == 6 && page == 2 && menuEntered == 1)
  {

    if (WateringTime == 0)
    {
      lcd.setCursor(0, 0);
      lcd.print(F("Auto Watering   "));
      lcd.setCursor(0, 1);
      lcd.print(F("Auto OFF        "));
    }
    else if (WateringTime == -1) {
      lcd.setCursor(0, 0);
      lcd.print(F("NFT Watering    "));
      lcd.setCursor(0, 1);
      lcd.print(F("NFT ON use setup"));
    }
    else {
      lcd.setCursor(0, 0);
      lcd.print(F("Set in 24h Clock"));
      lcd.setCursor(0, 1);
      lcd.print(F("     "));

      if (WateringTime < 10) {
        lcd.setCursor(5, 1);
        lcd.print(F("0"));
        lcd.print(WateringTime);

      }
      else if (WateringTime >= 10) {
        lcd.setCursor(5, 1);
        lcd.print(WateringTime);
      }
      lcd.setCursor(7, 1);
      lcd.print(F(":00     "));
    }
  }
  if (menuitem == 7 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("NFT with Cycle  "));
    lcd.setCursor(0, 1);
    lcd.print(F("Click to setup  "));
  }
  if (menuitem == 7 && page == 2 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("NFT    ON   OFF"));
    lcd.setCursor(0, 1);
    lcd.print(F("Mins  ="));
    lcd.setCursor(7, 1);
    lcd.print(NFTrunTime);
    lcd.setCursor(9, 1);
    lcd.print(F("   "));
    lcd.setCursor(12, 1);
    lcd.print(NFTDelay);

    if (NFTrunTime < 10) {
      lcd.setCursor(7, 1);
      lcd.print("0");
      lcd.print(NFTrunTime);
    }
    if (NFTrunTime >= NFTDelay) {
      NFTrunTime -= 5;
    }
  }
  if (menuitem == 7 && page == 3 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("NFT    ON   OFF"));
    lcd.setCursor(0, 1);
    lcd.print(F("Mins   "));
    lcd.setCursor(7, 1);
    lcd.print(NFTrunTime);
    lcd.setCursor(9, 1);
    lcd.print(F("  ="));
    lcd.setCursor(12, 1);
    lcd.print(NFTDelay);

    if (NFTrunTime < 10) {
      lcd.setCursor(7, 1);
      lcd.print("0");
      lcd.print(NFTrunTime);
    }

    if (NFTDelay <= NFTrunTime ) {
      NFTDelay += 10;
    }
  }

  if (menuitem == 8 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F(" Manual Water   "));
    lcd.setCursor(0, 1);
    lcd.print(F(" Click To Enter "));
  }
  if (menuitem == 8 && page == 2 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F(" Pump On/Off    "));
    lcd.setCursor(0, 1);
    if (manWater == 1) {
      lcd.print(F(" Pump Running "));
    }
    if (manWater == 0) {
      lcd.print(F(" Pump OFF      "));
    }
  }
  if (menuitem == 9 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Daylight Saving "));
    lcd.setCursor(0, 1);
    lcd.print(F(" Click To Enter "));
  }
  if (menuitem == 9 && page == 2 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Daylight Saving  "));
    lcd.setCursor(0, 1);
    lcd.print(F("  -1 hour "));
    lcd.setCursor(10, 1);
    lcd.print(DaylightSaving);
    lcd.print(F("      "));

  }
  if (menuitem == 10 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Heat Pad Temp   "));
    lcd.setCursor(0, 1);
    lcd.print(F("Click to setup  "));
  }
  if (menuitem == 10 && page == 2 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F("HeatPad Max Temp"));
    lcd.setCursor(0, 1);
    lcd.print(F("C= "));
    lcd.setCursor(3, 1);
    lcd.print(heatPadTemp);
    lcd.setCursor(8, 1);
    lcd.print(F("        "));

    if (heatPadTemp < 10) {
      lcd.setCursor(7, 1);
      lcd.print(F(" "));
    }
  }
  if (menuitem == 11 && page == 1 && menuEntered == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(F(" To Exit Menu   "));
    lcd.setCursor(0, 1);
    lcd.print(F(" Click To Exit  "));
  }
}
