/*
 * STIB_LED.cpp
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Taylor Smith (Fall 2018),
 * Class to help with controlling a LED.
 */

#include "Arduino.h"
#include "STIB_LED.h"

LED::LED()
{
  /* Constructor: does nothing special right now
    BE SURE YOU CALL LED::init() IN setup()!!!
  */
  pin = 0;
}

LED::~LED()
{
}

void LED::init(int p, unsigned int on, unsigned int off)
{
  /*RUN IN setup()!!!
  */
  pin = p;
  onTime = abs(on);
  offTime = abs(off);
  state = false;
  lastToggle = millis;
  nextToggle = lastToggle + offTime;
  
  pinMode(pin,OUTPUT);
  
  update();
}

void LED::update()
{
  /* RUN THIS AT END OF MAIN LOOP
     checks if it's time to toggle the LED, handles updating the
	 LED's state and the time variables.
  */
  if(millis() >= nextToggle)
  {
	  state = !state;
	  //lastToggle isn't set to millis in case there's some lag going on
	  lastToggle = nextToggle;
    digitalWrite(pin,state);
	  if(state)
	  {
		  //if the light is now on, advance nextToggle by onTime
		  nextToggle += onTime;
	  }
	  else
	  {
		  //otherwise, advance nextToggle by offTime
		  nextToggle += offTime;
	  }
  }
}

int LED::getPin()
{
  return pin;
}

bool LED::getState()
{
  return state;
}

unsigned long LED::getLastToggle()
{
  return lastToggle;
}

unsigned int LED::getOnTime()
{
  return onTime;
}

unsigned int LED::getOffTime()
{
  return offTime;
}

void LED::setOnTime(unsigned int on)
{
  onTime = abs(on);
}

void LED::setOffTime(unsigned int off)
{
  offTime = abs(off);
}

void LED::setDelays(unsigned int on, unsigned int off)
{
  onTime = abs(on);
  offTime = abs(off);
}
