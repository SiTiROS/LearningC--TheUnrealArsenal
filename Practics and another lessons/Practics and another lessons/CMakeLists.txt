# CMakeList.txt : CMake project for Practics and another lessons, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget "Practics and another lessons.cpp" "Practics and another lessons.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 17)
endif()

# TODO: Add tests and install targets if needed.
