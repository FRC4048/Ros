//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// ixfun.h
//
// Code generation for function 'ixfun'
//

#ifndef IXFUN_H
#define IXFUN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void expand_max(const array<double, 2U> &a, array<double, 2U> &c);

void expand_min(const double a[2], const array<double, 2U> &b,
                array<double, 2U> &c);

void expand_min(const array<double, 2U> &a, const double b[2],
                array<double, 2U> &c);

void expand_mod(const array<double, 2U> &a, const double b[2],
                array<double, 2U> &c);

} // namespace internal
} // namespace coder

#endif
// End of code generation (ixfun.h)
