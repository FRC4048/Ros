//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// geometry_msgs_TransformStampedStruct.cpp
//
// Code generation for function 'geometry_msgs_TransformStampedStruct'
//

// Include files
#include "geometry_msgs_TransformStampedStruct.h"
#include "amcl_test_types.h"
#include "geometry_msgs_TransformStruct.h"
#include "rt_nonfinite.h"
#include "std_msgs_HeaderStruct.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
void geometry_msgs_TransformStampedStruct(
    geometry_msgs_TransformStampedStruct_T &msg)
{
  static const char b_cv[30]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_', 'm',
                             's', 'g', 's', '/', 'T', 'r', 'a', 'n', 's', 'f',
                             'o', 'r', 'm', 'S', 't', 'a', 'm', 'p', 'e', 'd'};
  //  Message struct definition for geometry_msgs/TransformStamped
  std_msgs_HeaderStruct(msg.Header);
  geometry_msgs_TransformStruct(msg.Transform);
  for (int i{0}; i < 30; i++) {
    msg.MessageType[i] = b_cv[i];
  }
  msg.ChildFrameId.set_size(1, 0);
  //(&msg);
}

// End of code generation (geometry_msgs_TransformStampedStruct.cpp)
