# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CS3520_2017FA_PROJ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CS3520_2017FA_PROJ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CS3520_2017FA_PROJ.dir/flags.make

CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj: CMakeFiles/CS3520_2017FA_PROJ.dir/flags.make
CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj: ../BattleMode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CS3520_2017FA_PROJ.dir\BattleMode.cpp.obj -c C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\BattleMode.cpp

CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\BattleMode.cpp > CMakeFiles\CS3520_2017FA_PROJ.dir\BattleMode.cpp.i

CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\BattleMode.cpp -o CMakeFiles\CS3520_2017FA_PROJ.dir\BattleMode.cpp.s

CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj.requires:

.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj.requires

CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj.provides: CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CS3520_2017FA_PROJ.dir\build.make CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj.provides.build
.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj.provides

CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj.provides.build: CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj


CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj: CMakeFiles/CS3520_2017FA_PROJ.dir/flags.make
CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj: ../IUnit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CS3520_2017FA_PROJ.dir\IUnit.cpp.obj -c C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\IUnit.cpp

CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\IUnit.cpp > CMakeFiles\CS3520_2017FA_PROJ.dir\IUnit.cpp.i

CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\IUnit.cpp -o CMakeFiles\CS3520_2017FA_PROJ.dir\IUnit.cpp.s

CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj.requires:

.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj.requires

CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj.provides: CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CS3520_2017FA_PROJ.dir\build.make CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj.provides.build
.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj.provides

CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj.provides.build: CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj


CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj: CMakeFiles/CS3520_2017FA_PROJ.dir/flags.make
CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CS3520_2017FA_PROJ.dir\main.cpp.obj -c C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\main.cpp

CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\main.cpp > CMakeFiles\CS3520_2017FA_PROJ.dir\main.cpp.i

CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\main.cpp -o CMakeFiles\CS3520_2017FA_PROJ.dir\main.cpp.s

CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj.requires

CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj.provides: CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CS3520_2017FA_PROJ.dir\build.make CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj.provides

CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj.provides.build: CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj


CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj: CMakeFiles/CS3520_2017FA_PROJ.dir/flags.make
CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj: ../Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CS3520_2017FA_PROJ.dir\Map.cpp.obj -c C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\Map.cpp

CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\Map.cpp > CMakeFiles\CS3520_2017FA_PROJ.dir\Map.cpp.i

CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\Map.cpp -o CMakeFiles\CS3520_2017FA_PROJ.dir\Map.cpp.s

CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj.requires:

.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj.requires

CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj.provides: CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CS3520_2017FA_PROJ.dir\build.make CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj.provides.build
.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj.provides

CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj.provides.build: CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj


# Object files for target CS3520_2017FA_PROJ
CS3520_2017FA_PROJ_OBJECTS = \
"CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj" \
"CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj" \
"CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj" \
"CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj"

# External object files for target CS3520_2017FA_PROJ
CS3520_2017FA_PROJ_EXTERNAL_OBJECTS =

CS3520_2017FA_PROJ.exe: CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj
CS3520_2017FA_PROJ.exe: CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj
CS3520_2017FA_PROJ.exe: CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj
CS3520_2017FA_PROJ.exe: CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj
CS3520_2017FA_PROJ.exe: CMakeFiles/CS3520_2017FA_PROJ.dir/build.make
CS3520_2017FA_PROJ.exe: CMakeFiles/CS3520_2017FA_PROJ.dir/linklibs.rsp
CS3520_2017FA_PROJ.exe: CMakeFiles/CS3520_2017FA_PROJ.dir/objects1.rsp
CS3520_2017FA_PROJ.exe: CMakeFiles/CS3520_2017FA_PROJ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable CS3520_2017FA_PROJ.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CS3520_2017FA_PROJ.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CS3520_2017FA_PROJ.dir/build: CS3520_2017FA_PROJ.exe

.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/build

CMakeFiles/CS3520_2017FA_PROJ.dir/requires: CMakeFiles/CS3520_2017FA_PROJ.dir/BattleMode.cpp.obj.requires
CMakeFiles/CS3520_2017FA_PROJ.dir/requires: CMakeFiles/CS3520_2017FA_PROJ.dir/IUnit.cpp.obj.requires
CMakeFiles/CS3520_2017FA_PROJ.dir/requires: CMakeFiles/CS3520_2017FA_PROJ.dir/main.cpp.obj.requires
CMakeFiles/CS3520_2017FA_PROJ.dir/requires: CMakeFiles/CS3520_2017FA_PROJ.dir/Map.cpp.obj.requires

.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/requires

CMakeFiles/CS3520_2017FA_PROJ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CS3520_2017FA_PROJ.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/clean

CMakeFiles/CS3520_2017FA_PROJ.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug C:\Users\whyar\Documents\GitHub\CS3520-2017FA-PROJ\cmake-build-debug\CMakeFiles\CS3520_2017FA_PROJ.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CS3520_2017FA_PROJ.dir/depend

