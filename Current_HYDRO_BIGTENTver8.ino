
#include <EEPROM.h>
#include <RTClib.h>               // Real time clock
#include <DHT.h>                  // Air Temp Humid Sensor
#include <OneWire.h>              // Sensors (water temp) connected to one wire
#include <DallasTemperature.h>    // Water Temp Sensor
#include <LiquidCrystal_I2C.h>    // Lcd display 
#include <avr/wdt.h>              // Watchdog Lib
#include <TimerOne.h>
#include <ClickEncoder.h>

const int lightingPin = 4;
const int bulblightingPin = 9;
const int pumpPin = 6;
const int HeatMat = 10;

RTC_DS3231 rtc;                   // Init the DS3231 using the hardware interface (Nano A4=SDA A5=SCL)

unsigned long currentTime;
unsigned long previousTime = 0;
unsigned long currentsensorTime;
unsigned long previoussensorTime = 0;

int marker = 0;
char dateBuffer [12];             // storeing time date string

unsigned long pumpState = 0;
unsigned long pumpHour = 0;
unsigned long pumpMinute = 0;
unsigned long pumpSecond = 0;
unsigned long pumpHour2 = 0;

int eeAddress = 0;

int lampState = 0;
int lightingHour = 0;
int VeglampState = 0;
int VeglightingHour = 0;
int water = 0;
int WateringTime = 0;
int manWater = 0;
int NFTDelay = 0;
unsigned long NFTDelayPause = 0;
int NFTrunTime = 0;
unsigned long NFTrunInterval = 0;
float heatPadTemp = 0;
int HeatPadStatus = 0;
float HeatPadTempSwing = 0;
int TempCheck = 0;

int menuitem = 1;
int page = 1;
int lastMenuItem = 1;
int enter = 0;
int menuEntered = 0;
byte DaylightSaving = 0;

boolean up = false;
boolean down = false;
boolean middle = false;
boolean ButReset = false;

ClickEncoder *encoder;
int16_t last, value;

int dailyresethour = 0;
int dailyresetmin = 0;
int dailyreset = 0;
int dailyresetSecond = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Lcd Display ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);      // Set the LCD I2C address
// set the LCD address to 0x3F or 0x27 depending what display using for a 16 chars 2 line display
// Set the pins on the I2C chip used for LCD connections:
// addr, en,rw,rs,d4,d5,d6,d7,bl,blpol

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Air Temperature & Humidity sensor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define DHTPIN 2             // what pin we're connected to
#define DHTTYPE DHT22        // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);    // Initialize DHT sensor
int chk;
float hum;                   //Stores humidity value
float temp;                  //Stores temperature value
float checkTemp = 0;
float checkHum = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Water Temperature sensor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define ONE_WIRE_BUS 7
#define TEMPERATURE_PRECISION 9
OneWire oneWire(ONE_WIRE_BUS);          // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire);    // Pass our oneWire reference to Dallas Temperature.

//########################################################################## SETUP ##############################################################################
void setup()
{
  Serial.begin(9600);
  rtc.begin();                                 // Initialize the rtc object
  lcd.begin(16, 2);                            // initialize the lcd for 16 chars 2 lines
  lcd.backlight();                             // Turns backlight LCD on
  sensors.begin();                             // water temp sensor
  dht.begin();                                 // temp humid sensor
  EEPROM.get(0, lightingHour);                 // get initial lighting Cycle, water duration and watering hour ETC from memory
  EEPROM.get(8, water);
  EEPROM.get(16, WateringTime);
  EEPROM.get(24, VeglightingHour);
  EEPROM.get(32, NFTrunTime);
  EEPROM.get(40, NFTDelay);
  EEPROM.get(48, DaylightSaving);
  EEPROM.get(54, heatPadTemp);

  StartUp();                                  // start up screen showing software version

  pinMode (lightingPin, OUTPUT);              // Set the inputs are outputs starting state
  pinMode (bulblightingPin, OUTPUT);
  digitalWrite(bulblightingPin, HIGH);
  pinMode (pumpPin, OUTPUT);
  digitalWrite (pumpPin, HIGH);
  pinMode (HeatMat, OUTPUT);
  digitalWrite (HeatMat, HIGH);

  pinMode (A0, INPUT_PULLUP);                 // setting encoder pins to pullup to stop any channel float
  pinMode (A1, INPUT_PULLUP);
  pinMode (A2, INPUT_PULLUP);

  encoder = new ClickEncoder(A0, A1, A2);     // set analog channel 0,1,2 for use with the rotery encoder
  encoder->setAccelerationEnabled(false);     // disable encode acelleration

  Timer1.initialize(1000);                    // Rotery encoder Timer
  Timer1.attachInterrupt(timerIsr);

  last = encoder->getValue();                 // last rotery encoder Value

  sensors.requestTemperatures();              // request the first water temp data
    
  sensors.setResolution(0, TEMPERATURE_PRECISION);      // set the resolution to 9 bit per device
  sensors.setResolution(1, TEMPERATURE_PRECISION);
  sensors.setResolution(2, TEMPERATURE_PRECISION); 

  wdt_enable(WDTO_1S);                        // enable watchdog and wait 1 seconds before reset

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Uncomment to set the date and time ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));      // Automatic RTC DS3231 time update from computer clock while compiling
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));          // This line sets the RTC with an explicit date & time for example to set January 21, 2014 at 3am


  // IF YOU HAVE SET DATE TIME ABOVE AND REFLASHED THE CONTROLLER, REFLASH THE CONTROLLER AGAIN FOR A SECOND TIME WITH TIME AND DATE SET (//)
  // OR THE TIME DATE WILL RESET BACK TO THE INITIAL SET TIME EVERYTIME THE CONTROLLER IS RESET.

}

//########################################################################## LOOP ##################################################################################

void loop()
{
  wdt_reset();                           // Reset Watchdog and reset processor if crashed or inactive
  DailyReset();
  Reset();
  LightingTime();
  VEGLightingTime();
  WaterPump();
  ButonPressed();
  readRotaryEncoder();
  EncoderRotation();
  timerIsr();
  Display();
  Sensors();
  HeatMatControl();
  Debug();

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NFT Transition Times ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  NFTDelayPause = NFTDelay * 60000;
  NFTrunInterval = NFTrunTime * 60000;


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OUTPUT REAL TIME CLOCK ON SERIAL ~~~~~~~~~~~~~~~~~~~~~~~~~~

  DateTime now = rtc.now();
  sprintf(dateBuffer, "%02u-%02u-%04u ", now.day(), now.month(), now.year());
  // Serial.print(dateBuffer);
  sprintf(dateBuffer, "%02u:%02u:%02u ", now.hour(), now.minute(), now.second());
  // Serial.println(dateBuffer);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Time Stamps ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  pumpHour = (now.hour() * 60);
  pumpHour2 = (pumpHour * 60);
  pumpMinute = (now.minute() * 60);
  pumpSecond = now.second();

  lampState = (now.hour() * 60);
  VeglampState = (now.hour() * 60);

  dailyresethour = (now.hour() * 60);
  dailyresetmin = (now.minute() * 60);
  dailyresetSecond = now.second();

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Millis for LCD change ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  currentTime = millis();
  currentsensorTime = millis();


}
