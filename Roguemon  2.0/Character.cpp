

#include "Character.hpp"

Character::Character(int x, int y, int id, int life, int atk){
    this->id =id;
    position.x = x;
    position.y= y;
    this->atk = atk;
    this->life = life;
}

Character::~Character(){};