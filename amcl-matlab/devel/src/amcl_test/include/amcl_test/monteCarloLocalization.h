//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// monteCarloLocalization.h
//
// Code generation for function 'monteCarloLocalization'
//

#ifndef MONTECARLOLOCALIZATION_H
#define MONTECARLOLOCALIZATION_H

// Include files
#include "MonteCarloLocalizationBuiltins.h"
#include "likelihoodFieldSensorModel.h"
#include "odometryMotionModel.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
class CircularBuffer;

class CircularBufferIndex;

class SharedMapProperties;

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
class binaryOccupancyMap;

} // namespace coder

// Type Definitions
struct cell_wrap_1 {
  unsigned int f1[8];
};

namespace coder {
class monteCarloLocalization {
public:
  void set_SensorModel(
      likelihoodFieldSensorModel &sm,
      matlabshared::autonomous::internal::CircularBuffer &iobj_0,
      matlabshared::autonomous::internal::CircularBufferIndex &iobj_1,
      matlabshared::autonomous::internal::SharedMapProperties &iobj_2,
      binaryOccupancyMap &iobj_3, likelihoodFieldSensorModel &iobj_4);
  void setupAndReset();
  void matlabCodegenDestructor();
  void release();
  void releaseWrapper();
  ~monteCarloLocalization();
  monteCarloLocalization();

protected:
  void releaseImpl();

private:
  void SystemCore_delete();

public:
  bool matlabCodegenIsDeleted;
  int isInitialized;
  double Seed;
  nav::algs::internal::MonteCarloLocalizationBuiltins MCLObj;
  odometryMotionModel *PrivateMotionModel;
  likelihoodFieldSensorModel *PrivateSensorModel;
  double PrivateParticleLimits[2];
  double PrivateInitialPose[3];
  double PrivateInitialCovariance[9];
  double PrivateResamplingInterval;
  double PrivateUpdateThresholds[3];
  bool PrivateGlobalLocalization;
  odometryMotionModel _pobj0;
  likelihoodFieldSensorModel _pobj1;

private:
  bool isSetupComplete;
  cell_wrap_1 inputVarSize[2];
};

} // namespace coder

#endif
// End of code generation (monteCarloLocalization.h)
