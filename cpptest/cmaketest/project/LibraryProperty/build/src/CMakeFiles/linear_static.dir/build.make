# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/cmake-for-tng/bin/cmake

# The command to remove a file.
RM = /opt/cmake-for-tng/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhenkong/cpptest/cmaketest/project/LibraryProperty

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build

# Include any dependencies generated for this target.
include src/CMakeFiles/linear_static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/linear_static.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/linear_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/linear_static.dir/flags.make

src/CMakeFiles/linear_static.dir/helloLib.cpp.o: src/CMakeFiles/linear_static.dir/flags.make
src/CMakeFiles/linear_static.dir/helloLib.cpp.o: ../src/helloLib.cpp
src/CMakeFiles/linear_static.dir/helloLib.cpp.o: src/CMakeFiles/linear_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/linear_static.dir/helloLib.cpp.o"
	cd /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/linear_static.dir/helloLib.cpp.o -MF CMakeFiles/linear_static.dir/helloLib.cpp.o.d -o CMakeFiles/linear_static.dir/helloLib.cpp.o -c /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/src/helloLib.cpp

src/CMakeFiles/linear_static.dir/helloLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linear_static.dir/helloLib.cpp.i"
	cd /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/src/helloLib.cpp > CMakeFiles/linear_static.dir/helloLib.cpp.i

src/CMakeFiles/linear_static.dir/helloLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linear_static.dir/helloLib.cpp.s"
	cd /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/src/helloLib.cpp -o CMakeFiles/linear_static.dir/helloLib.cpp.s

# Object files for target linear_static
linear_static_OBJECTS = \
"CMakeFiles/linear_static.dir/helloLib.cpp.o"

# External object files for target linear_static
linear_static_EXTERNAL_OBJECTS =

lib/liblinear.a: src/CMakeFiles/linear_static.dir/helloLib.cpp.o
lib/liblinear.a: src/CMakeFiles/linear_static.dir/build.make
lib/liblinear.a: src/CMakeFiles/linear_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../lib/liblinear.a"
	cd /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/src && $(CMAKE_COMMAND) -P CMakeFiles/linear_static.dir/cmake_clean_target.cmake
	cd /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linear_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/linear_static.dir/build: lib/liblinear.a
.PHONY : src/CMakeFiles/linear_static.dir/build

src/CMakeFiles/linear_static.dir/clean:
	cd /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/src && $(CMAKE_COMMAND) -P CMakeFiles/linear_static.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/linear_static.dir/clean

src/CMakeFiles/linear_static.dir/depend:
	cd /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhenkong/cpptest/cmaketest/project/LibraryProperty /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/src /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/src /home/zhenkong/cpptest/cmaketest/project/LibraryProperty/build/src/CMakeFiles/linear_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/linear_static.dir/depend
