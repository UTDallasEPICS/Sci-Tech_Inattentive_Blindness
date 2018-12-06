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
#include "STIB_Button.h"
#include "Joystick.h"
#include "Keyboard.h"

//globals
Potentiometer pot; //210-580
float axisVal = 0; //variable that will be proccessed to get final output

void setup()
{
  pot.init(A0, 210, 580);
  Joystick.begin();
}

void loop()
{
  //input from potentiometer will be in range 0,1023
  axisVal = pot.getPosition();
  //the joystick requires input of -127,127
  axisVal = map(axisVal, 0, 1023, -127, 127);
  //modify value w/rational curve so steering is more sensitive near 0
  axisVal = nroot(axisVal,3) * 25.0;
  //previous step makes value tiny (127 -> 5.02), reason for * 25
  // X-axis controls car's right/left motion (Yaw)
  Joystick.setXAxis(axisVal);
  pot.update();
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
