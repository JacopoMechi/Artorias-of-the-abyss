#include "HUD.h"

HUD::HUD(sf::RenderWindow &window, Hero &hero, Inventory &inventory) : window(window), hero(hero), inventory(inventory)
{

    // setting font and size of health text
    if (!font.loadFromFile("Fonts/pixelFont.ttf"))
        std::cout << "Error on loading font for hud" << std::endl;
    healthText.setFont(font);
    healthText.setCharacterSize(20);

    // setting font and size of money counter text
    moneyText.setFont(font);
    moneyText.setCharacterSize(20);

    // setting font and size for counting how many consumables are in a slot in quickslot
    itemAmountText.setFont(font);
    itemAmountText.setCharacterSize(10);

    // adding texture for the hud
    if (!hudTexture.loadFromFile("Textures/PlayerHUD.png"))
        std::cout << "Erorr on loading texture for hud" << std::endl;
    // health
    healthSprite.setTexture(hudTexture);
    healthSprite.setTextureRect({healthX, healthY, healthWidth, healthHeight});
    healthSprite.setPosition(healthPosX, healthPosY);
    healthSprite.setScale(healthScale, healthScale);
    // money counter
    moneyCounterSprite.setTexture(hudTexture);
    moneyCounterSprite.setTextureRect({moneyX, moneyY, moneyWidth, moneyHeight});
    moneyCounterSprite.setPosition(moneyPosX, moneyPosY);
    moneyCounterSprite.setScale(moneyScale, moneyScale);
    // quickslot
    quickslotSprite.setTexture(hudTexture);
    quickslotSprite.setTextureRect({qsX, qsY, qsWidth, qsHeight});
    quickslotSprite.setPosition(qsPosX, qsPosY);
    // actions
    actionsSprite.setTexture(hudTexture);
    actionsSprite.setTextureRect({actionX, actionY, actionWidth, actionHeight});
    actionsSprite.setPosition(actionPosX, actionPosY);
    actionsSprite.setScale(actionScale, actionScale);
    // setting obscure button sprite
    obscureSprite.setTexture(hudTexture);
    obscureSprite.setTextureRect({obscureX, obscureY, obscureWidth, obscureHeight});
    obscureSprite.setScale(obscureScale, obscureScale);
    // setting interact box sprite
    boxSprite.setTexture(hudTexture);
    boxSprite.setTextureRect({interactX, interactY, interactWidth, interactHeight});
    boxSprite.setScale(interactScale, interactScale);

    achivementNotify.setTexture(hudTexture);
    achivementNotify.setTextureRect({achivementX, achivementY, achivementWidth, achivementHeight});

    achivementText.setFont(font);
    achivementText.setCharacterSize(20);

    // setting interaction text
    interactText.setFont(font);
    interactText.setCharacterSize(20);
}

HUD::~HUD()
{
    // deleting quickslot
    for (int i = 0; i < 3; i++)
        delete quickSlot[i];
}

void HUD::setTextPool(std::vector<std::wstring> textPool)
{
    this->textPool = textPool;
}

void HUD::draw()
{
    window.draw(quickslotSprite);
    window.draw(actionsSprite);
    // displaying inventory
    inventory.draw();
    // obscure sword attack
    if (hero.getCharacterType() && !hero.getCanAttack())
    {
        this->obscureButton({attackObsPosX, attackObsPosY});
    }
    else if (!hero.getCharacterType() && hero.getStartingSpell())
        this->obscureButton({attackObsPosX, attackObsPosY});
    // obscure dash button when dashes uses reaches 0
    if (hero.getDash() == 0)
        this->obscureButton({dashObsPosX, dashObsPosY});
    // handling aura shield active time and obscuring aura shield sprite
    if (!hero.getAuraReady())
    {
        hero.blockDamage(window);
        this->obscureButton({auraObsPosX, auraObsPosY});
        // obscuring aura shield button if is Mage
    }
    else if (!hero.getCharacterType())
        this->obscureButton({auraObsPosX, auraObsPosY});
    // obscure interact button when you are not close to an NPC
    if (!isAggro)
        this->obscureButton({interactObsPosX, interactObsPosY});
    // drawing quickslots items
    quickSlot[0]->displayItem(firstQsPosX, qsItemPosY, window);
    quickSlot[1]->displayItem(secondQsPosX, qsItemPosY, window);
    quickSlot[2]->displayItem(thirdQsPosX, qsItemPosY, window);
    // obscuring quickslot items when they are 0
    if (quickSlot[0]->getItemCount() == 0)
        this->obscureButton({firstObsQsPosX, firstObsQsPosY});
    if (quickSlot[1]->getItemCount() == 0)
        this->obscureButton({secondObsQsPosX, secondObsQsPosY});
    if (quickSlot[2]->getItemCount() == 0)
        this->obscureButton({thirdObsQsPosX, thirdObsQsPosY});

    // displaying item counts
    this->displayItemCount(quickSlot[0], {firstItemCountPosX, itemCountPosY});
    this->displayItemCount(quickSlot[1], {secondItemCountPosX, itemCountPosY});
    this->displayItemCount(quickSlot[2], {thirdItemCountPosX, itemCountPosY});

    // drawing npc interaction menu
    if (isInteraction)
    {
        // displaying interaction box
        this->drawInteractBox({interactNpcPosX, interactNpcPosY});

        // diplaying text for interaction box
        if (NPCType == 0 || NPCType == 1) // for chester and elizabeth
            this->drawShopText(L"[1] Parla       [2] Acquista\n[Q] Esci", {phrasePosX, phrasePosY});
        else // for the other npcs
            this->drawShopText(L"[1] Parla       [Q] Esci", {phrasePosX, phrasePosY});
    }

    if (isTalking)
    {
        // showing npc's dialogue box
        this->drawInteractBox({dialogueBoxPosX, dialogueBoxPosY});
        // showing dialouge
        if (NPCType == 3) // only Sif has one line of dialogue
            this->drawShopText(L"(Ulula)", {dialogueTextPosX, dialogueTextPosY});
        else
            this->drawShopText(textPool[dialogueTracker], {dialogueTextPosX, dialogueTextPosY});
    }
    if (unlockedAchivement)
    {
        window.draw(achivementNotify);
        window.draw(achivementText);
        achivementShowTime += dt;
        if (achivementShowTime >= achivementShowingTime)
        {
            unlockedAchivement = false;
            achivementShowTime = 0.f;
        }
    }
}

void HUD::displayHealthAndEffects(Hero &hero)
{
    // drawing effects
    quickSlot[0]->displayEffect({hero.getPos().x, hero.getPos().y}, window);
    quickSlot[1]->displayEffect({hero.getPos().x, hero.getPos().y}, window);
    quickSlot[2]->displayEffect({hero.getPos().x, hero.getPos().y}, window);
    // drawing health
    window.draw(healthSprite);
    std::string bar = std::string("HP: ") + std::to_string(hero.getHp()) + std::string("/100");
    healthText.setPosition(healthTextPosX, healthTextPosY);
    healthText.setString(bar);
    window.draw(healthText);
}

void HUD::assignItemInQuickslot(int slot)
{
    quickSlot[slot] = inventory.receiveItem();
}

void HUD::displayMoneyCounter(Hero &hero)
{
    window.draw(moneyCounterSprite);
    std::string counter = std::string("Monete: ") + std::to_string(hero.getCash());
    moneyText.setString(counter);
    moneyText.setPosition(moneyTextPosX, moneyTextPosY);
    window.draw(moneyText);
}

void HUD::obscureButton(sf::Vector2f pos)
{
    obscureSprite.setPosition(pos);
    window.draw(obscureSprite);
}

void HUD::displayItemCount(Item *item, sf::Vector2f pos)
{
    itemAmountText.setString(std::to_wstring(item->getItemCount()));
    itemAmountText.setPosition(pos);
    window.draw(itemAmountText);
}

void HUD::drawInteractBox(sf::Vector2f pos)
{
    boxSprite.setPosition(pos);
    window.draw(boxSprite);
}

void HUD::drawShopText(std::wstring text, sf::Vector2f textPos)
{
    interactText.setPosition(textPos);
    interactText.setString(text);
    window.draw(interactText);
}

void HUD::drawAchivement(const std::string &achivement)
{
    achivementShowTime = 0.0f;
    unlockedAchivement = true;
    achivementText.setString("Your first " + achivement);
    achivementNotify.setScale((achivementText.getGlobalBounds().width + achivementScaleVariation) / achivementNotify.getTextureRect().width, 1);
    achivementNotify.setPosition(middleScreen - achivementNotify.getGlobalBounds().width / 2, achivementPosVariation);
    achivementText.setPosition(achivementNotify.getGlobalBounds().left + achivementNotify.getGlobalBounds().width / 2 - achivementText.getGlobalBounds().width / 2, achivementNotify.getGlobalBounds().top + achivementNotify.getGlobalBounds().height / 2 - achivementText.getGlobalBounds().height / 2);
}

void HUD::gettingDelayTime(float dt)
{
    this->dt = dt;
    quickSlot[0]->effectTime(dt);
    quickSlot[0]->consumableEffectTime(dt, hero, window);
    quickSlot[1]->effectTime(dt);
    quickSlot[1]->consumableEffectTime(dt, hero, window);
    quickSlot[2]->effectTime(dt);
    quickSlot[2]->consumableEffectTime(dt, hero, window);
}

void HUD::useItem(int nItem, Hero &hero)
{
    quickSlot[nItem]->use(hero);
}

bool HUD::getInteraction() const
{
    return isInteraction;
}

void HUD::setInteraction(bool isInteraction)
{
    this->isInteraction = isInteraction;
}

void HUD::setType(int NPCType)
{
    this->NPCType = NPCType;
}

void HUD::setAggro(bool entityInRange, bool NPCInRange)
{
    if (entityInRange || NPCInRange)
        isAggro = true;
    else
        isAggro = false;
}

bool HUD::getIsTalking()
{
    return isTalking;
}

void HUD::setIsTalking(bool isTalking)
{
    this->isTalking = isTalking;
}

void HUD::nextPhrase()
{                                                                    
    dialogueTracker = (dialogueTracker + 1) % (textPool.size() / 2);
}