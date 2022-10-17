cmake_minimum_required (VERSION 3.8)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(ThreadingTest 
  "hello.cpp"
 "Assets/MatrixFixture.h" "Assets/MatrixFixture.cpp")

target_link_libraries(ThreadingTest GTest::gtest_main)

set_property(TARGET ThreadingTest PROPERTY CXX_STANDARD 17)

include(GoogleTest)
gtest_discover_tests(ThreadingTest)