//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// amcl_test.cpp
//
// Code generation for function 'amcl_test'
//

// Include files
#include "amcl_test.h"
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "MonteCarloLocalizationBuiltins.h"
#include "Publisher.h"
#include "SharedMapProperties.h"
#include "Subscriber.h"
#include "TransformationTree.h"
#include "amcl_test_types.h"
#include "binaryOccupancyMap.h"
#include "geometry_msgs_TransformStampedStruct.h"
#include "lidarScan.h"
#include "likelihoodFieldSensorModel.h"
#include "mod.h"
#include "monteCarloLocalization.h"
#include "nullAssignment.h"
#include "odometryMotionModel.h"
#include "quat2eul.h"
#include "rosReadBinaryOccupancyGrid.h"
#include "rosReadLidarScan.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "wrapToPi.h"
#include "coder_array.h"
#include "mclcodegen_api.hpp"
#include "mlroscpp_pub.h"
#include "mlroscpp_transform.h"
#include "rtGetInf.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

// Type Definitions
struct cell_wrap_0 {
  double f1[2];
};

// Function Definitions
void amcl_test()
{
  static const double val[9]{0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5};
  static double t4_f1[2]{0.0, 0.0};
  static const char b_cv[10]{'m', 'a', 't', 'l', 'a', 'b', '_', 'm', 's', 'g'};
  void *mclData;
  coder::binaryOccupancyMap lobj_12[2];
  coder::binaryOccupancyMap map;
  coder::binaryOccupancyMap *iobj_3;
  coder::lidarScan scan;
  coder::likelihoodFieldSensorModel lobj_10;
  coder::likelihoodFieldSensorModel rangeFinderModel;
  coder::matlabshared::autonomous::internal::CircularBuffer lobj_13[3];
  coder::matlabshared::autonomous::internal::CircularBuffer *iobj_0;
  coder::matlabshared::autonomous::internal::CircularBufferIndex lobj_14[3];
  coder::matlabshared::autonomous::internal::CircularBufferIndex *iobj_1;
  coder::matlabshared::autonomous::internal::SharedMapProperties lobj_15[3];
  coder::matlabshared::autonomous::internal::SharedMapProperties *iobj_2;
  coder::monteCarloLocalization amcl;
  coder::odometryMotionModel lobj_11;
  coder::odometryMotionModel odometryModel;
  coder::ros::Publisher debug;
  coder::ros::Subscriber mapSub;
  coder::ros::TransformationTree tftree;
  coder::ros::b_Publisher odom_vis_pub;
  coder::ros::b_Subscriber laserSub;
  coder::ros::c_Subscriber odomSub;
  coder::array<signed char, 1U> t5_Data;
  coder::array<bool, 1U> validAngleLimitIndices;
  coder::array<bool, 1U> validIndices;
  coder::array<bool, 1U> validRangeLimitIndices;
  geometry_msgs_PointStampedStruct_T msg;
  geometry_msgs_TransformStampedStruct_T expl_temp;
  geometry_msgs_TransformStampedStruct_T r;
  nav_msgs_MapMetaDataStruct_T t5_Info;
  sensor_msgs_LaserScanStruct_T scanMsg;
  double sensorTransform_Transform_Rotat[4];
  double pose[3];
  double odompose_Y;
  double odompose_Z;
  double randomSeed;
  char statustext[7];
  bool flag;
  t4_f1[1U] = rtGetInf();
  lobj_11.matlabCodegenIsDeleted = true;
  amcl._pobj0.matlabCodegenIsDeleted = true;
  amcl.MCLObj.matlabCodegenIsDeleted = true;
  amcl.matlabCodegenIsDeleted = true;
  std::printf("Starting\n");
  std::fflush(stdout);
  mapSub.init();
  laserSub.init();
  std::printf("Found /scan and /map topics\n");
  std::fflush(stdout);
  //      map = binaryOccupancyMap(100,100);
  mapSub.receive(t5_Data, t5_Info);
  coder::rosReadBinaryOccupancyGrid(t5_Info, t5_Data, lobj_13[2], lobj_14[2],
                                    lobj_15[2], map);
  std::printf("reveived map\n");
  std::fflush(stdout);
  odometryModel.isInitialized = 0;
  odometryModel.matlabCodegenIsDeleted = false;
  odometryModel.Noise[0] = 0.2;
  odometryModel.Noise[1] = 0.2;
  odometryModel.Noise[2] = 0.2;
  odometryModel.Noise[3] = 0.2;
  rangeFinderModel.NumBeams = 60.0;
  rangeFinderModel.MeasurementNoise = 0.2;
  rangeFinderModel.RandomMeasurementWeight = 0.05;
  rangeFinderModel.ExpectedMeasurementWeight = 0.95;
  rangeFinderModel.MaxLikelihoodDistance = 2.0;
  rangeFinderModel.SensorLimits[0] = 0.45;
  rangeFinderModel.SensorLimits[1] = 8.0;
  iobj_0 = &lobj_13[1];
  iobj_1 = &lobj_14[1];
  iobj_2 = &lobj_15[1];
  iobj_3 = &lobj_12[1];
  rangeFinderModel.InternalMap = map.copy(iobj_0, iobj_1, iobj_2, iobj_3);
  //  Query the Transformation Tree (tf tree) in ROS.
  std::printf("waiting for tf Tree");
  std::fflush(stdout);
  tftree.TransformHelper = MATLABROSTransform();
  UNUSED_PARAM(tftree.TransformHelper);
  geometry_msgs_TransformStampedStruct(r);
  std::printf("found transformationTree");
  std::fflush(stdout);
  tftree.waitForTransform();
  std::printf("Found tf transformation between base_link and base_scan");
  std::fflush(stdout);
  tftree.getTransform(expl_temp);
  //  Get the euler rotation angles.
  //  Setup the |SensorPose|, which includes the translation along base_link's
  //  +X, +Y direction in meters and rotation angle along base_link's +Z axis
  //  in radians.
  sensorTransform_Transform_Rotat[0] = expl_temp.Transform.Rotation.W;
  sensorTransform_Transform_Rotat[1] = expl_temp.Transform.Rotation.X;
  sensorTransform_Transform_Rotat[2] = expl_temp.Transform.Rotation.Y;
  sensorTransform_Transform_Rotat[3] = expl_temp.Transform.Rotation.Z;
  rangeFinderModel.SensorPose[0] = expl_temp.Transform.Translation.X;
  rangeFinderModel.SensorPose[1] = expl_temp.Transform.Translation.Y;
  coder::quat2eul(sensorTransform_Transform_Rotat, pose);
  rangeFinderModel.SensorPose[2] = pose[0];
  odomSub.init();
  // create ros publisher named debug and msg oject to send data
  debug.init();
  coder::ros::Publisher::rosmessage(msg);
  odom_vis_pub.init();
  coder::ros::Publisher::rosmessage();
  amcl.Seed = 67.0;
  amcl.isInitialized = 0;
  amcl._pobj1.NumBeams = 60.0;
  amcl._pobj1.MeasurementNoise = 0.2;
  amcl._pobj1.RandomMeasurementWeight = 0.05;
  amcl._pobj1.ExpectedMeasurementWeight = 0.95;
  amcl._pobj1.MaxLikelihoodDistance = 2.0;
  amcl.PrivateSensorModel = &amcl._pobj1;
  amcl._pobj0.isInitialized = 0;
  amcl._pobj0.matlabCodegenIsDeleted = false;
  amcl.PrivateMotionModel = &amcl._pobj0;
  randomSeed = amcl.Seed;
  mclData = mclInitializeWithSeed_real64(randomSeed);
  amcl.MCLObj.MCLData = mclData;
  amcl.MCLObj.matlabCodegenIsDeleted = false;
  amcl.matlabCodegenIsDeleted = false;
  amcl.PrivateMotionModel = odometryModel.clone(lobj_11);
  flag = (amcl.isInitialized == 1);
  if (flag) {
    sensorTransform_Transform_Rotat[0] = 0.2;
    sensorTransform_Transform_Rotat[1] = 0.2;
    sensorTransform_Transform_Rotat[2] = 0.2;
    sensorTransform_Transform_Rotat[3] = 0.2;
    mclData = amcl.MCLObj.MCLData;
    mclSetMotionModel_real64(mclData, &sensorTransform_Transform_Rotat[0]);
  }
  amcl.set_SensorModel(rangeFinderModel, lobj_13[0], lobj_14[0], lobj_15[0],
                       lobj_12[0], lobj_10);
  amcl.PrivateUpdateThresholds[0] = 0.2;
  amcl.PrivateUpdateThresholds[1] = 0.2;
  amcl.PrivateUpdateThresholds[2] = 0.2;
  flag = (amcl.isInitialized == 1);
  if (flag) {
    mclData = amcl.MCLObj.MCLData;
    mclSetUpdateThresholds_real64(mclData, 0.2, 0.2, 0.2);
  }
  amcl.PrivateResamplingInterval = 1.0;
  flag = (amcl.isInitialized == 1);
  if (flag) {
    mclData = amcl.MCLObj.MCLData;
    mclSetResamplingInterval_real64(mclData, 1.0);
  }
  amcl.PrivateParticleLimits[0] = 500.0;
  amcl.PrivateParticleLimits[1] = 5000.0;
  amcl.PrivateGlobalLocalization = false;
  std::copy(&val[0], &val[9], &amcl.PrivateInitialCovariance[0]);
  amcl.PrivateInitialPose[0] = 0.0;
  amcl.PrivateInitialPose[1] = 0.0;
  amcl.PrivateInitialPose[2] = 0.0;
  while (1) {
    //  Receive laser scan and odometry message.
    scanMsg.AngleMin = laserSub.receive(scanMsg.Ranges, statustext,
                                        scanMsg.AngleIncrement, flag);
    randomSeed = odomSub.get_LatestMessage(odompose_Y, odompose_Z);
    if (flag) {
      cell_wrap_0 parsedResults[2];
      double posecov[12];
      double posedata[12];
      double parsedAngleLimits[2];
      int i;
      int loop_ub;
      bool exitg1;
      //  Only keep lidar data between angle 200 and 350 (rest is obstructed)
      coder::rosReadLidarScan(scanMsg, scan);
      coder::robotics::internal::wrapToPi(scan.InternalAngles);
      if (scan.InternalRanges.size(0) == scan.InternalAngles.size(0)) {
        validIndices.set_size(scan.InternalRanges.size(0));
        loop_ub = scan.InternalRanges.size(0);
        for (i = 0; i < loop_ub; i++) {
          validIndices[i] = ((!std::isinf(scan.InternalRanges[i])) &&
                             (!std::isnan(scan.InternalRanges[i])) &&
                             ((!std::isinf(scan.InternalAngles[i])) &&
                              (!std::isnan(scan.InternalAngles[i]))));
        }
      } else {
        binary_expand_op_1(validIndices, scan);
      }
      scan.ContainsOnlyFiniteData = true;
      validRangeLimitIndices.set_size(scan.InternalRanges.size(0));
      loop_ub = scan.InternalRanges.size(0);
      for (i = 0; i < loop_ub; i++) {
        validRangeLimitIndices[i] = true;
      }
      parsedResults[0].f1[0] = 0.0;
      parsedResults[0].f1[1] = rtInf;
      flag = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub < 2)) {
        if (!(parsedResults[0].f1[loop_ub] == t4_f1[loop_ub])) {
          flag = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (!flag) {
        validRangeLimitIndices.set_size(scan.InternalRanges.size(0));
        loop_ub = scan.InternalRanges.size(0);
        for (i = 0; i < loop_ub; i++) {
          validRangeLimitIndices[i] = ((scan.InternalRanges[i] >= 0.0) &&
                                       (scan.InternalRanges[i] <= rtInf));
        }
      }
      parsedAngleLimits[0] = coder::internal::scalar::b_mod(6.6322511575784517,
                                                            6.2831853071795862);
      parsedAngleLimits[1] = coder::internal::scalar::b_mod(9.2502450355699466,
                                                            6.2831853071795862);
      if (parsedAngleLimits[0] == 0.0) {
        parsedAngleLimits[0] = 6.2831853071795862;
      }
      if (parsedAngleLimits[1] == 0.0) {
        parsedAngleLimits[1] = 6.2831853071795862;
      }
      parsedAngleLimits[0] -= 3.1415926535897931;
      parsedAngleLimits[1] -= 3.1415926535897931;
      coder::internal::sort(parsedAngleLimits);
      validAngleLimitIndices.set_size(scan.InternalAngles.size(0));
      loop_ub = scan.InternalAngles.size(0);
      for (i = 0; i < loop_ub; i++) {
        validAngleLimitIndices[i] =
            ((scan.InternalAngles[i] >= parsedAngleLimits[0]) &&
             (scan.InternalAngles[i] <= parsedAngleLimits[1]));
      }
      if (validIndices.size(0) == 1) {
        i = validRangeLimitIndices.size(0);
      } else {
        i = validIndices.size(0);
      }
      if ((validIndices.size(0) == validRangeLimitIndices.size(0)) &&
          (i == validAngleLimitIndices.size(0))) {
        loop_ub = validIndices.size(0);
        for (i = 0; i < loop_ub; i++) {
          validIndices[i] = (validIndices[i] && validRangeLimitIndices[i] &&
                             validAngleLimitIndices[i]);
        }
      } else {
        binary_expand_op(validIndices, validRangeLimitIndices,
                         validAngleLimitIndices);
      }
      flag = true;
      loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= validIndices.size(0))) {
        if (!validIndices[loop_ub - 1]) {
          flag = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (!flag) {
        loop_ub = validIndices.size(0);
        for (i = 0; i < loop_ub; i++) {
          validIndices[i] = !validIndices[i];
        }
        coder::internal::nullAssignment(scan.InternalAngles, validIndices);
        coder::internal::nullAssignment(scan.InternalRanges, validIndices);
        coder::robotics::internal::wrapToPi(scan.InternalAngles);
      }
      //  Compute robot's pose [x,y,yaw] from odometry message.
      pose[0] = randomSeed;
      pose[1] = odompose_Y;
      pose[2] = odompose_Z;
      //  send odom data back to ros with a frame id so we can see it in rviz
      //  odom_vis_msg.X = odompose.X;
      //  odom_vis_msg.Y = odompose.Y;
      //  odom_vis_msg.Z = 0;
      //  odom_vis_msg.Header.FrameId = 'odomVis';
      //  send(odom_vis_pub,odom_vis_msg)
      //  Update estimated robot's pose and covariance using new odometry and
      //  sensor readings.
      if (amcl.isInitialized != 1) {
        amcl.setupAndReset();
      }
      mclData = amcl.MCLObj.MCLData;
      mclUpdate_real64(mclData,
                       static_cast<double>(scan.InternalRanges.size(0)),
                       &(scan.InternalRanges.data())[0],
                       &(scan.InternalAngles.data())[0], &pose[0]);
      mclData = amcl.MCLObj.MCLData;
      mclIsUpdated_real64(mclData);
      mclData = amcl.MCLObj.MCLData;
      mclGetHypothesis_real64(mclData, &posecov[0]);
      for (i = 0; i < 3; i++) {
        loop_ub = i << 2;
        posedata[loop_ub] = posecov[i];
        posedata[loop_ub + 1] = posecov[i + 3];
        posedata[loop_ub + 2] = posecov[i + 6];
        posedata[loop_ub + 3] = posecov[i + 9];
      }
      //  Set the message object values(x,y,z) created by the publisher to the
      //  x,y,and yaw of the estimated pos
      msg.Point.X = posedata[0];
      // pos x
      msg.Point.Y = posedata[4];
      // pos y
      msg.Point.Z = 0.0;
      // pos yaw
      msg.Header.FrameId.set_size(1, 10);
      for (i = 0; i < 10; i++) {
        msg.Header.FrameId[i] = b_cv[i];
      }
      MATLABPUBLISHER_publish(debug.PublisherHelper, &msg);
      std::printf("estimated pose = (%f,%f,%f)\n", posedata[0], posedata[4],
                  posedata[8]);
      std::fflush(stdout);
    }
  }
}

// End of code generation (amcl_test.cpp)
