# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/wpr/桌面/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wpr/桌面/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wpr/code/opencv_test/2Core/1Mat_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wpr/code/opencv_test/2Core/1Mat_test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1Introduction_opencv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1Introduction_opencv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1Introduction_opencv.dir/flags.make

CMakeFiles/1Introduction_opencv.dir/main.cpp.o: CMakeFiles/1Introduction_opencv.dir/flags.make
CMakeFiles/1Introduction_opencv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wpr/code/opencv_test/2Core/1Mat_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1Introduction_opencv.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1Introduction_opencv.dir/main.cpp.o -c /home/wpr/code/opencv_test/2Core/1Mat_test/main.cpp

CMakeFiles/1Introduction_opencv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1Introduction_opencv.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wpr/code/opencv_test/2Core/1Mat_test/main.cpp > CMakeFiles/1Introduction_opencv.dir/main.cpp.i

CMakeFiles/1Introduction_opencv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1Introduction_opencv.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wpr/code/opencv_test/2Core/1Mat_test/main.cpp -o CMakeFiles/1Introduction_opencv.dir/main.cpp.s

# Object files for target 1Introduction_opencv
1Introduction_opencv_OBJECTS = \
"CMakeFiles/1Introduction_opencv.dir/main.cpp.o"

# External object files for target 1Introduction_opencv
1Introduction_opencv_EXTERNAL_OBJECTS =

1Introduction_opencv: CMakeFiles/1Introduction_opencv.dir/main.cpp.o
1Introduction_opencv: CMakeFiles/1Introduction_opencv.dir/build.make
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_shape.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_stitching.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_superres.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_videostab.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_viz.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_objdetect.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_calib3d.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_features2d.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_flann.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_highgui.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_ml.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_photo.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_video.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_videoio.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_imgcodecs.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_imgproc.so.3.2.0
1Introduction_opencv: /usr/local/opencv320/lib/libopencv_core.so.3.2.0
1Introduction_opencv: CMakeFiles/1Introduction_opencv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wpr/code/opencv_test/2Core/1Mat_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1Introduction_opencv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1Introduction_opencv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1Introduction_opencv.dir/build: 1Introduction_opencv

.PHONY : CMakeFiles/1Introduction_opencv.dir/build

CMakeFiles/1Introduction_opencv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1Introduction_opencv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1Introduction_opencv.dir/clean

CMakeFiles/1Introduction_opencv.dir/depend:
	cd /home/wpr/code/opencv_test/2Core/1Mat_test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wpr/code/opencv_test/2Core/1Mat_test /home/wpr/code/opencv_test/2Core/1Mat_test /home/wpr/code/opencv_test/2Core/1Mat_test/cmake-build-debug /home/wpr/code/opencv_test/2Core/1Mat_test/cmake-build-debug /home/wpr/code/opencv_test/2Core/1Mat_test/cmake-build-debug/CMakeFiles/1Introduction_opencv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1Introduction_opencv.dir/depend
