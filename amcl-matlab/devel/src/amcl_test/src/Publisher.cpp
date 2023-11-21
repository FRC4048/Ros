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
#include "geometry_msgs_PointStampedStruct.h"
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
  geometry_msgs_PointStampedStruct_T r;
  obj = this;
  for (int i{0}; i < 12; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  geometry_msgs_PointStampedStruct(r);
  obj->PublisherHelper =
      std::unique_ptr<MATLABPublisher<geometry_msgs::PointStamped,
                                      geometry_msgs_PointStampedStruct_T>>(
          new MATLABPublisher<geometry_msgs::PointStamped,
                              geometry_msgs_PointStampedStruct_T>()); //();
  MATLABPUBLISHER_createPublisher(obj->PublisherHelper, &obj->TopicName[0],
                                  12.0, obj->BufferSize, obj->IsLatching);
  return obj;
}

b_Publisher *b_Publisher::init()
{
  static const char topic[8]{'/', 'o', 'd', 'o', 'm', 'V', 'i', 's'};
  b_Publisher *obj;
  geometry_msgs_PointStampedStruct_T r;
  obj = this;
  for (int i{0}; i < 8; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  geometry_msgs_PointStampedStruct(r);
  obj->PublisherHelper =
      std::unique_ptr<MATLABPublisher<geometry_msgs::PointStamped,
                                      geometry_msgs_PointStampedStruct_T>>(
          new MATLABPublisher<geometry_msgs::PointStamped,
                              geometry_msgs_PointStampedStruct_T>()); //();
  MATLABPUBLISHER_createPublisher(obj->PublisherHelper, &obj->TopicName[0], 8.0,
                                  obj->BufferSize, obj->IsLatching);
  return obj;
}

void Publisher::rosmessage(geometry_msgs_PointStampedStruct_T &msgFromPub)
{
  geometry_msgs_PointStampedStruct(msgFromPub);
}

void Publisher::rosmessage()
{
  geometry_msgs_PointStampedStruct_T r;
  geometry_msgs_PointStampedStruct(r);
}

} // namespace ros
} // namespace coder

// End of code generation (Publisher.cpp)
