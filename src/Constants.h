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
const float roomElementHoldTime = 0.1f;


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
//setting pendant's rect
const int pendantX = 498;
const int pendantY = 99;
const int pendantWidth = 23;
const int pendantHeight = 17;
//setting pendant's effect rect
const int pendantEffectX = 525;
const int pendantEffectY = 191;
const int pendantEffectWidth = 25;
const int pendantEffectHeight = 26;


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


//setting flask rect
const int flaskX = 412;
const int flaskY = 2;
const int flaskWidth = 20;
const int flaskHeight = 21;
//setting flask effect rect
const int flaskEffectX = 530;
const int flaskEffectY = 157;
const int flaskEffectWidth = 17;
const int flaskEffectHeight = 22;


//positions for tracker in shop
const int trackedItemX = 541;
const int firstTrackedItemY = 295;
const int secondTrackedItemY = 400;
//rect for shop sprite
const int shopX = 89;
const int shopY = 355;
const int shopWidth = 352;
const int shopHeight = 313;
//position of shop sprite
const int shopPosX = 500;
const int shopPosY = 259;
//setting position for shop's box sprite (to buy items)
const int shopBoxPosX = 1000;
const int shopBoxPosY = 259;
//position of first and second item displayed in shop and their description
const int shopItemX = 559;
const int shopDescriptionX = 646;
const int firstShopItemY = 310;
const int firstShopDescriptionY = 330;
const int secondShopItemY = 420;
const int secondShopDescriptionY = 437;
//position of "Quanti ne vuoi acquistare..." in buying box
const int buyingTextX = 1010;
const int buyingTextY = 275;
//position of error message text when buying items
const int errorMessX = 1010;
const int errorMessY = 310;


//start button click bounds for menu
const int rightStartBound = 1139;
const int leftStartBound = 780;
const int topStartBound = 454;
const int bottomStartBound = 383;
//start/boscure button highlight pos
const float colorStartX = 764.0f;
const float colorStartY = 375.0f;
//hero buttons click bounds for menu
const int topHeroChooseBound = 584; 
const int bottomHeroChooseBound = 495;
//knight button click bounds for menu
const int rightKnightChooseBound = 957;
const int leftKnightChooseBound = 760;
//mage button click bounds for menu
const int rightMageChooseBound = 1155;
const int leftMageChooseBound = 959;
//quit button click bounds for menu
const int rightQuitBound = 1139;
const int leftQuitBound = 780;
const int topQuitBound = 694;
const int bottomQuitBound = 623; 
//to change color of quit button
const float coloredQuitX = 764.0f;
//highlight case
const float highlightQuitY = 615.0f;
//obscure case
const float obscureQuitY = 375.0f;
//bounds for in-game reseume/quit game menu button
const int rightIGMenuBound = 1161;
const int leftIGMenuBound = 771;
//resume case
const int topResumeBound = 543;
const int bottomResumeBound = 453;
//in-game quit case
const int topIGQuitBound = 657;
const int bottomIGQuitBound = 569;
//obscure/highlight resume button position
const float resumeColorPosX = 771.0f;
const float resumeColorPosY = 453.0f;
//obscure/highlight in-game quit button position
const float igQuitColorPosX = 771.0f;
const float igQuitColorPosY = 570.0f;
//for menu sprite rect
const int menuX = 0;
const int menuY = 0;
const int menuWidth = 1920;
const int menuHeight = 1080;
//setting position of knight text 
const float knightTextPosX = 805.0f;
const float knightTextPosY = 543.0f;
//setting position of mage text
const float mageTextPosX = 1015.0f;
const float mageTextPosY = 543.0f;
//setting shadow sprite rect
const int shadowX = 8;
const int shadowY = 825;
const int shadowWidth = 390;
const int shadowHeight = 92;
//setting highlight sprite rect
const int highlightX = 401;
const int highlightY = 827;
const int highlightWidth = 390;
const int highlightHeight = 92;


//setting items' tracker positions inside inventory class
const int invTrackerPosX = 130;
const int firstTrackerPosY = 440;
const int secondTrackerPosY = 505;
const int thirdTrackerPosY = 650;
const int fourthTrackerPosY = 755;

//settings collecibles rects in inventory
//guardian soul
const int guardianSoulX = 396;
const int guardianSoulY = 73;
const int guardianSoulWidth = 18;
const int guardianSoulHeight = 22;
//artorias' soul
const int artoriasX = 440;
const int artoriasY = 73;
const int artoriasWidth = 18;
const int artoriasHeight = 22;
//manus' soul
const int manusX = 396;
const int manusY = 99;
const int manusWidth = 18;
const int manusHeight = 22;
//oolacile's resident
const int residentX = 440;
const int residentY = 96;
const int residentWidth = 27;
const int residentHeight = 26;
//oolacile's sorcerer
const int sorcererX = 497;
const int sorcererY = 47;
const int sorcererWidth = 27;
const int sorcererHeight = 21;
//arotrias' shield
const int aShieldX = 419;
const int aShieldY = 143;
const int aShieldWidth = 22;
const int aShieldHeight =  21;
//stone guardian
const int stoneGuardX = 497;
const int stoneGuardY = 24;
const int stoneGuardWidth = 21;
const int stoneGuardHeight = 21;
//humanity
const int humanityX = 497;
const int humanityY = 0;
const int humanityWidth = 22;
const int humanityHeight = 20;
//for invetory rect
const int invX = 89;
const int invY = 259;
const int invWidth = 352;
const int invHeight = 450;
//for inventory position
const int invPosX = 89;
const int invPosY = 259;
//for inventory scale
const float invScale = 1.5f;
//for description box rect of inventory
const int descrX = 528;
const int descrY = 293;
const int descrWidth = 430;
const int descrHeight = 233;
//for description box position of inventory
const int descrPosX = 700;
const int descrPosY = 315;
//for description box scale of inventory
const float descrScale = 1.3f;
//for tracker sprite rect of inventory
const int trackerX = 116;
const int trackerY = 736;
const int trackerWidth = 266;
const int trackerHeight = 56;
//for tracker sprite scale of inventory
const float trackerScale = 1.5f;
//for assign box sprite rect of inventory
const int boxX = 994;
const int boxY = 318;
const int boxWidth = 289;
const int boxHeight = 98;
//for assign box sprite position of inventory
const int boxPosX = 994;
const int boxPosY = 418;
//for assign box text position in inventory
const int assignTextPosX = 1008;
const int assignTextPosY = 438;
//for tabname text position in invetory
const int tabNamePosX = 245;
const int tabNamePosY = 330;
//to display items and their names in the right position in inventory
const int firstItemPosX = 148;
const int firstItemPosY = 455;
const int firstItemDescrPosX = 235;
const int firstItemDescrPosY = 470;
const int secondItemPosX = 148;
const int secondItemPosY = 560;
const int secondItemDescrPosX = 235;
const int secondItemDescrPosY = 577;
const int thirdItemPosX = 148;
const int thirdItemPosY = 670;
const int thirdItemDescrPosX = 235;
const int thirdItemDescrPosY = 680;
const int fourthItemPosX = 142;
const int fourthItemPosY = 780;
const int fourthItemDescrPosX = 235;
const int fourthItemDescrPosY = 785;
//to draw item in description box
const int itemInDescrPosX = 800;
const int itemInDescrPosY = 460;
//to draw item description text in description box
const int itemDescrPosX = 950;
const int itemDescrPosY = 415;


//achievement showing time amount for hud
const float achievementShowTimeAmount = 3.0f;
//health sprite rect for hud
const int healthX = 1531;
const int healthY = 0;
const int healthWidth = 389;
const int healthHeight = 95;
//health sprite position for hud
const int healthPosX = 1610;
const int healthPosY = 0;
//health sprite scale for hud
const float healthScale = 0.8f;
//health text pos for hud
const int healthTextPosX = 1700;
const int healthTextPosY = 40;
//money counter sprite rect for hud
const int moneyX = 0;
const int moneyY = 986;
const int moneyWidth = 389;
const int moneyHeight = 95;
//money counter sprite position for hud
const int moneyPosX = 0;
const int moneyPosY = 1000;
//money text position for hud
const int moneyTextPosX = 90;
const int moneyTextPosY = 1035;
//money counter sprite scale for hud
const float moneyScale = 0.8f;
//quickslot sprite rect for hud
const int qsX = 810;
const int qsY = 960;
const int qsWidth = 300;
const int qsHeight = 77;
//quickslot sprite pos for hud
const int qsPosX = 810;
const int qsPosY = 960;
//action sprite rect for hud
const int actionX = 1743;
const int actionY = 363;
const int actionWidth = 85;
const int actionHeight = 351;
//action sprite pos or hud
const int actionPosX = 1743;
const int actionPosY = 363;
//action sprite scale for hud
const float actionScale = 0.8f;
//obscure sprite rect for hud
const int obscureX = 1756;
const int obscureY = 733;
const int obscureWidth = 63;
const int obscureHeight = 63;
//obscure sprite scale for hud
const float obscureScale = 0.9f;
//intercat box sprite rect for hud
const int interactX = 994;
const int interactY = 318;
const int interactWidth = 289;
const int interactHeight = 98;
//interact box sprite scale for hud
const float interactScale = 1.7f;
//achivement notify sprite rect for hud
const int achivementX = 994;
const int achivementY = 318;
const int achivementWidth = 289;
const int achivementHeight = 98;
//obscure attack pos
const int attackObsPosX = 1750;
const int attackObsPosY = 375;
//obscure dash pos
const int dashObsPosX = 1750;
const int dashObsPosY = 445;
//obscure aura shield pos
const int auraObsPosX = 1750;
const int auraObsPosY = 508;
//obscure interact pos
const int interactObsPosX = 1750;
const int interactObsPosY = 575;
//drawing quickslot items pos
const int qsItemPosY = 975;
const int firstQsPosX = 850;
const int secondQsPosX = 935;
const int thirdQsPosX = 1020;
//obscuring quickslot items pos
const int firstObsQsPosX = 847;
const int firstObsQsPosY = 971;
const int secondObsQsPosX = 932;
const int secondObsQsPosY = 971;
const int thirdObsQsPosX = 1015;
const int thirdObsQsPosY = 970;
//displaying item counts pos
const int firstItemCountPosX = 890;
const int secondItemCountPosX = 975;
const int thirdItemCountPosX = 1060;
const int itemCountPosY = 980;
//interact box pos for interactions with npcs
const int interactNpcPosX = 805;
const int interactNpcPosY = 295;
//interact dialogues pos for interactions with npcs
const int phrasePosX = 825;
const int phrasePosY = 325;
//dialogue box pos for npcs interactions
const int dialogueBoxPosX = 800;
const int dialogueBoxPosY = 303;
//setting dialogue text in dialogue box for npcs interactions
const int dialogueTextPosX = 820;
const int dialogueTextPosY = 333;
//achivement distance variation
const int achivementScaleVariation = 40;
const int achivementPosVariation = 40;
//to set achivements in the middle of the screen
const int middleScreen = 960;
#endif