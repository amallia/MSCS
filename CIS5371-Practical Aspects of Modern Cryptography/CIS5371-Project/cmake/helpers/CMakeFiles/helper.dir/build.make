# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake"

# Include any dependencies generated for this target.
include helpers/CMakeFiles/helper.dir/depend.make

# Include the progress variables for this target.
include helpers/CMakeFiles/helper.dir/progress.make

# Include the compile flags for this target's objects.
include helpers/CMakeFiles/helper.dir/flags.make

helpers/CMakeFiles/helper.dir/applicationhelper.cpp.o: helpers/CMakeFiles/helper.dir/flags.make
helpers/CMakeFiles/helper.dir/applicationhelper.cpp.o: ../helpers/applicationhelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object helpers/CMakeFiles/helper.dir/applicationhelper.cpp.o"
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helper.dir/applicationhelper.cpp.o -c "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/helpers/applicationhelper.cpp"

helpers/CMakeFiles/helper.dir/applicationhelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper.dir/applicationhelper.cpp.i"
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/helpers/applicationhelper.cpp" > CMakeFiles/helper.dir/applicationhelper.cpp.i

helpers/CMakeFiles/helper.dir/applicationhelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper.dir/applicationhelper.cpp.s"
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/helpers/applicationhelper.cpp" -o CMakeFiles/helper.dir/applicationhelper.cpp.s

helpers/CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.o: helpers/CMakeFiles/helper.dir/flags.make
helpers/CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.o: helpers/helper_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object helpers/CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.o"
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.o -c "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers/helper_autogen/mocs_compilation.cpp"

helpers/CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.i"
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers/helper_autogen/mocs_compilation.cpp" > CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.i

helpers/CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.s"
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers/helper_autogen/mocs_compilation.cpp" -o CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.s

# Object files for target helper
helper_OBJECTS = \
"CMakeFiles/helper.dir/applicationhelper.cpp.o" \
"CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.o"

# External object files for target helper
helper_EXTERNAL_OBJECTS =

../lib/libhelper.so.1.0: helpers/CMakeFiles/helper.dir/applicationhelper.cpp.o
../lib/libhelper.so.1.0: helpers/CMakeFiles/helper.dir/helper_autogen/mocs_compilation.cpp.o
../lib/libhelper.so.1.0: helpers/CMakeFiles/helper.dir/build.make
../lib/libhelper.so.1.0: /usr/lib64/libQt5Core.so.5.9.6
../lib/libhelper.so.1.0: /usr/lib/libtreefrog.so
../lib/libhelper.so.1.0: helpers/CMakeFiles/helper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../lib/libhelper.so"
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helper.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libhelper.so.1.0 ../../lib/libhelper.so.1.0 ../../lib/libhelper.so

../lib/libhelper.so: ../lib/libhelper.so.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate ../lib/libhelper.so

# Rule to build all files generated by this target.
helpers/CMakeFiles/helper.dir/build: ../lib/libhelper.so

.PHONY : helpers/CMakeFiles/helper.dir/build

helpers/CMakeFiles/helper.dir/clean:
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" && $(CMAKE_COMMAND) -P CMakeFiles/helper.dir/cmake_clean.cmake
.PHONY : helpers/CMakeFiles/helper.dir/clean

helpers/CMakeFiles/helper.dir/depend:
	cd "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project" "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/helpers" "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake" "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers" "/home/chris/Dropbox/MSCS/CIS5371-Practical Aspects of Modern Cryptography/CIS5371-Project/cmake/helpers/CMakeFiles/helper.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : helpers/CMakeFiles/helper.dir/depend

