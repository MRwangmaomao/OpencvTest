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
CMAKE_COMMAND = /home/wpr/下载/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wpr/下载/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wpr/code/OpencvTest/8feature2d/7Homography

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wpr/code/OpencvTest/8feature2d/7Homography/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BoardChess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BoardChess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BoardChess.dir/flags.make

CMakeFiles/BoardChess.dir/boardchess.cpp.o: CMakeFiles/BoardChess.dir/flags.make
CMakeFiles/BoardChess.dir/boardchess.cpp.o: ../boardchess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wpr/code/OpencvTest/8feature2d/7Homography/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BoardChess.dir/boardchess.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BoardChess.dir/boardchess.cpp.o -c /home/wpr/code/OpencvTest/8feature2d/7Homography/boardchess.cpp

CMakeFiles/BoardChess.dir/boardchess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BoardChess.dir/boardchess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wpr/code/OpencvTest/8feature2d/7Homography/boardchess.cpp > CMakeFiles/BoardChess.dir/boardchess.cpp.i

CMakeFiles/BoardChess.dir/boardchess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BoardChess.dir/boardchess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wpr/code/OpencvTest/8feature2d/7Homography/boardchess.cpp -o CMakeFiles/BoardChess.dir/boardchess.cpp.s

# Object files for target BoardChess
BoardChess_OBJECTS = \
"CMakeFiles/BoardChess.dir/boardchess.cpp.o"

# External object files for target BoardChess
BoardChess_EXTERNAL_OBJECTS =

BoardChess: CMakeFiles/BoardChess.dir/boardchess.cpp.o
BoardChess: CMakeFiles/BoardChess.dir/build.make
BoardChess: /usr/local/opencv320/lib/libopencv_dnn.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_ml.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_objdetect.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_shape.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_videostab.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_viz.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_stitching.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_superres.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_photo.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_calib3d.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_features2d.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_highgui.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_flann.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_video.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_videoio.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_imgcodecs.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_imgproc.so.3.4.3
BoardChess: /usr/local/opencv320/lib/libopencv_core.so.3.4.3
BoardChess: CMakeFiles/BoardChess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wpr/code/OpencvTest/8feature2d/7Homography/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BoardChess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BoardChess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BoardChess.dir/build: BoardChess

.PHONY : CMakeFiles/BoardChess.dir/build

CMakeFiles/BoardChess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BoardChess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BoardChess.dir/clean

CMakeFiles/BoardChess.dir/depend:
	cd /home/wpr/code/OpencvTest/8feature2d/7Homography/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wpr/code/OpencvTest/8feature2d/7Homography /home/wpr/code/OpencvTest/8feature2d/7Homography /home/wpr/code/OpencvTest/8feature2d/7Homography/cmake-build-debug /home/wpr/code/OpencvTest/8feature2d/7Homography/cmake-build-debug /home/wpr/code/OpencvTest/8feature2d/7Homography/cmake-build-debug/CMakeFiles/BoardChess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BoardChess.dir/depend

