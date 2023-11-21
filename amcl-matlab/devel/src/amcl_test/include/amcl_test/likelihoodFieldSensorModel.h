//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// likelihoodFieldSensorModel.h
//
// Code generation for function 'likelihoodFieldSensorModel'
//

#ifndef LIKELIHOODFIELDSENSORMODEL_H
#define LIKELIHOODFIELDSENSORMODEL_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class binaryOccupancyMap;

}

// Type Definitions
namespace coder {
class likelihoodFieldSensorModel {
public:
  double SensorPose[3];
  double SensorLimits[2];
  double NumBeams;
  double MeasurementNoise;
  double RandomMeasurementWeight;
  double ExpectedMeasurementWeight;
  double MaxLikelihoodDistance;
  binaryOccupancyMap *InternalMap;
};

} // namespace coder

#endif
// End of code generation (likelihoodFieldSensorModel.h)
