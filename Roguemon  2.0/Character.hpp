

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Subject.hpp"



class Character{
    
public:
    
    Character(int x, int y, int id, int life, int atk);
    
    virtual ~Character() = 0;
    
    
    virtual int getId() = 0;
    
    virtual void walk(int** walkMap, int index , int action) = 0;
    
    virtual sf::Vector2i getPos() = 0;
    
    virtual sf::Sprite getSprite() = 0;
    
    virtual std::string getType() = 0;
    
    virtual int getLife() = 0;
    
    virtual int getAttack() = 0;
    
    virtual void reduceLife(int damage) = 0;
    
    virtual void setHp(int hp) = 0;

    
    virtual void SetTextureState() = 0;
    
protected:
    
    int id;
    int atk;
    int life;
    
    sf::Vector2i position;
    enum Direction {Down, Left, Right, Up};
    sf::Vector2i source;
    
    bool updateFrame;
    float frameCounter, switchFrame, frameSpeed;
    sf::Clock clk;
    
    sf::Texture playerTexture;
    sf::Sprite playersprite;
    std::string type;

    
};


#endif /* Character_hpp */
