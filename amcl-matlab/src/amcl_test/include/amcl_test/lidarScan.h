//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// lidarScan.h
//
// Code generation for function 'lidarScan'
//

#ifndef LIDARSCAN_H
#define LIDARSCAN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class lidarScan {
public:
  array<double, 1U> InternalRanges;
  array<double, 1U> InternalAngles;
  bool ContainsOnlyFiniteData;
};

} // namespace coder

// Function Declarations
void binary_expand_op(coder::array<bool, 1U> &in1,
                      const coder::array<bool, 1U> &in2,
                      const coder::array<bool, 1U> &in3);

void binary_expand_op_1(coder::array<bool, 1U> &in1,
                        const coder::lidarScan &in2);

#endif
// End of code generation (lidarScan.h)
