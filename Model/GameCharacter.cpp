#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int a, int c, int mS, std::string& t): HP(hp), armor(a), cash(c), movementSpeed(mS),
weapon(nullptr), leftWeapon(nullptr), textPool(t){
}
GameCharacter::GameCharacter(const sf::Vector2f& pos,float rectPosX, float rectPosY, float rectWidth, float rectHeight): 
                        pos(pos), rectPosX(rectPosX), rectPosY(rectPosY), rectWidth(rectWidth), rectHeight(rectHeight){
    sprite.setTextureRect({rectPosX, rectPosY, rectWidth, rectHeight});
    animations[int(AnimationIndex::WalkingUp)] = Animation();//TODO needs to be adjusted
    animations[int(AnimationIndex::WalkingDown)] = Animation();
    animations[int(AnimationIndex::WalkingLeft)] = Animation();
    animations[int(AnimationIndex::WalkingRight)] = Animation();
    animations[int(AnimationIndex::Idle)] = Animation();
}

void GameCharacter::draw(sf::RenderTarget& rt) const{
    rt.draw(sprite);
}

void GameCharacter::setDirection(const sf::Vector2f& dir){
    vel = dir*speed;
    if(dir.x > 0.0f){
        curAnimation = AnimationIndex::WalkingRight;
    }else if(dir.x < 0.0f){
        curAnimation = AnimationIndex::WalkingLeft;
    }else if(dir.y < 0.0f){
        curAnimation = AnimationIndex::WalkingUp;
    }else if(dir.y > 0.0f){
        curAnimation = AnimationIndex::WalkingDown;
    }else
        curAnimation = AnimationIndex::Idle;

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
    if (hp < 0)
        hp = 0;
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

int GameCharacter::getMovementSpeed() const{
    return movementSpeed;
}

void GameCharacter::setMovementSpeed(int movementSpeed) {
    this->movementSpeed = movementSpeed;
}

Weapon* GameCharacter::getWeapon() {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::receiveDamage(int points) {
    points = points*armor/100;
    setHp(HP-points);
}

Weapon* GameCharacter::getShield() {
    return leftWeapon;
}

void GameCharacter::setShield(Weapon* leftWeapon) {
    this->leftWeapon = leftWeapon;
}


void GameCharacter::movement() {
    //will be overrided in Hero and Enemy
}

void GameCharacter::attack(GameCharacter &opponent) {//its virtual, needs to be overrided in enemy
    //TODO with SFML library type if (sf::Keyboard::isPressed(sf::Keyboard::E){}
    int hit = 1;
    if(weapon){//and something else
        hit = weapon -> getDamage();//edited in weapon -> from void use to int use
    }
    opponent.receiveDamage(hit);
}

bool GameCharacter::isChasing(int aggroDistance, const GameCharacter &enemy) {//FIXME position
    if (sf::norm(pos-enemy.pos) > aggroDistance) //is it ok?
        return false;
    return true;
}


//for npcs and bosses voicelines
void GameCharacter::isDialogue() {
    std::cout << textPool[dialogueTracker] << std::endl;
    //at the bottom
    if (dialogueTracker < textPool.size())
        dialogueTracker ++;
    //TODO add dialogues in main in a array of arrays
    //TODO add extra dialogues after beating a boss
    /*NPC
    Elizabeth
    "Bene bene, abbiamo un nuovo ospite. Da quale lontana era provieni?"
    "Ci sono molte cose che vorrei chiederti, ma so che non devo."
    "Ahh, capisco. Non sai cosa sia successo..."
    "Vedrai più avanti. Un antica bestia è stata risvegliata
     e ha generato l’Abisso, minacciando di corrompere tutta Oolacile."
    "Il cavaliere Artorias è venuto per fermare tutto questo,
     ma un tale eroe non è abbastanza coraggioso da affrontare tale potere."
    "Senza dubbio è stato sconfitto, travolto dall’oscurità,
     ma spero ancora che la Principessa Dusk venga salvata."
    "Non molto tempo fa, ho avuto un altro visitatore, un essere umano come te,
     da un tempo lontano."
    "Solo che era terribilmente odioso… e tempo che sia ancora tra noi."
    "Indossava un cappello e un lungo cappotto nero…"
    "Che le fiamme possano guidarti."
    "Ti ringrazio per aver salvato la principessa Dusk, te ne sarò debitrice e
     ti ricorderò per sempre."
    "Ma terrò per me la tua storia perché una leggenda rimarrà sempre una leggenda…"
    //Sif
    "(Ulula)"
    //Chester
    "Oh… Fammi indovinare"
    "Sei stato catapultato nel passato di un’era differente?"
    "Come avevo sospettato. È successo anche a me: siamo entrambi degli estranea
     in una terra sconosciuta."
    "Ma almeno adesso, siamo in due."
    "Beh… Errore mio."
    "Ma siamo entrambi avventurieri e, per questo, dobbiamo aiutarci a vicenda."
    "Ti è capitato di incontrare Artorias? Il leggendario camminatore degli Abissi,
     secondo gli antichi racconti."
    "Se ancora non è successo, meglio così. Se me lo stai chiedendo, sì, è ormai corrotto."
    "Ahahah ah ahah !"
    "Allora, cosa ti ha fare quel fungo gigante? Non che mi interessi.
     Non fa parte del mio business."
    "Eheheheh  eheh…"
    "Hm? Non ho molto da dire…"
    "Hai veramente ucciso Artorias?"
    "Ho sentito dire che l’Abisso lo ha trasformato in qualcosa di veramente pericoloso."
    "È assolutamente insidioso."
    "Ahahahahaha ahha!"
    "Che tu ci creda o no, Oolacile ha portato l’Abisso con se."
    "Ti sei mai chiesto: Vale veramente la pena?"
    "Eheheheh eheh eh…"
    //Principessa Dusk
    "...Mmn...ahh…"
    "…Aah...mmn…"
    "Salve avventuriero. Anche tu da queste parti, non è vero? Da quale era provieni?"
    "Sai… può sembrare strano, ma…"
    "Sono stata assalita da una creatura dell’Abisso e ci sarei
     morta se non fosse stato per il Grande Cavaliere Artorias."
    "In realtà, ho visto poco di quanto è accaduto durante lo scontro. Ero stordita."
    "Nonostante ciò, Artorias emanava un’aura particolare… In lui traspirava
     un equilibrio interiore…"
    "Che ritrovo tale e quale in te."
    "..."
    //Artorias
    "Chiunque tu sia, stai lontano!"
    "Presto... Sarò consumato... da loro, dall'Oscurità"
    "REEEUUUUGHHHHHHHH!"; //deve essere ripetuta anche dopo "ti prego, la..."
    "Ti prego, la propagazione dell'Abisso... deve essere fermata"
    //Manus
    "Restituiscimi ciò che mi appartiene!"*/
}