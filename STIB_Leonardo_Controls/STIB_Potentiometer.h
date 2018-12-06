/*
 * STIB_Potentiometer.h
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Taylor Smith (Fall 2018),
 * Class to help with using a potentiometer.
 * Features range mapping, in case your potentiometer can't rotate
 * over it's full range. Use the "AnalogReadSerial" example to find
 * out the min and max values. Given these values, the potentiometer
 * class will remap input from this range to [0,1023]. Output is also
 * constrained to [0,1023] so you don't need to worry about the sensor
 * accidentally getting out of range.
 */

#ifndef _STIB_POTENTIOMETER_H_
#define _STIB_POTENTIOMETER_H_

#include "Arduino.h"

class Potentiometer
{
  public:
    Potentiometer();
    ~Potentiometer();
    //void init();
    void init(int, int, int);
    void update();
    int getPin();
    int getValue();
    int getConstrainedValue();
    float getPosition();
    int getMaxVal();
    int getMinVal();
  private:
    int pin;              //pin that pot is connected to
    int value;            //raw value from pot
    int constrainedValue; //value constrained between min/maxVal
    float position;       //processed value
    int maxVal;           //at most 1023
    int minVal;           //at least 0
    /* max and min values allow adjusting the range - useful if the
       pot can only reach part of it's full range.
       You can use AnalogReadSerial ( in the examples) to see what
       values your pot can reach. Write them down so you don't have to
       go back and check again.
    */
};

#endif /* _STIB_POTENTIOMETER_H_ */
