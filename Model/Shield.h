#ifndef _SHIELD_H
#define _SHIELD_H

class Shield
{
public:
    int getDefence();

    int getLevel();

    void setLevel(int level);

private:
    Shield(int level = 1);

    ~Shield();

    int defence;
    int level;
};

#endif //_SHIELD_H