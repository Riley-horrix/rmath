/**
 * @file MatrixRep.hpp
 * @author Riley Horrix (horrixriley@gmail.com)
 * @brief Implementation of class MatrixRep
 * @version 0.1
 * @date 2024-07-23
 * 
 * Copyright (c) Riley Horrix 2024
 * 
 */

#include <Matrix/MatrixRep.h>

#include <array>

namespace rmath {

  /** ----- MatrixRep ----- */

  /** Initialisers */

  template<mat_dim rows, mat_dim cols, class D>
  MatrixRep<rows, cols, D>::MatrixRep(void): data{ 0 } {}

  template<mat_dim rows, mat_dim cols, class D>
  MatrixRep<rows, cols, D>::MatrixRep(const D value) {
    data.fill(value);
  }

  template<mat_dim rows, mat_dim cols, class D>
  MatrixRep<rows, cols, D>::MatrixRep(const std::initializer_list<D>& _data) {
    std::copy(_data.begin(), _data.end(), data.begin());
  }

  /** Member Functions */

  template<mat_dim rows, mat_dim cols, class D>
  inline D& MatrixRep<rows, cols, D>::get_elem(mat_dim row, mat_dim column) {
    return data[row * cols + column];
  }

  /** Overloads */

  template<mat_dim rows, mat_dim cols, class D>
  D& MatrixRep<rows, cols, D>::operator() (mat_dim row, mat_dim column) {
  return get_elem(row, column);
  }

} // namespace rmath