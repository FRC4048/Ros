//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// MonteCarloLocalizationBuiltins.cpp
//
// Code generation for function 'MonteCarloLocalizationBuiltins'
//

// Include files
#include "MonteCarloLocalizationBuiltins.h"
#include "MonteCarloLocalizationBuildable.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace nav {
namespace algs {
namespace internal {
void MonteCarloLocalizationBuiltins::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
  }
}

void MonteCarloLocalizationBuiltins::cleanup()
{
  coder::MonteCarloLocalizationBuildable::cleanup(MCLData);
}

MonteCarloLocalizationBuiltins::MonteCarloLocalizationBuiltins()
{
  matlabCodegenIsDeleted = true;
}

MonteCarloLocalizationBuiltins::~MonteCarloLocalizationBuiltins()
{
  matlabCodegenDestructor();
}

} // namespace internal
} // namespace algs
} // namespace nav
} // namespace coder

// End of code generation (MonteCarloLocalizationBuiltins.cpp)
