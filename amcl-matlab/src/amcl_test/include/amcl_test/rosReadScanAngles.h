//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// rosReadScanAngles.h
//
// Code generation for function 'rosReadScanAngles'
//

#ifndef ROSREADSCANANGLES_H
#define ROSREADSCANANGLES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void rosReadScanAngles(float msg_AngleMin, float msg_AngleIncrement,
                       const array<float, 1U> &msg_Ranges,
                       array<double, 1U> &angles);

}

#endif
// End of code generation (rosReadScanAngles.h)
