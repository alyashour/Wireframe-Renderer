# Create the test executable
add_executable(tests test.cpp)

# Link Google Test
target_link_libraries(tests gtest gtest_main)

# Link your source/library code to the tests
target_link_libraries(tests shared)  # Link to the library or other target

# Register the test executable with CTest
add_test(NAME Tests COMMAND tests)
