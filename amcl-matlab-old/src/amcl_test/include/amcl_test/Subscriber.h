//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// Subscriber.h
//
// Code generation for function 'Subscriber'
//

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

// Include files
#include "amcl_test_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class Subscriber {
public:
  Subscriber *init();
  void callback();
  double get_MessageCount() const;
  float receive(array<float, 1U> &receivedMsg_Ranges, char statusText[7],
                float &receivedMsg_AngleIncrement, float &receivedMsg_RangeMin,
                float &receivedMsg_RangeMax, bool &status) const;
  float get_LatestMessage(array<float, 1U> &lastSubMsg_Ranges,
                          float &lastSubMsg_AngleIncrement,
                          float &lastSubMsg_RangeMin,
                          float &lastSubMsg_RangeMax) const;
  char TopicName[5];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<sensor_msgs::LaserScan, sensor_msgs_LaserScanStruct_T>>
      SubscriberHelper;
  sensor_msgs_LaserScanStruct_T MsgStruct;
};

class b_Subscriber {
public:
  b_Subscriber *init();
  void callback();
  double get_MessageCount() const;
  double get_LatestMessage(double &lastSubMsg_Pose_Pose_Position_Y,
                           double &lastSubMsg_Pose_Pose_Orientation_X,
                           double &lastSubMsg_Pose_Pose_Orientation_Y,
                           double &lastSubMsg_Pose_Pose_Orientation_Z,
                           double &lastSubMsg_Pose_Pose_Orientation_W) const;
  char TopicName[5];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<nav_msgs::Odometry, nav_msgs_OdometryStruct_T>>
      SubscriberHelper;
  nav_msgs_OdometryStruct_T MsgStruct;
};

} // namespace ros
} // namespace coder

#endif
// End of code generation (Subscriber.h)
