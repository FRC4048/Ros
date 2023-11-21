//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// ixfun.cpp
//
// Code generation for function 'ixfun'
//

// Include files
#include "ixfun.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
void expand_max(const array<double, 2U> &a, array<double, 2U> &c)
{
  c.set_size(a.size(0), 2);
  if (a.size(0) != 0) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = c.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = std::fmax(a[b_k + a.size(0) * k], 1.0);
      }
    }
  }
}

void expand_min(const double a[2], const array<double, 2U> &b,
                array<double, 2U> &c)
{
  c.set_size(b.size(0), 2);
  if (b.size(0) != 0) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = c.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = std::fmin(a[k], b[b_k + b.size(0) * k]);
      }
    }
  }
}

void expand_min(const array<double, 2U> &a, const double b[2],
                array<double, 2U> &c)
{
  c.set_size(a.size(0), 2);
  if (a.size(0) != 0) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = c.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = std::fmin(a[b_k + a.size(0) * k], b[k]);
      }
    }
  }
}

void expand_mod(const array<double, 2U> &a, const double b[2],
                array<double, 2U> &c)
{
  c.set_size(a.size(0), 2);
  if (a.size(0) != 0) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = c.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = scalar::b_mod(a[b_k + a.size(0) * k], b[k]);
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (ixfun.cpp)
