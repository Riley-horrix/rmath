/**
 * @file MatrixRep.test.cpp
 * @author Riley Horrix (horrixriley@gmail.com)
 * @brief Testing Suite for MatrixRep.hpp
 * @version 0.1
 * @date 2024-07-22
 * 
 * Copyright (c) Riley Horrix 2024
 * 
 */

#include <catch2/catch_test_macros.hpp>
#include "Matrix/MatrixRep.h"

using namespace rmath;

TEST_CASE("MatrixReps are created and can be indexed with bracket operator", "[MatrixRep]") {
  MatrixRep<1,1, int> a;
  REQUIRE(a(0, 0) == 0);
  
  MatrixRep<2,1, double> b = 2.0;
  REQUIRE(b(0, 0) == 2.0);
  REQUIRE(b(1, 0) == 2.0);

  MatrixRep<2,2, long> c = {1, 2, 3, 4};
  REQUIRE(c(0, 0) == 1);
  REQUIRE(c(1, 1) == 4);

  MatrixRep<10,10, char> d = 'h';
  REQUIRE(d(2, 8) == 'h');
  REQUIRE(d(7, 8) == 'h');
  REQUIRE(d(9, 3) == 'h');
}