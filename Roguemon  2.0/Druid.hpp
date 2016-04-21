

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
#include "Constants.hpp"


class Druid : public Character{
public:
    
    Druid(int x, int y, int id, std::string addr);
    
    ~Druid(){}
    
    int getId(){
        return id;
    }
    
    
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

#endif /* Druid_hpp */
