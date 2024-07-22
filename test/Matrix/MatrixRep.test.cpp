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

TEST_CASE("MatrixReps are created and can be indexed correctly", "[MatrixRep]") {
  MatrixRep<1,1> a;
  REQUIRE(a(0, 0) == 0);
  
  MatrixRep<2,1> b = 2;
  REQUIRE(b(0, 0) == 2);
  REQUIRE(b(1, 0) == 2);

  MatrixRep<2,2> c = {1, 2, 3, 4};
  REQUIRE(c(0, 0) == 1);
  REQUIRE(c(1, 1) == 4);
}