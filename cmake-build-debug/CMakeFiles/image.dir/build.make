# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrian/CLionProjects/ED_Image

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrian/CLionProjects/ED_Image/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/image.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/image.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image.dir/flags.make

CMakeFiles/image.dir/estudiante/src/image.cpp.o: CMakeFiles/image.dir/flags.make
CMakeFiles/image.dir/estudiante/src/image.cpp.o: ../estudiante/src/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ED_Image/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image.dir/estudiante/src/image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image.dir/estudiante/src/image.cpp.o -c /home/adrian/CLionProjects/ED_Image/estudiante/src/image.cpp

CMakeFiles/image.dir/estudiante/src/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/estudiante/src/image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/CLionProjects/ED_Image/estudiante/src/image.cpp > CMakeFiles/image.dir/estudiante/src/image.cpp.i

CMakeFiles/image.dir/estudiante/src/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/estudiante/src/image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/CLionProjects/ED_Image/estudiante/src/image.cpp -o CMakeFiles/image.dir/estudiante/src/image.cpp.s

CMakeFiles/image.dir/estudiante/src/imageop.cpp.o: CMakeFiles/image.dir/flags.make
CMakeFiles/image.dir/estudiante/src/imageop.cpp.o: ../estudiante/src/imageop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ED_Image/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image.dir/estudiante/src/imageop.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image.dir/estudiante/src/imageop.cpp.o -c /home/adrian/CLionProjects/ED_Image/estudiante/src/imageop.cpp

CMakeFiles/image.dir/estudiante/src/imageop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/estudiante/src/imageop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/CLionProjects/ED_Image/estudiante/src/imageop.cpp > CMakeFiles/image.dir/estudiante/src/imageop.cpp.i

CMakeFiles/image.dir/estudiante/src/imageop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/estudiante/src/imageop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/CLionProjects/ED_Image/estudiante/src/imageop.cpp -o CMakeFiles/image.dir/estudiante/src/imageop.cpp.s

CMakeFiles/image.dir/estudiante/src/imageIO.cpp.o: CMakeFiles/image.dir/flags.make
CMakeFiles/image.dir/estudiante/src/imageIO.cpp.o: ../estudiante/src/imageIO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ED_Image/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/image.dir/estudiante/src/imageIO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image.dir/estudiante/src/imageIO.cpp.o -c /home/adrian/CLionProjects/ED_Image/estudiante/src/imageIO.cpp

CMakeFiles/image.dir/estudiante/src/imageIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/estudiante/src/imageIO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/CLionProjects/ED_Image/estudiante/src/imageIO.cpp > CMakeFiles/image.dir/estudiante/src/imageIO.cpp.i

CMakeFiles/image.dir/estudiante/src/imageIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/estudiante/src/imageIO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/CLionProjects/ED_Image/estudiante/src/imageIO.cpp -o CMakeFiles/image.dir/estudiante/src/imageIO.cpp.s

CMakeFiles/image.dir/estudiante/src/subimagen.cpp.o: CMakeFiles/image.dir/flags.make
CMakeFiles/image.dir/estudiante/src/subimagen.cpp.o: ../estudiante/src/subimagen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ED_Image/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/image.dir/estudiante/src/subimagen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image.dir/estudiante/src/subimagen.cpp.o -c /home/adrian/CLionProjects/ED_Image/estudiante/src/subimagen.cpp

CMakeFiles/image.dir/estudiante/src/subimagen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/estudiante/src/subimagen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/CLionProjects/ED_Image/estudiante/src/subimagen.cpp > CMakeFiles/image.dir/estudiante/src/subimagen.cpp.i

CMakeFiles/image.dir/estudiante/src/subimagen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/estudiante/src/subimagen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/CLionProjects/ED_Image/estudiante/src/subimagen.cpp -o CMakeFiles/image.dir/estudiante/src/subimagen.cpp.s

CMakeFiles/image.dir/estudiante/src/zoom.cpp.o: CMakeFiles/image.dir/flags.make
CMakeFiles/image.dir/estudiante/src/zoom.cpp.o: ../estudiante/src/zoom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ED_Image/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/image.dir/estudiante/src/zoom.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image.dir/estudiante/src/zoom.cpp.o -c /home/adrian/CLionProjects/ED_Image/estudiante/src/zoom.cpp

CMakeFiles/image.dir/estudiante/src/zoom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/estudiante/src/zoom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrian/CLionProjects/ED_Image/estudiante/src/zoom.cpp > CMakeFiles/image.dir/estudiante/src/zoom.cpp.i

CMakeFiles/image.dir/estudiante/src/zoom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/estudiante/src/zoom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrian/CLionProjects/ED_Image/estudiante/src/zoom.cpp -o CMakeFiles/image.dir/estudiante/src/zoom.cpp.s

# Object files for target image
image_OBJECTS = \
"CMakeFiles/image.dir/estudiante/src/image.cpp.o" \
"CMakeFiles/image.dir/estudiante/src/imageop.cpp.o" \
"CMakeFiles/image.dir/estudiante/src/imageIO.cpp.o" \
"CMakeFiles/image.dir/estudiante/src/subimagen.cpp.o" \
"CMakeFiles/image.dir/estudiante/src/zoom.cpp.o"

# External object files for target image
image_EXTERNAL_OBJECTS =

libimage.a: CMakeFiles/image.dir/estudiante/src/image.cpp.o
libimage.a: CMakeFiles/image.dir/estudiante/src/imageop.cpp.o
libimage.a: CMakeFiles/image.dir/estudiante/src/imageIO.cpp.o
libimage.a: CMakeFiles/image.dir/estudiante/src/subimagen.cpp.o
libimage.a: CMakeFiles/image.dir/estudiante/src/zoom.cpp.o
libimage.a: CMakeFiles/image.dir/build.make
libimage.a: CMakeFiles/image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adrian/CLionProjects/ED_Image/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libimage.a"
	$(CMAKE_COMMAND) -P CMakeFiles/image.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image.dir/build: libimage.a
.PHONY : CMakeFiles/image.dir/build

CMakeFiles/image.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image.dir/clean

CMakeFiles/image.dir/depend:
	cd /home/adrian/CLionProjects/ED_Image/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrian/CLionProjects/ED_Image /home/adrian/CLionProjects/ED_Image /home/adrian/CLionProjects/ED_Image/cmake-build-debug /home/adrian/CLionProjects/ED_Image/cmake-build-debug /home/adrian/CLionProjects/ED_Image/cmake-build-debug/CMakeFiles/image.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/image.dir/depend

