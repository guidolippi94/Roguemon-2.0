
#ifndef MainCharacter_hpp
#define MainCharacter_hpp

#include <stdio.h>
#include "Character.hpp"
#include "Subject.hpp"
#include "Music.hpp"

#include <list>
#include <vector>



class MainCharacter :public Character, public Subject{
    
public:
    
    MainCharacter(int x, int y, int id):Character(x, y, id){}

    
    void walk(int mappa[dimMapx][dimMapy], int index , int action){
    }
    
    int getId(){
        return id;
    }
    
    sf::Vector2i getPos(){
        return position;
    }
    
    sf::Sprite getSprite(){
        return playersprite;
    }
    
    void SetTextureState();
    
    std::list <Observer*> observers;
    
    void subscribe(Observer* o);
    
    void unsubscribe(Observer* o);
    
    void notify();
    
};


#endif /* MainCharacter_hpp */