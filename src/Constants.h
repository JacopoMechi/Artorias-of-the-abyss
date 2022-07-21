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
#endif