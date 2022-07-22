#include "achivementsObserver.h"

void AchivementsObserver::update(const std::string &achivement)
{
    std::cout << hud.getIsTalking() << std::endl;
    if (unlockedAchivements.find(achivement) != unlockedAchivements.end())
        return;

    std::cout << "sono in update" << std::endl;
    unlockedAchivements.insert(achivement);
    std::cout << achivement << std::endl;
}