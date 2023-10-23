//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// geometry_msgs_PoseWithCovarianceStruct.cpp
//
// Code generation for function 'geometry_msgs_PoseWithCovarianceStruct'
//

// Include files
#include "geometry_msgs_PoseWithCovarianceStruct.h"
#include "amcl_test_types.h"
#include "geometry_msgs_PoseStruct.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
void geometry_msgs_PoseWithCovarianceStruct(
    geometry_msgs_PoseWithCovarianceStruct_T &msg)
{
  static const char b_cv[32]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y',
                             '_', 'm', 's', 'g', 's', '/', 'P', 'o',
                             's', 'e', 'W', 'i', 't', 'h', 'C', 'o',
                             'v', 'a', 'r', 'i', 'a', 'n', 'c', 'e'};
  //  Message struct definition for geometry_msgs/PoseWithCovariance
  for (int i{0}; i < 32; i++) {
    msg.MessageType[i] = b_cv[i];
  }
  geometry_msgs_PoseStruct(msg.Pose);
  std::memset(&msg.Covariance[0], 0, 36U * sizeof(double));
  //(&msg);
}

// End of code generation (geometry_msgs_PoseWithCovarianceStruct.cpp)
