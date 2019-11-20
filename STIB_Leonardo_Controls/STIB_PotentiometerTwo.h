#ifndef _STIB_POTENTIOMETERTWO_H_
#define _STIB_POTENTIOMETERTWO_H_

#include "Arduino.h"

class PotentiometerTwo
{
  public:
    PotentiometerTwo();
    ~PotentiometerTwo();
    //void init();
    void initTwo(int, int, int);
    void updateTwo();
    int getPinTwo();
    int getValueTwo();
    int getConstrainedValueTwo();
    float getPositionTwo();
    int getMaxValTwo();
    int getMinValTwo();
  private:
    int pinTwo;              //pin that pot is connected to
    int valueTwo;            //raw value from pot
    int constrainedValueTwo; //value constrained between min/maxVal
    float positionTwo;       //processed value
    int maxValTwo;           //at most 1023
    int minValTwo;           //at least 0
    /* max and min values allow adjusting the range - useful if the
       pot can only reach part of it's full range.
       You can use AnalogReadSerial ( in the examples) to see what
       values your pot can reach. Write them down so you don't have to
       go back and check again.
    */
};

#endif /* _STIB_POTENTIOMETERTwo_H_ */
