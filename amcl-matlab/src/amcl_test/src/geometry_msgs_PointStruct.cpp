//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// geometry_msgs_PointStruct.cpp
//
// Code generation for function 'geometry_msgs_PointStruct'
//

// Include files
#include "geometry_msgs_PointStruct.h"
#include "amcl_test_types.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
geometry_msgs_PointStruct_T geometry_msgs_PointStruct()
{
  static const geometry_msgs_PointStruct_T b_msg{
      {'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_', 'm', 's', 'g', 's', '/',
       'P', 'o', 'i', 'n', 't'}, // MessageType
      0.0,                       // X
      0.0,                       // Y
      0.0                        // Z
  };
  geometry_msgs_PointStruct_T msg;
  msg = b_msg;
  //  Message struct definition for geometry_msgs/Point
  //(&b_msg);
  return msg;
}

// End of code generation (geometry_msgs_PointStruct.cpp)
