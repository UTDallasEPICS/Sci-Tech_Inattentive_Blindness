/*
 * STIB_Button.h
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Taylor Smith (Fall 2018),
 * Class to help with using active-low buttons
 * Includes state-change detection, press counting; makes use of the
 * Arduino's internal pull-up resistors.
 * Note that this means that when there's nothing connected to the pin
 * (i.e. the switch is open) the pin will read HIGH. This is counter
 * intuitive, but the class is written so you don't have to worry about
 * it.
 * 
 * Technically this is called an active-low button. See
 * http://vinduino.blogspot.com/2013/07/active-high-vs-active-low-button.html
 * for an explanation.
 * 
 * USAGE:
 * expects the physical button's input pin when you construct with 
 *   Button(int)
 * wasPressed() and wasReleased() are for state-change - i.e. they only
 *   return true the loop after a button is pressed or released.
 * isPressed() and isReleased() are for the current state.
 * YOU NEED TO CALL update() FOR EVERY BUTTON AFTER EVERY MAIN LOOP.
 */

#ifndef _STIB_BUTTON_H_
#define _STIB_BUTTON_H_

#include "Arduino.h"

class Button
{
	public:
		Button(int);
		~Button();
		//void setup();
		void update();
		int getPin();
		int getCount();
		bool getState();
		bool getLastState();
		bool wasPressed();
		bool wasReleased();
		bool isPressed();
		bool isReleased();
		void resetCount();
		void resetCount(int);
	private:
		int pin;		//pin that the button is connected to
		bool state;		//current state of button
		bool lastState;	//state of button during last loop
		int counter;	//tracks number of presses (not releases)
};

#endif /* _STIB_BUTTON_H_ */
