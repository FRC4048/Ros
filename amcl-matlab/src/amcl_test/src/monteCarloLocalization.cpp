//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// monteCarloLocalization.cpp
//
// Code generation for function 'monteCarloLocalization'
//

// Include files
#include "monteCarloLocalization.h"
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "MonteCarloLocalizationBuiltins.h"
#include "SharedMapProperties.h"
#include "binaryOccupancyMap.h"
#include "likelihoodFieldSensorModel.h"
#include "odometryMotionModel.h"
#include "rt_nonfinite.h"
#include "mclcodegen_api.hpp"
#include <cmath>
#include <cstring>

// Function Definitions
namespace coder {
void monteCarloLocalization::SystemCore_delete()
{
  release();
}

void monteCarloLocalization::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    SystemCore_delete();
  }
}

void monteCarloLocalization::release()
{
  if (isInitialized == 1) {
    isInitialized = 2;
    releaseWrapper();
  }
}

void monteCarloLocalization::releaseImpl()
{
  MCLObj.cleanup();
}

void monteCarloLocalization::releaseWrapper()
{
  if (isSetupComplete) {
    releaseImpl();
  }
}

monteCarloLocalization::monteCarloLocalization()
{
  matlabCodegenIsDeleted = true;
}

monteCarloLocalization::~monteCarloLocalization()
{
  matlabCodegenDestructor();
}

monteCarloLocalization *monteCarloLocalization::init()
{
  void *mclData;
  monteCarloLocalization *obj;
  double randomSeed;
  obj = this;
  obj->Seed = 67.0;
  obj->PrivateInitialPose[0] = 0.0;
  obj->PrivateInitialPose[1] = 0.0;
  obj->PrivateInitialPose[2] = 0.0;
  obj->isInitialized = 0;
  obj->_pobj1.NumBeams = 60.0;
  obj->_pobj1.MeasurementNoise = 0.2;
  obj->_pobj1.RandomMeasurementWeight = 0.05;
  obj->_pobj1.ExpectedMeasurementWeight = 0.95;
  obj->_pobj1.MaxLikelihoodDistance = 2.0;
  obj->PrivateSensorModel = &obj->_pobj1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.matlabCodegenIsDeleted = false;
  obj->PrivateMotionModel = &obj->_pobj0;
  randomSeed = obj->Seed;
  mclData = mclInitializeWithSeed_real64(randomSeed);
  obj->MCLObj.MCLData = mclData;
  obj->MCLObj.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

void monteCarloLocalization::set_SensorModel(
    likelihoodFieldSensorModel &sm,
    matlabshared::autonomous::internal::CircularBuffer &iobj_0,
    matlabshared::autonomous::internal::CircularBufferIndex &iobj_1,
    matlabshared::autonomous::internal::SharedMapProperties &iobj_2,
    binaryOccupancyMap &iobj_3, likelihoodFieldSensorModel &iobj_4)
{
  binaryOccupancyMap lobj_3;
  matlabshared::autonomous::internal::CircularBuffer lobj_0;
  matlabshared::autonomous::internal::CircularBufferIndex lobj_1;
  matlabshared::autonomous::internal::SharedMapProperties lobj_2;
  double value_idx_0;
  double value_idx_1;
  double value_idx_2;
  sm.InternalMap->copy(&lobj_0, &lobj_1, &lobj_2, &lobj_3);
  iobj_4.NumBeams = 60.0;
  iobj_4.MeasurementNoise = 0.2;
  iobj_4.RandomMeasurementWeight = 0.05;
  iobj_4.ExpectedMeasurementWeight = 0.95;
  iobj_4.MaxLikelihoodDistance = 2.0;
  value_idx_0 = sm.SensorPose[0];
  value_idx_1 = sm.SensorPose[1];
  value_idx_2 = sm.SensorPose[2];
  iobj_4.SensorPose[0] = value_idx_0;
  iobj_4.SensorPose[1] = value_idx_1;
  iobj_4.SensorPose[2] = value_idx_2;
  value_idx_0 = sm.SensorLimits[0];
  value_idx_1 = sm.SensorLimits[1];
  if ((value_idx_0 > value_idx_1) ||
      (std::isnan(value_idx_0) && (!std::isnan(value_idx_1)))) {
    value_idx_2 = value_idx_1;
  } else {
    value_idx_2 = value_idx_0;
  }
  if ((value_idx_0 < value_idx_1) ||
      (std::isnan(value_idx_0) && (!std::isnan(value_idx_1)))) {
    value_idx_0 = value_idx_1;
  }
  iobj_4.SensorLimits[0] = value_idx_2;
  iobj_4.SensorLimits[1] = value_idx_0;
  value_idx_2 = sm.NumBeams;
  iobj_4.NumBeams = value_idx_2;
  value_idx_2 = sm.MeasurementNoise;
  iobj_4.MeasurementNoise = value_idx_2;
  value_idx_2 = sm.RandomMeasurementWeight;
  iobj_4.RandomMeasurementWeight = value_idx_2;
  value_idx_2 = sm.ExpectedMeasurementWeight;
  iobj_4.ExpectedMeasurementWeight = value_idx_2;
  value_idx_2 = sm.MaxLikelihoodDistance;
  iobj_4.MaxLikelihoodDistance = value_idx_2;
  iobj_4.InternalMap = sm.InternalMap->copy(&iobj_0, &iobj_1, &iobj_2, &iobj_3);
  PrivateSensorModel = &iobj_4;
}

} // namespace coder

// End of code generation (monteCarloLocalization.cpp)
