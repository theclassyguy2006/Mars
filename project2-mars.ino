#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
int sensor;
int threshold = 500;
float smoke;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  sensor = analogRead(A2);
  smoke = analogRead(A0);
  
  if(sensor < threshold){
    if(smoke >= 250){
      lcd.print("Too much smoke");
      delay(1000);
      lcd.clear();
    }
    else{
      lcd.print("Bad Orientation");
      delay(1000);
      lcd.clear();
    }
  }
  else{
  	lcd.print("Solar Panel fine!");
    delay(1000);
    lcd.clear();
  }
}


