cmake_minimum_required(VERSION 3.0)
project(Artorias-Of-The-Abyss VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_NAME ArtoriasOfTheAbyss)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

include_directories(Model)

add_executable(${EXECUTABLE_NAME}   main.cpp
                                    Model/GameCharacter.h
                                    Model/GameCharacter.cpp
                                    Model/Bonfire.h
                                    Model/Bonfire.cpp
                                    Model/Gate.h
                                    Model/Gate.cpp
                                    Model/Rooms/Room.h
                                    Model/Rooms/Room.cpp
                                    Model/Rooms/RoomElement.h
                                    Model/Rooms/RoomElement.cpp
                                    Model/Menu.h
                                    Model/Menu.cpp
                                    ##Model/Weapon.h
                                    ##Model/Weapon.cpp
                                    Model/Item.cpp
                                    Model/Item.h
                                    Model/HUD.h
                                    Model/HUD.cpp
                                    Model/EstusFlask.h
                                    Model/EstusFlask.cpp
                                    Model/GreenBlossom.h
                                    Model/GreenBlossom.cpp
                                    Model/HomewardBone.h
                                    Model/HomewardBone.cpp
                                    Model/Pendant.h
                                    Model/Pendant.cpp
                                    Model/Hero.h
                                    Model/Hero.cpp
                                    Model/NPC.h
                                    Model/NPC.cpp
                                    Model/Game.h
                                    Model/Game.cpp
                                    Model/Enemy.h 
                                    Model/Enemy.cpp
                                    Model/Rooms/RoomFactory.h
                                    Model/Rooms/RoomFactory.cpp
                                    Model/Rooms/StartRoom.h
                                    Model/Rooms/StartRoom.cpp
                                    Model/Rooms/SecondRoom.h
                                    Model/Rooms/SecondRoom.cpp
                                    Model/Rooms/ThirdRoom.h
                                    Model/Rooms/ThirdRoom.cpp
                                    Model/Rooms/FourthRoom.h
                                    Model/Rooms/FourthRoom.cpp
                                    Model/Rooms/FinalRoom.h
                                    Model/Rooms/FinalRoom.cpp
                                    Model/NullItem.h
                                    Model/NullItem.cpp)

if(SFML_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)