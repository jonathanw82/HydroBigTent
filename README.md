<h1 align="center">
   <img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/hydro1.jpg" alt="Hydro image"/>
 </h1>
 
## Hydroponics
I created this Hydropoincs system out of my love of mixing technology with nature, the ability to harness the the building blocks of life to create tasty food in my dining room. This project is a work in progress but i am proud of the evolution of it.

The heart of the system is an arduino Uno, connected to a real-time clock module, an lcd display and a rotary encoder. The arduino works out to points in time and whether the lights should be on or off depending where it is between these time cycles, even if the power has dropped out during the cycle. It also monitors water temperature and turns on heat mats if the water temperature is below its designated temperature. Whilst also keeping an eye on the time in case watering intervals have been reached and turn pumps on if so. The system can handle NFT and Ebb and flow style systems.
During the creation of the system I have made it able to have 2 tents with 2 individual lights that can be set to their own time cycles.
The incorporation of a menu system and using EEprom to save settings was also implemented at this time. 

When I first created the system, I originally used a compact florescent light, but I found if chews too much power to lumen ratio, I also tried to run the lights of a solid state relay however being florescent, the solid state relay made if flicker even when it was off, due to the way solid state relay have a small but normal current flow through them that slowly charges up the capacitors in the florescent bulbs ballast, when they get to their minimum stating voltage the bulb with try to start but then die back dimply. To get round this, I used a standard relay, but due to the inrush current being 100+ times the operating current, the florescent bulb would fuse the relay terminals together not allowing the bulb to turn off, I even tried putting a snubber across the terminals but to no avail.  At this point I decided to go with a contactor as it is rated at well over any spike in current the bulb could produce. Soon after, the florescent was replaced with the led bulbs in the second lighting fixture created out of individual bulbs that can be added or removed depending on how with light intensity I needed for that particular application. More on lighting can be found here [Lighting](#lighting)


#### The users goals of this system are:
* An easy to navigate menu
* Low power consumption
* Zero landfill
* Create great food fast


#### I think this system gives this to the user because:
* The rotery encoder is easy to use with one button click.
* The display cycles through current realtime data such as temperature and humidity.
* The entire system only takes 210 watts max.
* The system can user multiple types of hydroponic platforms such as, Deep water Culture, Nutrient film technique, Ebb and flow etc.
* Due to the use of pool noodles, jiffy's, netcups, clay pebbles and coco, there is no rockwool so zero landfill.

 
 ## Features:
* Rotery encoder for navigation
* Lcd display for easy and real time data
* Realtime clock
* Led lights
* Silent running cooling fans
* Large quiet extractor fan [goto](#air-extraction)
* Silent running circulation fans
* Quiet air pump [goto](#air-pumps)
 
<div align="center">
   <img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/hydro_schem.jpg" alt="wireing diagram"/></div>
 
 
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
* 1x RK100 Can-fan [here](http://www.canfan.nl/cfrk100.html)
* 1x Acoustic air ducting [here](https://www.electrical2go.co.uk/insulated-aluminium-ducting-100mm-x-10m-fxalins-100.html?utm_source=google_shopping&gclid=EAIaIQobChMIhP-7jf_l6QIVmKztCh2FawO8EAQYBSABEgJEyvD_BwE)
* 1x Grow tent
* 1x Eheim air pump 400 [here](https://www.eheim.com/en_GB/products/technology/air-pumps/air-400)
* 6x golf ball air stones and pipe.
* 25x growsun 3w Full spaectrum 380nm-840nm Led Chips [here](https://www.banggood.com/3W-380nm-840nm-Full-Spectrum-LED-Plant-Grow-Light-Chip-for-Garden-3_0-3_4V-p-1060934.html?rmmds=search&cur_warehouse=CN)
* 15x High Power Led Chip 3W Cool White 3000K-3500K chips [here](https://www.lightinthebox.com/en/p/diy-3w-high-power-220-240lm-warm-white-light-led-module-3-2-3-6v-15pcs_p1549727.html?currency=GBP&litb_from=paid_adwords_shopping&country_code=gb&utm_source=google_shopping&utm_medium=cpc&adword_mt=&adword_ct=412206506589&adword_kw=&adword_pos=&adword_pl=&adword_net=u&adword_tar=&adw_src_id=3516490533_8950463197_93145555187_pla-861857501271&gclid=EAIaIQobChMI5uOt_P_l6QIVW-ztCh0_fAEAEAkYBSABEgL1ffD_BwE)
* 3x Noise Blocker 140mm fans [here](https://www.blacknoise.com/site/en/products/noiseblocker-it-fans/nb-eloop-series/120x120x25mm.php?lang=EN)


## Recycled parts:
* 1x 240v to 110v Auto Transformer [here](https://mcitransformer.com/product/mci-4-49-series/) From an old video game.
* 1x S-150-12 Switch mode power supply [here](https://uk.rs-online.com/web/p/embedded-switch-mode-power-supplies-smps/6210663?cm_mmc=UK-PLA-DS3A-_-google-_-PLA_UK_EN_Power_Supplies_%26_Transformers_Whoop-_-Embedded+Switch+Mode+Power+Supplies+(SMPS)_Whoop-_-6210663&matchtype=&pla-475399700067&gclid=EAIaIQobChMIk967q_rl6QIVjO7tCh3r8AJ4EAQYASABEgLKf_D_BwE&gclsrc=aw.ds) from an old video game.
* 1x RD-65A Switch mode power supply [here](https://uk.rs-online.com/web/p/embedded-switch-mode-power-supplies-smps/6447102/?relevancy-data=636F3D3126696E3D4931384E53656172636847656E65726963266C753D656E266D6D3D6D61746368616C6C7061727469616C26706D3D5E5B5C707B4C7D5C707B4E647D2D2C2F255C2E5D2B2426706F3D31333326736E3D592673723D2673743D4B4559574F52445F53494E474C455F414C5048415F4E554D455249432673633D592677633D4E4F4E45267573743D72642D363561267374613D72642D36356126&searchHistory=%7B%22enabled%22%3Atrue%7D) From an old video game.
* 1x Aluminium sheet from contoll unit of a screap 2 penny pusher.
* 1x Heatsink from an old sega daytona graphics card.
* 2x storage boxes.
* Variouse other parts


## Lcd Display:
<div align="center">
<img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/lightwithfan.jpg" alt="topof image" width="45%"/></div>

#
During day to day running the lcd display scrolls through a few screen of data including
* Time and date 
* Air temperature and humidity
* The big tank water temperature
* Tank 2 water temperature
* Tank3 water temperature
* Heat pad Status
* Light Cycle for the 12v led panel
* Light Cycle for the 240v led bulbs

### Setup program flow:
On pressing the rotary encoder centre button
* Lighting time 240v lights, on click will give a menu allowing selection of 0, 12, 14, 16, 18 hours duration.
* Lighting time 12v lights, on click will give a menu allowing selection of 0, 12, 14, 16, 18 hours duration.
* Watering duration, on click will give a menu allowing selection of between 5 and 90 seconds in 0.5 increments duration.
* Watering time, on click will give a menu allowing selection of auto water off, or if rotated to the right you can select what hour you would like to start watering. If at the auto water off selection if the encoder is rotate further left a selection to fur on NFT will appear. Further adjustment to NFT can be done in the next menu.
* NFT with Cycle, on click will give a menu allowing selection of on duration and off duration in minutes.
* Manual water, on click will give a menu allowing selection manual overriding the water pump, in case of now plants needing an initial dousing of nutrient feed.
* Daylight Saving, on click will give a menu allowing selection of plus or minus 1 hour. This only effects the clock on the lcd display and will not change the global watering or lighting cycles due to some plants being sensitive to changes in lighting durations.
* Heat mat temperature settings, on click will give a menu allowing the max temperate of the heat mate from 0 to 25 degrease centigrade.
* Exit Menu
* If the centre button on the encoder is held down it will cause the arduino to rest by kicking the watch dog, this can be done regardless of being in setup mode.


## Lighting
The 12v lighting panel was made up of a piece of aluminium from the lid of a 2p pusher control box with a heat sink from a Sega Daytona video game and stuck to the top with thermal glue. At first I wanted the cooling to be passive but there was to many chips in close succession so I had to add a fan, most of the early fans I used where really loud or vibrated to much so I added a noise blocker fan as they produce 178.3 m3/h @28.5db so it was a good compromise.  
#
<div align="center">
<img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/lightwithfan.jpg" alt="topof image" width="45%"/><img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/leds.jpg" alt="led image" width="45%"/> </div>


#
The first version only had the Growsun led grow lights giving a pink colour due to the colour spectrum from blue 320nm and the red 840nm with nothing much else, while plants did grow, I found they became leggy and unable to hold their own weight.  
#


<div align="center">
   <img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/fullspectrum.jpg" alt="light spectrum image"/>
 </div>

#
After some time googling, I found that even though plants don’t need yellow and green light for photosynthesis, there is some debate around whether green light help the plant push toxins out of the leaves, I have no clue if this is true however I decided to add some warm white leds to cover more of the visible light spectrum, even though some people will debate this is a waste of energy, however due to the wavelengths favouring the red end of the spectrum, the plants started to bolt early. At this point I changed them for cool white leds, the difference was amazing and the plants shot into life, woodier stems and healthy looking leaves.

#
 <div align="center">
   <img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/Warm_vs_Cool_White-1.jpg" alt="light spectrum image"/>
 </div>
 
#
I created a second lighting fixture as I needed more light but was unable to get any of the scrap parts I had used previously, so I had to improvise with the intention it would be replaced in a few months with something better, 3 years on I’m still using it. Created from a cardboard box and tinfoil with 6x 240v bulb holders and a light switch, The led bulbs emit almost no heat, so any concern there were eliminated, it's had had multiple chilli plants and peppers flower underneath no problems.
#

<div align="center">
<img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/20200603_195337.jpg" alt="240v lights image" width="45%"/><img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/20200603_195402.jpg" alt="240v lights image" width="45%"/> </div>
<div align="center">
<img src="https://github.com/jonathanw82/HydroBigTent/blob/master/images/20200603_195506.jpg" alt="peppers image" width="45%"/> </div>

[Back_to_top](#Hydroponics)

## Air Extraction:
I chose the RK100 Can-fan, as at the time was the most affordable however early on I realised it was for too powerful for what I needed as the tent caved in on itself when at full speed, it also made quite some noise, originally I put a cheap fan speed controller on it but due to the crude way they chopped the ac waveform it made the fan hum and drone. A proper speed controller was too expensive for the project. I did realise that half speed was ideal so I swapped out the fan speed controller for an 110v transformer I recycled from an old video game and it was a perfect extraction rate.

I could have used the arduino on a PWM channel with a solid state relay to regulate the fan speed but I was running out of space on the eerprom as it was.

## Air Pumps
During the early stages I tried multiple types of systems from deep water culture to NFT and in the end settles for deep water culture, I was originally using a really small air pump and for a while noticed that the plants were lagging in something especially in the summer months when the water temperature is close to 23degrees centigrade, I soon learned that the oxygen levels in the water drop depending on head so I went for the Eheim 400 air pump its fantastic, quiet and powerful enough for this application.

## Growroom tools:
My tools of choice when it comes to making nutrient solution:
* Bluelab Truncheon for testing the TDS/EC [here](https://bluelab.com/bluelab-commercial-truncheon-nutrient-meter)
* HM Digital PH-80 for testing PH [here](http://hmdigital.com/product/ph-80/)


## Nutrients:
The nutrients that have become stapes in my grow room
### Seedlings
* Growth Technology Formulex [here](https://www.growthtechnology.com/product/formulex/)
* Atami Rootbastic [here](https://grownuphydroponics.com/atami-rootbastic-explosive-root-growth-first-3-weeks-concentrated.html)
* Atami Silic Boost [here](https://grownuphydroponics.com/b-cuzz-silic-boost-concentrated-silicon-atami.html)
* Growth Technology Clonex [here](https://www.growthtechnology.com/product/clonex/)
### Mature plants
* Growth Technology Ionic Hydro Hard Water Grow [here](https://www.growthtechnology.com/product/ionic-hydro-hard-water-grow/)
* Growth Technology Ionic Hydro Hard Water Bloom [here](https://www.growthtechnology.com/product/ionic-hydro-hard-water-bloom/)
* Growth Technology Ionic Coco Grow [here](https://www.growthtechnology.com/product/ionic-for-coco-grow/)
* Growth Technology Ionic Coco Bloom [here](https://www.growthtechnology.com/product/ionic-for-coco-bloom/)
* Growth Technology Chilli Focus [here](https://www.growthtechnology.com/product/chilli-focus/)
* Atami Silic Boost [here](https://grownuphydroponics.com/b-cuzz-silic-boost-concentrated-silicon-atami.html)
* Atami Rootbastic [here](https://grownuphydroponics.com/atami-rootbastic-explosive-root-growth-first-3-weeks-concentrated.html)
* Atami Bloombastic [here](https://grownuphydroponics.com/atami-bloombastic-explosive-flower-growth-weeks-4-6-concentrated.html)
* Canna Pk 13/14 [here](https://www.canna-uk.com/pk_13_14)
* Silver Bullet Roots [here](https://www.growell.co.uk/pest-control-plant-health/disease-control/silver-bullet-roots.html)
* CalMag [here](https://www.canna-uk.com/calmag-agent)
* PH Down [here](https://www.growthtechnology.com/product/ph-down/)
### Pests
* Pyrethrum 5EC [here](https://www.pelgar.co.uk/product/pyrethrum-5-ec/)
* SB Plant Invigorator [here](https://sbproducts.co.uk/)


## Nice to have: 
These features may be included in future releases of this application.
* Digital Extraction fans
* Higher power led lighting
* Air conditioning
* Water cooler


## Bugs & ongoing fixes
* The rotary encoder can be laggy and need quite q few revolutions to get get to where the user needs to be in the menu.
* The water temp sensors are cheap and there output is erratic this can cause the heater mat relays to chatter if the target temperature is close. To get around this I have added if statments to look to see if the temperature being read is equal to -127 (-127 meaning no output) in future realeses I will get better quality sensors.


### Credits:
I would like to thank my firend Cersnic Tebor for his help with this project.

The ideas for the menu system came from here 
http://educ8s.tv/arduino-rotary-encoder-menu/

##### Media:

Images of light wave lengths
https://thegreensunshineco.com/think-beyond-white-led-and-bulb-grow-lights-kelvin-and-color-temperature/

Image of Full spectrum wave length
https://futureeden.co.uk/

All other images are my own.

[Back_to_top](#Hydroponics)
