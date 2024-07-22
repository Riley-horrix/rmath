/**
 * @file matrix.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Matrix/Matrix.h"

#include <ostream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <initializer_list>


/** Initialisers */

template<mat_dim i, mat_dim j, class D>
Matrix<i,j,D>::Matrix(const D* _data, const mat_dim entries){
#ifdef SAFE_MATRIX
  if (entries != i * j) throw RangeError(0, 0);
#endif
  memcpy(data, _data, entries * sizeof(D));
}

template<mat_dim i, mat_dim j, class D>
Matrix<i,j,D>::Matrix(std::initializer_list<D> list) {
#ifdef SAFE_MATRIX
  if (list.size() != i * j) throw RangeError(0, 0);
#endif
  memcpy(data, list.begin(), i * j * sizeof(D));
}

template<mat_dim i, mat_dim j, class D>
Matrix<i,j,D>::Matrix(D value) {
  std::fill_n(data, i * j, value);
}

template<mat_dim i, mat_dim j, class D>
Matrix<i,j,D>::Matrix(): data { 0 } {}

/** Member funcs and friend funcs */

template<mat_dim i, mat_dim j, class D>
std::ostream& operator<<(std::ostream& os,  const Matrix<i, j, D>& mat) {
  for (mat_dim y = 0; y < j; y++) {
    for (mat_dim x = 0; x < i; x++) {
      os << mat.data[x * i + y] << " ";
    }
    os << "\n";
  }
  return os;
}

template<mat_dim i, mat_dim j, class D>
Matrix<i, j, D> Matrix<i, j,D>::operator* (const int val) const {
  Matrix<i, j, D> ret;
  memcpy(ret.data, data, i * j * sizeof(D));
  for (mat_dim ind = i * j - 1;; ind--) {
    ret.data[ind] *= val;
    if (!ind) {
      break;
    }
  }
  return ret;
}

template<mat_dim i, mat_dim j, class D>
Matrix<i, j, D> Matrix<i, j,D>::operator* (const double val) const {
  Matrix<i, j, D> ret;
  memcpy(ret.data, data, i * j * sizeof(D));
  for (mat_dim ind = i * j - 1;; ind--) {
    ret.data[ind] *= val;
    if (!ind) {
      break;
    }
  }
  return ret;
}

template<mat_dim i, mat_dim j, class D>
inline void Matrix<i, j, D>::put(mat_dim x, mat_dim y, D value) {
#ifdef SAFE_MATRIX
  if (x >= i || y >= j || x < 0 || y < 0) throw RangeError(x, y);
#endif
  data[x * i + y] = value;
}

template<mat_dim i, mat_dim j, class D>
inline D Matrix<i, j, D>::get(mat_dim x, mat_dim y) const {
#ifdef SAFE_MATRIX
  if (x >= i || y >= j || x < 0 || y < 0) throw RangeError(x, y);
#endif
  return data[x * i + y];
}

template<mat_dim i, mat_dim j, class D>
Matrix<i,i,D> Matrix<i, j, D>::ident(void) {
  Matrix<i,i,D> ret = 0;
  
  for (mat_dim ind = (i - 1);; ind--) {
    ret.put(ind, ind, 1);
    if (ind == 0) break;
  }
  return ret;
}

template<mat_dim i, mat_dim j, class D>
bool Matrix<i,j,D>::operator==(const Matrix<i,j,D>& other) const {
  for (mat_dim x = i - 1;;x--) {
    for (mat_dim y = j - 1;;y--) {
      if (this->get(x, y) != other.get(x, y)) return false;
      if (y == 0) break;
    }
    if (x == 0) return true;
  }
}

template<mat_dim i, mat_dim j, class D>
template<mat_dim jj>
Matrix<i,jj, D> Matrix<i, j, D>::operator*(const Matrix<j,jj, D>& other) const
{
  Matrix<i, jj, D> ret;

  for (mat_dim x1 = 0; x1 < i; x1++) {
    for (mat_dim y2 = 0; y2 < jj; y2++) {
      D sum = 0;
      for (mat_dim ind = 0; ind < j; ind++) {
        sum += data[x1 * i + ind] * other.get(ind, y2);
      }
      ret.put(x1, y2, sum);
    }
  }
  return ret;
}

template<mat_dim i, mat_dim j, class D>
void Matrix<i, j, D>::pretty_print(void) {
  int max = INT_MIN;

  for (int y = 0; y < j; y++) {
    for (int x = 0; x < i; x++) {
      if (data[x * i + y] > max) max = data[x * i + y];
    }
  }

  int times = 1;
  while (max > 10) {
    times++;
    max /= 10;
  }

  for (int y = 0; y < j; y++) {
    for (int x = 0; x < i; x++) {
      D val = data[x * i + y];
      std::cout << val;
      int this_times = times;
      while (val > 10) {
        this_times--;
        val /= 10;
      }
      while (this_times-- > 0) {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }
}