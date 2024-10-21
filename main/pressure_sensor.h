#define lvl1 150
#define lvl2 400
#define lvl3 700

#include <array>
#include "pitch.h"

class psensors
{
  int level;
  int threshold;
  std::array<int,5> raw_values;
  std::array<int,5> binary_values; 
  public:
    psensors(int level);
    ~psensors() {};
    void set_reading(int s_id, int reading);
    std::array<int,5> get_reading(); // Get array of raw values
    void set_binary(); // Use raw values to get binary values by checking against threshold for given level
    std::array<int,5> get_binary(); // Get binary array to calculate output sound
    int get_level();
}