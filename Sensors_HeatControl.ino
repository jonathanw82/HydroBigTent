

void Sensors() {

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Air and Humid Sensor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  temp = dht.readTemperature();
  hum = dht.readHumidity();


  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Request Water Temperature ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  if (menuEntered == 1) {}                                                              // if the Setup is open disable reading water sensor
  else {
    if (currentsensorTime - previoussensorTime > 2000 && menuEntered == 0)             // checking water temp every 10 seconds if the setup menu is not active.
    {
      previoussensorTime = currentsensorTime;
      TempCheck = 1;
      sensors.requestTemperatures();
    }
    else {
      TempCheck = 0;
    }
  }
}
void HeatMatControl ()
{
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Water Temp & Heat Mat control ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  HeatPadStatus = digitalRead(HeatMat);

  if (TempCheck == 0) {                                                                            // TempCheck is used because when the sensors.requestTemperatures() is ran sometimes for a second or two
    if (sensors.getTempCByIndex(1) < heatPadTemp && HeatPadTempSwing == 0) {     // heat mat on    // the temp sensors.getTempCByIndex() will display a minus figure making the heat mat relay change state.
      digitalWrite(HeatMat, LOW);
    }
    else if (sensors.getTempCByIndex(1) > heatPadTemp) {    // heat mat off
      digitalWrite(HeatMat, HIGH);
      HeatPadTempSwing = 1;
    }
    if (sensors.getTempCByIndex(1) < heatPadTemp - 1.00 && HeatPadTempSwing == 1) {
      HeatPadTempSwing = 0;
    }
    // temp swing is used so that when the water temperature exceeds the heatpadtemp max temp
  }                                                                                 // the water temp has to drop back past the maxtemp by 1 degree before it can turn back on to stop on/off occilations!
}
