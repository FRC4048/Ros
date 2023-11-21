//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// geometry_msgs_PoseStruct.cpp
//
// Code generation for function 'geometry_msgs_PoseStruct'
//

// Include files
#include "geometry_msgs_PoseStruct.h"
#include "amcl_test_types.h"
#include "geometry_msgs_PointStruct.h"
#include "geometry_msgs_QuaternionStruct.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
void geometry_msgs_PoseStruct(geometry_msgs_PoseStruct_T &msg)
{
  static const char b_cv[18]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_',
                             'm', 's', 'g', 's', '/', 'P', 'o', 's', 'e'};
  //  Message struct definition for geometry_msgs/Pose
  for (int i{0}; i < 18; i++) {
    msg.MessageType[i] = b_cv[i];
  }
  msg.Position = geometry_msgs_PointStruct();
  msg.Orientation = geometry_msgs_QuaternionStruct();
  //(&msg);
}

// End of code generation (geometry_msgs_PoseStruct.cpp)