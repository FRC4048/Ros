//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// SpecialMsgUtil.cpp
//
// Code generation for function 'SpecialMsgUtil'
//

// Include files
#include "SpecialMsgUtil.h"
#include "amcl_test_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
void binary_expand_op_1(coder::array<double, 2U> &in1,
                        const coder::array<double, 1U> &in2,
                        const sensor_msgs_LaserScanStruct_T &in3,
                        const coder::array<int, 1U> &in4,
                        const coder::array<double, 1U> &in5)
{
  coder::array<double, 1U> b_in2;
  coder::array<double, 1U> b_in5;
  int loop_ub;
  int stride_0_0;
  int stride_1_0_tmp;
  if (in4.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  b_in2.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0_tmp = (in4.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] = static_cast<float>(in2[i * stride_0_0]) *
               in3.Ranges[in4[i * stride_1_0_tmp]];
  }
  if (in4.size(0) == 1) {
    loop_ub = in5.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  b_in5.set_size(loop_ub);
  stride_0_0 = (in5.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in5[i] = static_cast<float>(in5[i * stride_0_0]) *
               in3.Ranges[in4[i * stride_1_0_tmp]];
  }
  in1.set_size(b_in2.size(0), 2);
  loop_ub = b_in2.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
  loop_ub = b_in5.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i + in1.size(0)] = b_in5[i];
  }
}

// End of code generation (SpecialMsgUtil.cpp)
