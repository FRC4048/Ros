//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// amcl_test_types.h
//
// Code generation for function 'amcl_test'
//

#ifndef AMCL_TEST_TYPES_H
#define AMCL_TEST_TYPES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct ros_TimeStruct_T {
  unsigned int Sec;
  unsigned int Nsec;
};

struct geometry_msgs_PointStruct_T {
  char MessageType[19];
  double X;
  double Y;
  double Z;
};

struct geometry_msgs_QuaternionStruct_T {
  char MessageType[24];
  double X;
  double Y;
  double Z;
  double W;
};

struct geometry_msgs_PoseStruct_T {
  char MessageType[18];
  geometry_msgs_PointStruct_T Position;
  geometry_msgs_QuaternionStruct_T Orientation;
};

struct geometry_msgs_PoseWithCovarianceStruct_T {
  char MessageType[32];
  geometry_msgs_PoseStruct_T Pose;
  double Covariance[36];
};

struct geometry_msgs_Vector3Struct_T {
  char MessageType[21];
  double X;
  double Y;
  double Z;
};

struct geometry_msgs_TwistStruct_T {
  char MessageType[19];
  geometry_msgs_Vector3Struct_T Linear;
  geometry_msgs_Vector3Struct_T Angular;
};

struct geometry_msgs_TwistWithCovarianceStruct_T {
  char MessageType[33];
  geometry_msgs_TwistStruct_T Twist;
  double Covariance[36];
};

struct geometry_msgs_TransformStruct_T {
  char MessageType[23];
  geometry_msgs_Vector3Struct_T Translation;
  geometry_msgs_QuaternionStruct_T Rotation;
};

struct std_msgs_HeaderStruct_T {
  char MessageType[15];
  unsigned int Seq;
  ros_TimeStruct_T Stamp;
  coder::array<char, 2U> FrameId;
};

struct nav_msgs_OdometryStruct_T {
  char MessageType[17];
  std_msgs_HeaderStruct_T Header;
  coder::array<char, 2U> ChildFrameId;
  geometry_msgs_PoseWithCovarianceStruct_T Pose;
  geometry_msgs_TwistWithCovarianceStruct_T Twist;
};

struct sensor_msgs_LaserScanStruct_T {
  char MessageType[21];
  std_msgs_HeaderStruct_T Header;
  float AngleMin;
  float AngleMax;
  float AngleIncrement;
  float TimeIncrement;
  float ScanTime;
  float RangeMin;
  float RangeMax;
  coder::array<float, 1U> Ranges;
  coder::array<float, 1U> Intensities;
};

struct geometry_msgs_TransformStampedStruct_T {
  char MessageType[30];
  std_msgs_HeaderStruct_T Header;
  coder::array<char, 2U> ChildFrameId;
  geometry_msgs_TransformStruct_T Transform;
};

#endif
// End of code generation (amcl_test_types.h)
