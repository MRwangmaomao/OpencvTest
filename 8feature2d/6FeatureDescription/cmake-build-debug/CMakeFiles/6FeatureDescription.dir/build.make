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
CMAKE_SOURCE_DIR = /home/wpr/code/opencv_test/8feature2d/6FeatureDescription

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wpr/code/opencv_test/8feature2d/6FeatureDescription/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/6FeatureDescription.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/6FeatureDescription.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/6FeatureDescription.dir/flags.make

CMakeFiles/6FeatureDescription.dir/main.cpp.o: CMakeFiles/6FeatureDescription.dir/flags.make
CMakeFiles/6FeatureDescription.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wpr/code/opencv_test/8feature2d/6FeatureDescription/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/6FeatureDescription.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/6FeatureDescription.dir/main.cpp.o -c /home/wpr/code/opencv_test/8feature2d/6FeatureDescription/main.cpp

CMakeFiles/6FeatureDescription.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/6FeatureDescription.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wpr/code/opencv_test/8feature2d/6FeatureDescription/main.cpp > CMakeFiles/6FeatureDescription.dir/main.cpp.i

CMakeFiles/6FeatureDescription.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/6FeatureDescription.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wpr/code/opencv_test/8feature2d/6FeatureDescription/main.cpp -o CMakeFiles/6FeatureDescription.dir/main.cpp.s

# Object files for target 6FeatureDescription
6FeatureDescription_OBJECTS = \
"CMakeFiles/6FeatureDescription.dir/main.cpp.o"

# External object files for target 6FeatureDescription
6FeatureDescription_EXTERNAL_OBJECTS =

6FeatureDescription: CMakeFiles/6FeatureDescription.dir/main.cpp.o
6FeatureDescription: CMakeFiles/6FeatureDescription.dir/build.make
6FeatureDescription: /usr/local/opencv320/lib/libopencv_shape.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_stitching.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_superres.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_videostab.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_viz.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_objdetect.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_calib3d.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_features2d.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_flann.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_highgui.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_ml.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_photo.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_video.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_videoio.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_imgcodecs.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_imgproc.so.3.2.0
6FeatureDescription: /usr/local/opencv320/lib/libopencv_core.so.3.2.0
6FeatureDescription: CMakeFiles/6FeatureDescription.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wpr/code/opencv_test/8feature2d/6FeatureDescription/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 6FeatureDescription"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/6FeatureDescription.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/6FeatureDescription.dir/build: 6FeatureDescription

.PHONY : CMakeFiles/6FeatureDescription.dir/build

CMakeFiles/6FeatureDescription.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/6FeatureDescription.dir/cmake_clean.cmake
.PHONY : CMakeFiles/6FeatureDescription.dir/clean

CMakeFiles/6FeatureDescription.dir/depend:
	cd /home/wpr/code/opencv_test/8feature2d/6FeatureDescription/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wpr/code/opencv_test/8feature2d/6FeatureDescription /home/wpr/code/opencv_test/8feature2d/6FeatureDescription /home/wpr/code/opencv_test/8feature2d/6FeatureDescription/cmake-build-debug /home/wpr/code/opencv_test/8feature2d/6FeatureDescription/cmake-build-debug /home/wpr/code/opencv_test/8feature2d/6FeatureDescription/cmake-build-debug/CMakeFiles/6FeatureDescription.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/6FeatureDescription.dir/depend

