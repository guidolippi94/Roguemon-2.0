

#ifndef AbstractStrategy_hpp
#define AbstractStrategy_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class AbstractStrategy{
    
public:
    
    AbstractStrategy(){
    }
    
    virtual ~AbstractStrategy() = 0;
    
    
    virtual void walkStrategy(int** walkMap, int index, sf::Vector2i* position , sf::Vector2i* source, bool* updateframe, sf::Sprite* playersprite, sf::Texture* playerTexture , float* frameCounter) = 0;
    
protected:
    
    enum Direction {Down, Left, Right, Up};
    
};


#endif /* AbstractStrategy_hpp */
