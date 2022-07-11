#ifndef _NPC_H
#define _NPC_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "GameCharacters/GameCharacter.h"
#include "Item.h"
#include "GameCharacters/Hero.h"
#include "HomewardBone.h"
#include "Pendant.h"
#include "GreenBlossom.h"

class NPC : public GameCharacter
{

public:
    explicit NPC(sf::RenderWindow &window, int type, const sf::Vector2f &pos, int hp = 100, int armor = 0, int cash = 0, float movementSpeed = 0);
    virtual ~NPC() = default;

    // disabling inherited methods
    virtual void receiveDamage(int points) override; // to be unkillable
    virtual void attack(sf::RenderWindow &window) override;
    virtual void movement(bool isInventoryOpen, bool isInteracting) override;

    // to know if hero is close to npcs
    bool closeToHero(Hero &hero);

    // method to let HUD get text pool
    std::vector<std::wstring> getTextPool() const;

    // getter NPC information for HUD purpose
    int getNPCType() const;

private:
    // loading hud textures
    sf::Texture hudTexture;

    // initial tracker pos
    sf::Vector2f trackerPos = {773, 340};

    // for tracking character type
    int type;

    // setting textpool for dialogues depending on character
    std::vector<std::wstring> textPool;

    // inserting dialogue strings
    std::wstring elizabethPool[12] = {L"Bene bene, abbiamo un nuovo ospite. \nDa quale lontana era provieni?", // Elizabeth
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
                                      L"Ma terrò per me la tua storia \nperché una leggenda rimarrà sempre \nuna leggenda…"};
    std::wstring chesterPool[19] = {L"Oh… Fammi indovinare", // chester
                                    L"Sei stato catapultato nel passato di \nun'era differente?",
                                    L"Come avevo sospettato. È successo \nanche a me: siamo entrambi \ndegli estranei "
                                    L"in una terra \nsconosciuta.",
                                    L"Ma almeno adesso, siamo in due.",
                                    L"Beh… Errore mio.",
                                    L"Ma siamo entrambi avventurieri e, per \nquesto, dobbiamo aiutarci a \nvicenda.",
                                    L"Ti è capitato di incontrare Artorias? Il \nleggendario camminatore degli Abissi, \n"
                                    L"secondo gli antichi racconti.",
                                    L"Se ancora non è successo, meglio \ncosì. Se me lo stai chiedendo, sì, è \normai corrotto.",
                                    L"Ahahah ah ahah !",
                                    L"Allora, cosa ti ha fare quel fungo \ngigante? Non che mi interessi. "
                                    L"Non fa \nparte del mio business.",
                                    L"Eheheheh  eheh...",
                                    L"Hm? Non ho molto da dire...",
                                    L"Hai veramente ucciso Artorias?",
                                    L"Ho sentito dire che l'Abisso lo ha \ntrasformato in qualcosa di \nveramente pericoloso.",
                                    L"È assolutamente insidioso.",
                                    L"Ahahahahaha ahha!",
                                    L"Che tu ci creda o no, Oolacile ha \nportato l'Abisso con se.",
                                    L"Ti sei mai chiesto: \nVale veramente la pena?",
                                    L"Eheheheh eheh eh..."};
    std::wstring duskPool[9] = {L"...Mmn...ahh...", // Princess Dusk
                                L"...Aah...mmn...",
                                L"Salve avventuriero. Anche tu da \nqueste parti, non è vero? \nDa quale era provieni?",
                                L"Sai... può sembrare strano, ma...",
                                L"Sono stata assalita da una creatura\n dell'Abisso e ci sarei "
                                L"morta se non \nfosse stato per il Grande \nCavaliere Artorias.",
                                L"In realtà, ho visto poco di quanto è \naccaduto durante lo scontro. \nEro stordita.",
                                L"Nonostante ciò, Artorias emanava \nun'aura particolare... In lui traspirava "
                                L"\nun equilibrio interiore...",
                                L"Che ritrovo tale e quale in te.",
                                L"..."};
};

#endif