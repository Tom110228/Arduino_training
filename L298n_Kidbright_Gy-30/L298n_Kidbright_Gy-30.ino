//Home Of Maker for Kidbright Board
#include <LiquidCrystal_I2C.h>
#include <BH1750FVI.h>
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
//LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); 
const int buzzer = 13; //buzzer pin

// Motor A
#define enA 23
#define in1 18
#define in2 19
#define button 14

int rotDirection = 0;
int pressed = false;

void setup() {
  Serial.begin(115200);
    // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

  LightSensor.begin();
  // sets the pins as outputs:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(button, INPUT);

  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  // Move the DC motor forward at maximum speed
 
  uint16_t lux = LightSensor.GetLightIntensity();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lux");
  lcd.setCursor(0, 0);
  lcd.print("Light Sensor:");
  lcd.setCursor(4, 1);
  lcd.print(lux);
  lcd.setCursor(8, 1);
  lcd.print("(lux.)");

  analogWrite(enA, 150); // Send PWM signal to L298N Enable pin
  



  // If button is pressed - change rotation direction
  if (lux < 300 && rotDirection == 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  //  tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(5000);
    rotDirection = 1;
    Serial.print("Open window");
  
  }else if (lux > 300 && rotDirection == 1)  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
   // tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(5000);
   rotDirection = 0;
   Serial.print("Close window");
  }else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW); 
    delay(50);
  }

   delay(250);
}
