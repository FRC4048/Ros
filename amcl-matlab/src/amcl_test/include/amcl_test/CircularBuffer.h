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
#include "coder_array.h"
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
  void setValueAtIndices(const array<double, 2U> &indices,
                         const array<double, 1U> &values);
  void setBaseMatrix(const array<double, 2U> &region,
                     const array<double, 2U> &newBlock);
  bool ConstVal;
  CircularBufferIndex *Index;
  array<bool, 2U> Buffer;
};

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

// Function Declarations
void binary_expand_op_2(
    coder::matlabshared::autonomous::internal::CircularBuffer *in1,
    const coder::array<double, 2U> &in2, const coder::array<double, 2U> &in3,
    const coder::array<double, 2U> &in4, const coder::array<double, 2U> &in5,
    int in6, int in9, int in10);

#endif
// End of code generation (CircularBuffer.h)
