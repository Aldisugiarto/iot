#include "EEPROM.h"
#include <EEPROM.h>
/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 15;    // the number of the pushbutton pin
const int ledPin = 2;      // the number of the LED pin

// Variables will change:
int ledState;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int reading;
int addr = 0;
int flag = 0;
int count = 0;
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  //Serial.println(ledState);
  //  lastButtonState = ledState;
  // set initial LED state
  digitalWrite(ledPin, EEPROM.read(addr));
}

void loop() {

  reading = digitalRead(buttonPin);
  if (reading == 0 && flag == 0) {
    count++;
    flag = 1;
  }
  else if (reading == 1 && flag == 1) {
    flag = 0;
  }
  if (count == 0) {
    digitalWrite(ledPin, EEPROM.read(addr));
  }
  if (count == 1) {
    digitalWrite(ledPin, 1);
    EEPROM.write(addr, 1);
  }
  if (count == 2) {
    digitalWrite(ledPin, 0);
    EEPROM.write(addr, 0);
    count = 0;
  }
}
