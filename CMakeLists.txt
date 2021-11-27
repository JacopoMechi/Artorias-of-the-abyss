cmake_minimum_required(VERSION 3.0)
project(Artorias-Of-The-Abyss VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

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
                                    Model/Map.h
                                    Model/Map.cpp
                                    Model/MapElement.h
                                    Model/MapElement.cpp
                                    Model/Weapon.h
                                    Model/Weapon)

if(SFML_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
##find_package(SFML 2 COMPONENTS system window graphics network audio REQUIRED)
##target_link_libraries(Artorias_of_the_abyss sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
#[[add_executable(Artorias_of_the_abyss
        origin/Assioma
        Model/Bonfire.cpp
        Model/Bonfire.h
        Model/Catalyst.cpp
        Model/Catalyst.h
        Model/CharacterFactory.cpp
        Model/CharacterFactory.h
        Model/Enemy.cpp
        Model/Enemy.h
        Model/EstusFlask.cpp
        Model/EstusFlask.h
        Model/GameCharacter.cpp
        Model/GameCharacter.h
        Model/Gate.cpp
        Model/Gate.h
        Model/GreenBlossom.cpp
        Model/GreenBlossom.h
        Model/Hero.cpp
        Model/Hero.h
        Model/HomewardBone.cpp
        Model/HomewardBone.h
        Model/Inventory.cpp
        Model/Inventory.h
        Model/Item.cpp
        Model/Item.h
        Model/ItemFactory.cpp
        Model/ItemFactory.h
        Model/Map.cpp
        Model/Map.h
        Model/MapElements.cpp
        Model/MapElements.h
        Model/NPC.cpp
        Model/NPC.h
        Model/Pendant.cpp
        Model/Pendant.h
        Model/Shield.cpp
        Model/Shield.h
        Model/Shop.cpp
        Model/Shop.h
        Model/Sword.cpp
        Model/Sword.h
        Model/Wall.cpp
        Model/Wall.h
        Model/Weapon.cpp)]]
