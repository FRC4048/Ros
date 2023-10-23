//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// binaryOccupancyMap.h
//
// Code generation for function 'binaryOccupancyMap'
//

#ifndef BINARYOCCUPANCYMAP_H
#define BINARYOCCUPANCYMAP_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class SharedMapProperties;

class CircularBufferIndex;

class CircularBuffer;

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder

// Type Definitions
namespace coder {
class binaryOccupancyMap {
public:
  binaryOccupancyMap *
  init(matlabshared::autonomous::internal::CircularBuffer &iobj_0,
       matlabshared::autonomous::internal::CircularBufferIndex &iobj_1,
       matlabshared::autonomous::internal::SharedMapProperties &iobj_2);
  binaryOccupancyMap *
  copy(matlabshared::autonomous::internal::CircularBuffer *iobj_0,
       matlabshared::autonomous::internal::CircularBufferIndex *iobj_1,
       matlabshared::autonomous::internal::SharedMapProperties *iobj_2,
       binaryOccupancyMap *iobj_3);
  matlabshared::autonomous::internal::SharedMapProperties *SharedProperties;
  matlabshared::autonomous::internal::CircularBufferIndex *Index;
  matlabshared::autonomous::internal::CircularBuffer *Buffer;
  bool DefaultValueInternal;
  bool HasParent;
};

} // namespace coder

#endif
// End of code generation (binaryOccupancyMap.h)