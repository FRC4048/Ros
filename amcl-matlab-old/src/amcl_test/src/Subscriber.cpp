//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// Subscriber.cpp
//
// Code generation for function 'Subscriber'
//

// Include files
#include "Subscriber.h"
#include "amcl_test_types.h"
#include "nav_msgs_OdometryStruct.h"
#include "rt_nonfinite.h"
#include "sensor_msgs_LaserScanStruct.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include "ros/duration.h"
#include "ros/time.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace ros {
void Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

void b_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

float Subscriber::get_LatestMessage(array<float, 1U> &lastSubMsg_Ranges,
                                    float &lastSubMsg_AngleIncrement,
                                    float &lastSubMsg_RangeMin,
                                    float &lastSubMsg_RangeMax) const
{
  float lastSubMsg_AngleMin;
  int loop_ub;
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  lastSubMsg_Ranges.set_size(MsgStruct.Ranges.size(0));
  loop_ub = MsgStruct.Ranges.size(0);
  for (int i{0}; i < loop_ub; i++) {
    lastSubMsg_Ranges[i] = MsgStruct.Ranges[i];
  }
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
  lastSubMsg_AngleMin = MsgStruct.AngleMin;
  lastSubMsg_AngleIncrement = MsgStruct.AngleIncrement;
  lastSubMsg_RangeMin = MsgStruct.RangeMin;
  lastSubMsg_RangeMax = MsgStruct.RangeMax;
  return lastSubMsg_AngleMin;
}

double b_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

double Subscriber::get_MessageCount() const
{
  return MessageCount;
}

double b_Subscriber::get_LatestMessage(
    double &lastSubMsg_Pose_Pose_Position_Y,
    double &lastSubMsg_Pose_Pose_Orientation_X,
    double &lastSubMsg_Pose_Pose_Orientation_Y,
    double &lastSubMsg_Pose_Pose_Orientation_Z,
    double &lastSubMsg_Pose_Pose_Orientation_W) const
{
  double lastSubMsg_Pose_Pose_Position_X;
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  lastSubMsg_Pose_Pose_Position_X = MsgStruct.Pose.Pose.Position.X;
  lastSubMsg_Pose_Pose_Position_Y = MsgStruct.Pose.Pose.Position.Y;
  lastSubMsg_Pose_Pose_Orientation_X = MsgStruct.Pose.Pose.Orientation.X;
  lastSubMsg_Pose_Pose_Orientation_Y = MsgStruct.Pose.Pose.Orientation.Y;
  lastSubMsg_Pose_Pose_Orientation_Z = MsgStruct.Pose.Pose.Orientation.Z;
  lastSubMsg_Pose_Pose_Orientation_W = MsgStruct.Pose.Pose.Orientation.W;
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
  return lastSubMsg_Pose_Pose_Position_X;
}

Subscriber *Subscriber::init()
{
  static const char topic[5]{'/', 's', 'c', 'a', 'n'};
  Subscriber *obj;
  obj = this;
  for (int i{0}; i < 5; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->MessageCount = 0.0;
  sensor_msgs_LaserScanStruct(obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  obj->SubscriberHelper = std::unique_ptr<
      MATLABSubscriber<sensor_msgs::LaserScan, sensor_msgs_LaserScanStruct_T>>(
      new MATLABSubscriber<sensor_msgs::LaserScan,
                           sensor_msgs_LaserScanStruct_T>(
          structPtr, [this] { this->callback(); })); //();
  MATLABSUBSCRIBER_createSubscriber(obj->SubscriberHelper, &obj->TopicName[0],
                                    5.0, obj->BufferSize);
  obj->callback();
  return obj;
}

b_Subscriber *b_Subscriber::init()
{
  static const char topic[5]{'/', 'o', 'd', 'o', 'm'};
  b_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 5; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->MessageCount = 0.0;
  nav_msgs_OdometryStruct(obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  obj->SubscriberHelper = std::unique_ptr<
      MATLABSubscriber<nav_msgs::Odometry, nav_msgs_OdometryStruct_T>>(
      new MATLABSubscriber<nav_msgs::Odometry, nav_msgs_OdometryStruct_T>(
          structPtr, [this] { this->callback(); })); //();
  MATLABSUBSCRIBER_createSubscriber(obj->SubscriberHelper, &obj->TopicName[0],
                                    5.0, obj->BufferSize);
  obj->callback();
  return obj;
}

float Subscriber::receive(array<float, 1U> &receivedMsg_Ranges,
                          char statusText[7], float &receivedMsg_AngleIncrement,
                          float &receivedMsg_RangeMin,
                          float &receivedMsg_RangeMax, bool &status) const
{
  ::ros::Duration tDur;
  ::ros::Time tStop;
  double nMessages;
  bool exitg1;
  nMessages = get_MessageCount();
  tDur = tDur.fromSec(10.0);
  tStop = ::ros::Time::now() + (tDur);
  status = true;
  exitg1 = false;
  while ((!exitg1) && (get_MessageCount() == nMessages)) {
    ::ros::Time currentTime;
    currentTime = ::ros::Time::now();
    if (currentTime >= tStop) {
      status = false;
      exitg1 = true;
    }
  }
  getStatusText(status, &statusText[0]);
  return get_LatestMessage(receivedMsg_Ranges, receivedMsg_AngleIncrement,
                           receivedMsg_RangeMin, receivedMsg_RangeMax);
}

} // namespace ros
} // namespace coder

// End of code generation (Subscriber.cpp)
