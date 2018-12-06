# Sci-Tech_Inattentive_Blindness
Code and Related Files for Sci-Tech Innattentive Blindness Project
(STIB is an abbreviation of the above name and is used to mark files
that were written for this particular project)

###Arduino code:
'''
STIB_Leonardo_Controls
	│
	│	//borrowed from the internet. Allows the Leonardo to
	│	//act as a joystick. link to the source is in the code.
	│	//Note that the leonardo is able to act as a keyboard
	│	//and a joystick at the same time.
	├── Joystick.cpp
	├── Joystick.h
	│
	│	//represents buttons as objects; includes a few useful
	│	//features.
	├── STIB_Button.cpp
	├── STIB_Button.h
	│
	├── STIB_Leonardo_Controls.ino
	│
	│	//the potentiometer for the steering wheel can't rotate
	│	//fully, this class allows us to pretend that's not
	│	//the case.
	├── STIB_Potentiometer.cpp
	└── STIB_Potentiometer.h

STIB_Leonardo_LED
	│
	│	//represents LEDs as objects and makes timing blinks
	│	//simple.
	├── STIB_LED.cpp
	├── STIB_LED.h
	│
	└── STIB_Leonardo_LED.ino

STIB_Potentiometer_to_Serial
	│
	│	//use this to get the range of the steering wheel
	└── STIB_Potentiometer_to_Serial.ino
'''
