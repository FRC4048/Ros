//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// CircularBuffer.cpp
//
// Code generation for function 'CircularBuffer'
//

// Include files
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "ixfun.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace matlabshared {
namespace autonomous {
namespace internal {
void CircularBuffer::setBaseMatrix(const array<double, 2U> &region,
                                   const array<double, 2U> &newBlock)
{
  array<bool, 2U> b_newBlock;
  double d;
  double d1;
  double d2;
  double d3;
  int b_loop_ub;
  int b_loop_ub_tmp;
  int i;
  int i1;
  int i2;
  int i3;
  int loop_ub;
  int loop_ub_tmp;
  int unnamed_idx_0;
  int unnamed_idx_1;
  d = region[3];
  if (d < 1.0) {
    loop_ub_tmp = 0;
  } else {
    loop_ub_tmp = static_cast<int>(d);
  }
  d = region[region.size(0) + 3];
  if (d < 1.0) {
    b_loop_ub_tmp = 0;
  } else {
    b_loop_ub_tmp = static_cast<int>(d);
  }
  d = region[0];
  d1 = region[1];
  if (d > d1) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int>(d) - 1;
    i1 = static_cast<int>(d1);
  }
  d = region[region.size(0)];
  d1 = region[region.size(0) + 1];
  if (d > d1) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(d) - 1;
    i3 = static_cast<int>(d1);
  }
  b_newBlock.set_size(loop_ub_tmp, b_loop_ub_tmp);
  for (unnamed_idx_0 = 0; unnamed_idx_0 < b_loop_ub_tmp; unnamed_idx_0++) {
    for (unnamed_idx_1 = 0; unnamed_idx_1 < loop_ub_tmp; unnamed_idx_1++) {
      b_newBlock[unnamed_idx_1 + b_newBlock.size(0) * unnamed_idx_0] =
          (newBlock[unnamed_idx_1 + newBlock.size(0) * unnamed_idx_0] != 0.0);
    }
  }
  unnamed_idx_0 = i1 - i;
  unnamed_idx_1 = i3 - i2;
  for (i1 = 0; i1 < unnamed_idx_1; i1++) {
    for (i3 = 0; i3 < unnamed_idx_0; i3++) {
      Buffer[(i + i3) + Buffer.size(0) * (i2 + i1)] =
          b_newBlock[i3 + unnamed_idx_0 * i1];
    }
  }
  d = region[3] + 1.0;
  if (d > newBlock.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int>(d) - 1;
    i1 = newBlock.size(0);
  }
  d1 = region[2];
  if (d1 < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = static_cast<int>(d1);
  }
  d1 = region[region.size(0)];
  d2 = region[region.size(0) + 1];
  if (d1 > d2) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(d1) - 1;
    i3 = static_cast<int>(d2);
  }
  b_loop_ub = i1 - i;
  b_newBlock.set_size(b_loop_ub, b_loop_ub_tmp);
  for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
    for (unnamed_idx_0 = 0; unnamed_idx_0 < b_loop_ub; unnamed_idx_0++) {
      b_newBlock[unnamed_idx_0 + b_newBlock.size(0) * i1] =
          (newBlock[(i + unnamed_idx_0) + newBlock.size(0) * i1] != 0.0);
    }
  }
  unnamed_idx_1 = i3 - i2;
  for (i = 0; i < unnamed_idx_1; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      Buffer[i1 + Buffer.size(0) * (i2 + i)] = b_newBlock[i1 + loop_ub * i];
    }
  }
  d1 = region[region.size(0) + 3] + 1.0;
  if (d1 > newBlock.size(1)) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int>(d1) - 1;
    i1 = newBlock.size(1);
  }
  d2 = region[0];
  d3 = region[1];
  if (d2 > d3) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(d2) - 1;
    i3 = static_cast<int>(d3);
  }
  d2 = region[region.size(0) + 2];
  b_loop_ub = i1 - i;
  b_newBlock.set_size(loop_ub_tmp, b_loop_ub);
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    for (unnamed_idx_0 = 0; unnamed_idx_0 < loop_ub_tmp; unnamed_idx_0++) {
      b_newBlock[unnamed_idx_0 + b_newBlock.size(0) * i1] =
          (newBlock[unnamed_idx_0 + newBlock.size(0) * (i + i1)] != 0.0);
    }
  }
  unnamed_idx_0 = i3 - i2;
  if (d2 < 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = static_cast<int>(d2);
  }
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < unnamed_idx_0; i1++) {
      Buffer[(i2 + i1) + Buffer.size(0) * i] =
          b_newBlock[i1 + unnamed_idx_0 * i];
    }
  }
  if (d > newBlock.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int>(d) - 1;
    i1 = newBlock.size(0);
  }
  if (d1 > newBlock.size(1)) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(d1) - 1;
    i3 = newBlock.size(1);
  }
  unnamed_idx_1 = i1 - i;
  unnamed_idx_0 = i3 - i2;
  b_newBlock.set_size(unnamed_idx_1, unnamed_idx_0);
  for (i1 = 0; i1 < unnamed_idx_0; i1++) {
    for (i3 = 0; i3 < unnamed_idx_1; i3++) {
      b_newBlock[i3 + b_newBlock.size(0) * i1] =
          (newBlock[(i + i3) + newBlock.size(0) * (i2 + i1)] != 0.0);
    }
  }
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      Buffer[i1 + Buffer.size(0) * i] = b_newBlock[i1 + loop_ub * i];
    }
  }
}

void CircularBuffer::setValueAtIndices(const array<double, 2U> &indices,
                                       const array<double, 1U> &values)
{
  CircularBufferIndex *obj;
  array<double, 2U> mapStart;
  array<double, 2U> r;
  array<int, 1U> b_r;
  double y[2];
  int a;
  int loop_ub;
  obj = Index;
  mapStart.set_size(indices.size(0), 2);
  loop_ub = indices.size(0);
  for (int i{0}; i < 2; i++) {
    for (a = 0; a < loop_ub; a++) {
      mapStart[a + mapStart.size(0) * i] =
          (obj->Head[i] + indices[a + indices.size(0) * i]) - 1.0;
    }
  }
  loop_ub = mapStart.size(0) << 1;
  mapStart.set_size(mapStart.size(0), 2);
  for (int i{0}; i < loop_ub; i++) {
    mapStart[i] = mapStart[i] - 1.0;
  }
  y[0] = obj->Size[0];
  y[1] = obj->Size[1];
  if (mapStart.size(0) == 1) {
    double varargin_1;
    r.set_size(1, 2);
    varargin_1 = mapStart[0];
    r[0] = ::coder::internal::scalar::b_mod(varargin_1, y[0]);
    varargin_1 = mapStart[1];
    r[1] = ::coder::internal::scalar::b_mod(varargin_1, y[1]);
  } else {
    ::coder::internal::expand_mod(mapStart, y, r);
  }
  mapStart.set_size(r.size(0), 2);
  loop_ub = r.size(0) << 1;
  for (int i{0}; i < loop_ub; i++) {
    mapStart[i] = r[i] + 1.0;
  }
  a = Buffer.size(0);
  b_r.set_size(mapStart.size(0));
  loop_ub = mapStart.size(0);
  for (int i{0}; i < loop_ub; i++) {
    b_r[i] = static_cast<int>(static_cast<double>(a) *
                                  (mapStart[i + mapStart.size(0)] - 1.0) +
                              mapStart[i]);
  }
  loop_ub = values.size(0);
  for (int i{0}; i < loop_ub; i++) {
    Buffer[b_r[i] - 1] = (values[i] != 0.0);
  }
}

} // namespace internal
} // namespace autonomous
} // namespace matlabshared
} // namespace coder
void binary_expand_op_2(
    coder::matlabshared::autonomous::internal::CircularBuffer *in1,
    const coder::array<double, 2U> &in2, const coder::array<double, 2U> &in3,
    const coder::array<double, 2U> &in4, const coder::array<double, 2U> &in5,
    int in6, int in9, int in10)
{
  coder::array<double, 2U> b_in2;
  coder::array<double, 2U> b_in4;
  coder::array<double, 2U> b_in5;
  coder::array<double, 2U> c_in2;
  int b_loop_ub;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  b_in2.set_size(loop_ub, 2);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  b_in4.set_size(in3.size(0), 2);
  b_loop_ub = in3.size(0);
  for (int i{0}; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] = (in2[i1 * stride_0_0 + in2.size(0) * i] +
                                       in3[i1 * stride_1_0 + in3.size(0) * i]) -
                                      1.0;
    }
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      b_in4[i1 + b_in4.size(0) * i] = in4[i] - in3[i1 + in3.size(0) * i];
    }
  }
  stride_0_0 = in5.size(0) * in5.size(1);
  c_in2.set_size(((in2.size(0) + b_in2.size(0)) + b_in4.size(0)) + in3.size(0),
                 2);
  loop_ub = in2.size(0);
  for (int i{0}; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      c_in2[i1 + c_in2.size(0) * i] = in2[i1 + in2.size(0) * i];
    }
  }
  loop_ub = b_in2.size(0);
  for (int i{0}; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      c_in2[(i1 + in2.size(0)) + c_in2.size(0) * i] =
          b_in2[i1 + b_in2.size(0) * i];
    }
  }
  loop_ub = b_in4.size(0);
  for (int i{0}; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      c_in2[((i1 + in2.size(0)) + b_in2.size(0)) + c_in2.size(0) * i] =
          b_in4[i1 + b_in4.size(0) * i];
    }
  }
  loop_ub = in3.size(0);
  for (int i{0}; i < 2; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      c_in2[(((i1 + in2.size(0)) + b_in2.size(0)) + b_in4.size(0)) +
            c_in2.size(0) * i] = in3[i1 + in3.size(0) * i];
    }
  }
  b_in5.set_size(in9 + 1, in10 + 1);
  for (int i{0}; i <= in10; i++) {
    for (int i1{0}; i1 <= in9; i1++) {
      b_in5[i1 + b_in5.size(0) * i] = in5[((in6 + i1) + stride_0_0 * i) - 1];
    }
  }
  in1->setBaseMatrix(c_in2, b_in5);
}

// End of code generation (CircularBuffer.cpp)
