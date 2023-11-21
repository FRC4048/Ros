//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// wrapTo2Pi.cpp
//
// Code generation for function 'wrapTo2Pi'
//

// Include files
#include "wrapTo2Pi.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
void binary_expand_op_2(coder::array<bool, 1U> &in1,
                        const coder::array<double, 1U> &in2,
                        const coder::array<double, 1U> &in3)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = ((in2[i * stride_0_0] == 0.0) && (in3[i * stride_1_0] > 0.0));
  }
}

// End of code generation (wrapTo2Pi.cpp)
