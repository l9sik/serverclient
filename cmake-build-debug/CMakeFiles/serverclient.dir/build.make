# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "D:\CLion\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\!Univer\serverClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\!Univer\serverClient\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/serverclient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/serverclient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/serverclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serverclient.dir/flags.make

CMakeFiles/serverclient.dir/src/main.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/main.cpp.obj: src/main.cpp
CMakeFiles/serverclient.dir/src/main.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serverclient.dir/src/main.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/main.cpp.obj -MF CMakeFiles\serverclient.dir\src\main.cpp.obj.d -o CMakeFiles\serverclient.dir\src\main.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\main.cpp

CMakeFiles/serverclient.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/main.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\main.cpp > CMakeFiles\serverclient.dir\src\main.cpp.i

CMakeFiles/serverclient.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/main.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\main.cpp -o CMakeFiles\serverclient.dir\src\main.cpp.s

CMakeFiles/serverclient.dir/src/server.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/server.cpp.obj: src/server.cpp
CMakeFiles/serverclient.dir/src/server.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serverclient.dir/src/server.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/server.cpp.obj -MF CMakeFiles\serverclient.dir\src\server.cpp.obj.d -o CMakeFiles\serverclient.dir\src\server.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\server.cpp

CMakeFiles/serverclient.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/server.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\server.cpp > CMakeFiles\serverclient.dir\src\server.cpp.i

CMakeFiles/serverclient.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/server.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\server.cpp -o CMakeFiles\serverclient.dir\src\server.cpp.s

CMakeFiles/serverclient.dir/src/client.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/client.cpp.obj: src/client.cpp
CMakeFiles/serverclient.dir/src/client.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/serverclient.dir/src/client.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/client.cpp.obj -MF CMakeFiles\serverclient.dir\src\client.cpp.obj.d -o CMakeFiles\serverclient.dir\src\client.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\client.cpp

CMakeFiles/serverclient.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/client.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\client.cpp > CMakeFiles\serverclient.dir\src\client.cpp.i

CMakeFiles/serverclient.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/client.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\client.cpp -o CMakeFiles\serverclient.dir\src\client.cpp.s

CMakeFiles/serverclient.dir/src/serverMessage.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/serverMessage.cpp.obj: src/serverMessage.cpp
CMakeFiles/serverclient.dir/src/serverMessage.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/serverclient.dir/src/serverMessage.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/serverMessage.cpp.obj -MF CMakeFiles\serverclient.dir\src\serverMessage.cpp.obj.d -o CMakeFiles\serverclient.dir\src\serverMessage.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\serverMessage.cpp

CMakeFiles/serverclient.dir/src/serverMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/serverMessage.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\serverMessage.cpp > CMakeFiles\serverclient.dir\src\serverMessage.cpp.i

CMakeFiles/serverclient.dir/src/serverMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/serverMessage.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\serverMessage.cpp -o CMakeFiles\serverclient.dir\src\serverMessage.cpp.s

CMakeFiles/serverclient.dir/src/thsQueue.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/thsQueue.cpp.obj: src/thsQueue.cpp
CMakeFiles/serverclient.dir/src/thsQueue.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/serverclient.dir/src/thsQueue.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/thsQueue.cpp.obj -MF CMakeFiles\serverclient.dir\src\thsQueue.cpp.obj.d -o CMakeFiles\serverclient.dir\src\thsQueue.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\thsQueue.cpp

CMakeFiles/serverclient.dir/src/thsQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/thsQueue.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\thsQueue.cpp > CMakeFiles\serverclient.dir\src\thsQueue.cpp.i

CMakeFiles/serverclient.dir/src/thsQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/thsQueue.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\thsQueue.cpp -o CMakeFiles\serverclient.dir\src\thsQueue.cpp.s

CMakeFiles/serverclient.dir/src/genID.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/genID.cpp.obj: src/genID.cpp
CMakeFiles/serverclient.dir/src/genID.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/serverclient.dir/src/genID.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/genID.cpp.obj -MF CMakeFiles\serverclient.dir\src\genID.cpp.obj.d -o CMakeFiles\serverclient.dir\src\genID.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\genID.cpp

CMakeFiles/serverclient.dir/src/genID.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/genID.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\genID.cpp > CMakeFiles\serverclient.dir\src\genID.cpp.i

CMakeFiles/serverclient.dir/src/genID.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/genID.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\genID.cpp -o CMakeFiles\serverclient.dir\src\genID.cpp.s

CMakeFiles/serverclient.dir/src/msgHandle.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/msgHandle.cpp.obj: src/msgHandle.cpp
CMakeFiles/serverclient.dir/src/msgHandle.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/serverclient.dir/src/msgHandle.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/msgHandle.cpp.obj -MF CMakeFiles\serverclient.dir\src\msgHandle.cpp.obj.d -o CMakeFiles\serverclient.dir\src\msgHandle.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\msgHandle.cpp

CMakeFiles/serverclient.dir/src/msgHandle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/msgHandle.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\msgHandle.cpp > CMakeFiles\serverclient.dir\src\msgHandle.cpp.i

CMakeFiles/serverclient.dir/src/msgHandle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/msgHandle.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\msgHandle.cpp -o CMakeFiles\serverclient.dir\src\msgHandle.cpp.s

CMakeFiles/serverclient.dir/src/msgGen.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/msgGen.cpp.obj: src/msgGen.cpp
CMakeFiles/serverclient.dir/src/msgGen.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/serverclient.dir/src/msgGen.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/msgGen.cpp.obj -MF CMakeFiles\serverclient.dir\src\msgGen.cpp.obj.d -o CMakeFiles\serverclient.dir\src\msgGen.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\msgGen.cpp

CMakeFiles/serverclient.dir/src/msgGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/msgGen.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\msgGen.cpp > CMakeFiles\serverclient.dir\src\msgGen.cpp.i

CMakeFiles/serverclient.dir/src/msgGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/msgGen.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\msgGen.cpp -o CMakeFiles\serverclient.dir\src\msgGen.cpp.s

CMakeFiles/serverclient.dir/src/appHelper.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/appHelper.cpp.obj: src/appHelper.cpp
CMakeFiles/serverclient.dir/src/appHelper.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/serverclient.dir/src/appHelper.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/appHelper.cpp.obj -MF CMakeFiles\serverclient.dir\src\appHelper.cpp.obj.d -o CMakeFiles\serverclient.dir\src\appHelper.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\appHelper.cpp

CMakeFiles/serverclient.dir/src/appHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/appHelper.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\appHelper.cpp > CMakeFiles\serverclient.dir\src\appHelper.cpp.i

CMakeFiles/serverclient.dir/src/appHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/appHelper.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\appHelper.cpp -o CMakeFiles\serverclient.dir\src\appHelper.cpp.s

CMakeFiles/serverclient.dir/src/fileHandle.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/fileHandle.cpp.obj: src/fileHandle.cpp
CMakeFiles/serverclient.dir/src/fileHandle.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/serverclient.dir/src/fileHandle.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/fileHandle.cpp.obj -MF CMakeFiles\serverclient.dir\src\fileHandle.cpp.obj.d -o CMakeFiles\serverclient.dir\src\fileHandle.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\fileHandle.cpp

CMakeFiles/serverclient.dir/src/fileHandle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/fileHandle.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\fileHandle.cpp > CMakeFiles\serverclient.dir\src\fileHandle.cpp.i

CMakeFiles/serverclient.dir/src/fileHandle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/fileHandle.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\fileHandle.cpp -o CMakeFiles\serverclient.dir\src\fileHandle.cpp.s

CMakeFiles/serverclient.dir/src/MsgConverter.cpp.obj: CMakeFiles/serverclient.dir/flags.make
CMakeFiles/serverclient.dir/src/MsgConverter.cpp.obj: src/MsgConverter.cpp
CMakeFiles/serverclient.dir/src/MsgConverter.cpp.obj: CMakeFiles/serverclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/serverclient.dir/src/MsgConverter.cpp.obj"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serverclient.dir/src/MsgConverter.cpp.obj -MF CMakeFiles\serverclient.dir\src\MsgConverter.cpp.obj.d -o CMakeFiles\serverclient.dir\src\MsgConverter.cpp.obj -c D:\!Univer\serverClient\cmake-build-debug\src\MsgConverter.cpp

CMakeFiles/serverclient.dir/src/MsgConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverclient.dir/src/MsgConverter.cpp.i"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\!Univer\serverClient\cmake-build-debug\src\MsgConverter.cpp > CMakeFiles\serverclient.dir\src\MsgConverter.cpp.i

CMakeFiles/serverclient.dir/src/MsgConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverclient.dir/src/MsgConverter.cpp.s"
	"D:\CLion\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\!Univer\serverClient\cmake-build-debug\src\MsgConverter.cpp -o CMakeFiles\serverclient.dir\src\MsgConverter.cpp.s

# Object files for target serverclient
serverclient_OBJECTS = \
"CMakeFiles/serverclient.dir/src/main.cpp.obj" \
"CMakeFiles/serverclient.dir/src/server.cpp.obj" \
"CMakeFiles/serverclient.dir/src/client.cpp.obj" \
"CMakeFiles/serverclient.dir/src/serverMessage.cpp.obj" \
"CMakeFiles/serverclient.dir/src/thsQueue.cpp.obj" \
"CMakeFiles/serverclient.dir/src/genID.cpp.obj" \
"CMakeFiles/serverclient.dir/src/msgHandle.cpp.obj" \
"CMakeFiles/serverclient.dir/src/msgGen.cpp.obj" \
"CMakeFiles/serverclient.dir/src/appHelper.cpp.obj" \
"CMakeFiles/serverclient.dir/src/fileHandle.cpp.obj" \
"CMakeFiles/serverclient.dir/src/MsgConverter.cpp.obj"

# External object files for target serverclient
serverclient_EXTERNAL_OBJECTS =

serverclient.exe: CMakeFiles/serverclient.dir/src/main.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/server.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/client.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/serverMessage.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/thsQueue.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/genID.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/msgHandle.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/msgGen.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/appHelper.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/fileHandle.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/src/MsgConverter.cpp.obj
serverclient.exe: CMakeFiles/serverclient.dir/build.make
serverclient.exe: CMakeFiles/serverclient.dir/linklibs.rsp
serverclient.exe: CMakeFiles/serverclient.dir/objects1.rsp
serverclient.exe: CMakeFiles/serverclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\!Univer\serverClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable serverclient.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\serverclient.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serverclient.dir/build: serverclient.exe
.PHONY : CMakeFiles/serverclient.dir/build

CMakeFiles/serverclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\serverclient.dir\cmake_clean.cmake
.PHONY : CMakeFiles/serverclient.dir/clean

CMakeFiles/serverclient.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\!Univer\serverClient D:\!Univer\serverClient D:\!Univer\serverClient\cmake-build-debug D:\!Univer\serverClient\cmake-build-debug D:\!Univer\serverClient\cmake-build-debug\CMakeFiles\serverclient.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serverclient.dir/depend

