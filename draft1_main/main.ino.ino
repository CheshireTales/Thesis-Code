// This is the main file that connects to the ESP32 board

// includes
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h> 
#include "MultiMap.h"

// defines
#define button_1 = //FIND PIN - analogue in
#define button_2 = //FIND PIN - analogue in
#define button_3 = //FIND PIN - analogue in
#define button_4 = //FIND PIN - analogue in
#define button_5 = //FIND PIN - analogue in
#define POWER_button = //FIND PIN - digital in
#define POWER_LED = //FIND PIN - digital out
#define LED_1 = //FIND PIN - digital out
#define LED_2 = //FIND PIN - digital out
#define LED_3 = //FIND PIN - digital out

BLEMIDI_CREATE_INSTANCE("Instrument", MIDI); 

byte prevPowerState = LOW;
byte ledState = LOW;

void setup() {
  Serial.begin(115200)
  // setup input pins
  pinMode(button_1,INPUT_PULLUP);
  pinMode(button_2,INPUT_PULLUP);
  pinMode(button_3,INPUT_PULLUP);
  pinMode(button_4,INPUT_PULLUP);
  pinMode(button_5,INPUT_PULLUP);
  pinMode(POWER_button,INPUT_PULLUP);
  // setup output pins
  pinMode(POWER_LED, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  // MIDI
  MIDI.begin();
  // Level setup
  lvl = 1;
}

void loop() {
  // Check power, update LED for power state by toggling
  powerState = digitalRead(POWER_button);
  if (powerState != prevPowerState) {
    prevPowerState = powerState;
    if (powerState == LOW) {
      ledState = (ledState == HIGH) ? LOW: HIGH;
      digitalWrite(POWER_LED,ledState)

    }
  }
  // Read button inputs
  inputs = readInputs(button_1,button_2,button_3,button_4,button_5);
  // Check level
  if 
  switch(lvl) {
    case 1:
      level_1(LED_1,LED_2,LED_3,inputs);
    case 2:
      level_2(LED_1,LED_2,LED_3,inputs);
    case 3:
      level_3(LED_1,LED_2,LED_3,inputs);
  }   

  // Output sound

}

// Read buttons 1-5
std::array<int> readInputs(button_1,button_2,button_3,button_4,button_5) {
  int b1 = analogRead(button_1);
  int b2 = analogRead(button_2);
  int b3 = analogRead(button_3);
  int b4 = analogRead(button_4);
  int b5 = analogRead(button_5);
  input = [b1,b2,b3,b4,b5];
  return input;
}
// Only one octave, lowest force needed
void level_1(LED_1,LED_2,LED_3) {
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
}

// Two octaves (binary thumb button), middle force needed
void level_2(LED_1,LED_2,LED_3) {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);
}

// Two octaves (binary thumb button), high force (optional: variable volume based on force)
void level_3(LED_1,LED_2,LED_3) {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, HIGH);
}