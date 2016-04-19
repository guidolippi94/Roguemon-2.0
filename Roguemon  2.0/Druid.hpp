

#ifndef Druid_hpp
#define Druid_hpp

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

class Druid : public Character{
public:
    
    Druid(){};
    
    void init(int x, int y, int id , std::string addr){
        this->id =id;
        position.x = x;
        position.y = y;
        source.x = 0;
        source.y = Left;
        updateFrame = false;
        frameCounter=0, switchFrame=200, frameSpeed = 500;
        initP(addr);
    }
    
    ~Druid(){
        
    }
    
    int getId(){
        return id;
    }
    
    void initP(std::string addr);
    
    void walk(int mappa[8][16], int index , int action);
    
    sf::Vector2i getPos(){
        return position;
    }
    
    sf::Sprite getSprite(){
        return playersprite;
    }
    
    void SetTextureState();
    
    
protected:
    
};

#endif /* Druid_hpp */