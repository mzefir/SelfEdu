# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("SelfEdu")

# Include sub-projects.
add_subdirectory ("Threading")
add_subdirectory ("ThreadingTest")

add_subdirectory ("Playground")
