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
CMAKE_COMMAND = /home/user/Documents/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/user/Documents/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/ClionProjects/telegram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/ClionProjects/telegram/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/telegram.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/telegram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/telegram.dir/flags.make

CMakeFiles/telegram.dir/main.cpp.o: CMakeFiles/telegram.dir/flags.make
CMakeFiles/telegram.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ClionProjects/telegram/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/telegram.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/telegram.dir/main.cpp.o -c /home/user/ClionProjects/telegram/main.cpp

CMakeFiles/telegram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/telegram.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ClionProjects/telegram/main.cpp > CMakeFiles/telegram.dir/main.cpp.i

CMakeFiles/telegram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/telegram.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ClionProjects/telegram/main.cpp -o CMakeFiles/telegram.dir/main.cpp.s

CMakeFiles/telegram.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/telegram.dir/main.cpp.o.requires

CMakeFiles/telegram.dir/main.cpp.o.provides: CMakeFiles/telegram.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/telegram.dir/build.make CMakeFiles/telegram.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/telegram.dir/main.cpp.o.provides

CMakeFiles/telegram.dir/main.cpp.o.provides.build: CMakeFiles/telegram.dir/main.cpp.o


CMakeFiles/telegram.dir/lib/Users.cpp.o: CMakeFiles/telegram.dir/flags.make
CMakeFiles/telegram.dir/lib/Users.cpp.o: ../lib/Users.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ClionProjects/telegram/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/telegram.dir/lib/Users.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/telegram.dir/lib/Users.cpp.o -c /home/user/ClionProjects/telegram/lib/Users.cpp

CMakeFiles/telegram.dir/lib/Users.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/telegram.dir/lib/Users.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ClionProjects/telegram/lib/Users.cpp > CMakeFiles/telegram.dir/lib/Users.cpp.i

CMakeFiles/telegram.dir/lib/Users.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/telegram.dir/lib/Users.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ClionProjects/telegram/lib/Users.cpp -o CMakeFiles/telegram.dir/lib/Users.cpp.s

CMakeFiles/telegram.dir/lib/Users.cpp.o.requires:

.PHONY : CMakeFiles/telegram.dir/lib/Users.cpp.o.requires

CMakeFiles/telegram.dir/lib/Users.cpp.o.provides: CMakeFiles/telegram.dir/lib/Users.cpp.o.requires
	$(MAKE) -f CMakeFiles/telegram.dir/build.make CMakeFiles/telegram.dir/lib/Users.cpp.o.provides.build
.PHONY : CMakeFiles/telegram.dir/lib/Users.cpp.o.provides

CMakeFiles/telegram.dir/lib/Users.cpp.o.provides.build: CMakeFiles/telegram.dir/lib/Users.cpp.o


CMakeFiles/telegram.dir/lib/Cards.cpp.o: CMakeFiles/telegram.dir/flags.make
CMakeFiles/telegram.dir/lib/Cards.cpp.o: ../lib/Cards.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ClionProjects/telegram/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/telegram.dir/lib/Cards.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/telegram.dir/lib/Cards.cpp.o -c /home/user/ClionProjects/telegram/lib/Cards.cpp

CMakeFiles/telegram.dir/lib/Cards.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/telegram.dir/lib/Cards.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ClionProjects/telegram/lib/Cards.cpp > CMakeFiles/telegram.dir/lib/Cards.cpp.i

CMakeFiles/telegram.dir/lib/Cards.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/telegram.dir/lib/Cards.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ClionProjects/telegram/lib/Cards.cpp -o CMakeFiles/telegram.dir/lib/Cards.cpp.s

CMakeFiles/telegram.dir/lib/Cards.cpp.o.requires:

.PHONY : CMakeFiles/telegram.dir/lib/Cards.cpp.o.requires

CMakeFiles/telegram.dir/lib/Cards.cpp.o.provides: CMakeFiles/telegram.dir/lib/Cards.cpp.o.requires
	$(MAKE) -f CMakeFiles/telegram.dir/build.make CMakeFiles/telegram.dir/lib/Cards.cpp.o.provides.build
.PHONY : CMakeFiles/telegram.dir/lib/Cards.cpp.o.provides

CMakeFiles/telegram.dir/lib/Cards.cpp.o.provides.build: CMakeFiles/telegram.dir/lib/Cards.cpp.o


# Object files for target telegram
telegram_OBJECTS = \
"CMakeFiles/telegram.dir/main.cpp.o" \
"CMakeFiles/telegram.dir/lib/Users.cpp.o" \
"CMakeFiles/telegram.dir/lib/Cards.cpp.o"

# External object files for target telegram
telegram_EXTERNAL_OBJECTS =

telegram: CMakeFiles/telegram.dir/main.cpp.o
telegram: CMakeFiles/telegram.dir/lib/Users.cpp.o
telegram: CMakeFiles/telegram.dir/lib/Cards.cpp.o
telegram: CMakeFiles/telegram.dir/build.make
telegram: /usr/local/lib/libTgBot.a
telegram: /usr/lib/x86_64-linux-gnu/libssl.so
telegram: /usr/lib/x86_64-linux-gnu/libcrypto.so
telegram: /usr/lib/x86_64-linux-gnu/libboost_system.so
telegram: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
telegram: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
telegram: /usr/lib/x86_64-linux-gnu/libboost_regex.so
telegram: CMakeFiles/telegram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/ClionProjects/telegram/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable telegram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/telegram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/telegram.dir/build: telegram

.PHONY : CMakeFiles/telegram.dir/build

CMakeFiles/telegram.dir/requires: CMakeFiles/telegram.dir/main.cpp.o.requires
CMakeFiles/telegram.dir/requires: CMakeFiles/telegram.dir/lib/Users.cpp.o.requires
CMakeFiles/telegram.dir/requires: CMakeFiles/telegram.dir/lib/Cards.cpp.o.requires

.PHONY : CMakeFiles/telegram.dir/requires

CMakeFiles/telegram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/telegram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/telegram.dir/clean

CMakeFiles/telegram.dir/depend:
	cd /home/user/ClionProjects/telegram/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/ClionProjects/telegram /home/user/ClionProjects/telegram /home/user/ClionProjects/telegram/cmake-build-debug /home/user/ClionProjects/telegram/cmake-build-debug /home/user/ClionProjects/telegram/cmake-build-debug/CMakeFiles/telegram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/telegram.dir/depend

