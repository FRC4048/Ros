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
  void receive(array<signed char, 1U> &receivedMsg_Data,
               nav_msgs_MapMetaDataStruct_T &receivedMsg_Info) const;
  void get_LatestMessage(array<signed char, 1U> &lastSubMsg_Data,
                         nav_msgs_MapMetaDataStruct_T &lastSubMsg_Info) const;
  char TopicName[4];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<nav_msgs::OccupancyGrid, nav_msgs_OccupancyGridStruct_T>>
      SubscriberHelper;
  nav_msgs_OccupancyGridStruct_T MsgStruct;
};

class b_Subscriber {
public:
  b_Subscriber *init();
  void callback();
  double get_MessageCount() const;
  float receive(array<float, 1U> &receivedMsg_Ranges, char statusText[7],
                float &receivedMsg_AngleIncrement, bool &status) const;
  float get_LatestMessage(array<float, 1U> &lastSubMsg_Ranges,
                          float &lastSubMsg_AngleIncrement) const;
  char TopicName[5];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<sensor_msgs::LaserScan, sensor_msgs_LaserScanStruct_T>>
      SubscriberHelper;
  sensor_msgs_LaserScanStruct_T MsgStruct;
};

class c_Subscriber {
public:
  c_Subscriber *init();
  void callback();
  double get_MessageCount() const;
  double get_LatestMessage(double &lastSubMsg_Y, double &lastSubMsg_Z) const;
  char TopicName[4];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<geometry_msgs::Point, geometry_msgs_PointStruct_T>>
      SubscriberHelper;
  geometry_msgs_PointStruct_T MsgStruct;
};

} // namespace ros
} // namespace coder

#endif
// End of code generation (Subscriber.h)
