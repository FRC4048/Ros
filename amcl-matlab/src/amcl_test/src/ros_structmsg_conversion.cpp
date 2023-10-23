#include "ros_structmsg_conversion.h"


// Conversions between geometry_msgs_PointStruct_T and geometry_msgs::Point

void struct2msg(geometry_msgs::Point* msgPtr, geometry_msgs_PointStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  msgPtr->x =  structPtr->X;
  msgPtr->y =  structPtr->Y;
  msgPtr->z =  structPtr->Z;
}

void msg2struct(geometry_msgs_PointStruct_T* structPtr, geometry_msgs::Point const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  structPtr->X =  msgPtr->x;
  structPtr->Y =  msgPtr->y;
  structPtr->Z =  msgPtr->z;
}


// Conversions between geometry_msgs_PoseStruct_T and geometry_msgs::Pose

void struct2msg(geometry_msgs::Pose* msgPtr, geometry_msgs_PoseStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  struct2msg(&msgPtr->orientation, &structPtr->Orientation);
  struct2msg(&msgPtr->position, &structPtr->Position);
}

void msg2struct(geometry_msgs_PoseStruct_T* structPtr, geometry_msgs::Pose const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  msg2struct(&structPtr->Orientation, &msgPtr->orientation);
  msg2struct(&structPtr->Position, &msgPtr->position);
}


// Conversions between geometry_msgs_PoseWithCovarianceStruct_T and geometry_msgs::PoseWithCovariance

void struct2msg(geometry_msgs::PoseWithCovariance* msgPtr, geometry_msgs_PoseWithCovarianceStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertFromStructPrimitiveArray(msgPtr->covariance, structPtr->Covariance);
  struct2msg(&msgPtr->pose, &structPtr->Pose);
}

void msg2struct(geometry_msgs_PoseWithCovarianceStruct_T* structPtr, geometry_msgs::PoseWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertToStructPrimitiveArray(structPtr->Covariance, msgPtr->covariance);
  msg2struct(&structPtr->Pose, &msgPtr->pose);
}


// Conversions between geometry_msgs_QuaternionStruct_T and geometry_msgs::Quaternion

void struct2msg(geometry_msgs::Quaternion* msgPtr, geometry_msgs_QuaternionStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr->w =  structPtr->W;
  msgPtr->x =  structPtr->X;
  msgPtr->y =  structPtr->Y;
  msgPtr->z =  structPtr->Z;
}

void msg2struct(geometry_msgs_QuaternionStruct_T* structPtr, geometry_msgs::Quaternion const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  structPtr->W =  msgPtr->w;
  structPtr->X =  msgPtr->x;
  structPtr->Y =  msgPtr->y;
  structPtr->Z =  msgPtr->z;
}


// Conversions between geometry_msgs_TransformStruct_T and geometry_msgs::Transform

void struct2msg(geometry_msgs::Transform* msgPtr, geometry_msgs_TransformStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  struct2msg(&msgPtr->rotation, &structPtr->Rotation);
  struct2msg(&msgPtr->translation, &structPtr->Translation);
}

void msg2struct(geometry_msgs_TransformStruct_T* structPtr, geometry_msgs::Transform const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  msg2struct(&structPtr->Rotation, &msgPtr->rotation);
  msg2struct(&structPtr->Translation, &msgPtr->translation);
}


// Conversions between geometry_msgs_TransformStampedStruct_T and geometry_msgs::TransformStamped

void struct2msg(geometry_msgs::TransformStamped* msgPtr, geometry_msgs_TransformStampedStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/TransformStamped");

  convertFromStructPrimitiveArray(msgPtr->child_frame_id, structPtr->ChildFrameId);
  struct2msg(&msgPtr->header, &structPtr->Header);
  struct2msg(&msgPtr->transform, &structPtr->Transform);
}

void msg2struct(geometry_msgs_TransformStampedStruct_T* structPtr, geometry_msgs::TransformStamped const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/TransformStamped");

  convertToStructPrimitiveArray(structPtr->ChildFrameId, msgPtr->child_frame_id);
  msg2struct(&structPtr->Header, &msgPtr->header);
  msg2struct(&structPtr->Transform, &msgPtr->transform);
}


// Conversions between geometry_msgs_TwistStruct_T and geometry_msgs::Twist

void struct2msg(geometry_msgs::Twist* msgPtr, geometry_msgs_TwistStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  struct2msg(&msgPtr->angular, &structPtr->Angular);
  struct2msg(&msgPtr->linear, &structPtr->Linear);
}

void msg2struct(geometry_msgs_TwistStruct_T* structPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  msg2struct(&structPtr->Angular, &msgPtr->angular);
  msg2struct(&structPtr->Linear, &msgPtr->linear);
}


// Conversions between geometry_msgs_TwistWithCovarianceStruct_T and geometry_msgs::TwistWithCovariance

void struct2msg(geometry_msgs::TwistWithCovariance* msgPtr, geometry_msgs_TwistWithCovarianceStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistWithCovariance");

  convertFromStructPrimitiveArray(msgPtr->covariance, structPtr->Covariance);
  struct2msg(&msgPtr->twist, &structPtr->Twist);
}

void msg2struct(geometry_msgs_TwistWithCovarianceStruct_T* structPtr, geometry_msgs::TwistWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistWithCovariance");

  convertToStructPrimitiveArray(structPtr->Covariance, msgPtr->covariance);
  msg2struct(&structPtr->Twist, &msgPtr->twist);
}


// Conversions between geometry_msgs_Vector3Struct_T and geometry_msgs::Vector3

void struct2msg(geometry_msgs::Vector3* msgPtr, geometry_msgs_Vector3Struct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  structPtr->X;
  msgPtr->y =  structPtr->Y;
  msgPtr->z =  structPtr->Z;
}

void msg2struct(geometry_msgs_Vector3Struct_T* structPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  structPtr->X =  msgPtr->x;
  structPtr->Y =  msgPtr->y;
  structPtr->Z =  msgPtr->z;
}


// Conversions between nav_msgs_OdometryStruct_T and nav_msgs::Odometry

void struct2msg(nav_msgs::Odometry* msgPtr, nav_msgs_OdometryStruct_T const* structPtr)
{
  const std::string rosMessageType("nav_msgs/Odometry");

  convertFromStructPrimitiveArray(msgPtr->child_frame_id, structPtr->ChildFrameId);
  struct2msg(&msgPtr->header, &structPtr->Header);
  struct2msg(&msgPtr->pose, &structPtr->Pose);
  struct2msg(&msgPtr->twist, &structPtr->Twist);
}

void msg2struct(nav_msgs_OdometryStruct_T* structPtr, nav_msgs::Odometry const* msgPtr)
{
  const std::string rosMessageType("nav_msgs/Odometry");

  convertToStructPrimitiveArray(structPtr->ChildFrameId, msgPtr->child_frame_id);
  msg2struct(&structPtr->Header, &msgPtr->header);
  msg2struct(&structPtr->Pose, &msgPtr->pose);
  msg2struct(&structPtr->Twist, &msgPtr->twist);
}


// Conversions between ros_TimeStruct_T and ros::Time

void struct2msg(ros::Time* msgPtr, ros_TimeStruct_T const* structPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  structPtr->Nsec;
  msgPtr->sec =  structPtr->Sec;
}

void msg2struct(ros_TimeStruct_T* structPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  structPtr->Nsec =  msgPtr->nsec;
  structPtr->Sec =  msgPtr->sec;
}


// Conversions between sensor_msgs_LaserScanStruct_T and sensor_msgs::LaserScan

void struct2msg(sensor_msgs::LaserScan* msgPtr, sensor_msgs_LaserScanStruct_T const* structPtr)
{
  const std::string rosMessageType("sensor_msgs/LaserScan");

  msgPtr->angle_increment =  structPtr->AngleIncrement;
  msgPtr->angle_max =  structPtr->AngleMax;
  msgPtr->angle_min =  structPtr->AngleMin;
  struct2msg(&msgPtr->header, &structPtr->Header);
  convertFromStructPrimitiveArray(msgPtr->intensities, structPtr->Intensities);
  msgPtr->range_max =  structPtr->RangeMax;
  msgPtr->range_min =  structPtr->RangeMin;
  convertFromStructPrimitiveArray(msgPtr->ranges, structPtr->Ranges);
  msgPtr->scan_time =  structPtr->ScanTime;
  msgPtr->time_increment =  structPtr->TimeIncrement;
}

void msg2struct(sensor_msgs_LaserScanStruct_T* structPtr, sensor_msgs::LaserScan const* msgPtr)
{
  const std::string rosMessageType("sensor_msgs/LaserScan");

  structPtr->AngleIncrement =  msgPtr->angle_increment;
  structPtr->AngleMax =  msgPtr->angle_max;
  structPtr->AngleMin =  msgPtr->angle_min;
  msg2struct(&structPtr->Header, &msgPtr->header);
  convertToStructPrimitiveArray(structPtr->Intensities, msgPtr->intensities);
  structPtr->RangeMax =  msgPtr->range_max;
  structPtr->RangeMin =  msgPtr->range_min;
  convertToStructPrimitiveArray(structPtr->Ranges, msgPtr->ranges);
  structPtr->ScanTime =  msgPtr->scan_time;
  structPtr->TimeIncrement =  msgPtr->time_increment;
}


// Conversions between std_msgs_HeaderStruct_T and std_msgs::Header

void struct2msg(std_msgs::Header* msgPtr, std_msgs_HeaderStruct_T const* structPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromStructPrimitiveArray(msgPtr->frame_id, structPtr->FrameId);
  msgPtr->seq =  structPtr->Seq;
  struct2msg(&msgPtr->stamp, &structPtr->Stamp);
}

void msg2struct(std_msgs_HeaderStruct_T* structPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToStructPrimitiveArray(structPtr->FrameId, msgPtr->frame_id);
  structPtr->Seq =  msgPtr->seq;
  msg2struct(&structPtr->Stamp, &msgPtr->stamp);
}
