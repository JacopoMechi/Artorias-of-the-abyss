#ifndef _NPC_H
#define _NPC_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "GameCharacter.h"
#include "Item.h"
#include "Hero.h"
#include "HomewardBone.h"
#include "Pendant.h"
#include "GreenBlossom.h"


class NPC: public GameCharacter {

public:

    NPC(sf::RenderWindow &window, int type, const sf::Vector2f& pos, int hp = 100, int armor = 0, int cash = 0, float movementSpeed = 0);
    ~NPC();

    void receiveDamage() = delete;//to be unkillable

    void interact(Hero &hero);

    //handling inputs
    void updateInputs(sf::Event keyInput);

    //drawing text for all menus 
    void drawText(std::string text, sf::Vector2f textPos);

    //drawing interaction box
    void drawInteractBox(sf::Vector2f pos);

    //drawing shop box
    void drawShop(Item* item1, Item* item2);
    void drawShop(Item* item1);

    //drawing tracker for selecting an item to buy
    void drawTracker(sf::Vector2f pos);

    //to stop character moving while interacting with an NPC
    bool getIsInteraction();

    //to set aggro for hud
    void setAggro(bool aggro);
    bool getAggro();

private:

    //getting window from main
    sf::RenderWindow &window;

    //loading hud textures
    sf::Texture hudTexture;

    //shop sprite declaration
    sf::Sprite shopSprite;

    //interactions sprite declaration
    sf::Sprite interactionBoxSprite;

    //text for interactions
    sf::Text interactText;
    sf::Font interactFont;

    //tracker sprite
    sf::Sprite trackerSprite;

    //initial tracker pos
    sf::Vector2f trackerPos = {773, 340};

    //switch for open shop
    bool isInteraction = false;

    //switch for interaction menu
    bool aggro = false;

    //switch for shop menu
    bool isShop = false;

    //switch for talking
    bool isTalking = false;

    //for tracking character type
    int type;

    //for tracking phrase number
    int dialogueTracker = 0;

    //items selling list
    Item* merch[3] = {new GreenBlossom(), new HomewardBone(), new Pendant()};//TODO correct array declaration in other classes

    //setting textpool for dialogues depending on character
    std::vector<std::string> textPool;

    //inserting dialogue strings
    std::string elizabethPool[12] = {"Bene bene, abbiamo un nuovo ospite. \nDa quale lontana era provieni?",//Elizabeth
                            "Ci sono molte cose che vorrei chiederti, \nma so che non devo.",
                            "Ahh, capisco. Non sai cosa sia successo...",
                            "Vedrai più avanti. Un antica bestia è \nstata risvegliata "
                            "e ha generato l'Abisso, \nminacciando di corrompere tutta Oolacile.",
                            "Il cavaliere Artorias è venuto per fermare \ntutto questo, "
                            "ma un tale eroe non è \nabbastanza coraggioso da affrontare \ntale potere.",
                            "Senza dubbio è stato sconfitto, travolto \ndall'oscurità, "
                            "ma spero ancora \nche la Principessa Dusk venga salvata.",
                            "Non molto tempo fa, ho avuto un altro \nvisitatore, un essere umano come te, \n"
                            "da un tempo lontano.",
                            "Solo che era terribilmente odioso… e \ntemo che sia ancora tra noi.",
                            "E' calvo e indossa un indumento marrone...",
                            "Che le fiamme possano guidarti.",
                            "Ti ringrazio per aver salvato la \nprincipessa Dusk, te ne sarò debitrice \ne "
                            "ti ricorderò per sempre.",
                            "Ma terrò per me la tua storia \nperché una leggenda rimarrà sempre \nuna leggenda…"
                            };
    std::string sifPool = {"(Ulula)"};//sif
    std::string chesterPool[19] = {"Oh… Fammi indovinare",//chester
                            "Sei stato catapultato nel passato di un'era \ndifferente?",
                            "Come avevo sospettato. È successo anche a \nme: siamo entrambi degli estranei \n"
                            "in una terra sconosciuta.",
                            "Ma almeno adesso, siamo in due.",
                            "Beh… Errore mio.",
                            "Ma siamo entrambi avventurieri e, per questo, \ndobbiamo aiutarci a vicenda.",
                            "Ti è capitato di incontrare Artorias? Il \nleggendario camminatore degli Abissi, \n"
                            "secondo gli antichi racconti.",
                            "Se ancora non è successo, meglio così. Se \nme lo stai chiedendo, sì, è ormai corrotto.",
                            "Ahahah ah ahah !",
                            "Allora, cosa ti ha fare quel fungo gigante? Non \nche mi interessi. "
                            "Non fa parte del mio business.",
                            "Eheheheh  eheh...",
                            "Hm? Non ho molto da dire...",
                            "Hai veramente ucciso Artorias?",
                            "Ho sentito dire che l'Abisso lo ha trasformato in \nqualcosa di veramente pericoloso.",
                            "È assolutamente insidioso.",
                            "Ahahahahaha ahha!",
                            "Che tu ci creda o no, Oolacile ha portato \nl'Abisso con se.",
                            "Ti sei mai chiesto: Vale veramente la pena?",
                            "Eheheheh eheh eh..."};
    std::string duskPool[9] = {"...Mmn...ahh...",//Princess Dusk
                            "...Aah...mmn...",
                            "Salve avventuriero. Anche tu da queste parti, \nnon è vero? Da quale era provieni?",
                            "Sai... può sembrare strano, ma...",
                            "Sono stata assalita da una creatura dell'Abisso \ne ci sarei "
                            "morta se non fosse stato per \nil Grande Cavaliere Artorias.",
                            "In realtà, ho visto poco di quanto è accaduto \ndurante lo scontro. Ero stordita.",
                            "Nonostante ciò, Artorias emanava un'aura \nparticolare... In lui traspirava "
                            "un equilibrio \ninteriore...",
                            "Che ritrovo tale e quale in te.",
                            "..."};
};

#endif