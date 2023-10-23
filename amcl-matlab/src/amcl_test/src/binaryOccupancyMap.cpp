//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// binaryOccupancyMap.cpp
//
// Code generation for function 'binaryOccupancyMap'
//

// Include files
#include "binaryOccupancyMap.h"
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "SharedMapProperties.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace coder {
binaryOccupancyMap *binaryOccupancyMap::copy(
    matlabshared::autonomous::internal::CircularBuffer *iobj_0,
    matlabshared::autonomous::internal::CircularBufferIndex *iobj_1,
    matlabshared::autonomous::internal::SharedMapProperties *iobj_2,
    binaryOccupancyMap *iobj_3)
{
  binaryOccupancyMap *cpObj;
  matlabshared::autonomous::internal::CircularBuffer *obj;
  matlabshared::autonomous::internal::CircularBufferIndex *b_obj;
  matlabshared::autonomous::internal::SharedMapProperties *varargin_1;
  double obj_idx_2;
  double obj_idx_3;
  double varargin_1_idx_0;
  double varargin_1_idx_1;
  bool matrix[10000];
  bool obj_idx_0;
  bool obj_idx_1;
  iobj_3->HasParent = false;
  cpObj = iobj_3;
  varargin_1 = SharedProperties;
  varargin_1_idx_0 = varargin_1->GridOriginInLocal[0];
  varargin_1_idx_1 = varargin_1->GridOriginInLocal[1];
  iobj_2->GridOriginInLocal[0] = varargin_1_idx_0;
  iobj_2->GridOriginInLocal[1] = varargin_1_idx_1;
  varargin_1_idx_0 = varargin_1->LocalOriginInWorld[0];
  varargin_1_idx_1 = varargin_1->LocalOriginInWorld[1];
  iobj_2->LocalOriginInWorld[0] = varargin_1_idx_0;
  iobj_2->LocalOriginInWorld[1] = varargin_1_idx_1;
  varargin_1_idx_0 = varargin_1->LocalOriginInWorldInternal[0];
  varargin_1_idx_1 = varargin_1->LocalOriginInWorldInternal[1];
  iobj_2->LocalOriginInWorldInternal[0] = varargin_1_idx_0;
  iobj_2->LocalOriginInWorldInternal[1] = varargin_1_idx_1;
  iobj_3->SharedProperties = iobj_2;
  iobj_3->DefaultValueInternal = DefaultValueInternal;
  obj = Buffer;
  b_obj = obj->Index;
  iobj_1->Head[0] = 1.0;
  iobj_1->Head[1] = 1.0;
  iobj_1->DropEntireMap = false;
  iobj_1->NewRegions[0] = 0.0;
  iobj_1->NewRegions[1] = 0.0;
  iobj_1->NewRegions[2] = 0.0;
  iobj_1->NewRegions[3] = 0.0;
  iobj_1->DropTwoRegions[0] = false;
  iobj_1->DropTwoRegions[1] = false;
  varargin_1_idx_0 = b_obj->Head[0];
  varargin_1_idx_1 = b_obj->Head[1];
  iobj_1->Head[0] = varargin_1_idx_0;
  iobj_1->Head[1] = varargin_1_idx_1;
  varargin_1_idx_0 = b_obj->NewRegions[0];
  varargin_1_idx_1 = b_obj->NewRegions[1];
  obj_idx_2 = b_obj->NewRegions[2];
  obj_idx_3 = b_obj->NewRegions[3];
  iobj_1->NewRegions[0] = varargin_1_idx_0;
  iobj_1->NewRegions[1] = varargin_1_idx_1;
  iobj_1->NewRegions[2] = obj_idx_2;
  iobj_1->NewRegions[3] = obj_idx_3;
  iobj_1->DropEntireMap = b_obj->DropEntireMap;
  obj_idx_0 = b_obj->DropTwoRegions[0];
  obj_idx_1 = b_obj->DropTwoRegions[1];
  iobj_1->DropTwoRegions[0] = obj_idx_0;
  iobj_1->DropTwoRegions[1] = obj_idx_1;
  obj_idx_0 = obj->ConstVal;
  for (int i{0}; i < 10000; i++) {
    matrix[i] = obj->Buffer[i];
  }
  iobj_0->Index = iobj_1;
  iobj_0->ConstVal = obj_idx_0;
  for (int i{0}; i < 10000; i++) {
    iobj_0->Buffer[i] = matrix[i];
  }
  iobj_3->Buffer = iobj_0;
  iobj_3->Index = iobj_3->Buffer->Index;
  return cpObj;
}

binaryOccupancyMap *binaryOccupancyMap::init(
    matlabshared::autonomous::internal::CircularBuffer &iobj_0,
    matlabshared::autonomous::internal::CircularBufferIndex &iobj_1,
    matlabshared::autonomous::internal::SharedMapProperties &iobj_2)
{
  binaryOccupancyMap *obj;
  matlabshared::autonomous::internal::CircularBufferIndex *b_index;
  bool constVal;
  obj = this;
  obj->HasParent = false;
  obj->SharedProperties = &iobj_2;
  obj->SharedProperties->GridOriginInLocal[0] = 0.0;
  obj->SharedProperties->GridOriginInLocal[1] = 0.0;
  obj->SharedProperties->LocalOriginInWorld[0] = 0.0;
  obj->SharedProperties->LocalOriginInWorld[1] = 0.0;
  obj->SharedProperties->LocalOriginInWorldInternal[0] = -0.0;
  obj->SharedProperties->LocalOriginInWorldInternal[1] = -0.0;
  iobj_1.Head[0] = 1.0;
  iobj_1.Head[1] = 1.0;
  iobj_1.DropEntireMap = false;
  iobj_1.NewRegions[0] = 0.0;
  iobj_1.NewRegions[1] = 0.0;
  iobj_1.NewRegions[2] = 0.0;
  iobj_1.NewRegions[3] = 0.0;
  iobj_1.DropTwoRegions[0] = false;
  iobj_1.DropTwoRegions[1] = false;
  obj->Index = &iobj_1;
  obj->DefaultValueInternal = false;
  b_index = obj->Index;
  constVal = obj->DefaultValueInternal;
  iobj_0.Index = b_index;
  iobj_0.ConstVal = constVal;
  for (int i{0}; i < 10000; i++) {
    iobj_0.Buffer[i] = constVal;
  }
  obj->Buffer = &iobj_0;
  return obj;
}

} // namespace coder

// End of code generation (binaryOccupancyMap.cpp)
