#include <pressure_sensor.h>

psensors::psensors(int level) {
  level = level;
  if (level == 1) {
    threshold = lvl1;
  }
  if (level == 2) {
    threshold = lvl2;
  }
  if (level == 3) {
    threshold = lvl3;
  }
}

void psensors::set_reading(int s_id, int reading) {
  raw_values[s_id] = reading;
}

std::array<int,5> psensors::get_reading() {
  return raw_values;
}

void psensors::set_binary() {
  for(int i=0; i < 5; i++) {
    if (raw_values[i] >= threshold) {
      binary_values[i] = 1;
    }
    else {
      binary_values[i] = 0;
    }
  }
}

std::array<int,5> psensors::get_binary() {
  return binary_values;
}

int psensors::get_level() {
  return level;
}