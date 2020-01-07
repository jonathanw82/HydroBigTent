

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
      sensors.requestTemperatures();

   //   Serial.println("REQUESTING TEMP##################");
    }
    if (currentWaterTime - previousWaterTime > 1000)          // Request Temperatures every 1 seconds
    {
      previousWaterTime = currentWaterTime;
    //  Serial.println("PASSING DATA TO SENSOR VARIABLE~~~~~~~~~~~~~~~~~~");    
      SensorWater1 = sensors.getTempCByIndex(0);
      SensorWater2 = sensors.getTempCByIndex(1);
      SensorWater3 = sensors.getTempCByIndex(2);     
    }
    if(SensorWater1 == -127){}
    else{
      SensorWater1TrueRead = SensorWater1;
    }
    if(SensorWater2 == -127){}
    else{
      SensorWater2TrueRead = SensorWater2;
    }
    if(SensorWater3 == -127){}
    else{
      SensorWater3TrueRead = SensorWater3;
    }
    }  
  }
}
void HeatMatControl ()
{
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Water Temp & Heat Mat control ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  HeatPadStatus = digitalRead(HeatMat);


  if (SensorWater2TrueRead < heatPadTemp && HeatPadTempSwing == 0) {     // heat mat on
    digitalWrite(HeatMat, LOW);
  }
  else if (SensorWater2TrueRead > heatPadTemp && HeatPadTempSwing == 0) {    // heat mat off
    digitalWrite(HeatMat, HIGH);
    HeatPadTempSwing = 1;
  }
  if (SensorWater2TrueRead < heatPadTemp - 1.00 && HeatPadTempSwing == 1) {
    HeatPadTempSwing = 0;
  }
                                                                                  // temp swing is used so that when the water temperature exceeds the heatpadtemp max temp
}                                                                                 // the water temp has to drop back past the maxtemp by 1 degree before it can turn back on to stop on/off occilations!

  HeatPadTempSensor = sensors.getTempCByIndex(1);
                                                                           
    if (HeatPadTempSensor < heatPadTemp && HeatPadTempSwing == 0) {     // heat mat on   
      digitalWrite(HeatMat, LOW);
    }
    else if (HeatPadTempSensor > heatPadTemp) {    // heat mat off
      digitalWrite(HeatMat, HIGH);
      HeatPadTempSwing = 1;
    }
    if (HeatPadTempSensor < heatPadTemp - 1.00 && HeatPadTempSwing == 1) {
      HeatPadTempSwing = 0;
    }
                                                                                    // temp swing is used so that when the water temperature exceeds the heatpadtemp max temp
  }                                                                                 // the water temp has to drop back past the maxtemp by 1 degree before it can turn back on to stop on/off occilations!


