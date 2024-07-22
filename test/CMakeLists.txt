# Add Testing Libraries
find_package(Catch2 3 REQUIRED)

# Include Include Dirs
include_directories(../include)

# Test Setup
set(CTEST_OUTPUT_ON_FAILURE, True)

# Provide Test Executables

# Matrix
add_executable(matrix_test Matrix/Matrix.test.cpp)
target_link_libraries(matrix_test PRIVATE Catch2::Catch2WithMain)

# MatrixRep
add_executable(matrix_rep_test Matrix/MatrixRep.test.cpp)
target_link_libraries(matrix_rep_test PRIVATE Catch2::Catch2WithMain)

# Add Tests
include(CTest)
include(Catch)

catch_discover_tests(matrix_test)
catch_discover_tests(matrix_rep_test)