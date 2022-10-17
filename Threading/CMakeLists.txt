# CMakeList.txt : CMake project for Threading, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Threading 
	"main.cpp"
	"Assets/Matrix.h"
)

set_property(TARGET Threading PROPERTY CXX_STANDARD 17)



# TODO: Add tests and install targets if needed.
