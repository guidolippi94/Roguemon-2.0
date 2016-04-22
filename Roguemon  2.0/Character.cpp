

#include "Character.hpp"

Character::Character(int x, int y, int id){
    this->id =id;
    position.x = x;
    position.y= y;
    atk = 30;
    life = 30;
}



Character::~Character(){};