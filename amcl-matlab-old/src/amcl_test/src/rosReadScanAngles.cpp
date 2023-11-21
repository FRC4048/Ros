//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// rosReadScanAngles.cpp
//
// Code generation for function 'rosReadScanAngles'
//

// Include files
#include "rosReadScanAngles.h"
#include "rt_nonfinite.h"
#include "wrapToPi.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace coder {
void rosReadScanAngles(float msg_AngleMin, float msg_AngleIncrement,
                       const array<float, 1U> &msg_Ranges,
                       array<double, 1U> &angles)
{
  array<int, 2U> r;
  int loop_ub;
  if (msg_Ranges.size(0) - 1 < 0) {
    r.set_size(1, 0);
  } else {
    r.set_size(1, msg_Ranges.size(0));
    loop_ub = msg_Ranges.size(0);
    for (int i{0}; i < loop_ub; i++) {
      r[i] = i;
    }
  }
  angles.set_size(r.size(1));
  loop_ub = r.size(1);
  for (int i{0}; i < loop_ub; i++) {
    angles[i] = msg_AngleMin + static_cast<float>(r[i]) * msg_AngleIncrement;
  }
  robotics::internal::wrapToPi(angles);
}

} // namespace coder

// End of code generation (rosReadScanAngles.cpp)
