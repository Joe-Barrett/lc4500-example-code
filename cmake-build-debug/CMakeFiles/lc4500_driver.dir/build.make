# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lc4500_driver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lc4500_driver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lc4500_driver.dir/flags.make

CMakeFiles/lc4500_driver.dir/app.cpp.o: CMakeFiles/lc4500_driver.dir/flags.make
CMakeFiles/lc4500_driver.dir/app.cpp.o: ../app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lc4500_driver.dir/app.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc4500_driver.dir/app.cpp.o -c /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/app.cpp

CMakeFiles/lc4500_driver.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc4500_driver.dir/app.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/app.cpp > CMakeFiles/lc4500_driver.dir/app.cpp.i

CMakeFiles/lc4500_driver.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc4500_driver.dir/app.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/app.cpp -o CMakeFiles/lc4500_driver.dir/app.cpp.s

CMakeFiles/lc4500_driver.dir/app.cpp.o.requires:

.PHONY : CMakeFiles/lc4500_driver.dir/app.cpp.o.requires

CMakeFiles/lc4500_driver.dir/app.cpp.o.provides: CMakeFiles/lc4500_driver.dir/app.cpp.o.requires
	$(MAKE) -f CMakeFiles/lc4500_driver.dir/build.make CMakeFiles/lc4500_driver.dir/app.cpp.o.provides.build
.PHONY : CMakeFiles/lc4500_driver.dir/app.cpp.o.provides

CMakeFiles/lc4500_driver.dir/app.cpp.o.provides.build: CMakeFiles/lc4500_driver.dir/app.cpp.o


CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o: CMakeFiles/lc4500_driver.dir/flags.make
CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o: ../tcp_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o -c /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/tcp_client.cpp

CMakeFiles/lc4500_driver.dir/tcp_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc4500_driver.dir/tcp_client.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/tcp_client.cpp > CMakeFiles/lc4500_driver.dir/tcp_client.cpp.i

CMakeFiles/lc4500_driver.dir/tcp_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc4500_driver.dir/tcp_client.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/tcp_client.cpp -o CMakeFiles/lc4500_driver.dir/tcp_client.cpp.s

CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o.requires:

.PHONY : CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o.requires

CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o.provides: CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o.requires
	$(MAKE) -f CMakeFiles/lc4500_driver.dir/build.make CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o.provides.build
.PHONY : CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o.provides

CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o.provides.build: CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o


CMakeFiles/lc4500_driver.dir/packager.cpp.o: CMakeFiles/lc4500_driver.dir/flags.make
CMakeFiles/lc4500_driver.dir/packager.cpp.o: ../packager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lc4500_driver.dir/packager.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc4500_driver.dir/packager.cpp.o -c /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/packager.cpp

CMakeFiles/lc4500_driver.dir/packager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc4500_driver.dir/packager.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/packager.cpp > CMakeFiles/lc4500_driver.dir/packager.cpp.i

CMakeFiles/lc4500_driver.dir/packager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc4500_driver.dir/packager.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/packager.cpp -o CMakeFiles/lc4500_driver.dir/packager.cpp.s

CMakeFiles/lc4500_driver.dir/packager.cpp.o.requires:

.PHONY : CMakeFiles/lc4500_driver.dir/packager.cpp.o.requires

CMakeFiles/lc4500_driver.dir/packager.cpp.o.provides: CMakeFiles/lc4500_driver.dir/packager.cpp.o.requires
	$(MAKE) -f CMakeFiles/lc4500_driver.dir/build.make CMakeFiles/lc4500_driver.dir/packager.cpp.o.provides.build
.PHONY : CMakeFiles/lc4500_driver.dir/packager.cpp.o.provides

CMakeFiles/lc4500_driver.dir/packager.cpp.o.provides.build: CMakeFiles/lc4500_driver.dir/packager.cpp.o


CMakeFiles/lc4500_driver.dir/commands.cpp.o: CMakeFiles/lc4500_driver.dir/flags.make
CMakeFiles/lc4500_driver.dir/commands.cpp.o: ../commands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lc4500_driver.dir/commands.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc4500_driver.dir/commands.cpp.o -c /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/commands.cpp

CMakeFiles/lc4500_driver.dir/commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc4500_driver.dir/commands.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/commands.cpp > CMakeFiles/lc4500_driver.dir/commands.cpp.i

CMakeFiles/lc4500_driver.dir/commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc4500_driver.dir/commands.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/commands.cpp -o CMakeFiles/lc4500_driver.dir/commands.cpp.s

CMakeFiles/lc4500_driver.dir/commands.cpp.o.requires:

.PHONY : CMakeFiles/lc4500_driver.dir/commands.cpp.o.requires

CMakeFiles/lc4500_driver.dir/commands.cpp.o.provides: CMakeFiles/lc4500_driver.dir/commands.cpp.o.requires
	$(MAKE) -f CMakeFiles/lc4500_driver.dir/build.make CMakeFiles/lc4500_driver.dir/commands.cpp.o.provides.build
.PHONY : CMakeFiles/lc4500_driver.dir/commands.cpp.o.provides

CMakeFiles/lc4500_driver.dir/commands.cpp.o.provides.build: CMakeFiles/lc4500_driver.dir/commands.cpp.o


CMakeFiles/lc4500_driver.dir/init.cpp.o: CMakeFiles/lc4500_driver.dir/flags.make
CMakeFiles/lc4500_driver.dir/init.cpp.o: ../init.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lc4500_driver.dir/init.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc4500_driver.dir/init.cpp.o -c /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/init.cpp

CMakeFiles/lc4500_driver.dir/init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc4500_driver.dir/init.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/init.cpp > CMakeFiles/lc4500_driver.dir/init.cpp.i

CMakeFiles/lc4500_driver.dir/init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc4500_driver.dir/init.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/init.cpp -o CMakeFiles/lc4500_driver.dir/init.cpp.s

CMakeFiles/lc4500_driver.dir/init.cpp.o.requires:

.PHONY : CMakeFiles/lc4500_driver.dir/init.cpp.o.requires

CMakeFiles/lc4500_driver.dir/init.cpp.o.provides: CMakeFiles/lc4500_driver.dir/init.cpp.o.requires
	$(MAKE) -f CMakeFiles/lc4500_driver.dir/build.make CMakeFiles/lc4500_driver.dir/init.cpp.o.provides.build
.PHONY : CMakeFiles/lc4500_driver.dir/init.cpp.o.provides

CMakeFiles/lc4500_driver.dir/init.cpp.o.provides.build: CMakeFiles/lc4500_driver.dir/init.cpp.o


# Object files for target lc4500_driver
lc4500_driver_OBJECTS = \
"CMakeFiles/lc4500_driver.dir/app.cpp.o" \
"CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o" \
"CMakeFiles/lc4500_driver.dir/packager.cpp.o" \
"CMakeFiles/lc4500_driver.dir/commands.cpp.o" \
"CMakeFiles/lc4500_driver.dir/init.cpp.o"

# External object files for target lc4500_driver
lc4500_driver_EXTERNAL_OBJECTS =

lc4500_driver.exe: CMakeFiles/lc4500_driver.dir/app.cpp.o
lc4500_driver.exe: CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o
lc4500_driver.exe: CMakeFiles/lc4500_driver.dir/packager.cpp.o
lc4500_driver.exe: CMakeFiles/lc4500_driver.dir/commands.cpp.o
lc4500_driver.exe: CMakeFiles/lc4500_driver.dir/init.cpp.o
lc4500_driver.exe: CMakeFiles/lc4500_driver.dir/build.make
lc4500_driver.exe: CMakeFiles/lc4500_driver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable lc4500_driver.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lc4500_driver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lc4500_driver.dir/build: lc4500_driver.exe

.PHONY : CMakeFiles/lc4500_driver.dir/build

CMakeFiles/lc4500_driver.dir/requires: CMakeFiles/lc4500_driver.dir/app.cpp.o.requires
CMakeFiles/lc4500_driver.dir/requires: CMakeFiles/lc4500_driver.dir/tcp_client.cpp.o.requires
CMakeFiles/lc4500_driver.dir/requires: CMakeFiles/lc4500_driver.dir/packager.cpp.o.requires
CMakeFiles/lc4500_driver.dir/requires: CMakeFiles/lc4500_driver.dir/commands.cpp.o.requires
CMakeFiles/lc4500_driver.dir/requires: CMakeFiles/lc4500_driver.dir/init.cpp.o.requires

.PHONY : CMakeFiles/lc4500_driver.dir/requires

CMakeFiles/lc4500_driver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lc4500_driver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lc4500_driver.dir/clean

CMakeFiles/lc4500_driver.dir/depend:
	cd /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug /cygdrive/d/projects/MOONS/MoonsLibrary/trunk/lc4500_experimental/cmake-build-debug/CMakeFiles/lc4500_driver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lc4500_driver.dir/depend

