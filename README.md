<h1 align="center">
   <img src="https://github.com/jonathanw82/HydroBigTent/blob/master/hydro1.jpg" alt="Hydro image"/>
 </h1>
 

I created this Hydropoincs system out of my love of mixing technology with nature, the ability to harness the the building blocks of life to create tasty food in my dining room. This project is a work in progress but i am proud of the evolution of it.


#### The users goals of this application are:
* An easy to navigate menu
* Low power consumption
* Zero landfill
* Create great food fast

#### I think this application gives this to the user because:
* The rotery encoder is easy to use with one button click.
* The dispplay cycles through cueenrt realtime data such as temperature and humidity.
* The entire system only takes 210 watts max
* The system can user multiple types of hydroponic platforms such as, Deep water Culture, Nutrient film technique, Ebb and flow etc
* Due to the use of pool noodles, jiffy's, netcups, clay pebbles and coco, there is no rockwool so zero landfill


## Parts:
* 1x Arduino Uno (Rev3) [here](https://store.arduino.cc/arduino-uno-rev3)
* 1x RHT03 Humidity Temp Sensor [here](https://www.banggood.com/AM2302-DHT22-Temperature-And-Humidity-Sensor-Module-p-937403.html?gpla=1&gmcCountry=GB&currency=GBP&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgs&utm_content=lijing&utm_campaign=ssc-gb-all-bf11-re0323&gclid=EAIaIQobChMIgtuKq_Xl6QIVQuDtCh2hkg53EAQYBSABEgL3-PD_BwE&cur_warehouse=UK)
* 3x DS18B20 Water temp sensors [here](https://www.cricklewoodelectronics.com/Waterproof-Digital-Temperature-Probe-for-Arduino-DS18B20.html) Unfortunatly there are not the ones in use currently.
* 1x KY-040 Rotery Encoder [here](https://www.cricklewoodelectronics.com/Rotary-encoder-module-for-Arduino-KY-040.html?gclid=EAIaIQobChMIybWK-_Pl6QIVS7DtCh2XhAvKEAQYAyABEgKdBPD_BwE) 
* 1x Lcd 1602i2c Display [here](https://create.arduino.cc/projecthub/Oniichan_is_ded/lcd-i2c-tutorial-664e5a)
* 1x Real Time clock Modual [here](https://uk.banggood.com/DS3231-AT24C32-IIC-Precision-RTC-Real-Time-Clock-Memory-Module-p-1547989.html?gpla=1&gmcCountry=GB&currency=GBP&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgcs&utm_content=lijing&utm_campaign=ssc-gbg-summersale-all&utm_design=152&ad_id=358675083520&gclid=EAIaIQobChMItpGz1Pbl6QIVAWHmCh00lAPXEAQYEyABEgIt2_D_BwE&cur_warehouse=CN)
* 1x 4 channel realy [here](https://cpc.farnell.com/velleman-kit/vma400/4-channel-relay-module-for-arduino/dp/SC14419?mckv=sA419NTjI_dc|pcrid|224679642167|kword||match||plid||slid||product|SC14419|pgrid|47129782516|ptaid|pla-371255952663|&CMP=KNC-GUK-CPC-SHOPPING&gclid=EAIaIQobChMIssm7n_fl6QIVj-vtCh0o4Af9EAQYBSABEgLoQPD_BwE)
* 1x Contactor CUC20 [here](https://www.screwfix.com/p/british-general-20a-dp-contactor/6654p?_requestid=594347)
* 1x 5v 30amp Relay [here](https://robotdyn.com/relay-module-1-relay-5v-30a.html)
* 1x 240v to 110v Auto Transformer
* 1x S-150-12 Switch mode power supply [here](https://uk.rs-online.com/web/p/embedded-switch-mode-power-supplies-smps/6210663?cm_mmc=UK-PLA-DS3A-_-google-_-PLA_UK_EN_Power_Supplies_%26_Transformers_Whoop-_-Embedded+Switch+Mode+Power+Supplies+(SMPS)_Whoop-_-6210663&matchtype=&pla-475399700067&gclid=EAIaIQobChMIk967q_rl6QIVjO7tCh3r8AJ4EAQYASABEgLKf_D_BwE&gclsrc=aw.ds)
* 1x RD-65A Switch mode power supply [here](https://uk.rs-online.com/web/p/embedded-switch-mode-power-supplies-smps/6447102/?relevancy-data=636F3D3126696E3D4931384E53656172636847656E65726963266C753D656E266D6D3D6D61746368616C6C7061727469616C26706D3D5E5B5C707B4C7D5C707B4E647D2D2C2F255C2E5D2B2426706F3D31333326736E3D592673723D2673743D4B4559574F52445F53494E474C455F414C5048415F4E554D455249432673633D592677633D4E4F4E45267573743D72642D363561267374613D72642D36356126&searchHistory=%7B%22enabled%22%3Atrue%7D)


## Features:
* Rotery encoder for navigation
* Lcd display for easy and real time data
* Realtime clock
* Led lights
* Silent running cooling fans
* Large quiet extractor fan
* Silent running circulation fans
* Quiet air pump


### Nice to have: 
These features may be included in future releases of this application.
* Digital Extraction fans
* Higher power led lighting
* Air conditioning
* Water cooler


## Bugs & ongoing fixes
* The rotary encoder can be laggy and need quite q few revolutions to get get to where the user needs to be in the menu.
* The water temp sensors are cheap and there output is erratic this can cause the heater mat relays to chatter if the target temperature is close. To get around this I have added if statments to look to see if the temperature being read is equal to -127 (-127 meaning no output) in future realeses I will get better quality sensors.




### Credits:





##### Media:
