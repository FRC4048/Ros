//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// TransformationTree.h
//
// Code generation for function 'TransformationTree'
//

#ifndef TRANSFORMATIONTREE_H
#define TRANSFORMATIONTREE_H

// Include files
#include "rtwtypes.h"
#include "mlroscpp_transform.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct geometry_msgs_TransformStampedStruct_T;

// Type Definitions
namespace coder {
namespace ros {
class TransformationTree {
public:
  void waitForTransform();
  bool canTransform();
  void getTransform(geometry_msgs_TransformStampedStruct_T &tform);
  MATLABROSTransform TransformHelper;
};

} // namespace ros
} // namespace coder

#endif
// End of code generation (TransformationTree.h)
