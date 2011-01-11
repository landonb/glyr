# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/spohst/Projects/glyr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spohst/Projects/glyr

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

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

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
	$(CMAKE_COMMAND) -E cmake_progress_start /home/spohst/Projects/glyr/CMakeFiles /home/spohst/Projects/glyr/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/spohst/Projects/glyr/CMakeFiles 0
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
# Target rules for targets named glyr

# Build rule for target.
glyr: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glyr
.PHONY : glyr

# fast build rule for target.
glyr/fast:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/build
.PHONY : glyr/fast

src/core.o: src/core.c.o
.PHONY : src/core.o

# target to build an object file
src/core.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/core.c.o
.PHONY : src/core.c.o

src/core.i: src/core.c.i
.PHONY : src/core.i

# target to preprocess a source file
src/core.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/core.c.i
.PHONY : src/core.c.i

src/core.s: src/core.c.s
.PHONY : src/core.s

# target to generate assembly for a file
src/core.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/core.c.s
.PHONY : src/core.c.s

src/cover.o: src/cover.c.o
.PHONY : src/cover.o

# target to build an object file
src/cover.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover.c.o
.PHONY : src/cover.c.o

src/cover.i: src/cover.c.i
.PHONY : src/cover.i

# target to preprocess a source file
src/cover.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover.c.i
.PHONY : src/cover.c.i

src/cover.s: src/cover.c.s
.PHONY : src/cover.s

# target to generate assembly for a file
src/cover.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover.c.s
.PHONY : src/cover.c.s

src/cover/amazon.o: src/cover/amazon.c.o
.PHONY : src/cover/amazon.o

# target to build an object file
src/cover/amazon.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/amazon.c.o
.PHONY : src/cover/amazon.c.o

src/cover/amazon.i: src/cover/amazon.c.i
.PHONY : src/cover/amazon.i

# target to preprocess a source file
src/cover/amazon.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/amazon.c.i
.PHONY : src/cover/amazon.c.i

src/cover/amazon.s: src/cover/amazon.c.s
.PHONY : src/cover/amazon.s

# target to generate assembly for a file
src/cover/amazon.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/amazon.c.s
.PHONY : src/cover/amazon.c.s

src/cover/discogs.o: src/cover/discogs.c.o
.PHONY : src/cover/discogs.o

# target to build an object file
src/cover/discogs.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/discogs.c.o
.PHONY : src/cover/discogs.c.o

src/cover/discogs.i: src/cover/discogs.c.i
.PHONY : src/cover/discogs.i

# target to preprocess a source file
src/cover/discogs.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/discogs.c.i
.PHONY : src/cover/discogs.c.i

src/cover/discogs.s: src/cover/discogs.c.s
.PHONY : src/cover/discogs.s

# target to generate assembly for a file
src/cover/discogs.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/discogs.c.s
.PHONY : src/cover/discogs.c.s

src/cover/google.o: src/cover/google.c.o
.PHONY : src/cover/google.o

# target to build an object file
src/cover/google.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/google.c.o
.PHONY : src/cover/google.c.o

src/cover/google.i: src/cover/google.c.i
.PHONY : src/cover/google.i

# target to preprocess a source file
src/cover/google.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/google.c.i
.PHONY : src/cover/google.c.i

src/cover/google.s: src/cover/google.c.s
.PHONY : src/cover/google.s

# target to generate assembly for a file
src/cover/google.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/google.c.s
.PHONY : src/cover/google.c.s

src/cover/last_fm.o: src/cover/last_fm.c.o
.PHONY : src/cover/last_fm.o

# target to build an object file
src/cover/last_fm.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/last_fm.c.o
.PHONY : src/cover/last_fm.c.o

src/cover/last_fm.i: src/cover/last_fm.c.i
.PHONY : src/cover/last_fm.i

# target to preprocess a source file
src/cover/last_fm.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/last_fm.c.i
.PHONY : src/cover/last_fm.c.i

src/cover/last_fm.s: src/cover/last_fm.c.s
.PHONY : src/cover/last_fm.s

# target to generate assembly for a file
src/cover/last_fm.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/last_fm.c.s
.PHONY : src/cover/last_fm.c.s

src/cover/lyricswiki.o: src/cover/lyricswiki.c.o
.PHONY : src/cover/lyricswiki.o

# target to build an object file
src/cover/lyricswiki.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/lyricswiki.c.o
.PHONY : src/cover/lyricswiki.c.o

src/cover/lyricswiki.i: src/cover/lyricswiki.c.i
.PHONY : src/cover/lyricswiki.i

# target to preprocess a source file
src/cover/lyricswiki.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/lyricswiki.c.i
.PHONY : src/cover/lyricswiki.c.i

src/cover/lyricswiki.s: src/cover/lyricswiki.c.s
.PHONY : src/cover/lyricswiki.s

# target to generate assembly for a file
src/cover/lyricswiki.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/cover/lyricswiki.c.s
.PHONY : src/cover/lyricswiki.c.s

src/lyrics.o: src/lyrics.c.o
.PHONY : src/lyrics.o

# target to build an object file
src/lyrics.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics.c.o
.PHONY : src/lyrics.c.o

src/lyrics.i: src/lyrics.c.i
.PHONY : src/lyrics.i

# target to preprocess a source file
src/lyrics.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics.c.i
.PHONY : src/lyrics.c.i

src/lyrics.s: src/lyrics.c.s
.PHONY : src/lyrics.s

# target to generate assembly for a file
src/lyrics.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics.c.s
.PHONY : src/lyrics.c.s

src/lyrics/darklyrics.o: src/lyrics/darklyrics.c.o
.PHONY : src/lyrics/darklyrics.o

# target to build an object file
src/lyrics/darklyrics.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/darklyrics.c.o
.PHONY : src/lyrics/darklyrics.c.o

src/lyrics/darklyrics.i: src/lyrics/darklyrics.c.i
.PHONY : src/lyrics/darklyrics.i

# target to preprocess a source file
src/lyrics/darklyrics.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/darklyrics.c.i
.PHONY : src/lyrics/darklyrics.c.i

src/lyrics/darklyrics.s: src/lyrics/darklyrics.c.s
.PHONY : src/lyrics/darklyrics.s

# target to generate assembly for a file
src/lyrics/darklyrics.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/darklyrics.c.s
.PHONY : src/lyrics/darklyrics.c.s

src/lyrics/lyrdb.o: src/lyrics/lyrdb.c.o
.PHONY : src/lyrics/lyrdb.o

# target to build an object file
src/lyrics/lyrdb.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyrdb.c.o
.PHONY : src/lyrics/lyrdb.c.o

src/lyrics/lyrdb.i: src/lyrics/lyrdb.c.i
.PHONY : src/lyrics/lyrdb.i

# target to preprocess a source file
src/lyrics/lyrdb.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyrdb.c.i
.PHONY : src/lyrics/lyrdb.c.i

src/lyrics/lyrdb.s: src/lyrics/lyrdb.c.s
.PHONY : src/lyrics/lyrdb.s

# target to generate assembly for a file
src/lyrics/lyrdb.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyrdb.c.s
.PHONY : src/lyrics/lyrdb.c.s

src/lyrics/lyricswiki.o: src/lyrics/lyricswiki.c.o
.PHONY : src/lyrics/lyricswiki.o

# target to build an object file
src/lyrics/lyricswiki.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyricswiki.c.o
.PHONY : src/lyrics/lyricswiki.c.o

src/lyrics/lyricswiki.i: src/lyrics/lyricswiki.c.i
.PHONY : src/lyrics/lyricswiki.i

# target to preprocess a source file
src/lyrics/lyricswiki.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyricswiki.c.i
.PHONY : src/lyrics/lyricswiki.c.i

src/lyrics/lyricswiki.s: src/lyrics/lyricswiki.c.s
.PHONY : src/lyrics/lyricswiki.s

# target to generate assembly for a file
src/lyrics/lyricswiki.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyricswiki.c.s
.PHONY : src/lyrics/lyricswiki.c.s

src/lyrics/lyrix_at.o: src/lyrics/lyrix_at.c.o
.PHONY : src/lyrics/lyrix_at.o

# target to build an object file
src/lyrics/lyrix_at.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyrix_at.c.o
.PHONY : src/lyrics/lyrix_at.c.o

src/lyrics/lyrix_at.i: src/lyrics/lyrix_at.c.i
.PHONY : src/lyrics/lyrix_at.i

# target to preprocess a source file
src/lyrics/lyrix_at.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyrix_at.c.i
.PHONY : src/lyrics/lyrix_at.c.i

src/lyrics/lyrix_at.s: src/lyrics/lyrix_at.c.s
.PHONY : src/lyrics/lyrix_at.s

# target to generate assembly for a file
src/lyrics/lyrix_at.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/lyrix_at.c.s
.PHONY : src/lyrics/lyrix_at.c.s

src/lyrics/magistrix.o: src/lyrics/magistrix.c.o
.PHONY : src/lyrics/magistrix.o

# target to build an object file
src/lyrics/magistrix.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/magistrix.c.o
.PHONY : src/lyrics/magistrix.c.o

src/lyrics/magistrix.i: src/lyrics/magistrix.c.i
.PHONY : src/lyrics/magistrix.i

# target to preprocess a source file
src/lyrics/magistrix.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/magistrix.c.i
.PHONY : src/lyrics/magistrix.c.i

src/lyrics/magistrix.s: src/lyrics/magistrix.c.s
.PHONY : src/lyrics/magistrix.s

# target to generate assembly for a file
src/lyrics/magistrix.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/magistrix.c.s
.PHONY : src/lyrics/magistrix.c.s

src/lyrics/metrolyrics.o: src/lyrics/metrolyrics.c.o
.PHONY : src/lyrics/metrolyrics.o

# target to build an object file
src/lyrics/metrolyrics.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/metrolyrics.c.o
.PHONY : src/lyrics/metrolyrics.c.o

src/lyrics/metrolyrics.i: src/lyrics/metrolyrics.c.i
.PHONY : src/lyrics/metrolyrics.i

# target to preprocess a source file
src/lyrics/metrolyrics.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/metrolyrics.c.i
.PHONY : src/lyrics/metrolyrics.c.i

src/lyrics/metrolyrics.s: src/lyrics/metrolyrics.c.s
.PHONY : src/lyrics/metrolyrics.s

# target to generate assembly for a file
src/lyrics/metrolyrics.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/lyrics/metrolyrics.c.s
.PHONY : src/lyrics/metrolyrics.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/main.c.s
.PHONY : src/main.c.s

src/stringop.o: src/stringop.c.o
.PHONY : src/stringop.o

# target to build an object file
src/stringop.c.o:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/stringop.c.o
.PHONY : src/stringop.c.o

src/stringop.i: src/stringop.c.i
.PHONY : src/stringop.i

# target to preprocess a source file
src/stringop.c.i:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/stringop.c.i
.PHONY : src/stringop.c.i

src/stringop.s: src/stringop.c.s
.PHONY : src/stringop.s

# target to generate assembly for a file
src/stringop.c.s:
	$(MAKE) -f CMakeFiles/glyr.dir/build.make CMakeFiles/glyr.dir/src/stringop.c.s
.PHONY : src/stringop.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... glyr"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... src/core.o"
	@echo "... src/core.i"
	@echo "... src/core.s"
	@echo "... src/cover.o"
	@echo "... src/cover.i"
	@echo "... src/cover.s"
	@echo "... src/cover/amazon.o"
	@echo "... src/cover/amazon.i"
	@echo "... src/cover/amazon.s"
	@echo "... src/cover/discogs.o"
	@echo "... src/cover/discogs.i"
	@echo "... src/cover/discogs.s"
	@echo "... src/cover/google.o"
	@echo "... src/cover/google.i"
	@echo "... src/cover/google.s"
	@echo "... src/cover/last_fm.o"
	@echo "... src/cover/last_fm.i"
	@echo "... src/cover/last_fm.s"
	@echo "... src/cover/lyricswiki.o"
	@echo "... src/cover/lyricswiki.i"
	@echo "... src/cover/lyricswiki.s"
	@echo "... src/lyrics.o"
	@echo "... src/lyrics.i"
	@echo "... src/lyrics.s"
	@echo "... src/lyrics/darklyrics.o"
	@echo "... src/lyrics/darklyrics.i"
	@echo "... src/lyrics/darklyrics.s"
	@echo "... src/lyrics/lyrdb.o"
	@echo "... src/lyrics/lyrdb.i"
	@echo "... src/lyrics/lyrdb.s"
	@echo "... src/lyrics/lyricswiki.o"
	@echo "... src/lyrics/lyricswiki.i"
	@echo "... src/lyrics/lyricswiki.s"
	@echo "... src/lyrics/lyrix_at.o"
	@echo "... src/lyrics/lyrix_at.i"
	@echo "... src/lyrics/lyrix_at.s"
	@echo "... src/lyrics/magistrix.o"
	@echo "... src/lyrics/magistrix.i"
	@echo "... src/lyrics/magistrix.s"
	@echo "... src/lyrics/metrolyrics.o"
	@echo "... src/lyrics/metrolyrics.i"
	@echo "... src/lyrics/metrolyrics.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/stringop.o"
	@echo "... src/stringop.i"
	@echo "... src/stringop.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

