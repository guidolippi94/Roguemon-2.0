

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
#include "Constants.hpp"
//per observer
#include <list>
#include <vector>


class Elf : public Character, public Subject{
public:
    
    Elf(int x, int y, int id, std::string addr);
    
    ~Elf(){}
    
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
    
    //per observer
    void subscribe(Observer* o);
    
    void unsubscribe(Observer* o);
    
    void notify();
    
    
protected:
    
    //per observer
    std::list <Observer*> observers;

    
};

#endif /* Elf_hpp */
