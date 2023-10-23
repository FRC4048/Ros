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
#include "amcl_test_rtwutil.h"
#include "amcl_test_types.h"
#include "binaryOccupancyMap.h"
#include "geometry_msgs_TransformStampedStruct.h"
#include "lidarScan.h"
#include "likelihoodFieldSensorModel.h"
#include "minOrMax.h"
#include "monteCarloLocalization.h"
#include "odometryMotionModel.h"
#include "quat2eul.h"
#include "rosReadCartesian.h"
#include "rt_nonfinite.h"
#include "wrapToPi.h"
#include "coder_array.h"
#include "mclcodegen_api.hpp"
#include "mlroscpp_pub.h"
#include "mlroscpp_transform.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Declarations
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = b * std::sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * std::sqrt(b * b + 1.0);
  } else if (std::isnan(b)) {
    y = rtNaN;
  } else {
    y = a * 1.4142135623730951;
  }
  return y;
}

void amcl_test()
{
  static const double val[9]{0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5};
  void *mclData;
  coder::binaryOccupancyMap lobj_10[2];
  coder::binaryOccupancyMap b_lobj_3;
  coder::binaryOccupancyMap lobj_3;
  coder::binaryOccupancyMap map;
  coder::binaryOccupancyMap *iobj_3;
  coder::lidarScan scan;
  coder::likelihoodFieldSensorModel lobj_8;
  coder::likelihoodFieldSensorModel rangeFinderModel;
  coder::likelihoodFieldSensorModel *obj;
  coder::matlabshared::autonomous::internal::CircularBuffer lobj_11[3];
  coder::matlabshared::autonomous::internal::CircularBuffer b_lobj_0;
  coder::matlabshared::autonomous::internal::CircularBuffer lobj_0;
  coder::matlabshared::autonomous::internal::CircularBuffer *iobj_0;
  coder::matlabshared::autonomous::internal::CircularBufferIndex lobj_12[3];
  coder::matlabshared::autonomous::internal::CircularBufferIndex b_lobj_1;
  coder::matlabshared::autonomous::internal::CircularBufferIndex lobj_1;
  coder::matlabshared::autonomous::internal::CircularBufferIndex *iobj_1;
  coder::matlabshared::autonomous::internal::SharedMapProperties lobj_13[3];
  coder::matlabshared::autonomous::internal::SharedMapProperties b_lobj_2;
  coder::matlabshared::autonomous::internal::SharedMapProperties lobj_2;
  coder::matlabshared::autonomous::internal::SharedMapProperties *iobj_2;
  coder::monteCarloLocalization amcl;
  coder::odometryMotionModel lobj_9;
  coder::odometryMotionModel odometryModel;
  coder::ros::Publisher debug;
  coder::ros::Subscriber laserSub;
  coder::ros::TransformationTree tftree;
  coder::ros::b_Subscriber odomSub;
  coder::array<double, 2U> aRanges;
  coder::array<double, 2U> b_aAngles;
  coder::array<double, 2U> cart;
  coder::array<double, 1U> aAngles;
  coder::array<double, 1U> b_aRanges;
  geometry_msgs_PointStruct_T msg;
  geometry_msgs_TransformStampedStruct_T expl_temp;
  geometry_msgs_TransformStampedStruct_T r;
  sensor_msgs_LaserScanStruct_T scanMsg;
  double poseCov[9];
  double sensorTransform_Transform_Rotat[4];
  double sensorPose[3];
  double p[2];
  double odompose_Pose_Pose_Orientation_W;
  double odompose_Pose_Pose_Orientation_X;
  double odompose_Pose_Pose_Orientation_Y;
  double odompose_Pose_Pose_Orientation_Z;
  double odompose_Pose_Pose_Position_Y;
  char statustext[7];
  bool flag;
  lobj_9.matlabCodegenIsDeleted = true;
  amcl._pobj0.matlabCodegenIsDeleted = true;
  amcl.MCLObj.matlabCodegenIsDeleted = true;
  amcl.matlabCodegenIsDeleted = true;
  laserSub.init();
  map.init(lobj_11[2], lobj_12[2], lobj_13[2]);
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
  p[0] = 0.45;
  p[1] = 8.0;
  rangeFinderModel.SensorLimits[0] = coder::internal::minimum(p);
  rangeFinderModel.SensorLimits[1] = 8.0;
  iobj_0 = &lobj_11[1];
  iobj_1 = &lobj_12[1];
  iobj_2 = &lobj_13[1];
  iobj_3 = &lobj_10[1];
  rangeFinderModel.InternalMap = map.copy(iobj_0, iobj_1, iobj_2, iobj_3);
  //  Query the Transformation Tree (tf tree) in ROS.
  tftree.TransformHelper = MATLABROSTransform();
  UNUSED_PARAM(tftree.TransformHelper);
  geometry_msgs_TransformStampedStruct(r);
  tftree.waitForTransform();
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
  coder::quat2eul(sensorTransform_Transform_Rotat, sensorPose);
  rangeFinderModel.SensorPose[2] = sensorPose[0];
  odomSub.init();
  // create ros publisher named debug and msg oject to send data
  debug.init();
  msg = coder::ros::Publisher::rosmessage();
  amcl.init();
  amcl.PrivateMotionModel = odometryModel.clone(lobj_9);
  flag = (amcl.isInitialized == 1);
  if (flag) {
    sensorTransform_Transform_Rotat[0] = 0.2;
    sensorTransform_Transform_Rotat[1] = 0.2;
    sensorTransform_Transform_Rotat[2] = 0.2;
    sensorTransform_Transform_Rotat[3] = 0.2;
    mclData = amcl.MCLObj.MCLData;
    mclSetMotionModel_real64(mclData, &sensorTransform_Transform_Rotat[0]);
  }
  amcl.set_SensorModel(rangeFinderModel, lobj_11[0], lobj_12[0], lobj_13[0],
                       lobj_10[0], lobj_8);
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
  p[0] = 500.0;
  p[1] = 5000.0;
  amcl.PrivateParticleLimits[0] = coder::internal::minimum(p);
  amcl.PrivateParticleLimits[1] = 5000.0;
  amcl.PrivateGlobalLocalization = false;
  //      amcl.InitialPose = ExampleHelperAMCLGazeboTruePose;
  std::copy(&val[0], &val[9], &amcl.PrivateInitialCovariance[0]);
  while (1) {
    double odompose_Pose_Pose_Position_X;
    //  Receive laser scan and odometry message.
    scanMsg.AngleMin =
        laserSub.receive(scanMsg.Ranges, statustext, scanMsg.AngleIncrement,
                         scanMsg.RangeMin, scanMsg.RangeMax, flag);
    odompose_Pose_Pose_Position_X = odomSub.get_LatestMessage(
        odompose_Pose_Pose_Position_Y, odompose_Pose_Pose_Orientation_X,
        odompose_Pose_Pose_Orientation_Y, odompose_Pose_Pose_Orientation_Z,
        odompose_Pose_Pose_Orientation_W);
    if (flag) {
      double posecov[12];
      double posedata[12];
      double pose[3];
      double d;
      int i;
      int k;
      int nx;
      coder::rosReadCartesian(scanMsg, cart);
      if (cart.size(0) == 0) {
        b_aAngles.set_size(0, 0);
        aRanges.set_size(0, 0);
      } else {
        aAngles.set_size(cart.size(0));
        nx = cart.size(0);
        b_aRanges.set_size(cart.size(0));
        for (k = 0; k < nx; k++) {
          double d1;
          d = cart[k + cart.size(0)];
          d1 = cart[k];
          aAngles[k] = rt_atan2d_snf(d, d1);
          b_aRanges[k] = rt_hypotd_snf(d1, d);
        }
        b_aAngles.set_size(aAngles.size(0), 1);
        nx = aAngles.size(0);
        aRanges.set_size(b_aRanges.size(0), 1);
        for (i = 0; i < nx; i++) {
          b_aAngles[i] = aAngles[i];
          aRanges[i] = b_aRanges[i];
        }
      }
      nx = aRanges.size(0) * aRanges.size(1);
      scan.InternalRanges.set_size(nx);
      for (i = 0; i < nx; i++) {
        scan.InternalRanges[i] = aRanges[i];
      }
      scan.InternalAngles.set_size(nx);
      for (i = 0; i < nx; i++) {
        scan.InternalAngles[i] = b_aAngles[i];
      }
      coder::robotics::internal::wrapToPi(scan.InternalAngles);
      //  Create lidarScan object to pass to the AMCL object.
      //  For sensors that are mounted upside down, you need to reverse the
      //  order of scan angle readings using 'flip' function.
      //  Compute robot's pose [x,y,yaw] from odometry message.
      sensorTransform_Transform_Rotat[0] = odompose_Pose_Pose_Orientation_W;
      sensorTransform_Transform_Rotat[1] = odompose_Pose_Pose_Orientation_X;
      sensorTransform_Transform_Rotat[2] = odompose_Pose_Pose_Orientation_Y;
      sensorTransform_Transform_Rotat[3] = odompose_Pose_Pose_Orientation_Z;
      pose[0] = odompose_Pose_Pose_Position_X;
      pose[1] = odompose_Pose_Pose_Position_Y;
      coder::quat2eul(sensorTransform_Transform_Rotat, sensorPose);
      pose[2] = sensorPose[0];
      //  Update estimated robot's pose and covariance using new odometry and
      //  sensor readings.
      if (amcl.isInitialized != 1) {
        double grid[10000];
        bool B[10000];
        bool a[10000];
        bool x[2];
        bool exitg1;
        amcl.isSetupComplete = false;
        amcl.isInitialized = 1;
        obj = amcl.PrivateSensorModel;
        obj->InternalMap->copy(&lobj_0, &lobj_1, &lobj_2, &lobj_3);
        amcl.isSetupComplete = true;
        odompose_Pose_Pose_Position_X = amcl.PrivateUpdateThresholds[0];
        odompose_Pose_Pose_Position_Y = amcl.PrivateUpdateThresholds[1];
        odompose_Pose_Pose_Orientation_X = amcl.PrivateUpdateThresholds[2];
        mclData = amcl.MCLObj.MCLData;
        mclSetUpdateThresholds_real64(mclData, odompose_Pose_Pose_Position_X,
                                      odompose_Pose_Pose_Position_Y,
                                      odompose_Pose_Pose_Orientation_X);
        odompose_Pose_Pose_Position_X = amcl.PrivateResamplingInterval;
        mclData = amcl.MCLObj.MCLData;
        mclSetResamplingInterval_real64(mclData, odompose_Pose_Pose_Position_X);
        obj = amcl.PrivateSensorModel;
        iobj_3 =
            obj->InternalMap->copy(&b_lobj_0, &b_lobj_1, &b_lobj_2, &b_lobj_3);
        x[0] = (iobj_3->Index->Head[0] == 1.0);
        x[1] = (iobj_3->Index->Head[1] == 1.0);
        flag = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= 1)) {
          if (!x[k]) {
            flag = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (flag) {
          for (i = 0; i < 10000; i++) {
            a[i] = iobj_3->Buffer->Buffer[i];
          }
        } else {
          int stride;
          bool buffer[50];
          for (i = 0; i < 10000; i++) {
            a[i] = iobj_3->Buffer->Buffer[i];
          }
          p[0] = -(iobj_3->Index->Head[0] - 1.0);
          p[1] = -(iobj_3->Index->Head[1] - 1.0);
          stride = 1;
          for (k = 0; k < 2; k++) {
            int npages;
            int ns;
            int pagesize;
            int u0;
            d = p[k];
            if (d < 0.0) {
              u0 = -static_cast<int>(d);
              flag = false;
            } else {
              u0 = static_cast<int>(d);
              flag = true;
            }
            if (u0 > 100) {
              u0 -= 100 * (u0 / 100);
            }
            if (u0 > 50) {
              u0 = 100 - u0;
              flag = !flag;
            }
            x[k] = flag;
            ns = u0 - 1;
            pagesize = stride * 100;
            npages = -99 * k + 99;
            if (u0 > 0) {
              for (int b_i{0}; b_i <= npages; b_i++) {
                int pageroot;
                pageroot = b_i * pagesize;
                for (int j{0}; j < stride; j++) {
                  int i1;
                  i1 = pageroot + j;
                  if (x[k]) {
                    for (int b_k{0}; b_k <= ns; b_k++) {
                      buffer[b_k] = a[i1 + ((b_k - u0) + 100) * stride];
                    }
                    i = u0 + 1;
                    for (int b_k{100}; b_k >= i; b_k--) {
                      a[i1 + (b_k - 1) * stride] =
                          a[i1 + ((b_k - u0) - 1) * stride];
                    }
                    for (int b_k{0}; b_k <= ns; b_k++) {
                      a[i1 + b_k * stride] = buffer[b_k];
                    }
                  } else {
                    for (int b_k{0}; b_k <= ns; b_k++) {
                      buffer[b_k] = a[i1 + b_k * stride];
                    }
                    i = 99 - u0;
                    for (int b_k{0}; b_k <= i; b_k++) {
                      a[i1 + b_k * stride] = a[i1 + (b_k + u0) * stride];
                    }
                    for (int b_k{0}; b_k <= ns; b_k++) {
                      a[i1 + ((b_k - u0) + 100) * stride] = buffer[b_k];
                    }
                  }
                }
              }
            }
            stride = pagesize;
          }
          if (!iobj_3->HasParent) {
            for (i = 0; i < 10000; i++) {
              iobj_3->Buffer->Buffer[i] = a[i];
            }
            iobj_3->Index->Head[0] = 1.0;
            iobj_3->Index->Head[1] = 1.0;
          }
        }
        for (int b_i{0}; b_i < 100; b_i++) {
          for (int j{0}; j < 100; j++) {
            B[b_i + 100 * j] = a[(100 * b_i - j) + 99];
          }
        }
        for (i = 0; i < 10000; i++) {
          grid[i] = B[i];
        }
        iobj_2 = iobj_3->SharedProperties;
        odompose_Pose_Pose_Position_X =
            iobj_2->LocalOriginInWorld[0] + iobj_2->GridOriginInLocal[0];
        iobj_2 = iobj_3->SharedProperties;
        odompose_Pose_Pose_Position_Y =
            iobj_2->LocalOriginInWorld[1] + iobj_2->GridOriginInLocal[1];
        mclData = amcl.MCLObj.MCLData;
        mclSetOccupancyGrid_real64(mclData, 100.0, 100.0, 1.0,
                                   (odompose_Pose_Pose_Position_X +
                                    (odompose_Pose_Pose_Position_X + 100.0)) /
                                           2.0 +
                                       0.5,
                                   (odompose_Pose_Pose_Position_Y +
                                    (odompose_Pose_Pose_Position_Y + 100.0)) /
                                           2.0 +
                                       0.5,
                                   &grid[0]);
        odompose_Pose_Pose_Position_X = obj->NumBeams;
        odompose_Pose_Pose_Position_Y = obj->ExpectedMeasurementWeight;
        odompose_Pose_Pose_Orientation_X = obj->RandomMeasurementWeight;
        odompose_Pose_Pose_Orientation_Y = obj->MeasurementNoise;
        odompose_Pose_Pose_Orientation_Z = obj->MaxLikelihoodDistance;
        p[0] = obj->SensorLimits[0];
        p[1] = obj->SensorLimits[1];
        sensorPose[0] = obj->SensorPose[0];
        sensorPose[1] = obj->SensorPose[1];
        sensorPose[2] = obj->SensorPose[2];
        mclData = amcl.MCLObj.MCLData;
        mclSetSensorModel_real64(
            mclData, odompose_Pose_Pose_Position_X,
            odompose_Pose_Pose_Position_Y, odompose_Pose_Pose_Orientation_X,
            odompose_Pose_Pose_Orientation_Y, odompose_Pose_Pose_Orientation_Z,
            &p[0], &sensorPose[0]);
        sensorTransform_Transform_Rotat[0] = amcl.PrivateMotionModel->Noise[0];
        sensorTransform_Transform_Rotat[1] = amcl.PrivateMotionModel->Noise[1];
        sensorTransform_Transform_Rotat[2] = amcl.PrivateMotionModel->Noise[2];
        sensorTransform_Transform_Rotat[3] = amcl.PrivateMotionModel->Noise[3];
        mclData = amcl.MCLObj.MCLData;
        mclSetMotionModel_real64(mclData, &sensorTransform_Transform_Rotat[0]);
        odompose_Pose_Pose_Position_X = amcl.PrivateParticleLimits[0];
        odompose_Pose_Pose_Position_Y = amcl.PrivateParticleLimits[1];
        mclData = amcl.MCLObj.MCLData;
        mclInitializePf_real64(mclData, odompose_Pose_Pose_Position_X,
                               odompose_Pose_Pose_Position_Y, 0.0, 0.0, 0.05,
                               0.99);
        if (amcl.PrivateGlobalLocalization) {
          mclData = amcl.MCLObj.MCLData;
          mclGlobalLocalization_real64(mclData);
        } else {
          sensorPose[0] = amcl.PrivateInitialPose[0];
          sensorPose[1] = amcl.PrivateInitialPose[1];
          sensorPose[2] = amcl.PrivateInitialPose[2];
          std::copy(&amcl.PrivateInitialCovariance[0],
                    &amcl.PrivateInitialCovariance[9], &poseCov[0]);
          mclData = amcl.MCLObj.MCLData;
          mclSetInitialPose_real64(mclData, &sensorPose[0], &poseCov[0]);
        }
      }
      mclData = amcl.MCLObj.MCLData;
      mclUpdate_real64(mclData, static_cast<double>(nx),
                       &(scan.InternalRanges.data())[0],
                       &(scan.InternalAngles.data())[0], &pose[0]);
      mclData = amcl.MCLObj.MCLData;
      mclIsUpdated_real64(mclData);
      mclData = amcl.MCLObj.MCLData;
      mclGetHypothesis_real64(mclData, &posecov[0]);
      for (i = 0; i < 3; i++) {
        nx = i << 2;
        posedata[nx] = posecov[i];
        posedata[nx + 1] = posecov[i + 3];
        posedata[nx + 2] = posecov[i + 6];
        posedata[nx + 3] = posecov[i + 9];
      }
      //  Set the message object values(x,y,z) created by the publisher to the
      //  x,y,and yaw of the estimated pos
      msg.X = posedata[0];
      // pos x
      msg.Y = posedata[4];
      // pos y
      msg.Z = posedata[8];
      // pos yaw
      MATLABPUBLISHER_publish(debug.PublisherHelper, &msg);
      //  Drive robot to next pose.
      //   wander(wanderHelper);
    }
  }
}

// End of code generation (amcl_test.cpp)
