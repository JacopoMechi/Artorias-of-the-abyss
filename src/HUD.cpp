#include "HUD.h"

HUD::HUD(sf::RenderWindow &window, Hero &hero, Inventory &inventory) : window(window), hero(hero), inventory(inventory)
{

    // setting font and size of health text
    if (!font.loadFromFile("../pixelFont.ttf"))
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
    if (!hudTexture.loadFromFile("../Textures/PlayerHUD.png"))
        std::cout << "Erorr on loading texture for hud" << std::endl;
    // health
    healthSprite.setTexture(hudTexture);
    healthSprite.setTextureRect({1531, 0, 389, 95});
    healthSprite.setPosition(1610, 0);
    healthSprite.setScale(0.8f, 0.8f);
    // money counter
    moneyCounterSprite.setTexture(hudTexture);
    moneyCounterSprite.setTextureRect({0, 986, 389, 95});
    moneyCounterSprite.setPosition(0, 1000);
    moneyCounterSprite.setScale(0.8f, 0.8f);
    // quickslot
    quickslotSprite.setTexture(hudTexture);
    quickslotSprite.setTextureRect({810, 960, 300, 77});
    quickslotSprite.setPosition(810, 960);
    quickslotSprite.setScale(1.0f, 1.0f);
    // actions
    actionsSprite.setTexture(hudTexture);
    actionsSprite.setTextureRect({1743, 363, 85, 351});
    actionsSprite.setPosition(1743, 363);
    actionsSprite.setScale(0.8f, 0.8f);
    // setting obscure button sprite
    obscureSprite.setTexture(hudTexture);
    obscureSprite.setTextureRect({1756, 733, 63, 63});
    obscureSprite.setScale(0.9f, 0.9f);
    // setting interact box sprite
    boxSprite.setTexture(hudTexture);
    boxSprite.setTextureRect({994, 318, 289, 98});
    boxSprite.setScale(1.7f, 1.7f);

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
    // obscure and starting sword attack
    if (hero.getCharacterType())
    {
        if (hero.getStartAnimation())
            hero.attack();
        if (!hero.getCanAttack())
            this->obscureButton({1750, 375});
    }
    else
    {
        // obscure and starting spell attack
        if (hero.getStartAnimation()) // for showing the mage's staff
            hero.attack();
        if (hero.getStartingSpell())
        { // displaying spell and obscuring attack icon
            this->obscureButton({1750, 375});
            hero.castSpell();
        }
    }
    // obscure dash button when dashes uses reaches 0
    if (hero.getDash() == 0)
        this->obscureButton({1750, 445});
    // handling aura shield active time and obscuring aura shield sprite
    if (!hero.getAuraReady())
    {
        hero.blockDamage();
        this->obscureButton({1750, 508});
        // obscuring aura shield button if is Mage
    }
    else if (!hero.getCharacterType())
        this->obscureButton({1750, 508});
    // obscure interact button when you are not close to an NPC
    if (!isAggro)
        this->obscureButton({1750, 575});
    // drawing quickslots items
    quickSlot[0]->displayItem(850, 975, window);
    quickSlot[1]->displayItem(935, 975, window);
    quickSlot[2]->displayItem(1020, 975, window);
    // obscuring quickslot items when they are 0
    if (quickSlot[0]->getItemCount() == 0)
        this->obscureButton({847, 971});
    if (quickSlot[1]->getItemCount() == 0)
        this->obscureButton({932, 971});
    if (quickSlot[2]->getItemCount() == 0)
        this->obscureButton({1015, 970});

    // displaying item counts
    this->displayItemCount(quickSlot[0], {890, 980});
    this->displayItemCount(quickSlot[1], {975, 980});
    this->displayItemCount(quickSlot[2], {1060, 980});

    // drawing npc interaction menu
    if (isInteraction)
    {
        // displaying interaction box
        this->drawInteractBox({805, 295});

        // diplaying text for interaction box
        if (NPCType == 0 || NPCType == 1) // for chester and elizabeth
            this->drawShopText(L"[1] Parla       [2] Acquista\n[Q] Esci", {825, 325});
        else // for the other npcs
            this->drawShopText(L"[1] Parla       [Q] Esci", {825, 325});
    }

    if (isTalking)
    { // TODO hud must acquire npc's text pool
        // showing npc's dialogue box
        this->drawInteractBox({800, 303});
        // showing dialouge
        if (NPCType == 3) // only Sif has one line of dialogue
            this->drawShopText(L"(Ulula)", {820, 333});
        else
            this->drawShopText(textPool[dialogueTracker], {820, 333});
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
    healthText.setPosition(1700, 40);
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
    std::string counter = std::string("Monete: ") + std::to_string(hero.getMoneyAmount());
    moneyText.setString(counter);
    moneyText.setPosition(90, 1035);
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

void HUD::gettingDelayTime(float dt)
{
    quickSlot[0]->effectTime(dt);
    quickSlot[1]->effectTime(dt);
    quickSlot[2]->effectTime(dt);
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

void HUD::setAggro(bool isAggro)
{
    this->isAggro = isAggro;
}

// TODO for the moment
bool HUD::getIsTalking()
{
    return isTalking;
}

void HUD::setIsTalking(bool isTalking)
{
    this->isTalking = isTalking;
}

// TODO for the moment
void HUD::nextPhrase()
{                                                                    // TODO LATER adjust dialogue depending on situations (like changing chester's text pool when Artorias is killed)
    dialogueTracker = (dialogueTracker + 1) % (textPool.size() / 2); // FIXME why /2?
}