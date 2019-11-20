/*
 * STIB_PotentiometerTwo.cpp
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Nathan Khuc (Fall 2019),
 * Copy of the first potentiometer code for the pedal
 */

#include "Arduino.h"
#include "STIB_PotentiometerTwo.h"

PotentiometerTwo::PotentiometerTwo()
{
  /* Constructor: does nothing special right now
    BE SURE YOU CALL Potentiometer::init() IN setup()!!!
  */
  pinTwo = 0;
  valueTwo = 0;
  constrainedValueTwo = 0;
  positionTwo = 0;
  maxValTwo = 1023;
  minValTwo = 0;
}

PotentiometerTwo::~PotentiometerTwo()
{
}

void PotentiometerTwo::initTwo(int p, int mn, int mx)
{
  /*RUN IN setup()!!!
     sets up everything for the pedal.
  */
  pinTwo = p;
  positionTwo = 0;

  /* For safety's sake, checks that mx is really the largest
     and that mn is really the smallest; also that maxVal and
     minVal wind up within 0,1023
  */
  maxValTwo = min(max(mx, mn), 800);
  minValTwo = max(min(mx, mn), 150);

  //no need to set pinmode for an analog pin
  updateTwo();
}

void PotentiometerTwo::updateTwo()
{
  /* RUN THIS AT END OF MAIN LOOP
     gets the new reading and adjusts it
  */
  //read the sensor
  valueTwo = analogRead(pinTwo);
  
  if (valueTwo < ((maxValTwo - minValTwo)/2)+ minValTwo)           //Equation to reveerse Serial values
  {
      valueTwo = maxValTwo - (valueTwo - minValTwo);
  }
  else if (valueTwo > ((maxValTwo - minValTwo)/2)+ minValTwo)
  {
      valueTwo = (maxValTwo - valueTwo + minValTwo);
  }                                                     //new code
   
  //limit value to our range (in case somehow it gets outside)
  constrainedValueTwo = constrain(valueTwo, minValTwo, maxValTwo);
  //and then map the value to 0,1023
  positionTwo = map(constrainedValueTwo, minValTwo, maxValTwo, 150, 800);

  //functional note: map() uses integer math.
}

int  PotentiometerTwo::getPinTwo()
{
  return pinTwo;
}

int  PotentiometerTwo::getValueTwo()
{
  return valueTwo;
}

int  PotentiometerTwo::getConstrainedValueTwo()
{
  return constrainedValueTwo;
}

float PotentiometerTwo::getPositionTwo()
{
  return positionTwo;
}

int  PotentiometerTwo::getMaxValTwo()
{
  return maxValTwo;
}

int  PotentiometerTwo::getMinValTwo()
{
  return minValTwo;
}
