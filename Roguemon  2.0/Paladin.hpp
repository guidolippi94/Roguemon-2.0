

#ifndef Paladin_hpp
#define Paladin_hpp


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


class Paladin : public Character{
public:
    
    Paladin(int x, int y, int id, std::string addr);
        
    ~Paladin(){
        
    }
    
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


#endif /* Paladin_hpp */
