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

    //TODO for later
    bool getIsInteraction();

private:

    //getting window from main
    sf::RenderWindow &window;

    //loading hud textures
    sf::Texture hudTexture;

    //shop sprite declaration
    sf::Sprite shopSprite;

    //interaction sprite declaration
    sf::Sprite interactionBoxSprite;

    //text for "press Q to interact" box 
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

    //items selling list
    Item* merch[3] = {new GreenBlossom(), new HomewardBone(), new Pendant()};//TODO correct array declaration in other classes

    //inserting dialogue strings
     std::string elizabethPool[] = {"Bene bene, abbiamo un nuovo ospite. Da quale lontana era provieni?",//Elizabeth
                            "Ci sono molte cose che vorrei chiederti, ma so che non devo.",
                            "Ahh, capisco. Non sai cosa sia successo...",
                            "Vedrai più avanti. Un antica bestia è stata risvegliata "
                            "e ha generato l’Abisso, minacciando di corrompere tutta Oolacile.",
                            "Il cavaliere Artorias è venuto per fermare tutto questo, "
                            "ma un tale eroe non è abbastanza coraggioso da affrontare tale potere.",
                            "Senza dubbio è stato sconfitto, travolto dall’oscurità, "
                            "ma spero ancora che la Principessa Dusk venga salvata.",
                            "Non molto tempo fa, ho avuto un altro visitatore, un essere umano come te, "
                            "da un tempo lontano.",
                            "Solo che era terribilmente odioso… e tempo che sia ancora tra noi.",
                            "Indossava un cappello e un lungo cappotto nero…",
                            "Che le fiamme possano guidarti.",
                            "Ti ringrazio per aver salvato la principessa Dusk, te ne sarò debitrice e "
                            "ti ricorderò per sempre.",
                            "Ma terrò per me la tua storia perché una leggenda rimarrà sempre una leggenda…",
                            };
    std::string sifPool = {"(Ulula)"};//sif
    std::string chesterPool[] = {"Oh… Fammi indovinare",//chester
                            "Sei stato catapultato nel passato di un’era differente?",
                            "Come avevo sospettato. È successo anche a me: siamo entrambi degli estranea "
                            "in una terra sconosciuta.",
                            "Ma almeno adesso, siamo in due.",
                            "Beh… Errore mio.",
                            "Ma siamo entrambi avventurieri e, per questo, dobbiamo aiutarci a vicenda.",
                            "Ti è capitato di incontrare Artorias? Il leggendario camminatore degli Abissi, "
                            "secondo gli antichi racconti.",
                            "Se ancora non è successo, meglio così. Se me lo stai chiedendo, sì, è ormai corrotto.",
                            "Ahahah ah ahah !",
                            "Allora, cosa ti ha fare quel fungo gigante? Non che mi interessi. "
                            "Non fa parte del mio business.",
                            "Eheheheh  eheh…",
                            "Hm? Non ho molto da dire…",
                            "Hai veramente ucciso Artorias?",
                            "Ho sentito dire che l’Abisso lo ha trasformato in qualcosa di veramente pericoloso.",
                            "È assolutamente insidioso.",
                            "Ahahahahaha ahha!",
                            "Che tu ci creda o no, Oolacile ha portato l’Abisso con se.",
                            "Ti sei mai chiesto: Vale veramente la pena?",
                            "Eheheheh eheh eh…"};
    std::string duskPool[] = {"...Mmn...ahh…",//Princess Dusk
                            "…Aah...mmn…",
                            "Salve avventuriero. Anche tu da queste parti, non è vero? Da quale era provieni?",
                            "Sai… può sembrare strano, ma…",
                            "Sono stata assalita da una creatura dell’Abisso e ci sarei "
                            "morta se non fosse stato per il Grande Cavaliere Artorias.",
                            "In realtà, ho visto poco di quanto è accaduto durante lo scontro. Ero stordita.",
                            "Nonostante ciò, Artorias emanava un’aura particolare… In lui traspirava "
                            "un equilibrio interiore…",
                            "Che ritrovo tale e quale in te.",
                            "..."};
};

#endif