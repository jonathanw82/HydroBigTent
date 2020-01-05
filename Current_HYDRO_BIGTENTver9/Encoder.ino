
void readRotaryEncoder()
{
  if (menuEntered == 1) {

    value += encoder->getValue();

    if (value / 2 > last) {
      last = value / 2;
      down = true;
      if (currentTime - previousTime >= 50) {
        previousTime = currentTime;
      }
    } else   if (value / 2 < last) {
      last = value / 2;
      up = true;
      if (currentTime - previousTime >= 50) {
        previousTime = currentTime;
      }
    }
  }

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Encoder Timer ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void timerIsr() {
  encoder->service();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ROTATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void EncoderRotation() {

  if (up && page == 1 && menuEntered == 1 ) {       //~~~~~~~~~~~ We have turned the Rotary Encoder Anti Clockwise
    up = false;

    if (menuitem == 1)
    {
      menuitem == 2;
    }
    if (menuitem == 2)
    {
      menuitem == 3;
    }
    if (menuitem == 3)
    {
      menuitem == 4;
    }
    if (menuitem == 4)
    {
      menuitem == 5;
    }
    if (menuitem == 5)
    {
      menuitem == 6;
    }
    if (menuitem == 6)
    {
      menuitem == 7;
    }
    if (menuitem == 7)
    {
      menuitem == 8;
    }
    if (menuitem == 8)
    {
      menuitem == 9;
    }
    if (menuitem == 9)
    {
      menuitem == 10;
    }
    if (menuitem == 10)
    {
      menuitem == 11;
    }
    if (menuitem == 11)
    {
      menuitem == 12;
    }
    lastMenuItem = menuitem;
    menuitem--;

    if (menuitem <= 0)
    {
      menuitem = 1;
    }
  } else if (up && menuitem == 3 && enter == 1 && page == 2 &&  menuEntered == 1) {
    up = false;
    lightingHour--;
    EEPROM.put(0, lightingHour);

  } else if (up && menuitem == 4 && enter == 1 && page == 2 &&  menuEntered == 1) {
    up = false;
    VeglightingHour--;
    EEPROM.put(24, VeglightingHour);

  }
  else if (up && menuitem == 5 && enter == 1 && page == 2 && menuEntered == 1 ) {
    up = false;
    water -= 5;
    EEPROM.put(8, water);

  }
  else if (up && menuitem == 6 && enter == 1 && page == 2 && menuEntered == 1) {
    up = false;
    WateringTime--;
    EEPROM.put(16, WateringTime);

  }
  else if  (up && menuitem == 7 && enter == 1 && page == 2 && menuEntered == 1) {
    up = false;
    NFTrunTime -= 5;
    EEPROM.put(32, NFTrunTime);
  }
  else if  (up && menuitem == 7 && enter == 1 && page == 3 && menuEntered == 1) {
    up = false;
    NFTDelay -= 10;
    EEPROM.put(40, NFTDelay);
  }
  else if (up && menuitem == 8 && enter == 1 && page == 2 && menuEntered == 1) {
    up = false;
    manWater--;
  }
  else if  (up && menuitem == 9 && enter == 1 && page == 2 && menuEntered == 1) {
    up = false;
    DaylightSaving --;
    EEPROM.put(48, DaylightSaving);
  }
  else if  (up && menuitem == 10 && enter == 1 && page == 2 && menuEntered == 1) {
    up = false;
    heatPadTemp --;
    EEPROM.put(54, heatPadTemp);
  }
  if (down && page == 1 && menuEntered == 1) //~~~~~~~~~~~~~~~~~~~~ We have turned the Rotary Encoder Clockwise
  {

    down = false;

    if (down && menuitem == 3 && lastMenuItem == 2) {
      menuitem++;

    }
    else if (down && menuitem == 4 && lastMenuItem == 3) {
      menuitem++;

    }
    else if (down && menuitem == 5 &&  lastMenuItem == 4) {
      menuitem++;

    }
    else if (down && menuitem == 6 && lastMenuItem == 5) {
      menuitem++;

    }
    else if (down && menuitem == 7 && lastMenuItem == 6) {
      menuitem++;

    }
    else if (down && menuitem == 8 && lastMenuItem == 7) {
      menuitem++;
    }

    else if (down && menuitem == 9 && lastMenuItem == 8) {
      menuitem++;
    }

    else if (down && menuitem == 10 && lastMenuItem == 9) {
      menuitem++;
    }

    else if (down && menuitem == 11 && lastMenuItem == 10) {
      menuitem++;
    }
    lastMenuItem = menuitem;
    menuitem++;

    if (menuitem >= 12)
    {
      menuitem = 11;
    }
  }
  else if (down && menuitem == 3 && enter == 1 && page == 2 && menuEntered == 1) {
    down = false;
    lightingHour++;
    EEPROM.put(0, lightingHour);
  }

  if (lightingHour > 4) {
    lightingHour = 4;
  }
  else if (lightingHour < 0) {
    lightingHour = 0;
  }
  else if (down && menuitem == 4 && enter == 1 && page == 2 && menuEntered == 1) {
    down = false;
    VeglightingHour++;
    EEPROM.put(24, VeglightingHour);
  }

  if (VeglightingHour > 4) {
    VeglightingHour = 4;
  }
  else if (VeglightingHour < 0) {
    VeglightingHour = 0;
  }

  else if (down && menuitem == 5 && enter == 1 && page == 2 && menuEntered == 1 ) {
    down = false;
    water += 5;
    EEPROM.put(8, water);
  }
  if (water > 90) {
    water = 90;
  }
  else if (water < 5) {
    water = 5;
  }

  else if (down && menuitem == 6 && enter == 1 && page == 2 && menuEntered == 1) {
    down = false;
    WateringTime ++;
    EEPROM.put(16, WateringTime);
  }
  if (WateringTime > 24) {
    WateringTime = 24;
  }
  else if (WateringTime < -1) {
    WateringTime = -1;
  }
  else if (down && menuitem == 7 && enter == 1 && page == 2 && menuEntered == 1) {
    down = false;
    NFTrunTime += 5;
    EEPROM.put(32, NFTrunTime);
  }
  if (NFTrunTime < 5) {
    NFTrunTime = 5;
  }
  else if (NFTrunTime >= 50) {
    NFTrunTime = 50;
  }
  else if (down && menuitem == 7 && enter == 1 && page == 3 && menuEntered == 1) {
    down = false;
    NFTDelay += 10;
    EEPROM.put(40, NFTDelay);
  }
  if (NFTDelay < 10) {
    NFTDelay = 10;
  }
  else if (NFTDelay >= 60) {
    NFTDelay = 60;
  }

  else if (down && menuitem == 8 && enter == 1 && page == 2 && menuEntered == 1 ) {
    down = false;
    manWater ++;
  }
  if (manWater > 1) {
    manWater = 1;
  }
  else if (manWater < 0) {
    manWater = 0;
  }
  else if (down && menuitem == 9 && enter == 1 && page == 2 && menuEntered == 1) {
    down = false;
    DaylightSaving ++;
    EEPROM.put(48, DaylightSaving);
  }
  if (DaylightSaving < 0) {
    DaylightSaving = 0;
  }
  else if (DaylightSaving > 1) {
    DaylightSaving = 1;
  }
  else if  (down && menuitem == 10 && enter == 1 && page == 2 && menuEntered == 1) {
    down = false;
    heatPadTemp ++;
    EEPROM.put(54, heatPadTemp);
  }
    if (heatPadTemp < 0) {
    heatPadTemp = 0;
  }
  else if (heatPadTemp > 25) {
    heatPadTemp = 25;
  }

}
