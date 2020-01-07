void NFT() {
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NFT Pump Control ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  if (currentTime - previousTime >= NFTrunInterval)
  {
    previousTime = currentTime;
    digitalWrite (pumpPin, LOW);
  }
  
  if (currentTime - previousTime >= NFTDelayPause)
  {
    previousTime = currentTime;
    digitalWrite (pumpPin, HIGH);
  }
}

void WaterPump() {
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Manual Water ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  if (manWater == 0 && menuEntered == 1)
  {
    digitalWrite (pumpPin, HIGH);
    //  Serial.println(" Manual Water Pump OFF");
  }
  if (manWater == 1 && menuEntered == 1)
  {
    digitalWrite (pumpPin, LOW);
    // Serial.println(" Manual Water Pump ON");
  }



  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Water Pump Relay Times ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // so 8pm is 20*60*60 =72000 + 0 minutes times 60 (=0) + 30 seconds = 72030
  pumpState = pumpHour2 + (pumpMinute + pumpSecond);                            // as One hour is equal to 60 x 60 = 3600 seconds.
  // Serial.println (pumpState);                                                // so for 6am and the pump to run for 30 seconds.

  int waterTimeingsMIN = 1;
  int waterTimeingsMAX = 25;
  int waterTimeings = map (WateringTime, waterTimeingsMIN, waterTimeingsMAX, 0, 26);

  if (menuEntered == 1) {}                                                      // if the Setup is open disable reading watering times
  else {

    switch (waterTimeings) {
      case 0:
        if (pumpState >= 3600  && pumpState < 3600 + water) {                     // 60 =1am
          digitalWrite (pumpPin, LOW);
          //  Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          // Serial.println("Water Pump OFF");
        }
        break;
      case 1:
        if (pumpState >= 7200  && pumpState < 7200 + water) {                     // 120 = 2 am
          digitalWrite (pumpPin, LOW);
          //  Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          //  Serial.println("Water Pump OFF");
        }
        break;
      case 2:
        if (pumpState >= 10800  && pumpState < 10800 + water) {                   // 180 = 3am
          digitalWrite (pumpPin, LOW);
          //  Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          //  Serial.println("Water Pump OFF");
        }
        break;
      case 3:
        if (pumpState >= 14400  && pumpState < 14400 + water) {                  // 240 =4 am
          digitalWrite (pumpPin, LOW);
          //  Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          //  Serial.println("Water Pump OFF");
        }
        break;
      case 4:
        if (pumpState >= 18000  && pumpState < 18000 + water) {                 //  300 =8am
          digitalWrite (pumpPin, LOW);
          // Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          // Serial.println("Water Pump OFF");
        }
        break;
      case 5:
        if (pumpState >= 21600  && pumpState < 21600 + water) {                   //360 = 6am
          digitalWrite (pumpPin, LOW);
          // Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          // Serial.println("Water Pump OFF");
        }
        break;
      case 6:
        if (pumpState >= 25200  && pumpState < 25200 + water) {                    // 420 = 7am
          digitalWrite (pumpPin, LOW);
          // Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          //  Serial.println("Water Pump OFF");
        }
        break;
      case 7:
        if (pumpState >= 28800  && pumpState < 28800 + water) {                   // 480 = 8am
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 8:
        if (pumpState >= 32400  && pumpState < 32400 + water) {                     // 540 = 9am
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 9:
        if (pumpState >= 36000  && pumpState < 36000 + water) {                     // 600 =10am
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 10:
        if (pumpState >= 39600  && pumpState < 39600 + water) {                     // 660 = 11am
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 11:
        if (pumpState >= 43200  && pumpState < 43200 + water) {                      // 720 = 12 pm
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 12:
        if (pumpState >= 46800  && pumpState < 46800 + water) {                     // 780 = 13:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 13:
        if (pumpState >= 50400  && pumpState < 50400 + water) {                     // 840 = 14:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 14:
        if (pumpState >= 54000  && pumpState < 54000 + water) {                      // 900 =15:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 15:
        if (pumpState >= 57600  && pumpState < 57600 + water) {                     //  960 =16:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 16:
        if (pumpState >= 61200  && pumpState < 61200 + water) {                     // 1020 = 17:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 17:
        if (pumpState >= 64800  && pumpState < 64800 + water) {                     // 1080 = 18:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 18:
        if (pumpState >= 68400  && pumpState < 68400 + water) {                     // 1140 = 19:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 19:
        if (pumpState >= 72000  && pumpState < 72000 + water) {                     // 1200 = 20:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 20:
        if (pumpState >= 75600  && pumpState < 75600 + water) {                     // 1260 = 21:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 21:
        if (pumpState >= 79200  && pumpState < 79200 + water) {                     // 1320 = 22:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 22:
        if (pumpState >= 82800  && pumpState < 82800 + water) {                     // 1380 = 23:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 23:
        if (pumpState >= 86400  && pumpState < 86400 + water) {                     // 1440 = 24:00
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        else {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 24:
        if (WateringTime == 0)
        {
          digitalWrite (pumpPin, HIGH);
          Serial.println("Water Pump OFF");
        }
        break;
      case 25:
        if (WateringTime == -1)
        {
          digitalWrite (pumpPin, LOW);
          Serial.println("Water Pump ON");
        }
        break;
      case 26:
        if (WateringTime == -2)
        {
          NFT();
        }
    }
  }
}
