#include "Animation.h"

Animation::Animation(int x, int y, int width, int height): x(x), y(y), width(width), height(height){
        texture.loadFromFile();//TODO add sprite
        for (int i = 0; i < nFrames; i++){
            frames[i] = {x+i*width, y, width, height};//TODO what is rectleft? i think is the image swap
        }
    }

void Animation::applyToSprite(sf::Sprite& s) const{
        s.setTexture(texture);
        s.setTextureRect(frames[iFrame]);
    }

void Animation::update(float dt){
        time += dt;
        while(time >= holdTime){
            time -= holdTime;
            advance();
        }
    }