//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// CircularBuffer.h
//
// Code generation for function 'CircularBuffer'
//

#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBufferIndex;

}
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

// Type Definitions
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBuffer {
public:
  bool ConstVal;
  CircularBufferIndex *Index;
  bool Buffer[10000];
};

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

#endif
// End of code generation (CircularBuffer.h)
