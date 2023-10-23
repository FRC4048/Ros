//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// odometryMotionModel.cpp
//
// Code generation for function 'odometryMotionModel'
//

// Include files
#include "odometryMotionModel.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace coder {
void odometryMotionModel::SystemCore_delete()
{
  release();
}

void odometryMotionModel::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    SystemCore_delete();
  }
}

void odometryMotionModel::release()
{
  if (isInitialized == 1) {
    isInitialized = 2;
  }
}

odometryMotionModel *
odometryMotionModel::clone(odometryMotionModel &iobj_0) const
{
  odometryMotionModel *clonedObj;
  clonedObj = &iobj_0;
  iobj_0.isInitialized = 0;
  iobj_0.matlabCodegenIsDeleted = false;
  iobj_0.Noise[0] = Noise[0];
  iobj_0.Noise[1] = Noise[1];
  iobj_0.Noise[2] = Noise[2];
  iobj_0.Noise[3] = Noise[3];
  return clonedObj;
}

odometryMotionModel::odometryMotionModel()
{
  matlabCodegenIsDeleted = true;
}

odometryMotionModel::~odometryMotionModel()
{
  matlabCodegenDestructor();
}

} // namespace coder

// End of code generation (odometryMotionModel.cpp)
