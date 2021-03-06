#include "CharacterInputs.h"

CharacterInputs::CharacterInputs(Inventory &inventory, HUD &hud, Hero &hero, Shop &shop) : inventory(inventory), hud(hud), hero(hero), shop(shop)
{
}

void CharacterInputs::updateInputs(sf::Event keyInput)
{
    // to stop character's current animation
    if (inventory.getOpen() || hud.getInteraction())
    {
        hero.setDirX(0.0f);
        hero.setDirY(0.0f);
    }

    // handling inputs

    // handling inputs to scroll through invetory/shop items
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (inventory.getOpen() && !hud.getInteraction()) // scrolling through items (up)
            inventory.previousItem();
        else if (hud.getInteraction() && shop.getOpen())
            shop.previousItem();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (inventory.getOpen() && !hud.getInteraction()) // scrolling through items (down)
            inventory.nextItem();
        else if (hud.getInteraction() && shop.getOpen())
            shop.nextItem();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && inventory.getOpen() && !hud.getInteraction())
    {
        inventory.previousTab();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && inventory.getOpen() && !hud.getInteraction())
    {
        inventory.nextTab();
    }

    // opens inventory
    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::E)
    { // isInteracting to not open the inventory
        if (!hud.getInteraction())
        {
            inventory.setOpen(!inventory.getOpen());
            inventory.resetPositions();
        }
    }

    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Enter)
    {
        if (inventory.getOpen() && !hud.getInteraction()) // opens items descriptions
            inventory.setShowDescription(!inventory.getShowDescription());
        else if (hud.getIsTalking()) // scrolling through character's phrases
            hud.nextPhrase();
    }

    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1)
    {
        if (hud.getInteraction() && !shop.getOpen()) // to talk with npc
            hud.setIsTalking(!hud.getIsTalking());
        else if (hud.getInteraction() && shop.getIsBuying()) // to buy 1 of the selected item in shop
            shop.purchaseItem(hero, firstAmount, inventory.receiveItem(shop.getNItem()));
        else if (inventory.getNTab() == 0 && inventory.getAssign())
        { // to assign item in first slot of quickslot
            hud.assignItemInQuickslot(0);
            inventory.setAssign(false);
        }
        else if (!inventory.getOpen() && !hud.getInteraction()) // to use the first item in quickslot
            hud.useItem(0, hero);
    }
    else if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2)
    {
        if (hud.getInteraction() && (shop.getNPCType() == 1 || shop.getNPCType() == 0) && !shop.getIsBuying()) // to open shop
            shop.setOpen(!shop.getOpen());
        else if (hud.getInteraction() && shop.getIsBuying()) // to buy 5 of the selected item in shop
            shop.purchaseItem(hero, secondAmount, inventory.receiveItem(shop.getNItem()));
        else if (inventory.getNTab() == 0 && inventory.getAssign())
        { // to assign item in second slot of quickslot
            hud.assignItemInQuickslot(1);
            inventory.setAssign(false);
        }
        else if (!inventory.getOpen() && !hud.getInteraction()) // to use the second item in quickslot
            hud.useItem(1, hero);
    }
    else if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num3)
    {
        if (hud.getInteraction() && shop.getIsBuying()) // to buy 10 of the selected tem in shop
            shop.purchaseItem(hero, thirdAmount, inventory.receiveItem(shop.getNItem()));
        else if (inventory.getNTab() == 0 && inventory.getAssign())
        { // to assign item in third slot of quickslot
            hud.assignItemInQuickslot(2);
            inventory.setAssign(false);
        }
        else if (!inventory.getOpen() && !hud.getInteraction()) // to use third item in quickslot
            hud.useItem(2, hero);
    }
    // hero's dash and attack handling
    // for attacking or casting spells
    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::F && (hero.getCanAttack() || !hero.getStartingSpell()))
    {
        hero.getWeapon()->setStartAnimation(true);
        hero.setCanAttack(false);
    }
    // for dashes
    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Space)
        hero.dash();
    // for raising a shield aura
    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::LShift && hero.getCharacterType())
        hero.setAuraReady(false);

    // handling inputs for interaction with npc
    if (!inventory.getOpen() && keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Q)
    {
        if (NPCInRange)
        {
            // to open/close shop
            hud.setInteraction(!hud.getInteraction());
            hud.setIsTalking(false);
            // resetting shop
            shop.setOpen(false);
        }
    }

    // input for changing quickslot items. It opens a dialogue box
    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::U)
    {
        if (inventory.getShowDescription() && inventory.getOpen() && !hud.getInteraction())
            inventory.setAssign(!inventory.getAssign());
        else if (shop.getOpen())
            shop.setIsBuying(!shop.getIsBuying());
    }
}

int CharacterInputs::updateBonefireInputs(sf::Event keyInput, int level)
{
    if (entityInRange && !inventory.getOpen() && keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Q)
    {

        hero.setHp(100);
        inventory.setItemAmount(0, maxHomewardBoneAmount - inventory.receiveItem(0)->getItemCount());
        // changing spawn point of hero close to bonfire
        hero.setSpawnPoint({element->getPos().x + element->getSize().x, element->getPos().y});
        respawnLevel = level;
        if (achivementObserver != nullptr)
            achivementObserver->update("Bonefire");
    }
    return respawnLevel;
}

// handling hero's movement
void CharacterInputs::moveHero(sf::Event keyInput)
{
    if (!inventory.getOpen() && !hud.getInteraction())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && hero.getPos().y > bottomLimit)
        {
            hero.setDirY(-1.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPos().y < topLimit)
        {
            hero.setDirY(1.0f);
        }
        else
            hero.setDirY(0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPos().x > leftLimit)
        {
            hero.setDirX(-1.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPos().x < rightLimit)
        {
            hero.setDirX(1.0f);
        }
        else
            hero.setDirX(0);

        // handling collisions
        this->solveElementCollision();
        this->solveNPCCollision();
    }
}

void CharacterInputs::setHeroEntityAggro(bool NPCStatus, bool entityStatus)
{
    entityInRange = entityStatus;
    NPCInRange = NPCStatus;
}

void CharacterInputs::setEntityCollision(GameCharacter *entityCollision)
{
    this->entityCollision = entityCollision;
}

void CharacterInputs::attach(AchivementsObserver &achivementsObserver)
{
    this->achivementObserver = std::unique_ptr<AchivementsObserver>(&achivementsObserver);
}

void CharacterInputs::setEntityCollision(RoomElement *roomElement)
{
    this->element = roomElement;
}

void CharacterInputs::deleteEntity()
{
    if (element != nullptr)
        element = nullptr;
}

void CharacterInputs::deleteNPC()
{
    if (entityCollision != nullptr)
        entityCollision = nullptr;
}

void CharacterInputs::solveNPCCollision()
{
    if (entityCollision != nullptr)
    {
        float dist1 = entityCollision->getPos().x - (hero.getPos().x + hero.getSize().x);
        float dist2 = (entityCollision->getPos().x + entityCollision->getSize().x) - hero.getPos().x;
        float dist3 = entityCollision->getPos().y - (hero.getPos().y + hero.getSize().y);
        float dist4 = (entityCollision->getPos().y + entityCollision->getSize().y) - hero.getPos().y;
        if (dist1 < 0 && dist2 > 0 && dist3 < 0 && dist4 > 0)
        {
            float d1 = std::abs(dist1) < std::abs(dist2) ? dist1 : dist2;
            float d2 = std::abs(dist3) < std::abs(dist4) ? dist3 : dist4;
            if (std::abs(d1) < std::abs(d2))
            {
                hero.setPos(hero.getPos() + sf::Vector2f{d1, 0});
            }
            else
            {
                hero.setPos(hero.getPos() + sf::Vector2f{0, d2});
            }
        }
    }
}

void CharacterInputs::solveElementCollision()
{
    if (element != 0)
    { // checking if map element exists
        float dist1 = element->getPos().x - (hero.getPos().x + hero.getSize().x);
        float dist2 = (element->getPos().x + element->getSize().x) - hero.getPos().x;
        float dist3 = element->getPos().y - (hero.getPos().y + hero.getSize().y);
        float dist4 = (element->getPos().y + element->getSize().y) - hero.getPos().y;
        if (dist1 < 0 && dist2 > 0 && dist3 < 0 && dist4 > 0)
        {
            float d1 = std::abs(dist1) < std::abs(dist2) ? dist1 : dist2;
            float d2 = std::abs(dist3) < std::abs(dist4) ? dist3 : dist4;
            if (std::abs(d1) < std::abs(d2))
            {
                hero.setPos(hero.getPos() + sf::Vector2f{d1, 0});
            }
            else
            {
                hero.setPos(hero.getPos() + sf::Vector2f{0, d2});
            }
        }
    }
}