//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// CircularBufferIndex.h
//
// Code generation for function 'CircularBufferIndex'
//

#ifndef CIRCULARBUFFERINDEX_H
#define CIRCULARBUFFERINDEX_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBufferIndex {
public:
  double Head[2];
  double NewRegions[4];
  bool DropEntireMap;
  bool DropTwoRegions[2];
};

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

#endif
// End of code generation (CircularBufferIndex.h)
