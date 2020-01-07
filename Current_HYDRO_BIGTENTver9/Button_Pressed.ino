
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Enter Pressed ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ButonPressed() {

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Click button for encoder ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
    switch (b) {
      case ClickEncoder::Clicked:
        middle = true;
        break;
      case ClickEncoder::Held:
        ButReset = true;
        break;
      case ClickEncoder::DoubleClicked:
        break;
    }
  }


  if (middle) //Middle Button is Pressed
  {
    middle = false;
    if (page == 1 && menuitem == 1)
    {
      middle = false;
      menuEntered ++;                                       // menuEntered allows the program to only have one button to enter exit things
      lcd.clear();                                          // so when program is running it can exit to setup via menueEntered also have menuitem++ to forward the next menuitem
      menuitem = 2;
      value = 0;
    }
    if (page == 1 && menuitem == 3 && menuEntered == 1)
    {
      middle = false;
      page ++;
      enter++;
    }
    else if (page == 2 && menuitem == 3 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page --;
      enter --;

    }

    if (page == 1 && menuitem == 4 && menuEntered == 1)
    {
      middle = false;
      page ++;
      enter++;
    }
    else if (page == 2 && menuitem == 4 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page --;
      enter --;

    }
    if (page == 1 && menuitem == 5 && menuEntered == 1)
    {
      middle = false;
      page ++;
      enter++;
    }
    else if (page == 2 && menuitem == 5 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page --;
      enter --;

    }
    if (page == 1 && menuitem == 6 && menuEntered == 1)
    {
      middle = false;
      page ++;
      enter++;
    }
    else if (page == 2 && menuitem == 6 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page --;
      enter --;
    }
    if (page == 1 && menuitem == 7 && menuEntered == 1)
    {
      middle = false;
      page ++;
      enter ++;
    }
    else if (page == 2 && menuitem == 7 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page ++;
    }
    else if (page == 3 && menuitem == 7 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page = 1;
      enter --;
    }
    if (page == 1 && menuitem == 8 && menuEntered == 1)
    {
      middle = false;
      page ++;
      enter++;
    }
    else if (page == 2 && menuitem == 8 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page --;
      enter --;
      manWater = 0;

    }
    if (page == 1 && menuitem == 9 && menuEntered == 1)
    {
      middle = false;
      page ++;
      enter++;
    }
    else if (page == 2 && menuitem == 9 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page --;
      enter --;

    }
    if (page == 1 && menuitem == 10 && menuEntered == 1)
    {
      middle = false;
      page ++;
      enter ++;
    }
    else if (page == 2 && menuitem == 10 && enter == 1 && menuEntered == 1)
    {
      middle = false;
      page --;
      enter --;
    }

    if (page == 1 && menuitem == 11 && menuEntered == 1)
    {
      middle = false;
      page = 1;
      enter --;
      menuEntered = 0;
      menuitem = 1;
      lcd.clear();
      value = 0;

    }

  }
}
