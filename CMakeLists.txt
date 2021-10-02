cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game WIN32 main.cpp Game.h Game.cpp)
target_link_options(game PRIVATE -mwindows)

set(SFML_ROOT c:/SFML/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS audio graphics window system REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(game sfml-audio sfml-graphics sfml-window sfml-system)

## Copy dlls to build
#if(WIN32)
#    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
#    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
#    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#endif()