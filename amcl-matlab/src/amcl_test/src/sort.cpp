//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// sort.cpp
//
// Code generation for function 'sort'
//

// Include files
#include "sort.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
void sort(double x[2])
{
  if ((!(x[0] <= x[1])) && (!std::isnan(x[1]))) {
    double tmp;
    tmp = x[0];
    x[0] = x[1];
    x[1] = tmp;
  }
}

} // namespace internal
} // namespace coder

// End of code generation (sort.cpp)
