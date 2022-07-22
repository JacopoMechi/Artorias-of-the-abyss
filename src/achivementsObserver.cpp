#include "achivementsObserver.h"

void AchivementsObserver::update(const std::string &achivement)
{
    if (unlockedAchivements.find(achivement) != unlockedAchivements.end())
        return;
    unlockedAchivements.insert(achivement);
    hud.drawAchivement(achivement);
}