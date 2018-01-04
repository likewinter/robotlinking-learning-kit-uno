#include <Stepper.h>
 
//the steps of a circle
#define STEPS 100
 
//set steps and the connection with MCU
Stepper stepper(STEPS, 2, 3, 4, 5);
 
//available to store previous value
int previous = 0;
 
void setup()
{
  //speed of 180 per minute
  stepper.setSpeed(180);
}
 
void loop()
{
  //get analog value
  int val = analogRead(0);
 
  //current reading minus the reading of history
  stepper.step(val - previous);
 
  //store as prevous value
  previous = val;
}

