#ifndef _MAPELEMENT_H
#define _MAPELEMENT_H

class MapElement
{
public:
    MapElement(float posX, float posY);

    ~MapElement();

    float getPosX();
    void setPosX(float posX);

    float getPosY();
    void setPosY(float posY);

protected:
    float posX;
    float posY;
};
#endif //_MAPELEMENT_H