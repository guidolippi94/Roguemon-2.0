

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
    
    Monster(int x, int y, int id, std::string addr);
    
    ~Monster(){}
    
    int getId(){
        return id;
    }
    
    void walk(int walkMap[dimMapx][dimMapy], int index , int action);
    
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
