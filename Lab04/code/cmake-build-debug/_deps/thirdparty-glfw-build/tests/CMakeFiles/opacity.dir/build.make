# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug

# Include any dependencies generated for this target.
include _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/flags.make

_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.obj: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/flags.make
_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.obj: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/includes_C.rsp
_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.obj: _deps/thirdparty-glfw-src/tests/opacity.c
_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.obj: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.obj"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.obj -MF CMakeFiles\opacity.dir\opacity.c.obj.d -o CMakeFiles\opacity.dir\opacity.c.obj -c C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\tests\opacity.c

_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opacity.dir/opacity.c.i"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\tests\opacity.c > CMakeFiles\opacity.dir\opacity.c.i

_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opacity.dir/opacity.c.s"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\tests\opacity.c -o CMakeFiles\opacity.dir\opacity.c.s

_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.obj: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/flags.make
_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.obj: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/includes_C.rsp
_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.obj: _deps/thirdparty-glfw-src/deps/glad_gl.c
_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.obj: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\opacity.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\opacity.dir\__\deps\glad_gl.c.obj -c C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\deps\glad_gl.c

_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opacity.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\deps\glad_gl.c > CMakeFiles\opacity.dir\__\deps\glad_gl.c.i

_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opacity.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\deps\glad_gl.c -o CMakeFiles\opacity.dir\__\deps\glad_gl.c.s

# Object files for target opacity
opacity_OBJECTS = \
"CMakeFiles/opacity.dir/opacity.c.obj" \
"CMakeFiles/opacity.dir/__/deps/glad_gl.c.obj"

# External object files for target opacity
opacity_EXTERNAL_OBJECTS =

_deps/thirdparty-glfw-build/tests/opacity.exe: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/opacity.c.obj
_deps/thirdparty-glfw-build/tests/opacity.exe: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/__/deps/glad_gl.c.obj
_deps/thirdparty-glfw-build/tests/opacity.exe: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/build.make
_deps/thirdparty-glfw-build/tests/opacity.exe: _deps/thirdparty-glfw-build/src/libglfw3.a
_deps/thirdparty-glfw-build/tests/opacity.exe: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/linkLibs.rsp
_deps/thirdparty-glfw-build/tests/opacity.exe: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/objects1
_deps/thirdparty-glfw-build/tests/opacity.exe: _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable opacity.exe"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\opacity.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/build: _deps/thirdparty-glfw-build/tests/opacity.exe
.PHONY : _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/build

_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/clean:
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests && $(CMAKE_COMMAND) -P CMakeFiles\opacity.dir\cmake_clean.cmake
.PHONY : _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/clean

_deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\tests C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\tests\CMakeFiles\opacity.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/thirdparty-glfw-build/tests/CMakeFiles/opacity.dir/depend

