//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// rosReadCartesian.h
//
// Code generation for function 'rosReadCartesian'
//

#ifndef ROSREADCARTESIAN_H
#define ROSREADCARTESIAN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct sensor_msgs_LaserScanStruct_T;

// Function Declarations
namespace coder {
void rosReadCartesian(const sensor_msgs_LaserScanStruct_T &msg,
                      array<double, 2U> &cart);

}

#endif
// End of code generation (rosReadCartesian.h)
