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
1x RK100 Can-fan [here](http://www.canfan.nl/cfrk100.html)
1x Acoustic air ducting [here](https://www.electrical2go.co.uk/insulated-aluminium-ducting-100mm-x-10m-fxalins-100.html?utm_source=google_shopping&gclid=EAIaIQobChMIhP-7jf_l6QIVmKztCh2FawO8EAQYBSABEgJEyvD_BwE)
1x Grow tent
1x Eheim air pump 400 [here](https://www.eheim.com/en_GB/products/technology/air-pumps/air-400)
6x golf ball air stones and pipe.
25x growsun 3w Full spaectrum 380nm-840nm Led Chips [here](https://www.banggood.com/3W-380nm-840nm-Full-Spectrum-LED-Plant-Grow-Light-Chip-for-Garden-3_0-3_4V-p-1060934.html?rmmds=search&cur_warehouse=CN)
15x High Power Led Chip 3W Cool White 3000K-3500K chips [here](https://www.lightinthebox.com/en/p/diy-3w-high-power-220-240lm-warm-white-light-led-module-3-2-3-6v-15pcs_p1549727.html?currency=GBP&litb_from=paid_adwords_shopping&country_code=gb&utm_source=google_shopping&utm_medium=cpc&adword_mt=&adword_ct=412206506589&adword_kw=&adword_pos=&adword_pl=&adword_net=u&adword_tar=&adw_src_id=3516490533_8950463197_93145555187_pla-861857501271&gclid=EAIaIQobChMI5uOt_P_l6QIVW-ztCh0_fAEAEAkYBSABEgL1ffD_BwE)
3x Noise Blocker 120mm fans [here](https://www.blacknoise.com/site/en/products/noiseblocker-it-fans/nb-eloop-series/120x120x25mm.php?lang=EN)


## Recycled parts:
* 1x 240v to 110v Auto Transformer [here](https://mcitransformer.com/product/mci-4-49-series/) From an old video game.
* 1x S-150-12 Switch mode power supply [here](https://uk.rs-online.com/web/p/embedded-switch-mode-power-supplies-smps/6210663?cm_mmc=UK-PLA-DS3A-_-google-_-PLA_UK_EN_Power_Supplies_%26_Transformers_Whoop-_-Embedded+Switch+Mode+Power+Supplies+(SMPS)_Whoop-_-6210663&matchtype=&pla-475399700067&gclid=EAIaIQobChMIk967q_rl6QIVjO7tCh3r8AJ4EAQYASABEgLKf_D_BwE&gclsrc=aw.ds) from an old video game.
* 1x RD-65A Switch mode power supply [here](https://uk.rs-online.com/web/p/embedded-switch-mode-power-supplies-smps/6447102/?relevancy-data=636F3D3126696E3D4931384E53656172636847656E65726963266C753D656E266D6D3D6D61746368616C6C7061727469616C26706D3D5E5B5C707B4C7D5C707B4E647D2D2C2F255C2E5D2B2426706F3D31333326736E3D592673723D2673743D4B4559574F52445F53494E474C455F414C5048415F4E554D455249432673633D592677633D4E4F4E45267573743D72642D363561267374613D72642D36356126&searchHistory=%7B%22enabled%22%3Atrue%7D) From an old video game.
* 1x Aluminium sheet from contoll unit of a screap 2 penny pusher.
* 1x Heatsink from an old sega daytona graphics card.
* 2x storage boxes.
* Variouse other parts


## Features:
* Rotery encoder for navigation
* Lcd display for easy and real time data
* Realtime clock
* Led lights
* Silent running cooling fans
* Large quiet extractor fan
* Silent running circulation fans
* Quiet air pump

## Lighting
The lighting panel has evolved somewhat during construction. The first version only had the Growsun led grow lights giving a pink colour due to the colour spectrum from blue 320nm and the red 840nm with nothing much else, while plants did grow I found they became leggy and unable to hold their own weight. 
<h4 align="center">
   <img src="https://github.com/jonathanw82/HydroBigTent/blob/master/hydro1.jpg" alt="Hydro image"/>
 </h4>
After some time goggling, I found that even though plants don’t need yellow and green light for photosynthesis , there is some debate around whether green light help the plant push toxins out of the leaves, I have no clue if this is true however I decided to add some warm white leds in to mix it up however due to the wavelengths favouring the  red end of the spectrum, the plats stared to bolt early. At this point I changed them for cool white leds, the difference was amazing and the plants shot into life, woodier stems and healthy looking leaves.

### Nice to have: 
These features may be included in future releases of this application.
* Digital Extraction fans
* Higher power led lighting
* Air conditioning
* Water cooler


## Bugs & ongoing fixes
* The rotary encoder can be laggy and need quite q few revolutions to get get to where the user needs to be in the menu.
* The water temp sensors are cheap and there output is erratic this can cause the heater mat relays to chatter if the target temperature is close. To get around this I have added if statments to look to see if the temperature being read is equal to -127 (-127 meaning no output) in future realeses I will get better quality sensors.

## 


### Credits:





##### Media:

Images of light wave lengths
https://thegreensunshineco.com/think-beyond-white-led-and-bulb-grow-lights-kelvin-and-color-temperature/

Image of Full spectrum wave length
https://futureeden.co.uk/
