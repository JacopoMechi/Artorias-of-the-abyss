#include "GreenBlossom.h"

GreenBlossom::GreenBlossom(std::string n, int p, std::string d, int M, int c): Item(n, p, d, M, c){

}

GreenBlossom::~GreenBlossom(){

}

void GreenBlossom::use(Hero& hero, int newCooldown, int timeEffect) {
    int tmp = hero.getCooldown();
    // for time = timeEffect in seconds
    hero.setCooldown(newCooldown);
    //end time
    hero.setCooldown(tmp);
}