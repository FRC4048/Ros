//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// rosReadCartesian.cpp
//
// Code generation for function 'rosReadCartesian'
//

// Include files
#include "rosReadCartesian.h"
#include "SpecialMsgUtil.h"
#include "amcl_test_types.h"
#include "rosReadScanAngles.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace coder {
void rosReadCartesian(const sensor_msgs_LaserScanStruct_T &msg,
                      array<double, 2U> &cart)
{
  array<double, 1U> angles;
  array<double, 1U> cartAngles;
  array<double, 1U> r1;
  array<int, 1U> r;
  float args_RangeLimits_idx_0;
  float rangeLimits_idx_1;
  int end;
  int trueCount;
  rangeLimits_idx_1 = msg.RangeMax;
  args_RangeLimits_idx_0 = msg.RangeMin;
  end = msg.Ranges.size(0) - 1;
  trueCount = 0;
  for (int i{0}; i <= end; i++) {
    if ((!std::isinf(msg.Ranges[i])) && (!std::isnan(msg.Ranges[i])) &&
        (msg.Ranges[i] >= args_RangeLimits_idx_0) &&
        (msg.Ranges[i] <= rangeLimits_idx_1)) {
      trueCount++;
    }
  }
  r.set_size(trueCount);
  trueCount = 0;
  for (int i{0}; i <= end; i++) {
    if ((!std::isinf(msg.Ranges[i])) && (!std::isnan(msg.Ranges[i])) &&
        (msg.Ranges[i] >= args_RangeLimits_idx_0) &&
        (msg.Ranges[i] <= rangeLimits_idx_1)) {
      r[trueCount] = i;
      trueCount++;
    }
  }
  rosReadScanAngles(msg.AngleMin, msg.AngleIncrement, msg.Ranges, angles);
  cartAngles.set_size(r.size(0));
  trueCount = r.size(0);
  r1.set_size(r.size(0));
  for (end = 0; end < trueCount; end++) {
    double d;
    d = angles[r[end]];
    r1[end] = std::cos(d);
    cartAngles[end] = std::sin(d);
  }
  if ((r1.size(0) == r.size(0)) && (cartAngles.size(0) == r.size(0))) {
    cart.set_size(r1.size(0), 2);
    trueCount = r1.size(0);
    for (end = 0; end < trueCount; end++) {
      rangeLimits_idx_1 = msg.Ranges[r[end]];
      cart[end] = static_cast<float>(r1[end]) * rangeLimits_idx_1;
      cart[end + cart.size(0)] =
          static_cast<float>(cartAngles[end]) * rangeLimits_idx_1;
    }
  } else {
    binary_expand_op_1(cart, r1, msg, r, cartAngles);
  }
}

} // namespace coder

// End of code generation (rosReadCartesian.cpp)
