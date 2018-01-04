/********************************************************************
* name : Raytrace,
* function : Automatically Tracking Light Source。if you use a flashlight to shine the photoresistor, you will see the servo motor and the photoresistor rotate, finally stop at the direction of light source.
***********************************************************************/
#include <Servo.h>
const int photocellPin = A0;
/************************************************/
Servo myservo;//create servo object to control a servo

int outputValue = 0;
int angle[] = {0,10, 20, 30, 40, 50, 60,70, 80, 90, 100,110,120,130,140,150,160,170,180};
int maxVal = 0;
int maxPos = 0;
/*************************************************/
void setup()
{
  Serial.begin(9600);
  myservo.attach(9);//attachs the servo on pin 9 to servo object
}
/*************************************************/
void loop()
{
  for(int i = 0; i < 19; i ++)
  {
    myservo.write(angle[i]);
    outputValue = analogRead(photocellPin);
    Serial.println(outputValue);
    if(outputValue > maxVal)
    {
      maxVal = outputValue;
     maxPos =i;
    }
    delay(200);
  }
  myservo.write(angle[ maxPos]);
  while(1);
}
