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
#endif