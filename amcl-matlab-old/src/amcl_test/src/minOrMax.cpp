//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// minOrMax.cpp
//
// Code generation for function 'minOrMax'
//

// Include files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
double minimum(const double x[2])
{
  double ex;
  if ((x[0] > x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
    ex = x[1];
  } else {
    ex = x[0];
  }
  return ex;
}

} // namespace internal
} // namespace coder

// End of code generation (minOrMax.cpp)
