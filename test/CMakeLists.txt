# Add Testing Libraries
find_package(Catch2 3 REQUIRED)

# Provide Test Executable
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Add Tests
include(CTest)
include(Catch)

catch_discover_tests(tests)