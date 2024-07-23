/**
 * @file Matrix_rep.h
 * @author Riley Horrix (horrixriley@gmail.com)
 * @brief Definition of internal matrix representation class
 * @version 0.1
 * @date 2024-07-22
 * 
 * Copyright (c) Riley Horrix 2024
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
  template<mat_dim rows, mat_dim cols, class D> class MatrixRep {
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
       * @brief Construct a new Matrixrep object from an initialiser list, Fills the matrix from the data row wise from row 1 to row ROWS.
       * 
       * @param data Values to fill the matrix with.
       */
      MatrixRep(const std::initializer_list<D>& data);

      /**
       * @brief Destroy the Matrix Rep object and allow polymorphism
       * 
       */
      virtual ~MatrixRep() {}

      /**
       * @brief Returns an intermediate object that can be array indexed to get the element
       *        at row ROW, column COLUMN. Indexed from 0.
       * 
       * @return MatrixRepProxy intermediate type.
       */
      D& operator() (mat_dim row, mat_dim column);

    protected:
      /**
       * @brief Internal method for getting an element from the raw data, override 
       *        this to change the layout of the rows and values. Indexes from 0
       * 
       * @param column 
       * @param row 
       * @return D elem at row ROW and column COLUMN.
       */
      virtual inline D& get_elem(mat_dim row, mat_dim column);

    private:
    /**
     * @brief The raw data
     * 
     */
      std::array<D, rows * cols> data;

  };

} // namespace rmath

/** Include Declarations */
#include "../../src/Matrix/MatrixRep.hpp"