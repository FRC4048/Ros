//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// odometryMotionModel.h
//
// Code generation for function 'odometryMotionModel'
//

#ifndef ODOMETRYMOTIONMODEL_H
#define ODOMETRYMOTIONMODEL_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class odometryMotionModel {
public:
  odometryMotionModel *clone(odometryMotionModel &iobj_0) const;
  void matlabCodegenDestructor();
  void release();
  ~odometryMotionModel();
  odometryMotionModel();

private:
  void SystemCore_delete();

public:
  bool matlabCodegenIsDeleted;
  int isInitialized;
  double Noise[4];
};

} // namespace coder

#endif
// End of code generation (odometryMotionModel.h)
