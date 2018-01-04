
#include<LiquidCrystal.h>  

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);//initialize the pin of LCD
const int TrigPin = 2;//Trig attach to pin2
const int EchoPin = 3;//Echo attach to pin3
const int buzzer = 6;//buzzer attach to pin6
float cm;

void setup()
{
   Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission
   //set the below pins as OUTPUT
   pinMode(TrigPin,OUTPUT);
   pinMode(EchoPin,INPUT);
   pinMode(buzzer,OUTPUT);
   lcd.begin(16,2); //Initializes the interface to the LCD screen 
   lcd.print("Reversing radar"); //display "Reversing radar"
   delay(2000);  //delay 2s
   lcd.clear();//clear
}

void loop()//
{
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
	
  cm = pulseIn(EchoPin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  if(cm < 0)
  {
    cm = 0;
  }
  lcd.setCursor(0,0);  
  lcd.print("Distance:");
  lcd.setCursor(0,1);  
  lcd.print("                ");
  lcd.setCursor(3,1);  
  lcd.print(cm);  
  lcd.setCursor(9,1);
  lcd.print("cm");
  delay(100);
 
  if(cm < 15 & cm >= 5)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  }
  else if(cm < 5 & cm >= 0)
  {
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
     delay(1000);
  }
}
