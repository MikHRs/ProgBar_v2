# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michele/CLionProjects/ProgBar_v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michele/CLionProjects/ProgBar_v2/build

# Include any dependencies generated for this target.
include tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/flags.make

tests/lib/googletest/googlemock/gmock_main_autogen/timestamp: /usr/lib/qt5/bin/moc
tests/lib/googletest/googlemock/gmock_main_autogen/timestamp: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/michele/CLionProjects/ProgBar_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target gmock_main"
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && /usr/bin/cmake -E cmake_autogen /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock/CMakeFiles/gmock_main_autogen.dir/AutogenInfo.json ""
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && /usr/bin/cmake -E touch /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock/gmock_main_autogen/timestamp

tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/flags.make
tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o: tests/lib/googletest/googlemock/gmock_main_autogen/mocs_compilation.cpp
tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/michele/CLionProjects/ProgBar_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o"
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o -MF CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o -c /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock/gmock_main_autogen/mocs_compilation.cpp

tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.i"
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock/gmock_main_autogen/mocs_compilation.cpp > CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.i

tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.s"
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock/gmock_main_autogen/mocs_compilation.cpp -o CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.s

tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/flags.make
tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: /home/michele/CLionProjects/ProgBar_v2/tests/lib/googletest/googlemock/src/gmock_main.cc
tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/michele/CLionProjects/ProgBar_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -MF CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.d -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/michele/CLionProjects/ProgBar_v2/tests/lib/googletest/googlemock/src/gmock_main.cc

tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michele/CLionProjects/ProgBar_v2/tests/lib/googletest/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michele/CLionProjects/ProgBar_v2/tests/lib/googletest/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_main.a: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/gmock_main_autogen/mocs_compilation.cpp.o
lib/libgmock_main.a: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_main.a: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_main.a: tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/michele/CLionProjects/ProgBar_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../../../lib/libgmock_main.a"
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_main.a
.PHONY : tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/build

tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/clean

tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/depend: tests/lib/googletest/googlemock/gmock_main_autogen/timestamp
	cd /home/michele/CLionProjects/ProgBar_v2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michele/CLionProjects/ProgBar_v2 /home/michele/CLionProjects/ProgBar_v2/tests/lib/googletest/googlemock /home/michele/CLionProjects/ProgBar_v2/build /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock /home/michele/CLionProjects/ProgBar_v2/build/tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/lib/googletest/googlemock/CMakeFiles/gmock_main.dir/depend

