#include "CharacterInputs.h"

CharacterInputs::CharacterInputs(Inventory &inventory, HUD &hud, Hero &hero): inventory(inventory), hud(hud), hero(hero){

}

void CharacterInputs::updateInputs(sf::Event keyInput){
    //handling inputs
    //opens inventory
    if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::E){//&& !isInteraction// isInteracting to not open the inventory
        inventory.setInvOpen(!inventory.getInvOpen());
        inventory.resetPositions();    
    }
    if(inventory.getInvOpen()){
        //stop the character from moving
        hero.setDirX(0.0f);
        hero.setDirY(0.0f);
        //opens items descriptions
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Enter)
            inventory.setShowDescription(!inventory.getShowDescription());


        //inputs for scrolling in inventory
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Up)//&&!quickAssign//when quickAssign is open, it will not scroll
            //scrolling through items (up)
            inventory.previousItem();

        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Down)//&&!quickAssign//when quickAssign is open, it will not scroll
            //scrolling through items (down)
            inventory.nextItem();


        //inputs for switching tabs
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Right)//&&!quickAssign
            inventory.nextTab();

        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Left)//&&!quickAssign
            inventory.previousTab();


        //input for changing quickslot items. It opens a dialogue box
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::U && inventory.getShowDescription()){
            inventory.setAssign(!inventory.getAssign());
        }        

        //handling slot assign
        if(inventory.getNTab() == 0 && inventory.getAssign()){
            //std::cout << descriptionScroll << std::endl;
            if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1){
                hud.assignItemInQuickslot(0);
                inventory.setAssign(false);
            }else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2){
                hud.assignItemInQuickslot(1);
                inventory.setAssign(false);
            }else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num3){
                hud.assignItemInQuickslot(2);
                inventory.setAssign(false);
            }
        }
    }else{
        //handling inputs to move the character
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && hero.getPos().y > 30){
            hero.setDirY(-1.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPos().y < 745){
            hero.setDirY(1.0f);
        }
        else
            hero.setDirY(0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPos().x > 230){
            hero.setDirX(-1.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPos().x < 1550){
            hero.setDirX(1.0f);
        }
        else
            hero.setDirX(0.0f);
        
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num1)
            if(isInteraction && isBuying){//for buying items in shop
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
            }else{
                //quickSlot[0] -> use(hero);
            }
        else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num2){
            if(isInteraction && isBuying){//for buying items in shop
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
            }else{
                //quickSlot[1] -> use(hero);
            }
        }else if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Num3){
            if(isInteraction && isBuying){//for buying items in shop
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
            }else{
                //quickSlot[2] -> use(hero);
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
    /* if(isInRange){//TODO npc must be better
        if(!inventory.getInvOpen() && keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Q){
            isInteraction = !isInteraction;//open/close shop
            //for resetting interaction
            isShop = false;
            isTalking = false;
        }
    }

    if(isTalking){//TODO LATER adjust dialogue depending on situations (like changing chester's text pool when Artorias is killed)
        //scrolling through character's phrases
        if(keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Enter)
            dialogueTracker = (dialogueTracker+1)%(textPool.size()/2);//FIXME why /2?
    }

    //handling inputs for scrolling through items in shop 
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

void CharacterInputs::setHeroNPCAggro(int status){
    isInRange = status;
}