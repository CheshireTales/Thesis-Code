#include <esp32.h>

// constants
const int res = 10;

// pins
const int S1_PIN = 34;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(res);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor1_reading = analogRead(S1_PIN);
  float s1_voltage = ((float)sensor1_reading*5/(2^res-1));
  Serial.println("Sensor reading: ", sensor1_reading, " | ", s1_voltage);
}
