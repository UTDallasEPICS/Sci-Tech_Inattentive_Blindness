/*
 * STIB_Leonardo_LED
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Taylor Smith (Fall 2018),
 * Code for the LED Leonardo. Will handle:
 *  ~ LEDs, with blinking
 */

#include "STIB_LED.h"


const int ledCount = 9; //it's hard to get an array's size on the fly, so use this.
const int lastPin = 13; //used to assign pins - start from pin 13 and go down.
int delayMin = 50;      //minimum delay time in milliseconds
int delayMax = 1500;    //maximum delay time
int frameCount = 0;
LED leds[ledCount];

void setup() {
  /*random numbers in arduino aren't exactly random (there's a list of
    random numbers stored on the arduino that is read at runtime; it's
    always the same) but reading from a disconnected analog pin will
    generate a decent random number. Use that as a seed for the random
    function. */
  randomSeed(analogRead(A0));
  
  Serial.begin(9600);
  //set up all LEDs
  for (int i = 0; i < ledCount; i++)
  {
    leds[i].init(lastPin - i, 
      int(random(delayMin, delayMax)),  //choose random ontime
      int(random(delayMin, delayMax))); //choose random offtime
  }
}

void loop() {
  frameCount++;

  for (int i = 0; i < ledCount; i++)
  {
    leds[i].update();
  }

  /*experimental: randomly change delay times on an LED; this is the
  	only use of frameCount right now
  	You could have functions that change blink times based on
  	formulas (sinusodial, ect) or blink in patterns (morse code?)
  */
  if(frameCount % 100 == 0)
    {
  	leds[int(random(ledCount))].setDelays(
  		int(random(delayMin,delayMax)),
  		int(random(delayMin,delayMax)));
    }
}
