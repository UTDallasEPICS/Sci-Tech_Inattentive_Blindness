/*
 * STIB_Button.cpp
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Taylor Smith (Fall 2018),
 * Class to help with using active-low buttons
 * Includes state-change detection, press counting; makes use of the
 * Arduino's internal pull-up resistors.
 */

#include "Arduino.h"
#include "STIB_Button.h"

    Button::Button(int p)
	{
		pin = p;
		pinMode(pin,INPUT_PULLUP);
		resetCount();
		update();
		//setup();
	}
	
    Button::~Button()
	{
	}

	//currently not using the setup function to eliminate a step.
	/*void Button::setup()
	{
		pinMode(pin,INPUT_PULLUP);
		resetCount();
		update();
	}*/

	//Run this at the end of every loop
    void Button::update()
	{
		//current state now is the previous state, we need to keep it
		//so we can check for state-changes
		lastState = state;
		//remember: if the pin is HIGH, then it's NOT ACTIVE. So, we
		//invert the result of digitalRead().
		state = !digitalRead(pin);

		//update the count
		if(wasPressed())
		{
			counter++;
		}
	}
	
    int  Button::getPin()
	{
		return pin;
	}

    int  Button::getCount()
	{
		return counter;
	}
	
    bool Button::getState()
	{
		return state;
	}
	
	bool Button::getLastState()
	{
		return lastState;
	}
	
	
    bool Button::wasPressed()
	{
		return isPressed() && !lastState;
	}
    bool Button::wasReleased()
	{
		return isReleased() && lastState;
	}
	
    bool Button::isPressed()
	{
		return state;
	}
	
    bool Button::isReleased()
	{
		return !state;
	}
	
    void Button::resetCount()
	{
		counter = 0;
	}
	
    void Button::resetCount( int c)
	{
		counter = c;
	}
