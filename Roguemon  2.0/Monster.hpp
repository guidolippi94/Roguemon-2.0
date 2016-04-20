

#ifndef Monster_hpp
#define Monster_hpp

#include <stdio.h>
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <curses.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>

#include "TileMap.hpp"
#include "Character.hpp"
#include "Constants.hpp"


class Monster : public Character{
public:
    
    Monster(){};
    
    void init(int x, int y, int id , std::string addr){
        this->id =id;
        position.x = x;
        position.y = y;
        source.x = 1;
        source.y = Down;
        updateFrame = false;
        frameCounter=0, switchFrame=200, frameSpeed = 500;
        initP(addr);
    }
    
    ~Monster(){
        
    }
    
    int getId(){
        return id;
    }
    
    void initP(std::string addr);
    
    void walk(int mappa[dimMapx][dimMapy], int index , int action);
    
    sf::Vector2i getPos(){
        return position;
    }
    
    sf::Sprite getSprite(){
        return playersprite;
    }
    
    void SetTextureState();
    
    
protected:
    
};


#endif /* Monster_hpp */
