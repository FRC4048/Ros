//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// geometry_msgs_TwistStruct.cpp
//
// Code generation for function 'geometry_msgs_TwistStruct'
//

// Include files
#include "geometry_msgs_TwistStruct.h"
#include "amcl_test_types.h"
#include "geometry_msgs_Vector3Struct.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
void geometry_msgs_TwistStruct(geometry_msgs_TwistStruct_T &msg)
{
  static const char b_cv[19]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_', 'm',
                             's', 'g', 's', '/', 'T', 'w', 'i', 's', 't'};
  //  Message struct definition for geometry_msgs/Twist
  for (int i{0}; i < 19; i++) {
    msg.MessageType[i] = b_cv[i];
  }
  msg.Linear = geometry_msgs_Vector3Struct();
  msg.Angular = geometry_msgs_Vector3Struct();
  //(&msg);
}

// End of code generation (geometry_msgs_TwistStruct.cpp)
