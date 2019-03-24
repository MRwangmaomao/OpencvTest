cmake_minimum_required(VERSION 2.8)
project(Calibration)

set(CMAKE_CXX_STANDARD 11)
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

set(OpenCV_DIR "/usr/local/opencv320/share/OpenCV")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(Calibration main.cpp)
target_link_libraries(Calibration ${OpenCV_LIBS})

add_executable(test test.cpp)
target_link_libraries(test ${OpenCV_LIBS})

