# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/projet_patissier.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/projet_patissier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projet_patissier.dir/flags.make

CMakeFiles/projet_patissier.dir/main.c.obj: CMakeFiles/projet_patissier.dir/flags.make
CMakeFiles/projet_patissier.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projet_patissier.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\projet_patissier.dir\main.c.obj -c "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\main.c"

CMakeFiles/projet_patissier.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet_patissier.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\main.c" > CMakeFiles\projet_patissier.dir\main.c.i

CMakeFiles/projet_patissier.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet_patissier.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\main.c" -o CMakeFiles\projet_patissier.dir\main.c.s

CMakeFiles/projet_patissier.dir/core.c.obj: CMakeFiles/projet_patissier.dir/flags.make
CMakeFiles/projet_patissier.dir/core.c.obj: ../core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/projet_patissier.dir/core.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\projet_patissier.dir\core.c.obj -c "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\core.c"

CMakeFiles/projet_patissier.dir/core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet_patissier.dir/core.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\core.c" > CMakeFiles\projet_patissier.dir\core.c.i

CMakeFiles/projet_patissier.dir/core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet_patissier.dir/core.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\core.c" -o CMakeFiles\projet_patissier.dir\core.c.s

# Object files for target projet_patissier
projet_patissier_OBJECTS = \
"CMakeFiles/projet_patissier.dir/main.c.obj" \
"CMakeFiles/projet_patissier.dir/core.c.obj"

# External object files for target projet_patissier
projet_patissier_EXTERNAL_OBJECTS =

projet_patissier.exe: CMakeFiles/projet_patissier.dir/main.c.obj
projet_patissier.exe: CMakeFiles/projet_patissier.dir/core.c.obj
projet_patissier.exe: CMakeFiles/projet_patissier.dir/build.make
projet_patissier.exe: CMakeFiles/projet_patissier.dir/linklibs.rsp
projet_patissier.exe: CMakeFiles/projet_patissier.dir/objects1.rsp
projet_patissier.exe: CMakeFiles/projet_patissier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable projet_patissier.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\projet_patissier.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projet_patissier.dir/build: projet_patissier.exe
.PHONY : CMakeFiles/projet_patissier.dir/build

CMakeFiles/projet_patissier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\projet_patissier.dir\cmake_clean.cmake
.PHONY : CMakeFiles/projet_patissier.dir/clean

CMakeFiles/projet_patissier.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier" "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier" "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\cmake-build-debug" "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\cmake-build-debug" "C:\Users\Laurent Chau\Desktop\Dossier Principal\Cours\EFREI\Semestre 3\Informatique generale\Informatique generale\SSD\projet_patissier\cmake-build-debug\CMakeFiles\projet_patissier.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/projet_patissier.dir/depend
