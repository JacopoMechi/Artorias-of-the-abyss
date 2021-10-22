#include "GreenBlossom.h"

GreenBlossom::GreenBlossom(std::string n, int p, int c, std::string d, int M): Item(n, p, c, d, M){

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