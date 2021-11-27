cmake_minimum_required(VERSION 3.0.0)
project(Artorias-Of-The_Abyss VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_NAME ArtoriasOfTheAbyss)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

add_executable(${EXECUTABLE_NAME}   main.cpp
                                    Model/Bonfire.h
                                    Model/Bonfire.cpp
                                    Model/Map.h
                                    Model/Map.cpp
                                    Model/MapElement.h
                                    Model/MapElement.cpp)

if(SFML_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
