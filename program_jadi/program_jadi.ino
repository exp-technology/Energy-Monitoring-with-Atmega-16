//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int sensorPin = 33, sensorvalue =0;
long sensordisplay =0;
void setup()
{
  pinMode(sensorPin,INPUT);
  lcd.begin(16,4);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
  delay(2000);
  
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Amar Arduino!");
//  Serial.begin(9600);
}


void loop()
{
  sensordisplay=0;
  lcd.setCursor(0,2);
  for(int i =0 ;i <1000; i++){
  sensorvalue = analogRead(sensorPin);
  sensordisplay=sensordisplay + sensorvalue;
//  Serial.print(sensordisplay + " ");
  }

  sensordisplay = sensordisplay / 1000;
//  Serial.println(sensordisplay);
  lcd.print(sensordisplay);
  delay(1000);
  lcd.clear();
  delay(200);
}
