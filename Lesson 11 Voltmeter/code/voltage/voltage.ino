//www.RobotLinking.com
//2015.5.7
#include <LiquidCrystal.h>
/****************************************************/
const int analogIn = A0;
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
float val = 0;
/****************************************************/
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Voltage Value:");
}
/****************************************************/
void loop()
{
  val = analogRead(A0);
  val = val/1024*5.0;
  Serial.print(val);
  Serial.print("V");
 
  lcd.setCursor(6,1);
  lcd.print(val);
  lcd.print("V");
  delay(200);
}
