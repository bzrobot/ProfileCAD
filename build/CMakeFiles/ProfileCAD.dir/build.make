# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/Projects/ProfileCAD/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Projects/ProfileCAD/build

# Include any dependencies generated for this target.
include CMakeFiles/ProfileCAD.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProfileCAD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProfileCAD.dir/flags.make

CMakeFiles/ProfileCAD.dir/main.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/main.cpp.o: /root/Projects/ProfileCAD/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProfileCAD.dir/main.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/main.cpp.o -c /root/Projects/ProfileCAD/src/main.cpp

CMakeFiles/ProfileCAD.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/main.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/main.cpp > CMakeFiles/ProfileCAD.dir/main.cpp.i

CMakeFiles/ProfileCAD.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/main.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/main.cpp -o CMakeFiles/ProfileCAD.dir/main.cpp.s

CMakeFiles/ProfileCAD.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/main.cpp.o.requires

CMakeFiles/ProfileCAD.dir/main.cpp.o.provides: CMakeFiles/ProfileCAD.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/main.cpp.o.provides

CMakeFiles/ProfileCAD.dir/main.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/main.cpp.o


CMakeFiles/ProfileCAD.dir/Scene.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Scene.cpp.o: /root/Projects/ProfileCAD/src/Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProfileCAD.dir/Scene.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Scene.cpp.o -c /root/Projects/ProfileCAD/src/Scene.cpp

CMakeFiles/ProfileCAD.dir/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Scene.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Scene.cpp > CMakeFiles/ProfileCAD.dir/Scene.cpp.i

CMakeFiles/ProfileCAD.dir/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Scene.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Scene.cpp -o CMakeFiles/ProfileCAD.dir/Scene.cpp.s

CMakeFiles/ProfileCAD.dir/Scene.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Scene.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Scene.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Scene.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Scene.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Scene.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Scene.cpp.o


CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o: /root/Projects/ProfileCAD/src/Keyboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o -c /root/Projects/ProfileCAD/src/Keyboard.cpp

CMakeFiles/ProfileCAD.dir/Keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Keyboard.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Keyboard.cpp > CMakeFiles/ProfileCAD.dir/Keyboard.cpp.i

CMakeFiles/ProfileCAD.dir/Keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Keyboard.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Keyboard.cpp -o CMakeFiles/ProfileCAD.dir/Keyboard.cpp.s

CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o


CMakeFiles/ProfileCAD.dir/Machine.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Machine.cpp.o: /root/Projects/ProfileCAD/src/Machine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProfileCAD.dir/Machine.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Machine.cpp.o -c /root/Projects/ProfileCAD/src/Machine.cpp

CMakeFiles/ProfileCAD.dir/Machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Machine.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Machine.cpp > CMakeFiles/ProfileCAD.dir/Machine.cpp.i

CMakeFiles/ProfileCAD.dir/Machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Machine.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Machine.cpp -o CMakeFiles/ProfileCAD.dir/Machine.cpp.s

CMakeFiles/ProfileCAD.dir/Machine.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Machine.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Machine.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Machine.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Machine.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Machine.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Machine.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Machine.cpp.o


CMakeFiles/ProfileCAD.dir/Menu.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Menu.cpp.o: /root/Projects/ProfileCAD/src/Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProfileCAD.dir/Menu.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Menu.cpp.o -c /root/Projects/ProfileCAD/src/Menu.cpp

CMakeFiles/ProfileCAD.dir/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Menu.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Menu.cpp > CMakeFiles/ProfileCAD.dir/Menu.cpp.i

CMakeFiles/ProfileCAD.dir/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Menu.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Menu.cpp -o CMakeFiles/ProfileCAD.dir/Menu.cpp.s

CMakeFiles/ProfileCAD.dir/Menu.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Menu.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Menu.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Menu.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Menu.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Menu.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Menu.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Menu.cpp.o


CMakeFiles/ProfileCAD.dir/Window.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Window.cpp.o: /root/Projects/ProfileCAD/src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ProfileCAD.dir/Window.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Window.cpp.o -c /root/Projects/ProfileCAD/src/Window.cpp

CMakeFiles/ProfileCAD.dir/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Window.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Window.cpp > CMakeFiles/ProfileCAD.dir/Window.cpp.i

CMakeFiles/ProfileCAD.dir/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Window.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Window.cpp -o CMakeFiles/ProfileCAD.dir/Window.cpp.s

CMakeFiles/ProfileCAD.dir/Window.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Window.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Window.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Window.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Window.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Window.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Window.cpp.o


CMakeFiles/ProfileCAD.dir/Mouse.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Mouse.cpp.o: /root/Projects/ProfileCAD/src/Mouse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ProfileCAD.dir/Mouse.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Mouse.cpp.o -c /root/Projects/ProfileCAD/src/Mouse.cpp

CMakeFiles/ProfileCAD.dir/Mouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Mouse.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Mouse.cpp > CMakeFiles/ProfileCAD.dir/Mouse.cpp.i

CMakeFiles/ProfileCAD.dir/Mouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Mouse.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Mouse.cpp -o CMakeFiles/ProfileCAD.dir/Mouse.cpp.s

CMakeFiles/ProfileCAD.dir/Mouse.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Mouse.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Mouse.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Mouse.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Mouse.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Mouse.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Mouse.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Mouse.cpp.o


CMakeFiles/ProfileCAD.dir/CAD.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/CAD.cpp.o: /root/Projects/ProfileCAD/src/CAD.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ProfileCAD.dir/CAD.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/CAD.cpp.o -c /root/Projects/ProfileCAD/src/CAD.cpp

CMakeFiles/ProfileCAD.dir/CAD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/CAD.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/CAD.cpp > CMakeFiles/ProfileCAD.dir/CAD.cpp.i

CMakeFiles/ProfileCAD.dir/CAD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/CAD.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/CAD.cpp -o CMakeFiles/ProfileCAD.dir/CAD.cpp.s

CMakeFiles/ProfileCAD.dir/CAD.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/CAD.cpp.o.requires

CMakeFiles/ProfileCAD.dir/CAD.cpp.o.provides: CMakeFiles/ProfileCAD.dir/CAD.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/CAD.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/CAD.cpp.o.provides

CMakeFiles/ProfileCAD.dir/CAD.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/CAD.cpp.o


CMakeFiles/ProfileCAD.dir/UI.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/UI.cpp.o: /root/Projects/ProfileCAD/src/UI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ProfileCAD.dir/UI.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/UI.cpp.o -c /root/Projects/ProfileCAD/src/UI.cpp

CMakeFiles/ProfileCAD.dir/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/UI.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/UI.cpp > CMakeFiles/ProfileCAD.dir/UI.cpp.i

CMakeFiles/ProfileCAD.dir/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/UI.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/UI.cpp -o CMakeFiles/ProfileCAD.dir/UI.cpp.s

CMakeFiles/ProfileCAD.dir/UI.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/UI.cpp.o.requires

CMakeFiles/ProfileCAD.dir/UI.cpp.o.provides: CMakeFiles/ProfileCAD.dir/UI.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/UI.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/UI.cpp.o.provides

CMakeFiles/ProfileCAD.dir/UI.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/UI.cpp.o


CMakeFiles/ProfileCAD.dir/Geometry.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Geometry.cpp.o: /root/Projects/ProfileCAD/src/Geometry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ProfileCAD.dir/Geometry.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Geometry.cpp.o -c /root/Projects/ProfileCAD/src/Geometry.cpp

CMakeFiles/ProfileCAD.dir/Geometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Geometry.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Geometry.cpp > CMakeFiles/ProfileCAD.dir/Geometry.cpp.i

CMakeFiles/ProfileCAD.dir/Geometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Geometry.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Geometry.cpp -o CMakeFiles/ProfileCAD.dir/Geometry.cpp.s

CMakeFiles/ProfileCAD.dir/Geometry.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Geometry.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Geometry.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Geometry.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Geometry.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Geometry.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Geometry.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Geometry.cpp.o


CMakeFiles/ProfileCAD.dir/CLI.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/CLI.cpp.o: /root/Projects/ProfileCAD/src/CLI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ProfileCAD.dir/CLI.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/CLI.cpp.o -c /root/Projects/ProfileCAD/src/CLI.cpp

CMakeFiles/ProfileCAD.dir/CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/CLI.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/CLI.cpp > CMakeFiles/ProfileCAD.dir/CLI.cpp.i

CMakeFiles/ProfileCAD.dir/CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/CLI.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/CLI.cpp -o CMakeFiles/ProfileCAD.dir/CLI.cpp.s

CMakeFiles/ProfileCAD.dir/CLI.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/CLI.cpp.o.requires

CMakeFiles/ProfileCAD.dir/CLI.cpp.o.provides: CMakeFiles/ProfileCAD.dir/CLI.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/CLI.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/CLI.cpp.o.provides

CMakeFiles/ProfileCAD.dir/CLI.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/CLI.cpp.o


CMakeFiles/ProfileCAD.dir/FileIO.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/FileIO.cpp.o: /root/Projects/ProfileCAD/src/FileIO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ProfileCAD.dir/FileIO.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/FileIO.cpp.o -c /root/Projects/ProfileCAD/src/FileIO.cpp

CMakeFiles/ProfileCAD.dir/FileIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/FileIO.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/FileIO.cpp > CMakeFiles/ProfileCAD.dir/FileIO.cpp.i

CMakeFiles/ProfileCAD.dir/FileIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/FileIO.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/FileIO.cpp -o CMakeFiles/ProfileCAD.dir/FileIO.cpp.s

CMakeFiles/ProfileCAD.dir/FileIO.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/FileIO.cpp.o.requires

CMakeFiles/ProfileCAD.dir/FileIO.cpp.o.provides: CMakeFiles/ProfileCAD.dir/FileIO.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/FileIO.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/FileIO.cpp.o.provides

CMakeFiles/ProfileCAD.dir/FileIO.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/FileIO.cpp.o


CMakeFiles/ProfileCAD.dir/Debug.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Debug.cpp.o: /root/Projects/ProfileCAD/src/Debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/ProfileCAD.dir/Debug.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Debug.cpp.o -c /root/Projects/ProfileCAD/src/Debug.cpp

CMakeFiles/ProfileCAD.dir/Debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Debug.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Debug.cpp > CMakeFiles/ProfileCAD.dir/Debug.cpp.i

CMakeFiles/ProfileCAD.dir/Debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Debug.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Debug.cpp -o CMakeFiles/ProfileCAD.dir/Debug.cpp.s

CMakeFiles/ProfileCAD.dir/Debug.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Debug.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Debug.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Debug.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Debug.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Debug.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Debug.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Debug.cpp.o


CMakeFiles/ProfileCAD.dir/Lua.cpp.o: CMakeFiles/ProfileCAD.dir/flags.make
CMakeFiles/ProfileCAD.dir/Lua.cpp.o: /root/Projects/ProfileCAD/src/Lua.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/ProfileCAD.dir/Lua.cpp.o"
	/usr/sbin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProfileCAD.dir/Lua.cpp.o -c /root/Projects/ProfileCAD/src/Lua.cpp

CMakeFiles/ProfileCAD.dir/Lua.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProfileCAD.dir/Lua.cpp.i"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Projects/ProfileCAD/src/Lua.cpp > CMakeFiles/ProfileCAD.dir/Lua.cpp.i

CMakeFiles/ProfileCAD.dir/Lua.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProfileCAD.dir/Lua.cpp.s"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Projects/ProfileCAD/src/Lua.cpp -o CMakeFiles/ProfileCAD.dir/Lua.cpp.s

CMakeFiles/ProfileCAD.dir/Lua.cpp.o.requires:

.PHONY : CMakeFiles/ProfileCAD.dir/Lua.cpp.o.requires

CMakeFiles/ProfileCAD.dir/Lua.cpp.o.provides: CMakeFiles/ProfileCAD.dir/Lua.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProfileCAD.dir/build.make CMakeFiles/ProfileCAD.dir/Lua.cpp.o.provides.build
.PHONY : CMakeFiles/ProfileCAD.dir/Lua.cpp.o.provides

CMakeFiles/ProfileCAD.dir/Lua.cpp.o.provides.build: CMakeFiles/ProfileCAD.dir/Lua.cpp.o


# Object files for target ProfileCAD
ProfileCAD_OBJECTS = \
"CMakeFiles/ProfileCAD.dir/main.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Scene.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Machine.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Menu.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Window.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Mouse.cpp.o" \
"CMakeFiles/ProfileCAD.dir/CAD.cpp.o" \
"CMakeFiles/ProfileCAD.dir/UI.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Geometry.cpp.o" \
"CMakeFiles/ProfileCAD.dir/CLI.cpp.o" \
"CMakeFiles/ProfileCAD.dir/FileIO.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Debug.cpp.o" \
"CMakeFiles/ProfileCAD.dir/Lua.cpp.o"

# External object files for target ProfileCAD
ProfileCAD_EXTERNAL_OBJECTS =

ProfileCAD: CMakeFiles/ProfileCAD.dir/main.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Scene.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Machine.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Menu.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Window.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Mouse.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/CAD.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/UI.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Geometry.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/CLI.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/FileIO.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Debug.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/Lua.cpp.o
ProfileCAD: CMakeFiles/ProfileCAD.dir/build.make
ProfileCAD: /usr/lib64/libGLU.so
ProfileCAD: /usr/lib64/libGL.so
ProfileCAD: /usr/lib64/libglut.so
ProfileCAD: /usr/lib64/libXmu.so
ProfileCAD: /usr/lib64/libXi.so
ProfileCAD: /usr/lib64/liblua.so
ProfileCAD: CMakeFiles/ProfileCAD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Projects/ProfileCAD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable ProfileCAD"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProfileCAD.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProfileCAD.dir/build: ProfileCAD

.PHONY : CMakeFiles/ProfileCAD.dir/build

CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/main.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Scene.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Keyboard.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Machine.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Menu.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Window.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Mouse.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/CAD.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/UI.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Geometry.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/CLI.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/FileIO.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Debug.cpp.o.requires
CMakeFiles/ProfileCAD.dir/requires: CMakeFiles/ProfileCAD.dir/Lua.cpp.o.requires

.PHONY : CMakeFiles/ProfileCAD.dir/requires

CMakeFiles/ProfileCAD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProfileCAD.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProfileCAD.dir/clean

CMakeFiles/ProfileCAD.dir/depend:
	cd /root/Projects/ProfileCAD/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Projects/ProfileCAD/src /root/Projects/ProfileCAD/src /root/Projects/ProfileCAD/build /root/Projects/ProfileCAD/build /root/Projects/ProfileCAD/build/CMakeFiles/ProfileCAD.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProfileCAD.dir/depend

