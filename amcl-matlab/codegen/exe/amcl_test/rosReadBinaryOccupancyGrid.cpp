//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// rosReadBinaryOccupancyGrid.cpp
//
// Code generation for function 'rosReadBinaryOccupancyGrid'
//

// Include files
#include "rosReadBinaryOccupancyGrid.h"
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "SharedMapProperties.h"
#include "amcl_test_types.h"
#include "binaryOccupancyMap.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace coder {
binaryOccupancyMap *rosReadBinaryOccupancyGrid(
    const nav_msgs_MapMetaDataStruct_T &msg_Info,
    const array<signed char, 1U> &msg_Data,
    matlabshared::autonomous::internal::CircularBuffer &iobj_0,
    matlabshared::autonomous::internal::CircularBufferIndex &iobj_1,
    matlabshared::autonomous::internal::SharedMapProperties &iobj_2,
    binaryOccupancyMap &iobj_3)
{
  matlabshared::autonomous::internal::CircularBufferIndex *b_index;
  matlabshared::autonomous::internal::SharedMapProperties *obj;
  array<double, 1U> values;
  double bufferSize[2];
  double resolution;
  double sz_idx_1;
  int loop_ub;
  bool constVal;
  resolution = 1.0 / msg_Info.Resolution;
  sz_idx_1 = std::round(resolution);
  if (std::abs(sz_idx_1 - resolution) < 1.0E-5) {
    resolution = sz_idx_1;
  }
  iobj_3.HasParent = false;
  iobj_2.GridSize[0] = msg_Info.Height;
  iobj_2.GridSize[1] = msg_Info.Width;
  iobj_2.Resolution = resolution;
  iobj_2.Width = iobj_2.GridSize[1] / iobj_2.Resolution;
  iobj_2.Height = iobj_2.GridSize[0] / iobj_2.Resolution;
  iobj_3.SharedProperties = &iobj_2;
  iobj_3.SharedProperties->GridOriginInLocal[0] = 0.0;
  iobj_3.SharedProperties->GridOriginInLocal[1] = 0.0;
  resolution = iobj_3.SharedProperties->Resolution;
  iobj_3.SharedProperties->LocalOriginInWorld[0] = 0.0;
  iobj_3.SharedProperties->LocalOriginInWorld[1] = 0.0;
  sz_idx_1 = 0.0 * resolution - 0.5;
  bufferSize[0] = sz_idx_1;
  bufferSize[1] = sz_idx_1;
  binaryOccupancyMap::counterFPECeil(bufferSize);
  iobj_3.SharedProperties->LocalOriginInWorldInternal[0] =
      bufferSize[0] / resolution;
  iobj_3.SharedProperties->LocalOriginInWorldInternal[1] =
      bufferSize[1] / resolution;
  iobj_3.DataSize[0] = msg_Info.Height;
  iobj_3.DataSize[1] = msg_Info.Width;
  bufferSize[0] = iobj_3.SharedProperties->GridSize[0];
  bufferSize[1] = iobj_3.SharedProperties->GridSize[1];
  iobj_1.Head[0] = 1.0;
  iobj_1.Size[0] = bufferSize[0];
  iobj_1.Head[1] = 1.0;
  iobj_1.Size[1] = bufferSize[1];
  iobj_1.DropEntireMap = false;
  iobj_1.NewRegions[0] = 0.0;
  iobj_1.NewRegions[1] = 0.0;
  iobj_1.NewRegions[2] = 0.0;
  iobj_1.NewRegions[3] = 0.0;
  iobj_1.DropTwoRegions[0] = false;
  iobj_1.DropTwoRegions[1] = false;
  iobj_3.Index = &iobj_1;
  iobj_3.DefaultValueInternal = false;
  b_index = iobj_3.Index;
  constVal = iobj_3.DefaultValueInternal;
  resolution = b_index->Size[0];
  sz_idx_1 = b_index->Size[1];
  iobj_0.Index = b_index;
  iobj_0.ConstVal = constVal;
  iobj_0.Buffer.set_size(static_cast<int>(resolution),
                         static_cast<int>(sz_idx_1));
  loop_ub = static_cast<int>(resolution) * static_cast<int>(sz_idx_1);
  for (int i{0}; i < loop_ub; i++) {
    iobj_0.Buffer[i] = constVal;
  }
  double b_msg_Info[2];
  iobj_3.Buffer = &iobj_0;
  obj = iobj_3.SharedProperties;
  bufferSize[0] = obj->LocalOriginInWorld[0] + obj->GridOriginInLocal[0];
  bufferSize[1] = obj->LocalOriginInWorld[1] + obj->GridOriginInLocal[1];
  b_msg_Info[0] = msg_Info.Origin.Position.X - bufferSize[0];
  b_msg_Info[1] = msg_Info.Origin.Position.Y - bufferSize[1];
  b_msg_Info[0] += iobj_3.SharedProperties->LocalOriginInWorld[0];
  b_msg_Info[1] += iobj_3.SharedProperties->LocalOriginInWorld[1];
  resolution = iobj_3.SharedProperties->Resolution;
  iobj_3.SharedProperties->LocalOriginInWorld[0] = b_msg_Info[0];
  iobj_3.SharedProperties->LocalOriginInWorld[1] = b_msg_Info[1];
  b_msg_Info[0] = b_msg_Info[0] * resolution - 0.5;
  b_msg_Info[1] = b_msg_Info[1] * resolution - 0.5;
  binaryOccupancyMap::counterFPECeil(b_msg_Info);
  iobj_3.SharedProperties->LocalOriginInWorldInternal[0] =
      b_msg_Info[0] / resolution;
  iobj_3.SharedProperties->LocalOriginInWorldInternal[1] =
      b_msg_Info[1] / resolution;
  values.set_size(msg_Data.size(0));
  loop_ub = msg_Data.size(0);
  for (int i{0}; i < loop_ub; i++) {
    values[i] = msg_Data[i];
  }
  loop_ub = msg_Data.size(0) - 1;
  for (int i{0}; i <= loop_ub; i++) {
    if (msg_Data[i] == -1) {
      values[i] = 0.0;
    }
  }
  for (int i{0}; i <= loop_ub; i++) {
    if ((msg_Data[i] < 50) && (msg_Data[i] != -1)) {
      values[i] = 0.0;
    }
  }
  for (int i{0}; i <= loop_ub; i++) {
    if (msg_Data[i] >= 50) {
      values[i] = 1.0;
    }
  }
  return binaryOccupancyMap::writeToOG(iobj_3, values);
}

} // namespace coder

// End of code generation (rosReadBinaryOccupancyGrid.cpp)
