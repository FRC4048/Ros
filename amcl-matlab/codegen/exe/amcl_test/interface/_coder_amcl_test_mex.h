//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// _coder_amcl_test_mex.h
//
// Code generation for function 'amcl_test'
//

#ifndef _CODER_AMCL_TEST_MEX_H
#define _CODER_AMCL_TEST_MEX_H

// Include files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_amcl_test_mexFunction(int32_T nlhs, int32_T nrhs);

#endif
// End of code generation (_coder_amcl_test_mex.h)
