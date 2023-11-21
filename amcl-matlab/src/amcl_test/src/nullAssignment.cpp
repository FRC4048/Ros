//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// nullAssignment.cpp
//
// Code generation for function 'nullAssignment'
//

// Include files
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
void nullAssignment(array<double, 1U> &x, const array<bool, 1U> &idx)
{
  int k0;
  int nxin;
  int nxout;
  nxin = x.size(0);
  nxout = 0;
  k0 = idx.size(0);
  for (int k{0}; k < k0; k++) {
    nxout += idx[k];
  }
  nxout = x.size(0) - nxout;
  k0 = -1;
  for (int k{0}; k < nxin; k++) {
    if ((k + 1 > idx.size(0)) || (!idx[k])) {
      k0++;
      x[k0] = x[k];
    }
  }
  if (nxout < 1) {
    nxout = 0;
  }
  x.set_size(nxout);
}

} // namespace internal
} // namespace coder

// End of code generation (nullAssignment.cpp)
