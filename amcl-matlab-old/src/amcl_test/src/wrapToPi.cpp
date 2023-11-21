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
  bool exitg1;
  bool rEQ0;
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
  rEQ0 = false;
  nx = 1;
  exitg1 = false;
  while ((!exitg1) && (nx <= x.size(0))) {
    if (x[nx - 1]) {
      rEQ0 = true;
      exitg1 = true;
    } else {
      nx++;
    }
  }
  if (rEQ0) {
    y.set_size(theta.size(0));
    nx = theta.size(0);
    for (int k{0}; k < nx; k++) {
      y[k] = theta[k] + 3.1415926535897931;
    }
    theta.set_size(y.size(0));
    nx = y.size(0);
    for (int k{0}; k < nx; k++) {
      double varargin_1;
      double varargout_1;
      varargin_1 = y[k];
      if (std::isnan(varargin_1) || std::isinf(varargin_1)) {
        varargout_1 = rtNaN;
      } else if (varargin_1 == 0.0) {
        varargout_1 = 0.0;
      } else {
        varargout_1 = std::fmod(varargin_1, 6.2831853071795862);
        rEQ0 = (varargout_1 == 0.0);
        if (!rEQ0) {
          double q;
          q = std::abs(varargin_1 / 6.2831853071795862);
          rEQ0 =
              !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
        }
        if (rEQ0) {
          varargout_1 = 0.0;
        } else if (varargin_1 < 0.0) {
          varargout_1 += 6.2831853071795862;
        }
      }
      theta[k] = varargout_1;
    }
    if (theta.size(0) == y.size(0)) {
      r.set_size(theta.size(0));
      nx = theta.size(0);
      for (int k{0}; k < nx; k++) {
        r[k] = ((theta[k] == 0.0) && (y[k] > 0.0));
      }
    } else {
      binary_expand_op_2(r, theta, y);
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
