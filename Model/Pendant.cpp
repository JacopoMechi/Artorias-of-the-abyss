#include "Pendant.h"

Pendant::Pendant(std::string n, int p, int c, std::string d, int M): Item(n, p, c, d, M){

}

Pendant::~Pendant(){

}

void Pendant::use(GameCharacter& hero) {//TODO implement hold time
    int tmp = hero.getArmor();
    hero.setArmor(100);
    //wait 3 seconds with immuneTime
    hero.setArmor(tmp);
}