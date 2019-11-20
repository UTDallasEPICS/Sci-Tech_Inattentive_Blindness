/*
 * STIB_Potentiometer.cpp
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Taylor Smith (Fall 2018),
 * Class to help with using a potentiometer that can't rotate all the way.
 */

#include "Arduino.h"
#include "STIB_Potentiometer.h"

Potentiometer::Potentiometer()
{
  /* Constructor: does nothing special right now
    BE SURE YOU CALL Potentiometer::init() IN setup()!!!
  */
  pin = 0;
  value = 0;
  constrainedValue = 0;
  position = 0;
  maxVal = 1023;
  minVal = 0;
}

Potentiometer::~Potentiometer()
{
}

void Potentiometer::init(int p, int mn, int mx)
{
  /*RUN IN setup()!!!
     sets up everything for the steering wheel.
  */
  pin = p;
  position = 0;

  /* For safety's sake, checks that mx is really the largest
     and that mn is really the smallest; also that maxVal and
     minVal wind up within 0,1023
  */
  maxVal = min(max(mx, mn), 1023);
  minVal = max(min(mx, mn), 0);

  //no need to set pinmode for an analog pin
  update();
}

void Potentiometer::update()
{
  /* RUN THIS AT END OF MAIN LOOP
     gets the new reading and adjusts it
  */
  //read the sensor
  value = analogRead(pin);
  
  if (value < ((maxVal - minVal)/2)+ minVal)           //new code
  {
      value = maxVal - (value - minVal);
  }
  else if (value > ((maxVal - minVal)/2)+ minVal)
  {
      value = (maxVal - value + minVal);
  }                                                     //new code
   
  //limit value to our range (in case somehow it gets outside)
  constrainedValue = constrain(value, minVal, maxVal);
  //and then map the value to 0,1023
  position = map(constrainedValue, minVal, maxVal, 0, 1023);

  //functional note: map() uses integer math.
}

int  Potentiometer::getPin()
{
  return pin;
}

int  Potentiometer::getValue()
{
  return value;
}

int  Potentiometer::getConstrainedValue()
{
  return constrainedValue;
}

float Potentiometer::getPosition()
{
  return position;
}

int  Potentiometer::getMaxVal()
{
  return maxVal;
}

int  Potentiometer::getMinVal()
{
  return minVal;
}
