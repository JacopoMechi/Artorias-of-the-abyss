#ifndef _ACHIVEMENTOBSERVER_H
#define _ACHIVEMENTOBSERVER_H
#include <unordered_set>
#include "GUI/HUD.h"

class AchivementsObserver
{
public:
    AchivementsObserver(HUD &hud) : hud(hud){};
    void update(const std::string &achivement);

private:
    std::unordered_set<std::string> unlockedAchivements;
    HUD &hud;
};
#endif