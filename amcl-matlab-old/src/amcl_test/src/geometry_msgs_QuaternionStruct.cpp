//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// geometry_msgs_QuaternionStruct.cpp
//
// Code generation for function 'geometry_msgs_QuaternionStruct'
//

// Include files
#include "geometry_msgs_QuaternionStruct.h"
#include "amcl_test_types.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
geometry_msgs_QuaternionStruct_T geometry_msgs_QuaternionStruct()
{
  static const geometry_msgs_QuaternionStruct_T b_msg{
      {'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_', 'm', 's', 'g', 's',
       '/', 'Q', 'u', 'a', 't', 'e', 'r', 'n', 'i', 'o', 'n'}, // MessageType
      0.0,                                                     // X
      0.0,                                                     // Y
      0.0,                                                     // Z
      0.0                                                      // W
  };
  geometry_msgs_QuaternionStruct_T msg;
  msg = b_msg;
  //  Message struct definition for geometry_msgs/Quaternion
  //(&b_msg);
  return msg;
}

// End of code generation (geometry_msgs_QuaternionStruct.cpp)