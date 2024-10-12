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
    std::array<int,5> get_reading();
    void set_binary();
    std::array<int,5> get_binary();
    int get_level();
}