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
#include "coder_array.h"
#include "mclcodegen_api.hpp"
#include <cmath>
#include <cstring>

// Function Declarations
static int div_s32(int numerator, int denominator);

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

} // namespace coder
static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int tempAbsQuotient;
    unsigned int u;
    if (numerator < 0) {
      tempAbsQuotient = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      tempAbsQuotient = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      u = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      u = static_cast<unsigned int>(denominator);
    }
    tempAbsQuotient /= u;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int>(tempAbsQuotient);
    } else {
      quotient = static_cast<int>(tempAbsQuotient);
    }
  }
  return quotient;
}

namespace coder {
monteCarloLocalization::monteCarloLocalization()
{
  matlabCodegenIsDeleted = true;
}

monteCarloLocalization::~monteCarloLocalization()
{
  matlabCodegenDestructor();
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

void monteCarloLocalization::setupAndReset()
{
  void *mclData;
  binaryOccupancyMap b_lobj_3;
  binaryOccupancyMap lobj_3;
  binaryOccupancyMap *map;
  likelihoodFieldSensorModel *obj;
  matlabshared::autonomous::internal::CircularBuffer b_lobj_0;
  matlabshared::autonomous::internal::CircularBuffer lobj_0;
  matlabshared::autonomous::internal::CircularBufferIndex b_lobj_1;
  matlabshared::autonomous::internal::CircularBufferIndex lobj_1;
  matlabshared::autonomous::internal::SharedMapProperties b_lobj_2;
  matlabshared::autonomous::internal::SharedMapProperties lobj_2;
  matlabshared::autonomous::internal::SharedMapProperties *b_obj;
  array<double, 2U> grid;
  array<bool, 2U> B;
  array<bool, 2U> a;
  array<bool, 2U> buffer;
  double motionParams[4];
  double sensorPose[3];
  double p[2];
  double halfCell;
  double maxLikelihoodDistance;
  double origin_idx_0;
  double origin_idx_1;
  double x;
  int npages[2];
  int sizeB[2];
  int i;
  int k;
  int loop_ub;
  int m;
  int pagesize;
  int stride;
  bool b_x[2];
  bool exitg1;
  bool y;
  isSetupComplete = false;
  isInitialized = 1;
  obj = PrivateSensorModel;
  obj->InternalMap->copy(&lobj_0, &lobj_1, &lobj_2, &lobj_3);
  isSetupComplete = true;
  x = PrivateUpdateThresholds[0];
  halfCell = PrivateUpdateThresholds[1];
  origin_idx_1 = PrivateUpdateThresholds[2];
  mclData = MCLObj.MCLData;
  mclSetUpdateThresholds_real64(mclData, x, halfCell, origin_idx_1);
  x = PrivateResamplingInterval;
  mclData = MCLObj.MCLData;
  mclSetResamplingInterval_real64(mclData, x);
  obj = PrivateSensorModel;
  map = obj->InternalMap->copy(&b_lobj_0, &b_lobj_1, &b_lobj_2, &b_lobj_3);
  b_x[0] = (map->Index->Head[0] == 1.0);
  b_x[1] = (map->Index->Head[1] == 1.0);
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 1)) {
    if (!b_x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    a.set_size(map->Buffer->Buffer.size(0), map->Buffer->Buffer.size(1));
    loop_ub = map->Buffer->Buffer.size(0) * map->Buffer->Buffer.size(1);
    for (i = 0; i < loop_ub; i++) {
      a[i] = map->Buffer->Buffer[i];
    }
  } else {
    a.set_size(map->Buffer->Buffer.size(0), map->Buffer->Buffer.size(1));
    loop_ub = map->Buffer->Buffer.size(0) * map->Buffer->Buffer.size(1);
    for (i = 0; i < loop_ub; i++) {
      a[i] = map->Buffer->Buffer[i];
    }
    p[0] = -(map->Index->Head[0] - 1.0);
    p[1] = -(map->Index->Head[1] - 1.0);
    if ((a.size(0) != 0) && (a.size(1) != 0) &&
        ((a.size(0) != 1) || (a.size(1) != 1))) {
      if (p[0] < 0.0) {
        loop_ub = -static_cast<int>(p[0]);
        y = false;
      } else {
        loop_ub = static_cast<int>(p[0]);
        y = true;
      }
      if (a.size(0) <= 1) {
        loop_ub = 0;
      } else {
        if (loop_ub > a.size(0)) {
          loop_ub -= a.size(0) * div_s32(loop_ub, a.size(0));
        }
        if (loop_ub > (a.size(0) >> 1)) {
          loop_ub = a.size(0) - loop_ub;
          y = !y;
        }
      }
      sizeB[0] = loop_ub;
      b_x[0] = y;
      if (p[1] < 0.0) {
        loop_ub = -static_cast<int>(p[1]);
        y = false;
      } else {
        loop_ub = static_cast<int>(p[1]);
        y = true;
      }
      if (a.size(1) <= 1) {
        loop_ub = 0;
      } else {
        if (loop_ub > a.size(1)) {
          loop_ub -= a.size(1) * div_s32(loop_ub, a.size(1));
        }
        if (loop_ub > (a.size(1) >> 1)) {
          loop_ub = a.size(1) - loop_ub;
          y = !y;
        }
      }
      sizeB[1] = loop_ub;
      b_x[1] = y;
      loop_ub = a.size(0);
      stride = a.size(1);
      if (loop_ub >= stride) {
        stride = loop_ub;
      }
      buffer.set_size(1, stride / 2);
      stride = 1;
      npages[1] = 1;
      npages[0] = a.size(1);
      for (int dim{0}; dim < 2; dim++) {
        int b_npages;
        i = a.size(dim);
        loop_ub = sizeB[dim];
        m = loop_ub - 1;
        pagesize = stride * a.size(dim);
        b_npages = npages[dim];
        if ((a.size(dim) > 1) && (loop_ub > 0)) {
          for (int b_i{0}; b_i < b_npages; b_i++) {
            int pageroot;
            pageroot = b_i * pagesize;
            for (int j{0}; j < stride; j++) {
              int i1;
              i1 = pageroot + j;
              if (b_x[dim]) {
                int b_i1;
                for (k = 0; k <= m; k++) {
                  buffer[k] = a[i1 + ((k + i) - loop_ub) * stride];
                }
                b_i1 = loop_ub + 1;
                for (k = i; k >= b_i1; k--) {
                  a[i1 + (k - 1) * stride] =
                      a[i1 + ((k - loop_ub) - 1) * stride];
                }
                for (k = 0; k <= m; k++) {
                  a[i1 + k * stride] = buffer[k];
                }
              } else {
                int b_i1;
                for (k = 0; k <= m; k++) {
                  buffer[k] = a[i1 + k * stride];
                }
                b_i1 = i - loop_ub;
                for (k = 0; k < b_i1; k++) {
                  a[i1 + k * stride] = a[i1 + (k + loop_ub) * stride];
                }
                for (k = 0; k <= m; k++) {
                  a[i1 + ((k + i) - loop_ub) * stride] = buffer[k];
                }
              }
            }
          }
        }
        stride = pagesize;
      }
    }
    if (!map->HasParent) {
      loop_ub = a.size(0) * a.size(1);
      map->Buffer->Buffer.set_size(a.size(0), a.size(1));
      for (i = 0; i < loop_ub; i++) {
        map->Buffer->Buffer[i] = a[i];
      }
      map->Index->Head[0] = 1.0;
      map->Index->Head[1] = 1.0;
    }
  }
  stride = static_cast<int>(map->DataSize[0]);
  loop_ub = static_cast<int>(map->DataSize[1]);
  a.set_size(stride, loop_ub);
  m = stride - 1;
  pagesize = loop_ub - 1;
  B.set_size(loop_ub, stride);
  loop_ub *= stride;
  if (loop_ub >= 8192) {
    for (int b_i{0}; b_i <= pagesize; b_i++) {
      for (int j{0}; j <= m; j++) {
        B[b_i + B.size(0) * j] = a[((stride - j) + a.size(0) * b_i) - 1];
      }
    }
  } else {
    for (int b_i{0}; b_i <= pagesize; b_i++) {
      for (int j{0}; j <= m; j++) {
        B[b_i + B.size(0) * j] = a[((stride - j) + a.size(0) * b_i) - 1];
      }
    }
  }
  grid.set_size(B.size(0), B.size(1));
  for (i = 0; i < loop_ub; i++) {
    grid[i] = B[i];
  }
  x = map->SharedProperties->Resolution;
  halfCell = 1.0 / (2.0 * x);
  p[1] = map->SharedProperties->GridSize[1];
  if (std::isnan(p[1]) || std::isinf(p[1])) {
    x = rtNaN;
  } else if (p[1] == 0.0) {
    x = 0.0;
  } else {
    x = std::fmod(p[1], 2.0);
    if (x == 0.0) {
      x = 0.0;
    } else if (p[1] < 0.0) {
      x += 2.0;
    }
  }
  if (!(x != 0.0)) {
    b_obj = map->SharedProperties;
    x = b_obj->LocalOriginInWorld[0] + b_obj->GridOriginInLocal[0];
    p[1] = x + b_obj->Width;
    origin_idx_0 = (x + p[1]) / 2.0 + halfCell;
  } else {
    b_obj = map->SharedProperties;
    x = b_obj->LocalOriginInWorld[0] + b_obj->GridOriginInLocal[0];
    p[1] = x + b_obj->Width;
    origin_idx_0 = (x + p[1]) / 2.0;
  }
  p[0] = map->SharedProperties->GridSize[0];
  if (std::isnan(p[0]) || std::isinf(p[0])) {
    x = rtNaN;
  } else if (p[0] == 0.0) {
    x = 0.0;
  } else {
    x = std::fmod(p[0], 2.0);
    if (x == 0.0) {
      x = 0.0;
    } else if (p[0] < 0.0) {
      x += 2.0;
    }
  }
  if (!(x != 0.0)) {
    b_obj = map->SharedProperties;
    x = b_obj->LocalOriginInWorld[1] + b_obj->GridOriginInLocal[1];
    p[1] = x + b_obj->Height;
    origin_idx_1 = (x + p[1]) / 2.0 + halfCell;
  } else {
    b_obj = map->SharedProperties;
    x = b_obj->LocalOriginInWorld[1] + b_obj->GridOriginInLocal[1];
    p[1] = x + b_obj->Height;
    origin_idx_1 = (x + p[1]) / 2.0;
  }
  p[1] = map->SharedProperties->GridSize[1];
  halfCell = map->SharedProperties->GridSize[0];
  x = map->SharedProperties->Resolution;
  mclData = MCLObj.MCLData;
  mclSetOccupancyGrid_real64(mclData, p[1], halfCell, 1.0 / x, origin_idx_0,
                             origin_idx_1, &grid[0]);
  x = obj->NumBeams;
  halfCell = obj->ExpectedMeasurementWeight;
  origin_idx_1 = obj->RandomMeasurementWeight;
  origin_idx_0 = obj->MeasurementNoise;
  maxLikelihoodDistance = obj->MaxLikelihoodDistance;
  p[0] = obj->SensorLimits[0];
  p[1] = obj->SensorLimits[1];
  sensorPose[0] = obj->SensorPose[0];
  sensorPose[1] = obj->SensorPose[1];
  sensorPose[2] = obj->SensorPose[2];
  mclData = MCLObj.MCLData;
  mclSetSensorModel_real64(mclData, x, halfCell, origin_idx_1, origin_idx_0,
                           maxLikelihoodDistance, &p[0], &sensorPose[0]);
  motionParams[0] = PrivateMotionModel->Noise[0];
  motionParams[1] = PrivateMotionModel->Noise[1];
  motionParams[2] = PrivateMotionModel->Noise[2];
  motionParams[3] = PrivateMotionModel->Noise[3];
  mclData = MCLObj.MCLData;
  mclSetMotionModel_real64(mclData, &motionParams[0]);
  x = PrivateParticleLimits[0];
  halfCell = PrivateParticleLimits[1];
  mclData = MCLObj.MCLData;
  mclInitializePf_real64(mclData, x, halfCell, 0.0, 0.0, 0.05, 0.99);
  if (PrivateGlobalLocalization) {
    mclData = MCLObj.MCLData;
    mclGlobalLocalization_real64(mclData);
  } else {
    double poseCov[9];
    sensorPose[0] = PrivateInitialPose[0];
    sensorPose[1] = PrivateInitialPose[1];
    sensorPose[2] = PrivateInitialPose[2];
    for (i = 0; i < 9; i++) {
      poseCov[i] = PrivateInitialCovariance[i];
    }
    mclData = MCLObj.MCLData;
    mclSetInitialPose_real64(mclData, &sensorPose[0], &poseCov[0]);
  }
}

} // namespace coder

// End of code generation (monteCarloLocalization.cpp)
