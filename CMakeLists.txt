cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 17)
file(COPY media DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB MEDIA media/)
file(COPY MEDIA DESTINATION ${CMAKE_BINARY_DIR})

add_executable(game main.cpp
        src/Game.h src/Game.cpp
        src/TileMap.cpp src/TileMap.h src/Player.cpp src/Player.h)

if(WIN32)
    set(CMAKE_C_COMPILER c:/mingw64/bin/g++)

    set(SMFL_folder c:/SFML)
    target_link_options(game PRIVATE -mwindows)

    set(SFML_ROOT ${SMFL_folder}/lib/cmake/SFML)
    set(SFML_STATIC_LIBRARIES TRUE)
    find_package(SFML COMPONENTS audio graphics window system REQUIRED)

    include_directories(${SMFL_folder}/include)
    target_link_libraries(game sfml-audio sfml-graphics sfml-window sfml-system)
endif()


if (CMAKE_BUILD_TYPE MATCHES Debug)
    message(" ")
    message("CMAKE IN DEBUG MODE")
    message(" ")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message(" ")
    message("CMAKE IN RELEASE MODE")
    message(" ")
endif ()

##Ubuntu just need to install libsfml-dev
if(UNIX AND NOT APPLE)
    include_directories("./libs/SFML-utils")
    include_directories("./libs/SFML-utils/include")
    include_directories("./libs/SFML-utils/extlibs/cpp-utils/include")

    find_package(SFML REQUIRED system window graphics network audio)
    if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(game -lsfml-graphics -lsfml-window -lsfml-system)
    endif()
endif()

if(APPLE)
    # for MacOS X or iOS, watchOS, tvOS (since 3.10.3)
endif()

## Copy dlls to build
#if(WIN32)
#    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
#    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
#    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#endif()