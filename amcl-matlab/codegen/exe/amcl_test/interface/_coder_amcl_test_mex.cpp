//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// _coder_amcl_test_mex.cpp
//
// Code generation for function 'amcl_test'
//

// Include files
#include "_coder_amcl_test_mex.h"
#include "_coder_amcl_test_api.h"

// Function Definitions
void mexFunction(int32_T nlhs, mxArray *[], int32_T nrhs, const mxArray *[])
{
  mexAtExit(&amcl_test_atexit);
  // Module initialization.
  amcl_test_initialize();
  // Dispatch the entry-point.
  unsafe_amcl_test_mexFunction(nlhs, nrhs);
  // Module termination.
  amcl_test_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           nullptr, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void unsafe_amcl_test_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        9, "amcl_test");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "amcl_test");
  }
  // Call the function.
  amcl_test_api();
}

// End of code generation (_coder_amcl_test_mex.cpp)
