/**
 * Project Untitled
 */


#ifndef _MAPELEMENTS_H
#define _MAPELEMENTS_H

class MapElements {
public: 
    
void getPos();
    
/**
 * @param float pos[2]
 */
void setPos(float pos[2]);
    
void draw();
protected: 
    float pos[2];
    int dim[2];
};

#endif //_MAPELEMENTS_H