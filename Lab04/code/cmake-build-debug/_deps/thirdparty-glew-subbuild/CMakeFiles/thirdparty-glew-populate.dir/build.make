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
CMAKE_SOURCE_DIR = C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild

# Utility rule file for thirdparty-glew-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/thirdparty-glew-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thirdparty-glew-populate.dir/progress.make

CMakeFiles/thirdparty-glew-populate: CMakeFiles/thirdparty-glew-populate-complete

CMakeFiles/thirdparty-glew-populate-complete: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-install
CMakeFiles/thirdparty-glew-populate-complete: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-mkdir
CMakeFiles/thirdparty-glew-populate-complete: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-download
CMakeFiles/thirdparty-glew-populate-complete: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-patch
CMakeFiles/thirdparty-glew-populate-complete: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-configure
CMakeFiles/thirdparty-glew-populate-complete: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-build
CMakeFiles/thirdparty-glew-populate-complete: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-install
CMakeFiles/thirdparty-glew-populate-complete: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'thirdparty-glew-populate'"
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E make_directory C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/CMakeFiles
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/CMakeFiles/thirdparty-glew-populate-complete
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-done

thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-build: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'thirdparty-glew-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-build

thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-configure: thirdparty-glew-populate-prefix/tmp/thirdparty-glew-populate-cfgcmd.txt
thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-configure: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'thirdparty-glew-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-configure

thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-download: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-urlinfo.txt
thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-download: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (verify and extract) for 'thirdparty-glew-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -P C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/verify-thirdparty-glew-populate.cmake
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -P C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/extract-thirdparty-glew-populate.cmake
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-download

thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-install: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'thirdparty-glew-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-install

thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'thirdparty-glew-populate'"
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -Dcfgdir= -P C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/tmp/thirdparty-glew-populate-mkdirs.cmake
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-mkdir

thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-patch: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'thirdparty-glew-populate'"
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	"C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-patch

thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-test: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'thirdparty-glew-populate'"
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-build && "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sonia/Downloads/COMP371_FinalProject/Lab04/code/cmake-build-debug/_deps/thirdparty-glew-subbuild/thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-test

thirdparty-glew-populate: CMakeFiles/thirdparty-glew-populate
thirdparty-glew-populate: CMakeFiles/thirdparty-glew-populate-complete
thirdparty-glew-populate: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-build
thirdparty-glew-populate: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-configure
thirdparty-glew-populate: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-download
thirdparty-glew-populate: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-install
thirdparty-glew-populate: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-mkdir
thirdparty-glew-populate: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-patch
thirdparty-glew-populate: thirdparty-glew-populate-prefix/src/thirdparty-glew-populate-stamp/thirdparty-glew-populate-test
thirdparty-glew-populate: CMakeFiles/thirdparty-glew-populate.dir/build.make
.PHONY : thirdparty-glew-populate

# Rule to build all files generated by this target.
CMakeFiles/thirdparty-glew-populate.dir/build: thirdparty-glew-populate
.PHONY : CMakeFiles/thirdparty-glew-populate.dir/build

CMakeFiles/thirdparty-glew-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\thirdparty-glew-populate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/thirdparty-glew-populate.dir/clean

CMakeFiles/thirdparty-glew-populate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild C:\Users\sonia\Downloads\COMP371_FinalProject\Lab04\code\cmake-build-debug\_deps\thirdparty-glew-subbuild\CMakeFiles\thirdparty-glew-populate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thirdparty-glew-populate.dir/depend

