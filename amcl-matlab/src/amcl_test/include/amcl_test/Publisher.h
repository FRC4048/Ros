//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// Publisher.h
//
// Code generation for function 'Publisher'
//

#ifndef PUBLISHER_H
#define PUBLISHER_H

// Include files
#include "rtwtypes.h"
#include "mlroscpp_pub.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct geometry_msgs_PointStampedStruct_T;

// Type Definitions
namespace coder {
namespace ros {
class Publisher {
public:
  Publisher *init();
  static void rosmessage(geometry_msgs_PointStampedStruct_T &msgFromPub);
  static void rosmessage();
  char TopicName[12];
  double BufferSize;
  bool IsLatching;
  std::unique_ptr<MATLABPublisher<geometry_msgs::PointStamped,
                                  geometry_msgs_PointStampedStruct_T>>
      PublisherHelper;
};

class b_Publisher {
public:
  b_Publisher *init();
  char TopicName[8];
  double BufferSize;
  bool IsLatching;

private:
  std::unique_ptr<MATLABPublisher<geometry_msgs::PointStamped,
                                  geometry_msgs_PointStampedStruct_T>>
      PublisherHelper;
};

} // namespace ros
} // namespace coder

#endif
// End of code generation (Publisher.h)
