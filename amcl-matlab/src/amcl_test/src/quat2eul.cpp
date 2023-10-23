//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// quat2eul.cpp
//
// Code generation for function 'quat2eul'
//

// Include files
#include "quat2eul.h"
#include "amcl_test_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Declarations
static void binary_expand_op(double in1[3],
                             const coder::array<signed char, 2U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4);

// Function Definitions
static void binary_expand_op(double in1[3],
                             const coder::array<signed char, 2U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  loop_ub = in2.size(1);
  for (int i{0}; i < loop_ub; i++) {
    in1[in2[i]] = -in3[i * stride_0_0] * 2.0 * in4[i * stride_1_0];
  }
}

namespace coder {
void quat2eul(double q[4], double eul[3])
{
  array<double, 1U> r;
  array<double, 1U> x;
  array<signed char, 2U> r1;
  double aSinInput;
  double b_eul_tmp;
  double c_eul_tmp;
  double d_eul_tmp;
  double eul_tmp;
  double unnamed_idx_0;
  int b_trueCount;
  int k;
  int trueCount;
  bool b;
  aSinInput = 1.0 / std::sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) +
                              q[3] * q[3]);
  q[0] *= aSinInput;
  q[1] *= aSinInput;
  q[2] *= aSinInput;
  q[3] *= aSinInput;
  aSinInput = -2.0 * (q[1] * q[3] - q[0] * q[2]);
  unnamed_idx_0 = aSinInput;
  if (aSinInput >= 0.99999999999999778) {
    unnamed_idx_0 = 1.0;
  }
  if (aSinInput <= -0.99999999999999778) {
    unnamed_idx_0 = -1.0;
  }
  eul_tmp = q[0] * q[0];
  b_eul_tmp = q[1] * q[1];
  c_eul_tmp = q[2] * q[2];
  d_eul_tmp = q[3] * q[3];
  eul[0] = rt_atan2d_snf(2.0 * (q[1] * q[2] + q[0] * q[3]),
                         ((eul_tmp + b_eul_tmp) - c_eul_tmp) - d_eul_tmp);
  eul[1] = std::asin(unnamed_idx_0);
  eul[2] = rt_atan2d_snf(2.0 * (q[2] * q[3] + q[0] * q[1]),
                         ((eul_tmp - b_eul_tmp) - c_eul_tmp) + d_eul_tmp);
  trueCount = 0;
  b = ((aSinInput >= 0.99999999999999778) ||
       (aSinInput <= -0.99999999999999778));
  if (b) {
    trueCount = 1;
  }
  x.set_size(trueCount);
  for (k = 0; k < trueCount; k++) {
    x[0] = unnamed_idx_0;
  }
  b_trueCount = 0;
  if (b) {
    b_trueCount = 1;
  }
  for (k = 0; k < b_trueCount; k++) {
    if (std::isnan(x[0])) {
      x[0] = rtNaN;
    } else if (x[0] < 0.0) {
      x[0] = -1.0;
    } else {
      x[0] = (x[0] > 0.0);
    }
  }
  b_trueCount = 0;
  if (b) {
    b_trueCount = 1;
  }
  r.set_size(b_trueCount);
  for (k = 0; k < b_trueCount; k++) {
    r[0] = rt_atan2d_snf(q[1], q[0]);
  }
  k = 0;
  if (b) {
    k = 1;
  }
  r1.set_size(1, k);
  if (b) {
    r1[0] = 0;
  }
  if (trueCount == b_trueCount) {
    if (k - 1 >= 0) {
      eul[0] = -x[0] * 2.0 * r[0];
    }
  } else {
    binary_expand_op(eul, r1, x, r);
  }
  trueCount = 0;
  if (b) {
    trueCount = 1;
  }
  if (trueCount - 1 >= 0) {
    eul[2] = 0.0;
  }
}

} // namespace coder

// End of code generation (quat2eul.cpp)
