//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// Publisher.cpp
//
// Code generation for function 'Publisher'
//

// Include files
#include "Publisher.h"
#include "amcl_test_types.h"
#include "geometry_msgs_PointStruct.h"
#include "rt_nonfinite.h"
#include "mlroscpp_pub.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace ros {
Publisher *Publisher::init()
{
  static const char topic[12]{'/', 'm', 'y', '_', 'm', 's',
                              'g', '_', 'e', 'p', 'i', 'c'};
  Publisher *obj;
  obj = this;
  for (int i{0}; i < 12; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  geometry_msgs_PointStruct();
  obj->PublisherHelper = std::unique_ptr<
      MATLABPublisher<geometry_msgs::Point, geometry_msgs_PointStruct_T>>(
      new MATLABPublisher<geometry_msgs::Point,
                          geometry_msgs_PointStruct_T>()); //();
  MATLABPUBLISHER_createPublisher(obj->PublisherHelper, &obj->TopicName[0],
                                  12.0, obj->BufferSize, obj->IsLatching);
  return obj;
}

geometry_msgs_PointStruct_T Publisher::rosmessage()
{
  return geometry_msgs_PointStruct();
}

} // namespace ros
} // namespace coder

// End of code generation (Publisher.cpp)
