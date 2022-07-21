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

//min distance between hero and bonfire to interact
const int minBonfireDist = 190;

//setting bonfire scale
const float bonfireScale = 0.7f;

//first bonfire rect
const int firstBonfireX = 1;
const int firstBonfireY = 520;
const int firstBonfireWidth = 184;
const int firstBonfireHeight = 297;

//second bonfire rect
const int secondBonfireX = 191;
const int secondBonfireY = 540;
const int secondBonfireWidth = 203;
const int secondBonfireHeight = 277;

//third bonfire rect
const int thirdBonfireX = 405;
const int thirdBonfireY = 521;
const int thirdBonfireWidth = 176;
const int thirdBonfireHeight = 293;

//animation holding time for room element class
const float roomElementHoldTime = 0.01f;


//for setting npc spawning position
const float npcSpawnX = 322.0f;
const float npcSpawnY = 224.0f;

//for setting enemy spawning position
const float enemySpawnX = 900.0f;
const float enemySpawnY = 200.0f;

//for setting bonfire spawning poisition
const float bonfireSpawnX = 900.0f;
const float bonfireSpawnY = 400.0f;

//to change hero level by setting level floors
const int secondFloor = 3;
const int thirdFloor = 7;

//room sprite rect
const int roomX = 0;
const int roomY = 0;
const int roomWidth = 1920;
const int roomHeight = 1080;


//sprite rect for open door
const int doorX = 140;
const int doorY = 308;
const int doorWidth = 120;
const int doorHeight = 195;

//position for right ad left gate
const float gateY = 425.0f;
//left case
const float leftGateX = 158.0f;
//right case
const float rightGateX = 1626.0f;


//setting pendant immune time
const float pendantImmuneTimeAmount = 3.0f;
//setting pendant scale
const float pendantScale = 2.1f;
//setting pendant visual effect scale
const float pendantEffectScale = 6.5f;
//setting pendant effect display distance from hero pos
const int xPendantEffectVariation = 30;


//setting item's scale
const float itemScale = 2.5f;
//setting item effect's scale
const float itemEffectScale = 7.0f;
//setting time effect holdtime
const float itemHoldTimeAmount = 2.0f;


//setting homeward bone's rect
const int boneX = 497;
const int boneY = 71;
const int boneWidth = 23;
const int boneHeight = 22;
//setting homeward bone's scale
const float boneScale = 2.2f;


//setting green blossom's rect
const int blossomX = 453;
const int blossomY = 2;
const int blossomWidth = 20;
const int blossomHeight = 20;
//setting green blossom effect's rect
const int blossomEffectX = 530;
const int blossomEffectY = 124;
const int blossomEffectWidth = 17;
const int blossomEffectHeight = 22;
//setting green blossom cooldown
const float blossomCooldown = 1.0f;
//setting effect time of blossom
const float blossomEffectTime = 5.0f;
//setting green blossom's arrow up hud effect rect
const int arrowUpX = 554;
const int arrowUpY = 0;
const int arrowUpWidth = 43;
const int arrowUpHeight = 63;
//setting green blossom's arrow up hud effect pos
const int arrowUpPosX = 1700;
const int arrowUpPosY = 445;
//setting green blossom's arrow up hud effect scale
const float arrowUpScale = 0.8f;
#endif