/*
 * STIB_Leonardo_Controller
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Taylor Smith (Fall 2018),
 * Code for the controller Leonardo. Will handle:
 *  ~ Steering wheel input (potentiometer -> joystick axis)
 *  ~ Button input
 */
#include "STIB_Potentiometer.h"
#include "STIB_PotentiometerTwo.h"
#include "STIB_Button.h"
#include "Joystick.h"
#include "Keyboard.h"

//globals
Potentiometer pot; //210-580
float axisVal = 0; //variable that will be proccessed to get final output
PotentiometerTwo potTwo; //LaneHallSensor
float axisValTwo = 0; //variable that will be proccessed to get final output

void setup()
{
  pot.init(A0, 210, 580);
  potTwo.initTwo(A1, 170, 870); //Set up both potentiometers
  Joystick.begin();
}

void loop()
{
  
  axisVal = pot.getPosition();                  //input from potentiometer will be in range 0,1023
  axisVal = map(axisVal, 0, 1023, -127, 127);   //the joystick requires input of -127,127
  axisVal = nroot(axisVal,3) * 25.0;            //modify value w/rational curve so steering is more sensitive near 0
                                                //previous step makes value tiny (127 -> 5.02), reason for * 25
  if ((axisVal > -50)  && (axisVal < 50))       //Buffer for zeroing the steering wheel
  {
    axisVal = 0;
  }
  Joystick.setXAxis(axisVal);                   // X-axis controls car's right/left motion (Yaw)
  pot.update();                                 //Update new potentiometer values

  axisValTwo = potTwo.getPositionTwo();            //input from potentiometer
  axisValTwo = map(axisValTwo, 170, 800, -127, 0); //Since we want ton only accelerate we will go from -127 to 0
  if (axisValTwo > -5)                             //Buffer for non acceleration
  {
     axisValTwo = 0;
  }
  Joystick.setYAxis(axisValTwo);                  //Control y axis motion
  /*Serial.print(axisValTwo);
  Serial.print("\n");
  delay(100);*/                                   //To test values
  
  potTwo.updateTwo();
  
}


float nroot(float input, float n)
{
  //allows getting the nth root of +/- numbers
  if(input >= 0)
  {
    return pow(input,1.0/n);
    }
  return -pow(-input,1.0/n);
}
//
