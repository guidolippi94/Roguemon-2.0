//
//  Elf.hpp
//  provamappa
//
//  Created by Francesco Pegoraro on 01/04/16.
//  Copyright © 2016 Francesco Pegoraro. All rights reserved.
//

#ifndef Elf_hpp
#define Elf_hpp

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

class Elf : public Character{
public:
    
    Elf(int x, int y, int id){
        this->id =id;
        position.x = x;
        position.y = y;
        source.x = 1;
        source.y = Down;
        updateFrame = false;
        frameCounter=0, switchFrame=200, frameSpeed = 500;
        initP("pene");
    }
    
    ~Elf(){
        
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

#endif /* Elf_hpp */
