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
CMAKE_COMMAND = "D:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gusta\Documents\hld_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gusta\Documents\hld_game\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/main.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/main.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\main.cpp.obj -c C:\Users\gusta\Documents\hld_game\main.cpp

CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gusta\Documents\hld_game\main.cpp > CMakeFiles\game.dir\main.cpp.i

CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gusta\Documents\hld_game\main.cpp -o CMakeFiles\game.dir\main.cpp.s

CMakeFiles/game.dir/src/Game.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Game.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/Game.cpp.obj: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/Game.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\src\Game.cpp.obj -c C:\Users\gusta\Documents\hld_game\src\Game.cpp

CMakeFiles/game.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Game.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gusta\Documents\hld_game\src\Game.cpp > CMakeFiles\game.dir\src\Game.cpp.i

CMakeFiles/game.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Game.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gusta\Documents\hld_game\src\Game.cpp -o CMakeFiles\game.dir\src\Game.cpp.s

CMakeFiles/game.dir/src/TileMap.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/TileMap.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/TileMap.cpp.obj: ../src/TileMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/TileMap.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\src\TileMap.cpp.obj -c C:\Users\gusta\Documents\hld_game\src\TileMap.cpp

CMakeFiles/game.dir/src/TileMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/TileMap.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gusta\Documents\hld_game\src\TileMap.cpp > CMakeFiles\game.dir\src\TileMap.cpp.i

CMakeFiles/game.dir/src/TileMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/TileMap.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gusta\Documents\hld_game\src\TileMap.cpp -o CMakeFiles\game.dir\src\TileMap.cpp.s

CMakeFiles/game.dir/src/Player.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Player.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/Player.cpp.obj: ../src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/Player.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\src\Player.cpp.obj -c C:\Users\gusta\Documents\hld_game\src\Player.cpp

CMakeFiles/game.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Player.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gusta\Documents\hld_game\src\Player.cpp > CMakeFiles\game.dir\src\Player.cpp.i

CMakeFiles/game.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Player.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gusta\Documents\hld_game\src\Player.cpp -o CMakeFiles\game.dir\src\Player.cpp.s

CMakeFiles/game.dir/src/Entity.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Entity.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/Entity.cpp.obj: ../src/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/src/Entity.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\src\Entity.cpp.obj -c C:\Users\gusta\Documents\hld_game\src\Entity.cpp

CMakeFiles/game.dir/src/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Entity.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gusta\Documents\hld_game\src\Entity.cpp > CMakeFiles\game.dir\src\Entity.cpp.i

CMakeFiles/game.dir/src/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Entity.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gusta\Documents\hld_game\src\Entity.cpp -o CMakeFiles\game.dir\src\Entity.cpp.s

CMakeFiles/game.dir/src/Assets.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Assets.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/Assets.cpp.obj: ../src/Assets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/src/Assets.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\src\Assets.cpp.obj -c C:\Users\gusta\Documents\hld_game\src\Assets.cpp

CMakeFiles/game.dir/src/Assets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Assets.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gusta\Documents\hld_game\src\Assets.cpp > CMakeFiles\game.dir\src\Assets.cpp.i

CMakeFiles/game.dir/src/Assets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Assets.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gusta\Documents\hld_game\src\Assets.cpp -o CMakeFiles\game.dir\src\Assets.cpp.s

CMakeFiles/game.dir/src/Collision.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Collision.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/Collision.cpp.obj: ../src/Collision.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/src/Collision.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\src\Collision.cpp.obj -c C:\Users\gusta\Documents\hld_game\src\Collision.cpp

CMakeFiles/game.dir/src/Collision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Collision.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gusta\Documents\hld_game\src\Collision.cpp > CMakeFiles\game.dir\src\Collision.cpp.i

CMakeFiles/game.dir/src/Collision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Collision.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gusta\Documents\hld_game\src\Collision.cpp -o CMakeFiles\game.dir\src\Collision.cpp.s

CMakeFiles/game.dir/src/GameManager.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/GameManager.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/src/GameManager.cpp.obj: ../src/GameManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/src/GameManager.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\src\GameManager.cpp.obj -c C:\Users\gusta\Documents\hld_game\src\GameManager.cpp

CMakeFiles/game.dir/src/GameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/GameManager.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gusta\Documents\hld_game\src\GameManager.cpp > CMakeFiles\game.dir\src\GameManager.cpp.i

CMakeFiles/game.dir/src/GameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/GameManager.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gusta\Documents\hld_game\src\GameManager.cpp -o CMakeFiles\game.dir\src\GameManager.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/main.cpp.obj" \
"CMakeFiles/game.dir/src/Game.cpp.obj" \
"CMakeFiles/game.dir/src/TileMap.cpp.obj" \
"CMakeFiles/game.dir/src/Player.cpp.obj" \
"CMakeFiles/game.dir/src/Entity.cpp.obj" \
"CMakeFiles/game.dir/src/Assets.cpp.obj" \
"CMakeFiles/game.dir/src/Collision.cpp.obj" \
"CMakeFiles/game.dir/src/GameManager.cpp.obj"

# External object files for target game
game_EXTERNAL_OBJECTS =

game.exe: CMakeFiles/game.dir/main.cpp.obj
game.exe: CMakeFiles/game.dir/src/Game.cpp.obj
game.exe: CMakeFiles/game.dir/src/TileMap.cpp.obj
game.exe: CMakeFiles/game.dir/src/Player.cpp.obj
game.exe: CMakeFiles/game.dir/src/Entity.cpp.obj
game.exe: CMakeFiles/game.dir/src/Assets.cpp.obj
game.exe: CMakeFiles/game.dir/src/Collision.cpp.obj
game.exe: CMakeFiles/game.dir/src/GameManager.cpp.obj
game.exe: CMakeFiles/game.dir/build.make
game.exe: C:/SFML/lib/libsfml-audio-s-d.a
game.exe: C:/SFML/lib/libsfml-graphics-s-d.a
game.exe: C:/SFML/lib/libsfml-window-s-d.a
game.exe: C:/SFML/lib/libsfml-system-s-d.a
game.exe: C:/SFML/lib/libopenal32.a
game.exe: C:/SFML/lib/libvorbisfile.a
game.exe: C:/SFML/lib/libvorbisenc.a
game.exe: C:/SFML/lib/libvorbis.a
game.exe: C:/SFML/lib/libogg.a
game.exe: C:/SFML/lib/libFLAC.a
game.exe: C:/SFML/lib/libfreetype.a
game.exe: CMakeFiles/game.dir/linklibs.rsp
game.exe: CMakeFiles/game.dir/objects1.rsp
game.exe: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game.exe
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gusta\Documents\hld_game C:\Users\gusta\Documents\hld_game C:\Users\gusta\Documents\hld_game\cmake-build-debug C:\Users\gusta\Documents\hld_game\cmake-build-debug C:\Users\gusta\Documents\hld_game\cmake-build-debug\CMakeFiles\game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

