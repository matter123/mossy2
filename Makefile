# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mfosdick/mossy2-x64

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mfosdick/mossy2-x64

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mfosdick/mossy2-x64/CMakeFiles /home/mfosdick/mossy2-x64/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mfosdick/mossy2-x64/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named kernel

# Build rule for target.
kernel: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 kernel
.PHONY : kernel

# fast build rule for target.
kernel/fast:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/build
.PHONY : kernel/fast

src/begin.o: src/begin.cpp.o
.PHONY : src/begin.o

# target to build an object file
src/begin.cpp.o:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/begin.cpp.o
.PHONY : src/begin.cpp.o

src/begin.i: src/begin.cpp.i
.PHONY : src/begin.i

# target to preprocess a source file
src/begin.cpp.i:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/begin.cpp.i
.PHONY : src/begin.cpp.i

src/begin.s: src/begin.cpp.s
.PHONY : src/begin.s

# target to generate assembly for a file
src/begin.cpp.s:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/begin.cpp.s
.PHONY : src/begin.cpp.s

src/hhalf.o: src/hhalf.cpp.o
.PHONY : src/hhalf.o

# target to build an object file
src/hhalf.cpp.o:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/hhalf.cpp.o
.PHONY : src/hhalf.cpp.o

src/hhalf.i: src/hhalf.cpp.i
.PHONY : src/hhalf.i

# target to preprocess a source file
src/hhalf.cpp.i:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/hhalf.cpp.i
.PHONY : src/hhalf.cpp.i

src/hhalf.s: src/hhalf.cpp.s
.PHONY : src/hhalf.s

# target to generate assembly for a file
src/hhalf.cpp.s:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/hhalf.cpp.s
.PHONY : src/hhalf.cpp.s

src/panic.o: src/panic.cpp.o
.PHONY : src/panic.o

# target to build an object file
src/panic.cpp.o:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/panic.cpp.o
.PHONY : src/panic.cpp.o

src/panic.i: src/panic.cpp.i
.PHONY : src/panic.i

# target to preprocess a source file
src/panic.cpp.i:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/panic.cpp.i
.PHONY : src/panic.cpp.i

src/panic.s: src/panic.cpp.s
.PHONY : src/panic.s

# target to generate assembly for a file
src/panic.cpp.s:
	$(MAKE) -f CMakeFiles/kernel.dir/build.make CMakeFiles/kernel.dir/src/panic.cpp.s
.PHONY : src/panic.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... kernel"
	@echo "... rebuild_cache"
	@echo "... src/begin.o"
	@echo "... src/begin.i"
	@echo "... src/begin.s"
	@echo "... src/hhalf.o"
	@echo "... src/hhalf.i"
	@echo "... src/hhalf.s"
	@echo "... src/panic.o"
	@echo "... src/panic.i"
	@echo "... src/panic.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

