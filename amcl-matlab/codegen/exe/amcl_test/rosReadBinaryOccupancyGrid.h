//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// rosReadBinaryOccupancyGrid.h
//
// Code generation for function 'rosReadBinaryOccupancyGrid'
//

#ifndef ROSREADBINARYOCCUPANCYGRID_H
#define ROSREADBINARYOCCUPANCYGRID_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct nav_msgs_MapMetaDataStruct_T;

namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBuffer;

class CircularBufferIndex;

class SharedMapProperties;

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
class binaryOccupancyMap;

} // namespace coder

// Function Declarations
namespace coder {
binaryOccupancyMap *rosReadBinaryOccupancyGrid(
    const nav_msgs_MapMetaDataStruct_T &msg_Info,
    const array<signed char, 1U> &msg_Data,
    matlabshared::autonomous::internal::CircularBuffer &iobj_0,
    matlabshared::autonomous::internal::CircularBufferIndex &iobj_1,
    matlabshared::autonomous::internal::SharedMapProperties &iobj_2,
    binaryOccupancyMap &iobj_3);

}

#endif
// End of code generation (rosReadBinaryOccupancyGrid.h)
