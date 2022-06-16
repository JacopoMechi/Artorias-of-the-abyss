#include "CharacterInputs.h"

CharacterInputs::CharacterInputs(Inventory &inventory, HUD &hud, Hero &hero, Shop &shop): inventory(inventory), hud(hud), hero(hero), shop(shop){

}

void CharacterInputs::updateInputs(sf::Event keyInput){
    //to stop the character current animation
    if(inventory.getOpen() || hud.getInteraction()){
        hero.setDirX(0.0f);
        hero.setDirY(0.0f);
    }

    //handling inputs

    //handling inputs to move the character
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(!inventory.getOpen() && !hud.getInteraction() && hero.getPos().y > 30)
            hero.setDirY(-1.0f);
        else if(inventory.getOpen() && !hud.getInteraction())//scrolling through items (up)
            inventory.previousItem();
        else if(hud.getInteraction() && shop.getOpen())
            shop.previousItem();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if(!inventory.getOpen() && !hud.getInteraction() && hero.getPos().y < 745)
            hero.setDirY(1.0f);
        else if(inventory.getOpen() && !hud.getInteraction())//scrolling through items (down)
            inventory.nextItem();
        else if(hud.getInteraction() && shop.getOpen())
            shop.nextItem();
    }
    else
        hero.setDirY(0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(!inventory.getOpen() && !hud.getInteraction() && hero.getPos().x > 230)
            hero.setDirX(-1.0f);
        else if(inventory.getOpen() && !hud.getInteraction())
            inventory.previousTab();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(!inventory.getOpen() && !hud.getInteraction() && hero.getPos().x < 1550)
            hero.setDirX(1.0f);
        else if(inventory.getOpen() && !hud.getInteraction())
            inventory.nextTab();
    }
    else
        hero.setDirX(0.0f);

    //opens inventory
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::E){//&& !isInteraction// isInteracting to not open the inventory
        if(!hud.getInteraction()){
            inventory.setOpen(!inventory.getOpen());
            inventory.resetPositions();    
        }
    }
    
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Enter){
        if(inventory.getOpen() && !hud.getInteraction())//opens items descriptions
            inventory.setShowDescription(!inventory.getShowDescription());
        else if(hud.getIsTalking())//scrolling through character's phrases
            hud.nextPhrase();
    }    

    
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1)
        if(isInteraction){// && isBuying //for buying items in shop
            //if isBuying
            /*if(price <= hero.getMoneyAmount()){
                hero.setMoneyAmount(hero.getMoneyAmount() - price);
                if(NPCType == 0)
                        inventory.setItemAmount(2, inventory.receiveItem(2) -> getItemCount() + 1);
                    else if (shopTrackerPos.x == 773 && shopTrackerPos.y == 340) //first item of elizabeth
                        inventory.setItemAmount(1, inventory.receiveItem(1) -> getItemCount() + 1);
                    else //second item of elizabeth
                        inventory.setItemAmount(3, inventory.receiveItem(3) -> getItemCount() + 1);

                printErrorMessage = false;
            }else
                printErrorMessage = true;*/
            hud.setIsTalking(!hud.getIsTalking());
        }else if(inventory.getNTab() == 0 && inventory.getAssign()){
            hud.assignItemInQuickslot(0);
            inventory.setAssign(false);
        }else{
            hud.useItem(0, hero);
        }
    else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2){
        if(isInteraction){// && isBuying //to open shop
            /*if((5*price) <= hero.getMoneyAmount()){
                hero.setMoneyAmount(hero.getMoneyAmount() - (price*5));
                if(NPCType == 0)
                        inventory.setItemAmount(2, inventory.receiveItem(2) -> getItemCount() + 5);
                    else if (shopTrackerPos.x == 773 && shopTrackerPos.y == 340) //first item of elizabeth
                        inventory.setItemAmount(1, inventory.receiveItem(1) -> getItemCount() + 5);
                    else //second item of elizabeth
                        inventory.setItemAmount(3, inventory.receiveItem(3) -> getItemCount() + 5);

                printErrorMessage = false;
            }else
                printErrorMessage = true;*/
            shop.setOpen(!shop.getOpen());
        }else if(inventory.getNTab() == 0 && inventory.getAssign()){
            hud.assignItemInQuickslot(1);
            inventory.setAssign(false);
        }else{
            hud.useItem(1, hero);
        }
    }else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num3){
        if(isInteraction){// && isBuying //for buying items in shop
            //if isBuying
            /*if((10*price) <= hero.getMoneyAmount()){
                hero.setMoneyAmount(hero.getMoneyAmount() - (price*10));
                if(NPCType == 0)
                        inventory.setItemAmount(2, inventory.receiveItem(2) -> getItemCount() + 10);
                    else if (shopTrackerPos.x == 773 && shopTrackerPos.y == 340) //first item of elizabeth
                        inventory.setItemAmount(1, inventory.receiveItem(1) -> getItemCount() + 10);
                    else //second item of elizabeth
                        inventory.setItemAmount(3, inventory.receiveItem(3) -> getItemCount() + 10);

                printErrorMessage = false;
            }else
                printErrorMessage = true;*/
        }else if(inventory.getNTab() == 0 && inventory.getAssign()){
            hud.assignItemInQuickslot(2);
            inventory.setAssign(false);
        }else{
            hud.useItem(2, hero);
        }
    }
    //hero's dash and attack handling
    //for attacking or casting spells
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::F && (hero.getCanAttack() || !hero.getStartingSpell())){
        hero.setStartAnimation(true);
        if(!hero.getCharacterType()){//when hero is a mage
            hero.setSpellDirection();
            hero.setStartingSpell(true);
        }else//when hero is a knight
            hero.setCanAttack(false);
    }
    //for dashes
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Space)
        hero.dash();
    //for raising a shield aura
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::LShift && hero.getCharacterType())
        hero.setAuraReady(false);
    
    //handling inputs for interaction with npc
    if(!inventory.getOpen() && keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Q){
        if(isInRange){//TODO npc must be better
            isInteraction = !isInteraction;//open/close shop
            //for resetting interaction
            hud.setInteraction(!hud.getInteraction());
            hud.setIsTalking(false);
            //resetting shop
            shop.setOpen(false);
        }
    }

    //input for changing quickslot items. It opens a dialogue box
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::U && inventory.getShowDescription() && 
        inventory.getOpen() && !hud.getInteraction()){
        inventory.setAssign(!inventory.getAssign());
    }

    /*//handling inputs for scrolling through items in shop 
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Up && NPCType == 1)
        shopTrackerPos = {768, 336};
    else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Down && NPCType == 1)
        shopTrackerPos = {768, 441};   

    //opening buying interface
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::U && isShop)
        isBuying = !isBuying;    

    //select talking option in interaction
    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1 && isInteraction && !isShop && !isTalking && !isBuying)
        isTalking = !isTalking;    

    //selecting shop option in interaction
    //(only for specifics NPCs)
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2 && !isBuying)
        isShop = !isShop;
    }*/
}

void CharacterInputs::setHeroNPCAggro(bool status){
    isInRange = status;
}

void CharacterInputs::setInteraction(bool interaction){
    isInteraction = interaction;
}