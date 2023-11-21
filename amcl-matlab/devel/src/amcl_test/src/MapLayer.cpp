//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// MapLayer.cpp
//
// Code generation for function 'MapLayer'
//

// Include files
#include "MapLayer.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
void binary_expand_op_3(coder::array<double, 2U> &in1,
                        const coder::array<double, 2U> &in2)
{
  coder::array<double, 2U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(loop_ub, 2);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] = (in1[i1 * stride_0_0 + in1.size(0) * i] -
                                       in2[i1 * stride_1_0 + in2.size(0) * i]) +
                                      1.0;
    }
  }
  in1.set_size(b_in1.size(0), 2);
  loop_ub = b_in1.size(0);
  for (int i{0}; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
}

// End of code generation (MapLayer.cpp)
