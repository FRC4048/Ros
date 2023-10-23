//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// sensor_msgs_LaserScanStruct.cpp
//
// Code generation for function 'sensor_msgs_LaserScanStruct'
//

// Include files
#include "sensor_msgs_LaserScanStruct.h"
#include "amcl_test_types.h"
#include "rt_nonfinite.h"
#include "std_msgs_HeaderStruct.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
void sensor_msgs_LaserScanStruct(sensor_msgs_LaserScanStruct_T &msg)
{
  static const char b_cv[21]{'s', 'e', 'n', 's', 'o', 'r', '_',
                             'm', 's', 'g', 's', '/', 'L', 'a',
                             's', 'e', 'r', 'S', 'c', 'a', 'n'};
  //  Message struct definition for sensor_msgs/LaserScan
  std_msgs_HeaderStruct(msg.Header);
  for (int i{0}; i < 21; i++) {
    msg.MessageType[i] = b_cv[i];
  }
  msg.AngleMin = 0.0F;
  msg.AngleMax = 0.0F;
  msg.AngleIncrement = 0.0F;
  msg.TimeIncrement = 0.0F;
  msg.ScanTime = 0.0F;
  msg.RangeMin = 0.0F;
  msg.RangeMax = 0.0F;
  msg.Ranges.set_size(0);
  msg.Intensities.set_size(0);
  //(&msg);
}

// End of code generation (sensor_msgs_LaserScanStruct.cpp)
