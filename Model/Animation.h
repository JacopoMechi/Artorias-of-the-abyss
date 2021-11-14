#include "Graphics.hpp"

class Animation{
public:
    Animation() = default; //TODO check meaning
    Animation(int x, int y, int width, int height){
        texture.loadFromFile();//TODO add sprite
        for (int i = 0; i < nFrames; i++){
            frames[i] = {x+i*width, y, width, height};//TODO what is rectleft? i think is the image swap
        }
    }
    void applyToSprite(sf::Sprite& s) const{
        s.setTexture(texture);
        s.setTextureRect(frames[iFrame]);
    }
    void update(float dt){
        time += dt;
        while(time >= holdTime){
            time -= holdTime;
            advance();
        }
    }
private:
    void advance(){
        if (++iFrame >= nFrames)//TODO check meaning
            iFrame = 0;
    }
    static constexpr int nFrames = 5;//TODO what is constexpr?
    static constexpr float holdTime = 0.1f;// f: defined as float
    sf::Texture texture;
    sf::IntRect frames[nFrames];//TODO what is IntRect?
    int iFrame = 0;
    float time = 0.0f;
};