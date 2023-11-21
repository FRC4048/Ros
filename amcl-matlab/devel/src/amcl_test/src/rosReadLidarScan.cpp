//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// rosReadLidarScan.cpp
//
// Code generation for function 'rosReadLidarScan'
//

// Include files
#include "rosReadLidarScan.h"
#include "amcl_test_types.h"
#include "lidarScan.h"
#include "rosReadScanAngles.h"
#include "rt_nonfinite.h"
#include "wrapToPi.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace coder {
void rosReadLidarScan(const sensor_msgs_LaserScanStruct_T &msg,
                      lidarScan &lidarScanObj)
{
  int loop_ub;
  rosReadScanAngles(msg.AngleMin, msg.AngleIncrement, msg.Ranges,
                    lidarScanObj.InternalAngles);
  lidarScanObj.ContainsOnlyFiniteData = false;
  lidarScanObj.InternalRanges.set_size(msg.Ranges.size(0));
  loop_ub = msg.Ranges.size(0);
  for (int i{0}; i < loop_ub; i++) {
    lidarScanObj.InternalRanges[i] = msg.Ranges[i];
  }
  robotics::internal::wrapToPi(lidarScanObj.InternalAngles);
}

} // namespace coder

// End of code generation (rosReadLidarScan.cpp)
