/**
 * @file matrix_rep.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "matrix_rep.h"

#include <array>
#include <cstring>

namespace rmath {

  /** Initialisers */

  template<mat_dim cols, mat_dim rows, class D>
  MatrixRep<cols, rows, D>::MatrixRep(void): data{ 0 } {}

  template<mat_dim cols, mat_dim rows, class D>
  inline MatrixRep<cols, rows, D>::MatrixRep(const D value) {
    data.fill(value);
  }

  template<mat_dim rows, mat_dim cols, class D>
  MatrixRep<rows, cols, D>::MatrixRep(const std::array<D,rows*cols> _data): data(_data) {}
  
}