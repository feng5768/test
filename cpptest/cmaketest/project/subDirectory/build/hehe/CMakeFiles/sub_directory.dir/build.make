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
CMAKE_SOURCE_DIR = /home/zhenkong/cpptest/cmaketest/project/subDirectory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhenkong/cpptest/cmaketest/project/subDirectory/build

# Include any dependencies generated for this target.
include hehe/CMakeFiles/sub_directory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include hehe/CMakeFiles/sub_directory.dir/compiler_depend.make

# Include the progress variables for this target.
include hehe/CMakeFiles/sub_directory.dir/progress.make

# Include the compile flags for this target's objects.
include hehe/CMakeFiles/sub_directory.dir/flags.make

hehe/CMakeFiles/sub_directory.dir/main.cpp.o: hehe/CMakeFiles/sub_directory.dir/flags.make
hehe/CMakeFiles/sub_directory.dir/main.cpp.o: ../src/main.cpp
hehe/CMakeFiles/sub_directory.dir/main.cpp.o: hehe/CMakeFiles/sub_directory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhenkong/cpptest/cmaketest/project/subDirectory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hehe/CMakeFiles/sub_directory.dir/main.cpp.o"
	cd /home/zhenkong/cpptest/cmaketest/project/subDirectory/build/hehe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT hehe/CMakeFiles/sub_directory.dir/main.cpp.o -MF CMakeFiles/sub_directory.dir/main.cpp.o.d -o CMakeFiles/sub_directory.dir/main.cpp.o -c /home/zhenkong/cpptest/cmaketest/project/subDirectory/src/main.cpp

hehe/CMakeFiles/sub_directory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sub_directory.dir/main.cpp.i"
	cd /home/zhenkong/cpptest/cmaketest/project/subDirectory/build/hehe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhenkong/cpptest/cmaketest/project/subDirectory/src/main.cpp > CMakeFiles/sub_directory.dir/main.cpp.i

hehe/CMakeFiles/sub_directory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sub_directory.dir/main.cpp.s"
	cd /home/zhenkong/cpptest/cmaketest/project/subDirectory/build/hehe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhenkong/cpptest/cmaketest/project/subDirectory/src/main.cpp -o CMakeFiles/sub_directory.dir/main.cpp.s

# Object files for target sub_directory
sub_directory_OBJECTS = \
"CMakeFiles/sub_directory.dir/main.cpp.o"

# External object files for target sub_directory
sub_directory_EXTERNAL_OBJECTS =

hehe/sub_directory: hehe/CMakeFiles/sub_directory.dir/main.cpp.o
hehe/sub_directory: hehe/CMakeFiles/sub_directory.dir/build.make
hehe/sub_directory: hehe/CMakeFiles/sub_directory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhenkong/cpptest/cmaketest/project/subDirectory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sub_directory"
	cd /home/zhenkong/cpptest/cmaketest/project/subDirectory/build/hehe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sub_directory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hehe/CMakeFiles/sub_directory.dir/build: hehe/sub_directory
.PHONY : hehe/CMakeFiles/sub_directory.dir/build

hehe/CMakeFiles/sub_directory.dir/clean:
	cd /home/zhenkong/cpptest/cmaketest/project/subDirectory/build/hehe && $(CMAKE_COMMAND) -P CMakeFiles/sub_directory.dir/cmake_clean.cmake
.PHONY : hehe/CMakeFiles/sub_directory.dir/clean

hehe/CMakeFiles/sub_directory.dir/depend:
	cd /home/zhenkong/cpptest/cmaketest/project/subDirectory/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhenkong/cpptest/cmaketest/project/subDirectory /home/zhenkong/cpptest/cmaketest/project/subDirectory/src /home/zhenkong/cpptest/cmaketest/project/subDirectory/build /home/zhenkong/cpptest/cmaketest/project/subDirectory/build/hehe /home/zhenkong/cpptest/cmaketest/project/subDirectory/build/hehe/CMakeFiles/sub_directory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hehe/CMakeFiles/sub_directory.dir/depend
