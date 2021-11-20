#ifndef _MAPELEMENT_H
#define _MAPELEMENT_H

class MapElement
{
public:
    float getPosX();
    void setPosX(float posX);

    float getPosY();
    void setPosY(float posY);

protected:
    MapElement(float posX, float posY);

    ~MapElement();
    float posX;
    float posY;
};
#endif //_MAPELEMENT_H