#include <Arduino.h>

// constants
const int res = 10;

// pins
//const int S1_PIN = 34;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReadResolution(res);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor1_reading = analogRead(A0);
  float s1_voltage = ((float)sensor1_reading*5/(2^res-1));
  if (sensor1_reading > 350) {
    Serial.print("LEVEL 2 REACHED ----- ");
  }
  if (sensor1_reading > 150) {
    Serial.print("LEVEL 1 REACHED ");
  }
  Serial.println("Sensor reading: " + String(sensor1_reading) + " | " + String(s1_voltage));
  
  delay(100);
}
