//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// rosReadLidarScan.h
//
// Code generation for function 'rosReadLidarScan'
//

#ifndef ROSREADLIDARSCAN_H
#define ROSREADLIDARSCAN_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct sensor_msgs_LaserScanStruct_T;

namespace coder {
class lidarScan;

}

// Function Declarations
namespace coder {
void rosReadLidarScan(const sensor_msgs_LaserScanStruct_T &msg,
                      lidarScan &lidarScanObj);

}

#endif
// End of code generation (rosReadLidarScan.h)
