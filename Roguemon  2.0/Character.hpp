//
//  Character.hpp
//  provamappa
//
//  Created by Francesco Pegoraro on 07/04/16.
//  Copyright © 2016 Francesco Pegoraro. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class Character{
    
public:
    
    Character();
    
    virtual void init(int x, int y, int id , std::string addr) = 0;
    
    virtual ~Character() = 0;
    
    virtual int getId() = 0;
    
    virtual void initP(std::string addr) = 0;
    
    virtual void walk(int mappa[100][100], int index , int action) = 0;
    
    virtual sf::Vector2i getPos() = 0;
    
    virtual sf::Sprite getSprite() = 0;
    
    virtual void SetTextureState() = 0;
    
protected:
    
    int id;
    sf::Vector2i position;
    enum Direction {Down, Left, Right, Up};
    sf::Vector2i source;
    bool updateFrame;
    float frameCounter, switchFrame, frameSpeed;
    sf::Clock clk;
    sf::Texture playerTexture;
    sf::Sprite playersprite;
    
};


#endif /* Character_hpp */
