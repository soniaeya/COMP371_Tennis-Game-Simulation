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
include _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/flags.make

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.obj: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/flags.make
_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.obj: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/includes_C.rsp
_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.obj: _deps/thirdparty-glfw-src/examples/simple.c
_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.obj: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.obj"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.obj -MF CMakeFiles\simple.dir\simple.c.obj.d -o CMakeFiles\simple.dir\simple.c.obj -c C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\examples\simple.c

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/simple.c.i"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\examples\simple.c > CMakeFiles\simple.dir\simple.c.i

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/simple.c.s"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\examples\simple.c -o CMakeFiles\simple.dir\simple.c.s

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/glfw.rc.obj: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/flags.make
_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/glfw.rc.obj: _deps/thirdparty-glfw-src/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/glfw.rc.obj"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\examples\glfw.rc CMakeFiles\simple.dir\glfw.rc.obj

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/flags.make
_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/includes_C.rsp
_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: _deps/thirdparty-glfw-src/deps/glad_gl.c
_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\simple.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\simple.dir\__\deps\glad_gl.c.obj -c C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\deps\glad_gl.c

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\deps\glad_gl.c > CMakeFiles\simple.dir\__\deps\glad_gl.c.i

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\deps\glad_gl.c -o CMakeFiles\simple.dir\__\deps\glad_gl.c.s

# Object files for target simple
simple_OBJECTS = \
"CMakeFiles/simple.dir/simple.c.obj" \
"CMakeFiles/simple.dir/glfw.rc.obj" \
"CMakeFiles/simple.dir/__/deps/glad_gl.c.obj"

# External object files for target simple
simple_EXTERNAL_OBJECTS =

_deps/thirdparty-glfw-build/examples/simple.exe: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/simple.c.obj
_deps/thirdparty-glfw-build/examples/simple.exe: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/glfw.rc.obj
_deps/thirdparty-glfw-build/examples/simple.exe: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj
_deps/thirdparty-glfw-build/examples/simple.exe: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/build.make
_deps/thirdparty-glfw-build/examples/simple.exe: _deps/thirdparty-glfw-build/src/libglfw3.a
_deps/thirdparty-glfw-build/examples/simple.exe: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/linkLibs.rsp
_deps/thirdparty-glfw-build/examples/simple.exe: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/objects1
_deps/thirdparty-glfw-build/examples/simple.exe: _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable simple.exe"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\simple.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/build: _deps/thirdparty-glfw-build/examples/simple.exe
.PHONY : _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/build

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/clean:
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples && $(CMAKE_COMMAND) -P CMakeFiles\simple.dir\cmake_clean.cmake
.PHONY : _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/clean

_deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-src\examples C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build\examples\CMakeFiles\simple.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/thirdparty-glfw-build/examples/CMakeFiles/simple.dir/depend

