/*
 * STIB_LED.h
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Taylor Smith (Fall 2018),
 * Class to help with controlling a LED, specifically blinking. For
 * multiple LEDs, use an array. Changes to the LED's state are made when
 * update() is called.
 * Lapsed time is stored as an unsigned long (a larger version of the
 * int type) because the numbers can get very large (there are a lot of
 * milliseconds in a day).
 */

#ifndef _STIB_LED_H_
#define _STIB_LED_H_

#include "Arduino.h"

class LED
{
  public:
    LED();
    ~LED();
    //void init();
    void init(int, unsigned int, unsigned int);
    void update();
    int getPin();
    bool getState();
    unsigned long getLastToggle();
    unsigned int getOnTime();
    unsigned int getOffTime();
    void setOnTime(unsigned int);
    void setOffTime(unsigned int);
    void setDelays(unsigned int, unsigned int);
  private:
    int pin;                  //pin that LED is connected to
    bool state;               //is LED on or off
    unsigned long lastToggle; //time in milliseconds of last toggle
    unsigned long nextToggle; //time in milliseconds of next toggle
    unsigned int onTime;      //how long to leave the LED on
    unsigned int offTime;     //how long to leave the LED off
};

#endif /* _STIB_LED_H_ */
