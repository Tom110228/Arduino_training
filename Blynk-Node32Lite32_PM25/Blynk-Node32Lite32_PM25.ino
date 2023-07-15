
// Fill-in information from your Blynk Template here
#include <LiquidCrystgal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);



#define BLYNK_TEMPLATE_ID "TMPL6eGysWpyo"
#define BLYNK_DEVICE_NAME "ProjectSmartFarming"


#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// define the GPIO connected with Relays and switches


#include "BlynkEdgent.h"


// When App button is pushed - switch the state




void setup()
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  delay(100);
  // pinMode(wifiLed, OUTPUT);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();

  Serial.print("PM25: ");
  Serial.println(Valpm25);
  Serial.println("");
  Serial.print("PM10: ");
  Serial.println(Valpm10);


  lcd.setCursor(0, 0);
  lcd.print("PM2.5 = ");
  lcd.print(Valpm25);
  lcd.setCursor(0, 1);
  lcd.print("PM10=");
  lcd.print(Valpm10);

//  lcd.clear(); 




  BlynkEdgent.run();
  Blynk.virtualWrite(V1, pm25);
  Blynk.virtualWrite(V2, pm10);



  delay(100);
}
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
