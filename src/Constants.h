#ifndef _CONSTANTS_H
#define _CONSTANTS_H

//defining constant values for classes

//for hero's initial position and respawn point
const float heroInitPosX = 500.0f;
const float heroInitPosY = 500.0f;

//to change item amount when buying items
const int firstAmount = 1;
const int secondAmount = 5;
const int thirdAmount = 10;

//max item amount for bonfire in characterinputs class
const int maxHomewardBoneAmount = 5;

//to set limits of the map for the character
const int bottomLimit = 30;
const int topLimit = 745;
const int leftLimit = 230;
const int rightLimit = 1550;

//setting weapon animation holding as constant
const float weaponAnimationHoldingTime = 0.13f;

//for sword initial rect
const int firstSwordX = 0;
const int firstSwordY = 162;
const int firstSwordWidth = 21;
const int firstSwordHeight = 40;
//for sword initial damage
const int firstSwordDamage = 5;

//rect for level 2 sword
const int secondSwordX = 0;
const int secondSwordY = 205;
const int secondSwordWidth = 21;
const int secondSwordHeight = 40;
//for level 2 sword damage
const int secondSwordDamage = 10;

//rect for level 3 sword
const int thirdSwordX = 0;
const int thirdSwordY = 254;
const int thirdSwordWidth = 21;
const int thirdSwordHeight = 40;
//for level 3 sword damage
const int thirdSwordDamage = 15;

//to set the sword in right position
const int swordRightPosX = 100;
const int swordRightPosY = -50;

//to set the sword in left position
const int swordLeftPosX = -120;
const int swordLeftPosY = -50;

//for sword scale
const float swordScale = 7.5f;

//for sword n frames
const int maxSwordFrames = 5;

//rect for first catalyst
const int firstCatalystX = 2;
const int firstCatalystY = 332;
const int firstCatalystWidth = 38;
const int firstCatalystHeight = 36;
//rect for first spell
const int firstSpellX = 3;
const int firstSpellY = 299;
const int firstSpellWidth = 33;
const int firstSpellHeight = 20;
//for level 1 catalyst damage
const int firstCatalystDamage = 15;

//rect for second catalyst
const int secondCatalystX = 46;
const int secondCatalystY = 332;
const int secondCatalystWidth = 38;
const int secondCatalystHeight = 36;
//rect for second spell
const int secondSpellX = 46;
const int secondSpellY = 299;
const int secondSpellWidth = 33;
const int secondSpellHeight = 20;
//for level 2 catalyst damage
const int secondCatalystDamage = 20;

//rect for third catalyst
const int thirdCatalystX = 90;
const int thirdCatalystY = 332;
const int thirdCatalystWidth = 38;
const int thirdCatalystHeight = 36;
//rect for third spell
const int thirdSpellX = 90;
const int thirdSpellY = 299;
const int thirdSpellWidth = 33;
const int thirdSpellHeight = 20;
//for level 3 catalyst damage
const int thirdCatalystDamage = 25;

//for catalyst's spawn pos when launching game
const int catalystSpawnPosX = 650;
const int catalystSpawnPosY = 540;

//to set spell's position in the right way
const int ySpellVariation = 40;
//right facing position
const int xRightSpellVariation = 150;
//left facing position
const int xLeftSpellVariation = -150;

//to set catalyst's position in the right way
//right facing position
const int xRightCatalystVariation = 10;
const int yRightCatalystVariation = 40;
//left facing position
const int xLeftCatalystVariation = -20;
const int yLeftCatalystVariation = 40;

//to set spell's bound
const int spellLeftLimit = 0;
const int spellRightLimit = 1920;

//for catalyst scale
const float catalystScale = 3.5f;

//for cataltst n frames
const int maxCatalystFrames = 1;
#endif