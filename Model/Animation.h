#include "Graphic.hpp"

class Animation{
public:
    Animation() = default; //TODO check meaning
    Animation(int x, int y, int width, int height);
    void applyToSprite(sf::Sprite& s) const;
    void update(float dt);
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