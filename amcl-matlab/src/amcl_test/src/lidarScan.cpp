//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// lidarScan.cpp
//
// Code generation for function 'lidarScan'
//

// Include files
#include "lidarScan.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
void binary_expand_op(coder::array<bool, 1U> &in1,
                      const coder::array<bool, 1U> &in2,
                      const coder::array<bool, 1U> &in3)
{
  coder::array<bool, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in3.size(0) == 1) {
    if (in2.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in2.size(0);
    }
  } else {
    loop_ub = in3.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] =
        (in1[i * stride_0_0] && in2[i * stride_1_0] && in3[i * stride_2_0]);
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

void binary_expand_op_1(coder::array<bool, 1U> &in1,
                        const coder::lidarScan &in2)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.InternalAngles.size(0) == 1) {
    loop_ub = in2.InternalRanges.size(0);
  } else {
    loop_ub = in2.InternalAngles.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.InternalRanges.size(0) != 1);
  stride_1_0 = (in2.InternalAngles.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    double d;
    double d1;
    d = in2.InternalRanges[i * stride_0_0];
    d1 = in2.InternalAngles[i * stride_1_0];
    in1[i] = ((!std::isinf(d)) && (!std::isnan(d)) &&
              ((!std::isinf(d1)) && (!std::isnan(d1))));
  }
}

// End of code generation (lidarScan.cpp)
