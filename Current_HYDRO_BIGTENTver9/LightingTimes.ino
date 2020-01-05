

void LightingTime() {
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ lighting RELAY ACTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  int lightingHourMin = 1;
  int lightingHourMax = 4;
  int range = map (lightingHour, lightingHourMin, lightingHourMax, 0, 3);

  if (lightingHour == 0) {
    digitalWrite (bulblightingPin, HIGH);
  }
  else {
    switch (range) {

      case 0:
        if (lampState >= 360 && lampState < 1080) {              // 12 hour
          digitalWrite (bulblightingPin, LOW);
        }
        else {
          digitalWrite (bulblightingPin, HIGH);
        }
        break;
      case 1:
        if (lampState >= 360 && lampState < 1200) {              // 14 hour
          digitalWrite (bulblightingPin, LOW);
        }
        else {
          digitalWrite (bulblightingPin, HIGH);
        }
        break;
      case 2:
        if (lampState >= 360 && lampState < 1320) {              // 16 hour
          digitalWrite (bulblightingPin, LOW);
        }
        else {
          digitalWrite (bulblightingPin, HIGH);

        }
        break;
      case 3:
        if (lampState >= 360 && lampState < 1440) {               // 18 hour
          digitalWrite (bulblightingPin, LOW);
        }
        else {
          //digitalWrite (lightingPin, LOW);
          digitalWrite (bulblightingPin, HIGH);

        }
        break;
    }
  }
  // Hour times it by 60 add the minutes, Clock cannot roll over so 12am following pm will not work
  // 18 hour cycle 6am = 360 12pm = 1440
  // 16 hour cycle 6am = 360 10pm = 1320
  // 14 hour cycle 6am = 360 8pm = 1200
  // 12 hour cycle 6am = 360 6pm = 1080

}



void VEGLightingTime() {
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ lighting VEG ACTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  int VeglightingHourMin = 1;
  int VeglightingHourMax = 4;
  int range = map (VeglightingHour, VeglightingHourMin, VeglightingHourMax, 0, 3);

  if (VeglightingHour == 0) {
    digitalWrite (lightingPin, LOW);
   
  }
  else {
    switch (range) {

      case 0:
        if (VeglampState >= 360 && VeglampState < 1080) {              // 12 hour
          digitalWrite (lightingPin, HIGH);
        }
        else {
          digitalWrite (lightingPin, LOW);
        }
        break;
      case 1:
        if (VeglampState >= 360 && VeglampState < 1200) {              // 14 hour
          digitalWrite (lightingPin, HIGH);
        }
        else {
          digitalWrite (lightingPin, LOW);
        }
        break;
      case 2:
        if (VeglampState >= 360 && VeglampState < 1320) {              // 16 hour
          digitalWrite (lightingPin, HIGH);
        }
        else {
          digitalWrite (lightingPin, LOW);
        }
        break;
      case 3:
        if (VeglampState >= 360 && VeglampState < 1440) {               // 18 hour
          digitalWrite (lightingPin, HIGH);
        }
        else {
          digitalWrite (lightingPin, LOW);
        }
        break;
    }
  }

  // Hour times it by 60 add the minutes, Clock cannot roll over so 12am following pm will not work
  // 18 hour cycle 6am = 360 12pm = 1440
  // 16 hour cycle 6am = 360 10pm = 1320
  // 14 hour cycle 6am = 360 8pm = 1200
  // 12 hour cycle 6am = 360 6pm = 1080

}
