#include "Pendant.h"

Pendant::Pendant(std::string n, int p, std::string d, int M, int c): Item(n, p, d, M, c){

}

Pendant::~Pendant(){

}

void Pendant::use(GameCharacter& hero) {//TODO implement hold time
    int tmp = hero.getArmor();
    hero.setArmor(100);
    //wait 3 seconds with immuneTime
    hero.setArmor(tmp);
}