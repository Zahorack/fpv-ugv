# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\oholly.DQI\CLionProjects\server-backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug

# Include any dependencies generated for this target.
include application/CMakeFiles/server_backend_exe.dir/depend.make

# Include the progress variables for this target.
include application/CMakeFiles/server_backend_exe.dir/progress.make

# Include the compile flags for this target's objects.
include application/CMakeFiles/server_backend_exe.dir/flags.make

application/CMakeFiles/server_backend_exe.dir/main.cpp.obj: application/CMakeFiles/server_backend_exe.dir/flags.make
application/CMakeFiles/server_backend_exe.dir/main.cpp.obj: application/CMakeFiles/server_backend_exe.dir/includes_CXX.rsp
application/CMakeFiles/server_backend_exe.dir/main.cpp.obj: ../application/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object application/CMakeFiles/server_backend_exe.dir/main.cpp.obj"
	cd /d C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\application && C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\server_backend_exe.dir\main.cpp.obj -c C:\Users\oholly.DQI\CLionProjects\server-backend\application\main.cpp

application/CMakeFiles/server_backend_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_backend_exe.dir/main.cpp.i"
	cd /d C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\application && C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\oholly.DQI\CLionProjects\server-backend\application\main.cpp > CMakeFiles\server_backend_exe.dir\main.cpp.i

application/CMakeFiles/server_backend_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_backend_exe.dir/main.cpp.s"
	cd /d C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\application && C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\oholly.DQI\CLionProjects\server-backend\application\main.cpp -o CMakeFiles\server_backend_exe.dir\main.cpp.s

# Object files for target server_backend_exe
server_backend_exe_OBJECTS = \
"CMakeFiles/server_backend_exe.dir/main.cpp.obj"

# External object files for target server_backend_exe
server_backend_exe_EXTERNAL_OBJECTS =

application/server_backend_exe.exe: application/CMakeFiles/server_backend_exe.dir/main.cpp.obj
application/server_backend_exe.exe: application/CMakeFiles/server_backend_exe.dir/build.make
application/server_backend_exe.exe: application/CMakeFiles/server_backend_exe.dir/linklibs.rsp
application/server_backend_exe.exe: application/CMakeFiles/server_backend_exe.dir/objects1.rsp
application/server_backend_exe.exe: application/CMakeFiles/server_backend_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable server_backend_exe.exe"
	cd /d C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\application && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\server_backend_exe.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/CMakeFiles/server_backend_exe.dir/build: application/server_backend_exe.exe

.PHONY : application/CMakeFiles/server_backend_exe.dir/build

application/CMakeFiles/server_backend_exe.dir/clean:
	cd /d C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\application && $(CMAKE_COMMAND) -P CMakeFiles\server_backend_exe.dir\cmake_clean.cmake
.PHONY : application/CMakeFiles/server_backend_exe.dir/clean

application/CMakeFiles/server_backend_exe.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\oholly.DQI\CLionProjects\server-backend C:\Users\oholly.DQI\CLionProjects\server-backend\application C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\application C:\Users\oholly.DQI\CLionProjects\server-backend\cmake-build-debug\application\CMakeFiles\server_backend_exe.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : application/CMakeFiles/server_backend_exe.dir/depend
