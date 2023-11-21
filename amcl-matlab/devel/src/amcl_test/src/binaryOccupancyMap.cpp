//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// binaryOccupancyMap.cpp
//
// Code generation for function 'binaryOccupancyMap'
//

// Include files
#include "binaryOccupancyMap.h"
#include "CircularBuffer.h"
#include "CircularBufferIndex.h"
#include "MapLayer.h"
#include "SharedMapProperties.h"
#include "ixfun.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
namespace coder {
binaryOccupancyMap *binaryOccupancyMap::copy(
    matlabshared::autonomous::internal::CircularBuffer *iobj_0,
    matlabshared::autonomous::internal::CircularBufferIndex *iobj_1,
    matlabshared::autonomous::internal::SharedMapProperties *iobj_2,
    binaryOccupancyMap *iobj_3)
{
  binaryOccupancyMap *cpObj;
  matlabshared::autonomous::internal::CircularBuffer *obj;
  matlabshared::autonomous::internal::CircularBufferIndex *b_obj;
  matlabshared::autonomous::internal::SharedMapProperties *varargin_1;
  array<bool, 2U> matrix;
  double obj_idx_2;
  double obj_idx_3;
  double varargin_1_idx_0;
  double varargin_1_idx_1;
  int loop_ub;
  bool obj_idx_0;
  bool obj_idx_1;
  iobj_3->HasParent = false;
  cpObj = iobj_3;
  varargin_1 = SharedProperties;
  iobj_2->Resolution = varargin_1->Resolution;
  varargin_1_idx_0 = varargin_1->GridSize[0];
  varargin_1_idx_1 = varargin_1->GridSize[1];
  iobj_2->GridSize[0] = varargin_1_idx_0;
  iobj_2->GridSize[1] = varargin_1_idx_1;
  iobj_2->Width = varargin_1->Width;
  iobj_2->Height = varargin_1->Height;
  varargin_1_idx_0 = varargin_1->GridOriginInLocal[0];
  varargin_1_idx_1 = varargin_1->GridOriginInLocal[1];
  iobj_2->GridOriginInLocal[0] = varargin_1_idx_0;
  iobj_2->GridOriginInLocal[1] = varargin_1_idx_1;
  varargin_1_idx_0 = varargin_1->LocalOriginInWorld[0];
  varargin_1_idx_1 = varargin_1->LocalOriginInWorld[1];
  iobj_2->LocalOriginInWorld[0] = varargin_1_idx_0;
  iobj_2->LocalOriginInWorld[1] = varargin_1_idx_1;
  varargin_1_idx_0 = varargin_1->LocalOriginInWorldInternal[0];
  varargin_1_idx_1 = varargin_1->LocalOriginInWorldInternal[1];
  iobj_2->LocalOriginInWorldInternal[0] = varargin_1_idx_0;
  iobj_2->LocalOriginInWorldInternal[1] = varargin_1_idx_1;
  iobj_3->SharedProperties = iobj_2;
  iobj_3->DefaultValueInternal = DefaultValueInternal;
  obj = Buffer;
  b_obj = obj->Index;
  varargin_1_idx_0 = b_obj->Size[0];
  varargin_1_idx_1 = b_obj->Size[1];
  iobj_1->Head[0] = 1.0;
  iobj_1->Size[0] = varargin_1_idx_0;
  iobj_1->Head[1] = 1.0;
  iobj_1->Size[1] = varargin_1_idx_1;
  iobj_1->DropEntireMap = false;
  iobj_1->NewRegions[0] = 0.0;
  iobj_1->NewRegions[1] = 0.0;
  iobj_1->NewRegions[2] = 0.0;
  iobj_1->NewRegions[3] = 0.0;
  iobj_1->DropTwoRegions[0] = false;
  iobj_1->DropTwoRegions[1] = false;
  varargin_1_idx_0 = b_obj->Head[0];
  varargin_1_idx_1 = b_obj->Head[1];
  iobj_1->Head[0] = varargin_1_idx_0;
  iobj_1->Head[1] = varargin_1_idx_1;
  varargin_1_idx_0 = b_obj->Size[0];
  varargin_1_idx_1 = b_obj->Size[1];
  iobj_1->Size[0] = varargin_1_idx_0;
  iobj_1->Size[1] = varargin_1_idx_1;
  varargin_1_idx_0 = b_obj->NewRegions[0];
  varargin_1_idx_1 = b_obj->NewRegions[1];
  obj_idx_2 = b_obj->NewRegions[2];
  obj_idx_3 = b_obj->NewRegions[3];
  iobj_1->NewRegions[0] = varargin_1_idx_0;
  iobj_1->NewRegions[1] = varargin_1_idx_1;
  iobj_1->NewRegions[2] = obj_idx_2;
  iobj_1->NewRegions[3] = obj_idx_3;
  iobj_1->DropEntireMap = b_obj->DropEntireMap;
  obj_idx_0 = b_obj->DropTwoRegions[0];
  obj_idx_1 = b_obj->DropTwoRegions[1];
  iobj_1->DropTwoRegions[0] = obj_idx_0;
  iobj_1->DropTwoRegions[1] = obj_idx_1;
  obj_idx_0 = obj->ConstVal;
  matrix.set_size(obj->Buffer.size(0), obj->Buffer.size(1));
  loop_ub = obj->Buffer.size(0) * obj->Buffer.size(1);
  for (int i{0}; i < loop_ub; i++) {
    matrix[i] = obj->Buffer[i];
  }
  varargin_1_idx_0 = iobj_1->Size[0];
  varargin_1_idx_1 = iobj_1->Size[1];
  iobj_0->Index = iobj_1;
  iobj_0->ConstVal = obj_idx_0;
  iobj_0->Buffer.set_size(static_cast<int>(varargin_1_idx_0),
                          static_cast<int>(varargin_1_idx_1));
  loop_ub =
      static_cast<int>(varargin_1_idx_0) * static_cast<int>(varargin_1_idx_1);
  for (int i{0}; i < loop_ub; i++) {
    iobj_0->Buffer[i] = matrix[i];
  }
  iobj_3->Buffer = iobj_0;
  iobj_3->Index = iobj_3->Buffer->Index;
  varargin_1_idx_0 = DataSize[0];
  varargin_1_idx_1 = DataSize[1];
  iobj_3->DataSize[0] = varargin_1_idx_0;
  iobj_3->DataSize[1] = varargin_1_idx_1;
  return cpObj;
}

void binaryOccupancyMap::counterFPECeil(double val[2])
{
  array<double, 2U> r;
  double a_idx_0;
  double a_idx_1;
  double absx;
  double d;
  double d1;
  double highFPE_idx_0_tmp;
  int exponent;
  bool b;
  bool highFPE_idx_0;
  d = val[0];
  absx = std::abs(d);
  if (std::isinf(absx) || std::isnan(absx)) {
    d1 = rtNaN;
    a_idx_0 = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    d1 = 4.94065645841247E-324;
    a_idx_0 = 4.94065645841247E-324;
  } else {
    std::frexp(absx, &exponent);
    d1 = std::ldexp(1.0, exponent - 53);
    a_idx_0 = d1;
  }
  highFPE_idx_0_tmp = d - std::floor(d);
  highFPE_idx_0 = (highFPE_idx_0_tmp <= d1 * 2.0);
  d = val[1];
  absx = std::abs(d);
  if (std::isinf(absx) || std::isnan(absx)) {
    d1 = rtNaN;
    a_idx_1 = rtNaN;
  } else if (absx < 4.4501477170144028E-308) {
    d1 = 4.94065645841247E-324;
    a_idx_1 = 4.94065645841247E-324;
  } else {
    std::frexp(absx, &exponent);
    d1 = std::ldexp(1.0, exponent - 53);
    a_idx_1 = d1;
  }
  absx = d - std::floor(d);
  exponent = 0;
  if (highFPE_idx_0_tmp <= a_idx_0 * 2.0) {
    exponent = 1;
  }
  if (absx <= a_idx_1 * 2.0) {
    exponent++;
  }
  r.set_size(1, exponent);
  exponent = 0;
  if (highFPE_idx_0_tmp <= a_idx_0 * 2.0) {
    r[0] = val[0];
    exponent = 1;
  }
  if (absx <= a_idx_1 * 2.0) {
    r[exponent] = val[1];
  }
  exponent = 0;
  if (highFPE_idx_0_tmp <= a_idx_0 * 2.0) {
    exponent = 1;
  }
  if (absx <= a_idx_1 * 2.0) {
    exponent++;
  }
  for (int k{0}; k < exponent; k++) {
    r[k] = std::floor(r[k]);
  }
  exponent = 0;
  if (highFPE_idx_0_tmp <= a_idx_0 * 2.0) {
    val[0] = r[0];
    exponent = 1;
  }
  if (absx <= a_idx_1 * 2.0) {
    val[1] = r[exponent];
  }
  exponent = 0;
  highFPE_idx_0 = !highFPE_idx_0;
  if (highFPE_idx_0) {
    exponent = 1;
  }
  b = !(absx <= d1 * 2.0);
  if (b) {
    exponent++;
  }
  r.set_size(1, exponent);
  exponent = 0;
  if (highFPE_idx_0) {
    r[0] = val[0];
    exponent = 1;
  }
  if (b) {
    r[exponent] = val[1];
  }
  exponent = 0;
  if (highFPE_idx_0) {
    exponent = 1;
  }
  if (b) {
    exponent++;
  }
  for (int k{0}; k < exponent; k++) {
    r[k] = std::ceil(r[k]);
  }
  exponent = 0;
  if (highFPE_idx_0) {
    val[0] = r[0];
    exponent = 1;
  }
  if (b) {
    val[1] = r[exponent];
  }
}

binaryOccupancyMap *
binaryOccupancyMap::writeToOG(binaryOccupancyMap &og,
                              const array<double, 1U> &values)
{
  matlabshared::autonomous::internal::CircularBuffer *obj;
  matlabshared::autonomous::internal::CircularBufferIndex *b_obj;
  array<double, 2U> bRight;
  array<double, 2U> b_y;
  array<double, 2U> botRightIJ;
  array<double, 2U> c_y;
  array<double, 2U> mapStart;
  array<double, 2U> matrix;
  array<double, 2U> uLeft;
  array<double, 2U> varargin_1;
  array<double, 2U> x;
  array<double, 2U> y;
  array<double, 1U> b_matrix;
  array<int, 1U> r;
  array<bool, 2U> b_x;
  array<bool, 1U> validInd;
  double result[2];
  double d;
  double tmp;
  int dim;
  int i;
  int i1;
  int i2;
  int i3;
  int k;
  int lowerDim;
  int nd2;
  int npages;
  int vstride;
  bool guard1;
  result[1] = og.SharedProperties->GridSize[1];
  tmp = og.SharedProperties->GridSize[0];
  dim = static_cast<int>(result[1]);
  matrix.set_size(static_cast<int>(tmp), dim);
  for (i = 0; i < dim; i++) {
    vstride = static_cast<int>(tmp);
    for (i1 = 0; i1 < vstride; i1++) {
      matrix[i1 + matrix.size(0) * i] = values[i + dim * i1];
    }
  }
  dim = 1;
  if (matrix.size(0) != 1) {
    dim = 0;
  }
  if ((matrix.size(0) != 0) && (matrix.size(1) != 0) &&
      (matrix.size(dim) > 1)) {
    int pagelen;
    vstride = 1;
    for (k = 0; k < dim; k++) {
      vstride *= matrix.size(0);
    }
    pagelen = vstride * matrix.size(dim);
    npages = 1;
    lowerDim = dim + 2;
    for (k = lowerDim; k < 3; k++) {
      npages *= matrix.size(1);
    }
    i = matrix.size(dim) - 1;
    nd2 = matrix.size(dim) >> 1;
    i1 = npages - 1;
    for (npages = 0; npages <= i1; npages++) {
      i2 = vstride - 1;
      for (int b_i{0}; b_i <= i2; b_i++) {
        lowerDim = npages * pagelen + b_i;
        for (k = 0; k < nd2; k++) {
          dim = lowerDim + k * vstride;
          tmp = matrix[dim];
          i3 = lowerDim + (i - k) * vstride;
          matrix[dim] = matrix[i3];
          matrix[i3] = tmp;
        }
      }
    }
  }
  result[0] = og.SharedProperties->GridSize[0];
  if (std::isnan(result[0])) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  } else if (result[0] < 1.0) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, static_cast<int>(result[0] - 1.0) + 1);
    vstride = static_cast<int>(result[0] - 1.0);
    for (i = 0; i <= vstride; i++) {
      y[i] = static_cast<double>(i) + 1.0;
    }
  }
  result[1] = og.SharedProperties->GridSize[1];
  if (std::isnan(result[1])) {
    b_y.set_size(1, 1);
    b_y[0] = rtNaN;
  } else if (result[1] < 1.0) {
    b_y.set_size(1, 0);
  } else {
    b_y.set_size(1, static_cast<int>(result[1] - 1.0) + 1);
    vstride = static_cast<int>(result[1] - 1.0);
    for (i = 0; i <= vstride; i++) {
      b_y[i] = static_cast<double>(i) + 1.0;
    }
  }
  x.set_size(y.size(1), b_y.size(1));
  i = b_y.size(1);
  c_y.set_size(y.size(1), b_y.size(1));
  for (k = 0; k < i; k++) {
    i1 = x.size(0);
    for (lowerDim = 0; lowerDim < i1; lowerDim++) {
      x[lowerDim + x.size(0) * k] = y[lowerDim];
    }
    i1 = c_y.size(0);
    for (lowerDim = 0; lowerDim < i1; lowerDim++) {
      c_y[lowerDim + c_y.size(0) * k] = b_y[k];
    }
  }
  dim = x.size(0) * x.size(1);
  varargin_1.set_size(dim, 2);
  for (i = 0; i < dim; i++) {
    varargin_1[i] = x[i];
  }
  for (i = 0; i < dim; i++) {
    varargin_1[i + varargin_1.size(0)] = c_y[i];
  }
  guard1 = false;
  if (varargin_1.size(0) << 1 == 2) {
    i = matrix.size(0) * matrix.size(1);
    if (i > 1) {
      bool d_y[2];
      bool e_y;
      bool exitg1;
      result[0] = i;
      result[1] = 1.0;
      botRightIJ.set_size(varargin_1.size(0), 2);
      vstride = varargin_1.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < vstride; i1++) {
          botRightIJ[i1 + botRightIJ.size(0) * i] =
              (varargin_1[i1 + varargin_1.size(0) * i] + result[i]) - 1.0;
        }
      }
      if (varargin_1.size(0) == 1) {
        uLeft.set_size(1, 2);
        tmp = varargin_1[0];
        uLeft[0] = std::fmax(tmp, 1.0);
        tmp = varargin_1[1];
        uLeft[1] = std::fmax(tmp, 1.0);
      } else {
        internal::expand_max(varargin_1, uLeft);
      }
      result[0] = og.SharedProperties->GridSize[0];
      result[1] = og.SharedProperties->GridSize[1];
      if (botRightIJ.size(0) == 1) {
        bRight.set_size(1, 2);
        tmp = botRightIJ[0];
        bRight[0] = std::fmin(tmp, result[0]);
        tmp = botRightIJ[1];
        bRight[1] = std::fmin(tmp, result[1]);
      } else {
        internal::expand_min(botRightIJ, result, bRight);
      }
      if (bRight.size(0) == uLeft.size(0)) {
        vstride = bRight.size(0) << 1;
        bRight.set_size(bRight.size(0), 2);
        for (i = 0; i < vstride; i++) {
          bRight[i] = (bRight[i] - uLeft[i]) + 1.0;
        }
      } else {
        binary_expand_op_3(bRight, uLeft);
      }
      b_x.set_size(bRight.size(0), 2);
      vstride = bRight.size(0) << 1;
      for (i = 0; i < vstride; i++) {
        b_x[i] = (bRight[i] > 0.0);
      }
      d_y[0] = true;
      d_y[1] = true;
      dim = 0;
      for (int b_i{0}; b_i < 2; b_i++) {
        lowerDim = dim + b_x.size(0);
        npages = dim;
        dim += b_x.size(0);
        exitg1 = false;
        while ((!exitg1) && (npages + 1 <= lowerDim)) {
          if (!b_x[npages]) {
            d_y[b_i] = false;
            exitg1 = true;
          } else {
            npages++;
          }
        }
      }
      e_y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (!d_y[k]) {
          e_y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (e_y) {
        d = uLeft[0] - varargin_1[0];
        tmp = d + bRight[0];
        if (d + 1.0 > tmp) {
          i = 1;
          i1 = 0;
        } else {
          i = static_cast<int>(d + 1.0);
          i1 = static_cast<int>(tmp);
        }
        d = uLeft[1] - varargin_1[1];
        obj = og.Buffer;
        b_obj = obj->Index;
        if (uLeft.size(0) == 1) {
          mapStart.set_size(1, 2);
          tmp = uLeft[0];
          mapStart[0] = std::fmax(tmp, 1.0);
          tmp = uLeft[1];
          mapStart[1] = std::fmax(tmp, 1.0);
        } else {
          internal::expand_max(uLeft, mapStart);
        }
        if ((mapStart[0] > b_obj->Size[0]) || (mapStart[1] > b_obj->Size[1])) {
          uLeft.set_size(mapStart.size(0), 2);
          vstride = mapStart.size(0);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < vstride; i3++) {
              uLeft[i3 + uLeft.size(0) * i2] =
                  (b_obj->Head[i2] + mapStart[i3 + mapStart.size(0) * i2]) -
                  1.0;
            }
          }
          mapStart.set_size(uLeft.size(0), 2);
          dim = uLeft.size(0) << 1;
          for (i2 = 0; i2 < dim; i2++) {
            mapStart[i2] = uLeft[i2];
          }
          mapStart.set_size(mapStart.size(0), 2);
          for (i2 = 0; i2 < dim; i2++) {
            mapStart[i2] = mapStart[i2] - 1.0;
          }
          result[0] = b_obj->Size[0];
          result[1] = b_obj->Size[1];
          if (mapStart.size(0) == 1) {
            botRightIJ.set_size(1, 2);
            tmp = mapStart[0];
            botRightIJ[0] = internal::scalar::b_mod(tmp, result[0]);
            tmp = mapStart[1];
            botRightIJ[1] = internal::scalar::b_mod(tmp, result[1]);
          } else {
            internal::expand_mod(mapStart, result, botRightIJ);
          }
          mapStart.set_size(botRightIJ.size(0), 2);
          vstride = botRightIJ.size(0) << 1;
          for (i2 = 0; i2 < vstride; i2++) {
            mapStart[i2] = botRightIJ[i2] + 1.0;
          }
        }
        result[0] = static_cast<double>(i1 - i) + 1.0;
        result[1] = !(d + 1.0 > d + bRight[1]);
        botRightIJ.set_size(mapStart.size(0), 2);
        vstride = mapStart.size(0);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < vstride; i2++) {
            botRightIJ[i2 + botRightIJ.size(0) * i1] =
                (b_obj->Size[i1] - mapStart[i2 + mapStart.size(0) * i1]) + 1.0;
          }
        }
        if (botRightIJ.size(0) == 1) {
          bRight.set_size(1, 2);
          tmp = botRightIJ[0];
          bRight[0] = std::fmin(result[0], tmp);
          tmp = botRightIJ[1];
          bRight[1] =
              std::fmin(static_cast<double>(static_cast<int>(result[1])), tmp);
        } else {
          internal::expand_min(result, botRightIJ, bRight);
        }
        if (bRight[0] < 1.0) {
          vstride = 0;
        } else {
          vstride = static_cast<int>(bRight[0]);
        }
        if (bRight[1] < 1.0) {
          nd2 = -1;
        } else {
          nd2 = 0;
        }
        uLeft.set_size(mapStart.size(0), 2);
        lowerDim = mapStart.size(0);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < lowerDim; i2++) {
            uLeft[i2 + uLeft.size(0) * i1] =
                (b_obj->Head[i1] + mapStart[i2 + mapStart.size(0) * i1]) - 1.0;
          }
        }
        mapStart.set_size(uLeft.size(0), 2);
        dim = uLeft.size(0) << 1;
        for (i1 = 0; i1 < dim; i1++) {
          mapStart[i1] = uLeft[i1];
        }
        mapStart.set_size(mapStart.size(0), 2);
        for (i1 = 0; i1 < dim; i1++) {
          mapStart[i1] = mapStart[i1] - 1.0;
        }
        result[0] = b_obj->Size[0];
        result[1] = b_obj->Size[1];
        if (mapStart.size(0) == 1) {
          botRightIJ.set_size(1, 2);
          tmp = mapStart[0];
          botRightIJ[0] = internal::scalar::b_mod(tmp, result[0]);
          tmp = mapStart[1];
          botRightIJ[1] = internal::scalar::b_mod(tmp, result[1]);
        } else {
          internal::expand_mod(mapStart, result, botRightIJ);
        }
        mapStart.set_size(botRightIJ.size(0), 2);
        lowerDim = botRightIJ.size(0) << 1;
        for (i1 = 0; i1 < lowerDim; i1++) {
          mapStart[i1] = botRightIJ[i1] + 1.0;
        }
        varargin_1.set_size(mapStart.size(0), 2);
        lowerDim = mapStart.size(0);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < lowerDim; i2++) {
            varargin_1[i2 + varargin_1.size(0) * i1] =
                (b_obj->Size[i1] - mapStart[i2 + mapStart.size(0) * i1]) + 1.0;
          }
          result[i1] = bRight[i1];
        }
        if (varargin_1.size(0) == 1) {
          botRightIJ.set_size(1, 2);
          tmp = varargin_1[0];
          botRightIJ[0] = std::fmin(tmp, result[0]);
          tmp = varargin_1[1];
          botRightIJ[1] = std::fmin(tmp, result[1]);
        } else {
          internal::expand_min(varargin_1, result, botRightIJ);
        }
        if (mapStart.size(0) == botRightIJ.size(0)) {
          varargin_1.set_size(botRightIJ.size(0), 2);
          lowerDim = botRightIJ.size(0);
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < lowerDim; i2++) {
              varargin_1[i2 + varargin_1.size(0) * i1] =
                  bRight[i1] - botRightIJ[i2 + botRightIJ.size(0) * i1];
            }
          }
          uLeft.set_size(
              ((mapStart.size(0) + mapStart.size(0)) + varargin_1.size(0)) +
                  botRightIJ.size(0),
              2);
          lowerDim = mapStart.size(0);
          dim = varargin_1.size(0);
          npages = botRightIJ.size(0);
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < lowerDim; i2++) {
              uLeft[i2 + uLeft.size(0) * i1] =
                  mapStart[i2 + mapStart.size(0) * i1];
              uLeft[(i2 + mapStart.size(0)) + uLeft.size(0) * i1] =
                  (mapStart[i2 + mapStart.size(0) * i1] +
                   botRightIJ[i2 + botRightIJ.size(0) * i1]) -
                  1.0;
            }
            for (i2 = 0; i2 < dim; i2++) {
              uLeft[((i2 + mapStart.size(0)) + mapStart.size(0)) +
                    uLeft.size(0) * i1] =
                  varargin_1[i2 + varargin_1.size(0) * i1];
            }
            for (i2 = 0; i2 < npages; i2++) {
              uLeft[(((i2 + mapStart.size(0)) + mapStart.size(0)) +
                     varargin_1.size(0)) +
                    uLeft.size(0) * i1] =
                  botRightIJ[i2 + botRightIJ.size(0) * i1];
            }
          }
          for (i1 = 0; i1 <= nd2; i1++) {
            for (i2 = 0; i2 < vstride; i2++) {
              matrix[i2] = matrix[(i + i2) - 1];
            }
          }
          matrix.set_size(vstride, nd2 + 1);
          obj->setBaseMatrix(uLeft, matrix);
        } else {
          binary_expand_op_2(obj, mapStart, botRightIJ, bRight, matrix, i,
                             vstride - 1, nd2);
        }
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    result[0] = og.SharedProperties->GridSize[0];
    result[1] = og.SharedProperties->GridSize[1];
    validInd.set_size(varargin_1.size(0));
    vstride = varargin_1.size(0);
    for (i = 0; i < vstride; i++) {
      d = varargin_1[i];
      tmp = varargin_1[i + varargin_1.size(0)];
      validInd[i] = ((d > 0.0) && (d < result[0] + 1.0) && (tmp > 0.0) &&
                     (tmp < result[1] + 1.0));
    }
    i = matrix.size(0) * matrix.size(1);
    if (i == 1) {
      lowerDim = validInd.size(0) - 1;
      dim = 0;
      for (int b_i{0}; b_i <= lowerDim; b_i++) {
        if (validInd[b_i]) {
          dim++;
        }
      }
      r.set_size(dim);
      dim = 0;
      for (int b_i{0}; b_i <= lowerDim; b_i++) {
        if (validInd[b_i]) {
          r[dim] = b_i;
          dim++;
        }
      }
      uLeft.set_size(r.size(0), 2);
      vstride = r.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < vstride; i1++) {
          uLeft[i1 + uLeft.size(0) * i] =
              varargin_1[r[i1] + varargin_1.size(0) * i];
        }
      }
      b_matrix = matrix.reshape(1);
      og.Buffer->setValueAtIndices(uLeft, b_matrix);
    } else {
      lowerDim = validInd.size(0) - 1;
      dim = 0;
      for (int b_i{0}; b_i <= lowerDim; b_i++) {
        if (validInd[b_i]) {
          dim++;
        }
      }
      r.set_size(dim);
      dim = 0;
      for (int b_i{0}; b_i <= lowerDim; b_i++) {
        if (validInd[b_i]) {
          r[dim] = b_i;
          dim++;
        }
      }
      uLeft.set_size(r.size(0), 2);
      vstride = r.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < vstride; i1++) {
          uLeft[i1 + uLeft.size(0) * i] =
              varargin_1[r[i1] + varargin_1.size(0) * i];
        }
      }
      b_matrix.set_size(r.size(0));
      vstride = r.size(0);
      for (i = 0; i < vstride; i++) {
        b_matrix[i] = matrix[r[i]];
      }
      og.Buffer->setValueAtIndices(uLeft, b_matrix);
    }
  }
  return &og;
}

} // namespace coder

// End of code generation (binaryOccupancyMap.cpp)
