//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// geometry_msgs_PointStampedStruct.cpp
//
// Code generation for function 'geometry_msgs_PointStampedStruct'
//

// Include files
#include "geometry_msgs_PointStampedStruct.h"
#include "amcl_test_types.h"
#include "geometry_msgs_PointStruct.h"
#include "rt_nonfinite.h"
#include "std_msgs_HeaderStruct.h"
#include <cstring>

// Function Definitions
void geometry_msgs_PointStampedStruct(geometry_msgs_PointStampedStruct_T &msg)
{
  static const char b_cv[26]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_',
                             'm', 's', 'g', 's', '/', 'P', 'o', 'i', 'n',
                             't', 'S', 't', 'a', 'm', 'p', 'e', 'd'};
  //  Message struct definition for geometry_msgs/PointStamped
  for (int i{0}; i < 26; i++) {
    msg.MessageType[i] = b_cv[i];
  }
  std_msgs_HeaderStruct(msg.Header);
  msg.Point = geometry_msgs_PointStruct();
  //(&msg);
}

// End of code generation (geometry_msgs_PointStampedStruct.cpp)
