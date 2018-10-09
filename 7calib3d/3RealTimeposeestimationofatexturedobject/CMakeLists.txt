cmake_minimum_required( VERSION 2.8 )
project( pose_estimation )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

set(OpenCV_DIR "/usr/local/opencv320/share/OpenCV")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

#include_directories("/usr/include/eigen3") 
#set(sample_dir ${CMAKE_CURRENT_SOURCE_DIR}/tutorial_code/calib3d/#real_time_pose_estimation/src/)
 
add_executable(pnp_registration
	src/main_registration.cpp
	src/CsvReader.cpp
	src/CsvWriter.cpp
	src/ModelRegistration.cpp
	src/Mesh.cpp
	src/Model.cpp
	src/PnPProblem.cpp
	src/Utils.cpp
	src/RobustMatcher.cpp
)
add_executable(pnp_detection
		src/main_detection.cpp
		src/CsvReader.cpp
		src/CsvWriter.cpp
		src/ModelRegistration.cpp
		src/Mesh.cpp
		src/Model.cpp
		src/PnPProblem.cpp
		src/Utils.cpp
		src/RobustMatcher.cpp
		) 
target_link_libraries(pnp_registration ${OpenCV_LIBS} )
target_link_libraries(pnp_detection ${OpenCV_LIBS} )

