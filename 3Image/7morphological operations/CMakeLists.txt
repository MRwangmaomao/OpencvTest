cmake_minimum_required(VERSION 2.8)
project(7morphological_operations)

set(CMAKE_CXX_STANDARD 11)
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

set(OpenCV_DIR "/usr/local/opencv320/share/OpenCV")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(7morphological_operations main.cpp)
target_link_libraries(7morphological_operations ${OpenCV_LIBS})