# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\piero\Downloads\b-tree-Piero16301

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\piero\Downloads\b-tree-Piero16301\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Arbol_B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Arbol_B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Arbol_B.dir/flags.make

CMakeFiles/Arbol_B.dir/main.cpp.obj: CMakeFiles/Arbol_B.dir/flags.make
CMakeFiles/Arbol_B.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\piero\Downloads\b-tree-Piero16301\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Arbol_B.dir/main.cpp.obj"
	C:\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Arbol_B.dir\main.cpp.obj -c C:\Users\piero\Downloads\b-tree-Piero16301\main.cpp

CMakeFiles/Arbol_B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Arbol_B.dir/main.cpp.i"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\piero\Downloads\b-tree-Piero16301\main.cpp > CMakeFiles\Arbol_B.dir\main.cpp.i

CMakeFiles/Arbol_B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Arbol_B.dir/main.cpp.s"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\piero\Downloads\b-tree-Piero16301\main.cpp -o CMakeFiles\Arbol_B.dir\main.cpp.s

# Object files for target Arbol_B
Arbol_B_OBJECTS = \
"CMakeFiles/Arbol_B.dir/main.cpp.obj"

# External object files for target Arbol_B
Arbol_B_EXTERNAL_OBJECTS =

Arbol_B.exe: CMakeFiles/Arbol_B.dir/main.cpp.obj
Arbol_B.exe: CMakeFiles/Arbol_B.dir/build.make
Arbol_B.exe: CMakeFiles/Arbol_B.dir/linklibs.rsp
Arbol_B.exe: CMakeFiles/Arbol_B.dir/objects1.rsp
Arbol_B.exe: CMakeFiles/Arbol_B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\piero\Downloads\b-tree-Piero16301\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Arbol_B.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Arbol_B.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Arbol_B.dir/build: Arbol_B.exe

.PHONY : CMakeFiles/Arbol_B.dir/build

CMakeFiles/Arbol_B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Arbol_B.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Arbol_B.dir/clean

CMakeFiles/Arbol_B.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\piero\Downloads\b-tree-Piero16301 C:\Users\piero\Downloads\b-tree-Piero16301 C:\Users\piero\Downloads\b-tree-Piero16301\cmake-build-debug C:\Users\piero\Downloads\b-tree-Piero16301\cmake-build-debug C:\Users\piero\Downloads\b-tree-Piero16301\cmake-build-debug\CMakeFiles\Arbol_B.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Arbol_B.dir/depend

