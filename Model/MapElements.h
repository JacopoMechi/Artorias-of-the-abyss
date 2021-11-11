/**
 * Project Untitled
 */


#ifndef _MAPELEMENTS_H
#define _MAPELEMENTS_H

class MapElements {
public: 
    
float getPosX();
void setPosX(float posX);

float getPosY();
void setPosY(float posY);
    
void draw();
protected: 
    float posX;
    float posY;
    int dim[2];
};

#endif //_MAPELEMENTS_H