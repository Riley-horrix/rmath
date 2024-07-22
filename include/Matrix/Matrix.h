/**
 * @file Matrix.h
 * @author Riley Horrix (horrixriley@gmail.com)
 * @brief Definition of matrix class
 * @version 0.1
 * @date 2024-07-22
 * 
 * Copyright (c) Riley Horrix 2024
 * 
 */

#pragma once

#include "MatrixRep.h"

#include <ostream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <initializer_list>

typedef unsigned int mat_dim;

/**
 * @brief 
 * 
 * @tparam i 
 * @tparam j 
 * @tparam D 
 */
template<mat_dim i, mat_dim j, class D = int> class Matrix {
  private:
    D data[i * j];

  public:
    /** Initialise Matrix to 0 matrix. */
    Matrix();
    /** Initialise Matrix to val matrix. */
    Matrix(D val);
    /** Initialise Matrix data to data. Optional entries param that makes sure
     *  data of the right length is used to initialise matrix. */
    Matrix(const D* _data, const mat_dim entries = i * j);
    /** Initialise Matrix with an array literal. */
    Matrix(std::initializer_list<D> list);

    /** Returns a i * i matrix with ones on the leading edge. */ 
    static Matrix<i, i, D> ident(void);

    /** A throwable error for out of index accesses to the matrix, can only be thrown when SAFE_MATRIX is defined. */
    struct RangeError{
      mat_dim x;
      mat_dim y;
      RangeError(mat_dim x, mat_dim y): x(x), y(y) {}
    };

    inline D get(mat_dim x, mat_dim y) const;
    inline void put(mat_dim x, mat_dim y, D val);
    void pretty_print(void);

    template<mat_dim jj> 
    Matrix<i, jj, D> operator* (const Matrix<j,jj, D>&) const;
    Matrix<i, j, D> operator* (const int) const;
    Matrix<i, j, D> operator* (const double) const;

    bool operator==(const Matrix<i,j, D>&) const;

    template<mat_dim ii, mat_dim jj, class DD>
    friend std::ostream& operator<< (std::ostream& os,  const Matrix<ii, jj, DD>& mat);
};

/** Typedefs */

template<mat_dim i, class D = int>
using Vector = Matrix<1, i, D>;

template<class D = int>
using Vec3 = Matrix<1, 3, D>;

template<class D = int>
using Vec2 = Matrix<1, 2, D>;

/** Include implementations */

#include "../../src/Matrix/Matrix.hpp"