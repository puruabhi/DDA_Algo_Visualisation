# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/abhisheikh/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/abhisheikh/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenGL_Practice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL_Practice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL_Practice.dir/flags.make

CMakeFiles/OpenGL_Practice.dir/main.cpp.o: CMakeFiles/OpenGL_Practice.dir/flags.make
CMakeFiles/OpenGL_Practice.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL_Practice.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL_Practice.dir/main.cpp.o -c /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/main.cpp

CMakeFiles/OpenGL_Practice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_Practice.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/main.cpp > CMakeFiles/OpenGL_Practice.dir/main.cpp.i

CMakeFiles/OpenGL_Practice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Practice.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/main.cpp -o CMakeFiles/OpenGL_Practice.dir/main.cpp.s

CMakeFiles/OpenGL_Practice.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OpenGL_Practice.dir/main.cpp.o.requires

CMakeFiles/OpenGL_Practice.dir/main.cpp.o.provides: CMakeFiles/OpenGL_Practice.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGL_Practice.dir/build.make CMakeFiles/OpenGL_Practice.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGL_Practice.dir/main.cpp.o.provides

CMakeFiles/OpenGL_Practice.dir/main.cpp.o.provides.build: CMakeFiles/OpenGL_Practice.dir/main.cpp.o


CMakeFiles/OpenGL_Practice.dir/glad.c.o: CMakeFiles/OpenGL_Practice.dir/flags.make
CMakeFiles/OpenGL_Practice.dir/glad.c.o: ../glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OpenGL_Practice.dir/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OpenGL_Practice.dir/glad.c.o   -c /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/glad.c

CMakeFiles/OpenGL_Practice.dir/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGL_Practice.dir/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/glad.c > CMakeFiles/OpenGL_Practice.dir/glad.c.i

CMakeFiles/OpenGL_Practice.dir/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGL_Practice.dir/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/glad.c -o CMakeFiles/OpenGL_Practice.dir/glad.c.s

CMakeFiles/OpenGL_Practice.dir/glad.c.o.requires:

.PHONY : CMakeFiles/OpenGL_Practice.dir/glad.c.o.requires

CMakeFiles/OpenGL_Practice.dir/glad.c.o.provides: CMakeFiles/OpenGL_Practice.dir/glad.c.o.requires
	$(MAKE) -f CMakeFiles/OpenGL_Practice.dir/build.make CMakeFiles/OpenGL_Practice.dir/glad.c.o.provides.build
.PHONY : CMakeFiles/OpenGL_Practice.dir/glad.c.o.provides

CMakeFiles/OpenGL_Practice.dir/glad.c.o.provides.build: CMakeFiles/OpenGL_Practice.dir/glad.c.o


CMakeFiles/OpenGL_Practice.dir/shader.cpp.o: CMakeFiles/OpenGL_Practice.dir/flags.make
CMakeFiles/OpenGL_Practice.dir/shader.cpp.o: ../shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGL_Practice.dir/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL_Practice.dir/shader.cpp.o -c /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/shader.cpp

CMakeFiles/OpenGL_Practice.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_Practice.dir/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/shader.cpp > CMakeFiles/OpenGL_Practice.dir/shader.cpp.i

CMakeFiles/OpenGL_Practice.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Practice.dir/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/shader.cpp -o CMakeFiles/OpenGL_Practice.dir/shader.cpp.s

CMakeFiles/OpenGL_Practice.dir/shader.cpp.o.requires:

.PHONY : CMakeFiles/OpenGL_Practice.dir/shader.cpp.o.requires

CMakeFiles/OpenGL_Practice.dir/shader.cpp.o.provides: CMakeFiles/OpenGL_Practice.dir/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGL_Practice.dir/build.make CMakeFiles/OpenGL_Practice.dir/shader.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGL_Practice.dir/shader.cpp.o.provides

CMakeFiles/OpenGL_Practice.dir/shader.cpp.o.provides.build: CMakeFiles/OpenGL_Practice.dir/shader.cpp.o


CMakeFiles/OpenGL_Practice.dir/square.cpp.o: CMakeFiles/OpenGL_Practice.dir/flags.make
CMakeFiles/OpenGL_Practice.dir/square.cpp.o: ../square.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenGL_Practice.dir/square.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL_Practice.dir/square.cpp.o -c /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/square.cpp

CMakeFiles/OpenGL_Practice.dir/square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_Practice.dir/square.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/square.cpp > CMakeFiles/OpenGL_Practice.dir/square.cpp.i

CMakeFiles/OpenGL_Practice.dir/square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Practice.dir/square.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/square.cpp -o CMakeFiles/OpenGL_Practice.dir/square.cpp.s

CMakeFiles/OpenGL_Practice.dir/square.cpp.o.requires:

.PHONY : CMakeFiles/OpenGL_Practice.dir/square.cpp.o.requires

CMakeFiles/OpenGL_Practice.dir/square.cpp.o.provides: CMakeFiles/OpenGL_Practice.dir/square.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGL_Practice.dir/build.make CMakeFiles/OpenGL_Practice.dir/square.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGL_Practice.dir/square.cpp.o.provides

CMakeFiles/OpenGL_Practice.dir/square.cpp.o.provides.build: CMakeFiles/OpenGL_Practice.dir/square.cpp.o


CMakeFiles/OpenGL_Practice.dir/grid.cpp.o: CMakeFiles/OpenGL_Practice.dir/flags.make
CMakeFiles/OpenGL_Practice.dir/grid.cpp.o: ../grid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OpenGL_Practice.dir/grid.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL_Practice.dir/grid.cpp.o -c /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/grid.cpp

CMakeFiles/OpenGL_Practice.dir/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_Practice.dir/grid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/grid.cpp > CMakeFiles/OpenGL_Practice.dir/grid.cpp.i

CMakeFiles/OpenGL_Practice.dir/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Practice.dir/grid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/grid.cpp -o CMakeFiles/OpenGL_Practice.dir/grid.cpp.s

CMakeFiles/OpenGL_Practice.dir/grid.cpp.o.requires:

.PHONY : CMakeFiles/OpenGL_Practice.dir/grid.cpp.o.requires

CMakeFiles/OpenGL_Practice.dir/grid.cpp.o.provides: CMakeFiles/OpenGL_Practice.dir/grid.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGL_Practice.dir/build.make CMakeFiles/OpenGL_Practice.dir/grid.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGL_Practice.dir/grid.cpp.o.provides

CMakeFiles/OpenGL_Practice.dir/grid.cpp.o.provides.build: CMakeFiles/OpenGL_Practice.dir/grid.cpp.o


CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o: CMakeFiles/OpenGL_Practice.dir/flags.make
CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o: ../text_renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o -c /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/text_renderer.cpp

CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/text_renderer.cpp > CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.i

CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/text_renderer.cpp -o CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.s

CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o.requires:

.PHONY : CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o.requires

CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o.provides: CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGL_Practice.dir/build.make CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o.provides

CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o.provides.build: CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o


# Object files for target OpenGL_Practice
OpenGL_Practice_OBJECTS = \
"CMakeFiles/OpenGL_Practice.dir/main.cpp.o" \
"CMakeFiles/OpenGL_Practice.dir/glad.c.o" \
"CMakeFiles/OpenGL_Practice.dir/shader.cpp.o" \
"CMakeFiles/OpenGL_Practice.dir/square.cpp.o" \
"CMakeFiles/OpenGL_Practice.dir/grid.cpp.o" \
"CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o"

# External object files for target OpenGL_Practice
OpenGL_Practice_EXTERNAL_OBJECTS =

OpenGL_Practice: CMakeFiles/OpenGL_Practice.dir/main.cpp.o
OpenGL_Practice: CMakeFiles/OpenGL_Practice.dir/glad.c.o
OpenGL_Practice: CMakeFiles/OpenGL_Practice.dir/shader.cpp.o
OpenGL_Practice: CMakeFiles/OpenGL_Practice.dir/square.cpp.o
OpenGL_Practice: CMakeFiles/OpenGL_Practice.dir/grid.cpp.o
OpenGL_Practice: CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o
OpenGL_Practice: CMakeFiles/OpenGL_Practice.dir/build.make
OpenGL_Practice: CMakeFiles/OpenGL_Practice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable OpenGL_Practice"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGL_Practice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL_Practice.dir/build: OpenGL_Practice

.PHONY : CMakeFiles/OpenGL_Practice.dir/build

CMakeFiles/OpenGL_Practice.dir/requires: CMakeFiles/OpenGL_Practice.dir/main.cpp.o.requires
CMakeFiles/OpenGL_Practice.dir/requires: CMakeFiles/OpenGL_Practice.dir/glad.c.o.requires
CMakeFiles/OpenGL_Practice.dir/requires: CMakeFiles/OpenGL_Practice.dir/shader.cpp.o.requires
CMakeFiles/OpenGL_Practice.dir/requires: CMakeFiles/OpenGL_Practice.dir/square.cpp.o.requires
CMakeFiles/OpenGL_Practice.dir/requires: CMakeFiles/OpenGL_Practice.dir/grid.cpp.o.requires
CMakeFiles/OpenGL_Practice.dir/requires: CMakeFiles/OpenGL_Practice.dir/text_renderer.cpp.o.requires

.PHONY : CMakeFiles/OpenGL_Practice.dir/requires

CMakeFiles/OpenGL_Practice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGL_Practice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL_Practice.dir/clean

CMakeFiles/OpenGL_Practice.dir/depend:
	cd /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug /home/abhisheikh/Documents/CLion_Projects/OpenGL_Practice/cmake-build-debug/CMakeFiles/OpenGL_Practice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGL_Practice.dir/depend

