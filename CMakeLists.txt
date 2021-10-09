cmake_minimum_required(VERSION 3.17)
project(Artorias_of_the_abyss)

set(CMAKE_CXX_STANDARD 14)

include_directories(Model)

add_executable(Artorias_of_the_abyss
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
        Model/Weapon.cpp
        Model/Weapon.h)
