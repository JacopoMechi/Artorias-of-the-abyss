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
    void drawText(std::wstring text, sf::Vector2f textPos);

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
    Item* merch[3] = {new GreenBlossom(), new HomewardBone(), new Pendant()};

    //setting textpool for dialogues depending on character
    std::vector<std::wstring> textPool;

    //inserting dialogue strings
    std::wstring elizabethPool[12] = {L"Bene bene, abbiamo un nuovo ospite. \nDa quale lontana era provieni?",//Elizabeth
                            L"Ci sono molte cose che vorrei \nchiederti, ma so che non devo.",
                            L"Ahh, capisco. Non sai cosa sia \nsuccesso...",
                            L"Vedrai più avanti. Un antica bestia è \nstata risvegliata "
                            L"e ha generato \nl'Abisso, minacciando di corrompere \ntutta Oolacile.",
                            L"Il cavaliere Artorias è venuto per \nfermare tutto questo, "
                            L"ma un tale eroe \nnon è abbastanza coraggioso da \naffrontare tale potere.",
                            L"Senza dubbio è stato sconfitto, \ntravolto dall'oscurità, "
                            L"ma spero \nancora che la Principessa Dusk venga \nsalvata.",
                            L"Non molto tempo fa, ho avuto un altro \nvisitatore, un essere umano come te, \n"
                            L"da un tempo lontano.",
                            L"Solo che era terribilmente odioso… e \ntemo che sia ancora tra noi.",
                            L"E' calvo e indossa un indumento \nmarrone...",
                            L"Che le fiamme possano guidarti.",
                            L"Ti ringrazio per aver salvato la \nprincipessa Dusk, te ne sarò debitrice \ne "
                            L"ti ricorderò per sempre.",
                            L"Ma terrò per me la tua storia \nperché una leggenda rimarrà sempre \nuna leggenda…"
                            };
    std::wstring sifPool = {L"(Ulula)"};//sif
    std::wstring chesterPool[19] = {L"Oh… Fammi indovinare",//chester
                            L"Sei stato catapultato nel passato di un'era \ndifferente?",
                            L"Come avevo sospettato. È successo anche a \nme: siamo entrambi degli estranei \n"
                            L"in una terra sconosciuta.",
                            L"Ma almeno adesso, siamo in due.",
                            L"Beh… Errore mio.",
                            L"Ma siamo entrambi avventurieri e, per questo, \ndobbiamo aiutarci a vicenda.",
                            L"Ti è capitato di incontrare Artorias? Il \nleggendario camminatore degli Abissi, \n"
                            L"secondo gli antichi racconti.",
                            L"Se ancora non è successo, meglio così. Se \nme lo stai chiedendo, sì, è ormai corrotto.",
                            L"Ahahah ah ahah !",
                            L"Allora, cosa ti ha fare quel fungo gigante? Non \nche mi interessi. "
                            L"Non fa parte del mio business.",
                            L"Eheheheh  eheh...",
                            L"Hm? Non ho molto da dire...",
                            L"Hai veramente ucciso Artorias?",
                            L"Ho sentito dire che l'Abisso lo ha trasformato in \nqualcosa di veramente pericoloso.",
                            L"È assolutamente insidioso.",
                            L"Ahahahahaha ahha!",
                            L"Che tu ci creda o no, Oolacile ha portato \nl'Abisso con se.",
                            L"Ti sei mai chiesto: Vale veramente la pena?",
                            L"Eheheheh eheh eh..."};
    std::wstring duskPool[9] = {L"...Mmn...ahh...",//Princess Dusk
                            L"...Aah...mmn...",
                            L"Salve avventuriero. Anche tu da queste parti, \nnon è vero? Da quale era provieni?",
                            L"Sai... può sembrare strano, ma...",
                            L"Sono stata assalita da una creatura dell'Abisso \ne ci sarei "
                            L"morta se non fosse stato per \nil Grande Cavaliere Artorias.",
                            L"In realtà, ho visto poco di quanto è accaduto \ndurante lo scontro. Ero stordita.",
                            L"Nonostante ciò, Artorias emanava un'aura \nparticolare... In lui traspirava "
                            L"un equilibrio \ninteriore...",
                            L"Che ritrovo tale e quale in te.",
                            L"..."};
};

#endif