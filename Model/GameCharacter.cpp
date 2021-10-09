#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int a, int c, int d, int s): HP(hp), armor(a), cash(c), dashCount(d), speed(s),
    weapon(nullptr), leftWeapon(nullptr){
}

GameCharacter::~GameCharacter() {
    if (weapon != nullptr)
        delete weapon;
    if (leftWeapon != nullptr)
        delete leftWeapon;
}

int GameCharacter::getHp() const{
    return HP;
}

void GameCharacter::setHp(int hp) {
    this->HP = hp;
}

int GameCharacter::getArmor() const{
    return armor;
}

void GameCharacter::setArmor(int armor) {
    this->armor = armor;
}

int GameCharacter::getCash() const{
    return cash;
}

void GameCharacter::setCash( int cash) {
    this->cash = cash;
}

int GameCharacter::getDash() const{
    return dashCount;
}

void GameCharacter::setDash(int dashCount) {
    this->dashCount = dashCount;
}

int GameCharacter::getMovementSpeed() const{
    return speed;
}

void GameCharacter::setMovementSpeed(int speed) {
    this->speed = speed;
}

Weapon* GameCharacter::getWeapon() {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::receiveDamage() {

}

Weapon* GameCharacter::getShield() {
    return leftWeapon;
}

void GameCharacter::setShield(Weapon* leftWeapon) {
    this->leftWeapon = leftWeapon;
}

void GameCharacter::isUnkillable() {

}


void GameCharacter::movement() {
    //will be overrided in Hero and Enemy
}

void GameCharacter::attack() {

}

void GameCharacter::isChasing() {

}

void GameCharacter::respawn() {

}

//for npcs and bosses voicelines
void GameCharacter::isDialogue(int voiceLine) {// TODO must be in-game output
    //FIXME check it on constructor
    //NPC
    //Elizabeth
    if (voiceLine == 0)
        std::cout << "Bene bene, abbiamo un nuovo ospite. Da quale lontana era provieni?";
    else if (voiceLine == 1)
        std::cout << "Ci sono molte cose che vorrei chiederti, ma so che non devo.";
    else if (voiceLine == 2)
        std::cout << "Ahh, capisco. Non sai cosa sia successo...";
    else if (voiceLine == 3)
        std::cout << "Vedrai più avanti. Un antica bestia è stata risvegliata "
                     "e ha generato l’Abisso, minacciando di corrompere tutta Oolacile.";
    else if (voiceLine == 4)
        std::cout << "Il cavaliere Artorias è venuto per fermare tutto questo,"
                     " ma un tale eroe non è abbastanza coraggioso da affrontare tale potere.";
    else if (voiceLine == 5)
        std::cout << "Senza dubbio è stato sconfitto, travolto dall’oscurità,"
                     " ma spero ancora che la Principessa Dusk venga salvata.";
    else if (voiceLine == 6)
        std::cout << "Non molto tempo fa, ho avuto un altro visitatore, un essere umano come te,"
                     " da un tempo lontano.";
    else if (voiceLine == 7)
        std::cout << "Solo che era terribilmente odioso… e tempo che sia ancora tra noi.";
    else if (voiceLine == 8)
        std::cout << "Indossava un cappello e un lungo cappotto nero…";
    else if (voiceLine == 9)
        std::cout << "Che le fiamme possano guidarti.";
    else if (voiceLine == 10)
        std::cout << "Ti ringrazio per aver salvato la principessa Dusk, te ne sarò debitrice e"
                     " ti ricorderò per sempre.";
    else if (voiceLine == 11)
        std::cout << "Ma terrò per me la tua storia perché una leggenda rimarrà sempre una leggenda…";
    //Sif
    else if (voiceLine == 12)
        std::cout << "(Ulula)";
    //Chester
    else if (voiceLine == 13)
        std::cout << "Oh… Fammi indovinare";
    else if (voiceLine == 14)
        std::cout << "Sei stato catapultato nel passato di un’era differente?";
    else if (voiceLine == 15)
        std::cout << "Come avevo sospettato. È successo anche a me: siamo entrambi degli estranea"
                     " in una terra sconosciuta.";
    else if (voiceLine == 16)
        std::cout << "Ma almeno adesso, siamo in due.";
    else if (voiceLine == 17)
        std::cout << "Beh… Errore mio.";
    else if (voiceLine == 18)
        std::cout << "Ma siamo entrambi avventurieri e, per questo, dobbiamo aiutarci a vicenda.";
    else if (voiceLine == 19)
        std::cout << "Ti è capitato di incontrare Artorias? Il leggendario camminatore degli Abissi,"
                     " secondo gli antichi racconti.";
    else if (voiceLine == 20)
        std::cout << "Se ancora non è successo, meglio così. Se me lo stai chiedendo, sì, è ormai corrotto.";
    else if (voiceLine == 21)
        std::cout << "Ahahah ah ahah !";
    else if (voiceLine == 22)
        std::cout << "Allora, cosa ti ha fare quel fungo gigante? Non che mi interessi. "
                     "Non fa parte del mio business.";
    else if (voiceLine == 23)
        std::cout << "Eheheheh  eheh…";
    else if (voiceLine == 24)
        std::cout << "Hm? Non ho molto da dire…";
    else if (voiceLine == 25)
        std::cout << "Hai veramente ucciso Artorias?";
    else if (voiceLine == 26)
        std::cout << "Ho sentito dire che l’Abisso lo ha trasformato in qualcosa di veramente pericoloso.";
    else if (voiceLine == 27)
        std::cout << "È assolutamente insidioso.";
    else if (voiceLine == 28)
        std::cout << "Ahahahahaha ahha!";
    else if (voiceLine == 29)
        std::cout << "Che tu ci creda o no, Oolacile ha portato l’Abisso con se.";
    else if (voiceLine == 30)
        std::cout << "Ti sei mai chiesto: Vale veramente la pena?";
    else if (voiceLine == 31)
        std::cout << "Eheheheh eheh eh…";
    //Principessa Dusk
    else if (voiceLine == 32)
        std::cout << "...Mmn...ahh…";
    else if (voiceLine == 33)
        std::cout << "…Aah...mmn…";
    else if (voiceLine == 34)
        std::cout << "Salve avventuriero. Anche tu da queste parti, non è vero? Da quale era provieni?";
    else if (voiceLine == 35)
        std::cout << "Sai… può sembrare strano, ma…";
    else if (voiceLine == 36)
        std::cout << "Sono stata assalita da una creatura dell’Abisso e ci sarei"
                     " morta se non fosse stato per il Grande Cavaliere Artorias.";
    else if (voiceLine == 37)
        std::cout << "In realtà, ho visto poco di quanto è accaduto durante lo scontro. Ero stordita.";
    else if (voiceLine == 38)
        std::cout << "Nonostante ciò, Artorias emanava un’aura particolare… In lui traspirava"
                     " un equilibrio interiore…";
    else if (voiceLine == 39)
        std::cout << "Che ritrovo tale e quale in te. ";
    else if (voiceLine == 40)
        std::cout << "...";
    //Bosses
    //Artorias
    else if (voiceLine == 41)
        std::cout << "Chiunque tu sia, stai lontano!";
    else if (voiceLine == 42)
        std::cout << "Presto... Sarò consumato... da loro, dall'Oscurità";
    else if (voiceLine == 43)
        std::cout << "REEEUUUUGHHHHHHHH!"; //deve essere ripetuta anche dopo "ti prego, la..."
    else if (voiceLine == 44)
        std::cout << "Ti prego, la propagazione dell'Abisso... deve essere fermata";
    //Manus
    else if (voiceLine == 45)
        std::cout << "Restituiscimi ciò che mi appartiene!";
}