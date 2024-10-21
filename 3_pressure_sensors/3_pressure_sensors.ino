#include <Arduino.h>

// constants
const int res = 10;

// pins
#define S1_PIN 34
#define S2_PIN 35
#define S3_PIN 32

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReadResolution(res);
  pinMode(S1_PIN,INPUT);
  pinMode(S2_PIN,INPUT);
  pinMode(S3_PIN,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor1_reading = analogRead(S1_PIN);
  int sensor2_reading = analogRead(S2_PIN);
  int sensor3_reading = analogRead(S3_PIN);
  
  std::array<int,3> raw = {sensor1_reading,sensor2_reading,sensor3_reading};
  std::array<int,3> binary;
  for(int i=0; i < 5; i++) {
    if (raw[i] >= 150) {
      binary[i] = 1;
    }
    else {
      binary[i] = 0;
    }
  }


  // float s1_voltage = ((float)sensor1_reading*5/(2^res-1));
  Serial.print(String(binary[0])+String(binary[1])+String(binary[2])+"| ");
  Serial.println("S1: " + String(sensor1_reading) + " | S2: " + String(sensor2_reading) + " | S3: " + String(sensor3_reading));
  
  delay(100);
}

