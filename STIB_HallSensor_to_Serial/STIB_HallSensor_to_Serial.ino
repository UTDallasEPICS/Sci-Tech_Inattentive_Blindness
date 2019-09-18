/*
 * STIB_HallSensor_to_Serial.ino
 * UTDallas EPICS
 * Sci-Tech Inattentive Blindness Project
 * Authors: Nathan Khuc (Fall 2019),
 * Reworking of the AnalogReadSerial example to better serve our
 * purposes. Hook up the Hall Effect Sensor to A1.
 */

int min = 2000;
int max = -5;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  delay(100);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 1:
  int sensorValue = analogRead(A1);
  max = max(sensorValue,max);
  min = min(sensorValue,min);
  // print out the value you read:
  Serial.println(sensorValue);
  Serial.print("max: ");
  Serial.println(max);
  Serial.print("min: ");
  Serial.println(min);
  Serial.println("+++++++");
  delay(10);        // delay in between reads for stability
}
