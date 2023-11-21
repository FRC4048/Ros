//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// wrapToPi.cpp
//
// Code generation for function 'wrapToPi'
//

// Include files
#include "wrapToPi.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "wrapTo2Pi.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace coder {
namespace robotics {
namespace internal {
void wrapToPi(array<double, 1U> &theta)
{
  array<double, 1U> y;
  array<bool, 1U> r;
  array<bool, 1U> x;
  int nx;
  bool b_y;
  bool exitg1;
  nx = theta.size(0);
  y.set_size(theta.size(0));
  for (int k{0}; k < nx; k++) {
    y[k] = std::abs(theta[k]);
  }
  x.set_size(y.size(0));
  nx = y.size(0);
  for (int k{0}; k < nx; k++) {
    x[k] = (y[k] > 3.1415926535897931);
  }
  b_y = false;
  nx = 1;
  exitg1 = false;
  while ((!exitg1) && (nx <= x.size(0))) {
    if (x[nx - 1]) {
      b_y = true;
      exitg1 = true;
    } else {
      nx++;
    }
  }
  if (b_y) {
    y.set_size(theta.size(0));
    nx = theta.size(0);
    for (int k{0}; k < nx; k++) {
      y[k] = theta[k] + 3.1415926535897931;
    }
    theta.set_size(y.size(0));
    nx = y.size(0);
    for (int k{0}; k < nx; k++) {
      double varargin_1;
      varargin_1 = y[k];
      theta[k] =
          ::coder::internal::scalar::b_mod(varargin_1, 6.2831853071795862);
    }
    if (theta.size(0) == y.size(0)) {
      r.set_size(theta.size(0));
      nx = theta.size(0);
      for (int k{0}; k < nx; k++) {
        r[k] = ((theta[k] == 0.0) && (y[k] > 0.0));
      }
    } else {
      binary_expand_op_5(r, theta, y);
    }
    nx = r.size(0) - 1;
    for (int k{0}; k <= nx; k++) {
      if (r[k]) {
        theta[k] = 6.2831853071795862;
      }
    }
    nx = theta.size(0);
    for (int k{0}; k < nx; k++) {
      theta[k] = theta[k] - 3.1415926535897931;
    }
  }
}

} // namespace internal
} // namespace robotics
} // namespace coder

// End of code generation (wrapToPi.cpp)
