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
CMAKE_SOURCE_DIR = C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild

# Utility rule file for thirdparty-glfw-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/thirdparty-glfw-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thirdparty-glfw-populate.dir/progress.make

CMakeFiles/thirdparty-glfw-populate: CMakeFiles/thirdparty-glfw-populate-complete

CMakeFiles/thirdparty-glfw-populate-complete: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-install
CMakeFiles/thirdparty-glfw-populate-complete: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-mkdir
CMakeFiles/thirdparty-glfw-populate-complete: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-download
CMakeFiles/thirdparty-glfw-populate-complete: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-patch
CMakeFiles/thirdparty-glfw-populate-complete: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-configure
CMakeFiles/thirdparty-glfw-populate-complete: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-build
CMakeFiles/thirdparty-glfw-populate-complete: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-install
CMakeFiles/thirdparty-glfw-populate-complete: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'thirdparty-glfw-populate'"
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E make_directory C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/CMakeFiles
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/CMakeFiles/thirdparty-glfw-populate-complete
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-done

thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-build: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'thirdparty-glfw-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-build

thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-configure: thirdparty-glfw-populate-prefix/tmp/thirdparty-glfw-populate-cfgcmd.txt
thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-configure: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'thirdparty-glfw-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-configure

thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-download: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-urlinfo.txt
thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-download: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (verify and extract) for 'thirdparty-glfw-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -P C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/verify-thirdparty-glfw-populate.cmake
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -P C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/extract-thirdparty-glfw-populate.cmake
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-download

thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-install: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'thirdparty-glfw-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-install

thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'thirdparty-glfw-populate'"
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -Dcfgdir= -P C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/tmp/thirdparty-glfw-populate-mkdirs.cmake
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-mkdir

thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-patch: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'thirdparty-glfw-populate'"
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-patch

thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-test: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'thirdparty-glfw-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glfw-subbuild/thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-test

thirdparty-glfw-populate: CMakeFiles/thirdparty-glfw-populate
thirdparty-glfw-populate: CMakeFiles/thirdparty-glfw-populate-complete
thirdparty-glfw-populate: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-build
thirdparty-glfw-populate: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-configure
thirdparty-glfw-populate: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-download
thirdparty-glfw-populate: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-install
thirdparty-glfw-populate: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-mkdir
thirdparty-glfw-populate: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-patch
thirdparty-glfw-populate: thirdparty-glfw-populate-prefix/src/thirdparty-glfw-populate-stamp/thirdparty-glfw-populate-test
thirdparty-glfw-populate: CMakeFiles/thirdparty-glfw-populate.dir/build.make
.PHONY : thirdparty-glfw-populate

# Rule to build all files generated by this target.
CMakeFiles/thirdparty-glfw-populate.dir/build: thirdparty-glfw-populate
.PHONY : CMakeFiles/thirdparty-glfw-populate.dir/build

CMakeFiles/thirdparty-glfw-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\thirdparty-glfw-populate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/thirdparty-glfw-populate.dir/clean

CMakeFiles/thirdparty-glfw-populate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glfw-subbuild\CMakeFiles\thirdparty-glfw-populate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thirdparty-glfw-populate.dir/depend

