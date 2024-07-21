/**
 * @file matrix_rep.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once 

#include <array>

namespace rmath {

  typedef unsigned int mat_dim;

  /**
   * @brief Class to represent the internal representation of matrix data.
   * 
   * @tparam rows Number of rows in the matrix.
   * @tparam cols Number of rows in the matrix.
   * @tparam D    Data type of the matrix.
   */
  template<mat_dim rows, mat_dim cols, class D = int> class MatrixRep {
    private:
      std::array<D, rows * cols> data;

    public:
      /**
       * @brief Construct a new zero Matrix Rep object.
       * 
       */
      MatrixRep(void);

      /**
       * @brief Construct a new Matrix Rep object initialised to VALUE param.
       * 
       * @param value What value every entry the matrix is initialised to.
       */
      MatrixRep(const D value);

      /**
       * @brief Construct a new Matrix Rep object from an array. Fills the matrix from the data row wise from row 1 to row ROWS.
       * 
       * @param data Values to fill the matrix with.
       */
      MatrixRep(const std::array<D, rows * cols> data);
  };
}

/** Include Declarations */
#include "../src/matrix_rep.hpp"