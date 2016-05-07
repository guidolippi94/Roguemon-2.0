

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "Paladin.hpp"

Paladin::Paladin(int x, int y, int id, std::string addr):MainCharacter(x, y, id){
    if(!playerTexture.loadFromFile("Paladin.png"))//carico l immag del persongg
        std::cout<<"Paladin not found"<<std::endl;
    playersprite.setTexture(playerTexture);
    playersprite.setPosition(32,32);
    source.x = 1;
    source.y = Right;  //cambiare per posizione di partenza
    updateFrame = false;
    frameCounter=0, switchFrame=200, frameSpeed = 500;
    
    atk=80;
    life=60;
}



void Paladin::walk(int** walkMap , int index , int action)
{
    if ( action == 1){ //indicheranno dove si muove il player nel display
        source.y = Down;
        SetTextureState();
        if(walkMap[position.x-1][position.y] != 1){
            playersprite.setPosition((position.y)*32, (position.x)*32 - index);
            if(index % 8 == 0){
                updateFrame = true;
                SetTextureState();
            }
            if(index == 32){
                position.x--;
                updateFrame = true;
                source.x = 0;
                SetTextureState();
            }
        }
    }
    else if(action == 2){
        source.y=Left;
        SetTextureState();
        if(walkMap[position.x+1][position.y] != 1){
            playersprite.setPosition((position.y)*32, (position.x)*32 + index);
            if(index % 8 == 0){
                updateFrame = true;
                SetTextureState();
            }
            if(index == 32){
                position.x++;
                updateFrame = true;
                source.x = 0;
                SetTextureState();
            }
        }
    }
    else if(action == 3){
        source.y=Up;
        SetTextureState();
        if(walkMap[position.x][position.y+1] != 1){
            playersprite.setPosition((position.y)*32 +index, (position.x)*32);
            if(index % 8 == 0){
                updateFrame = true;
                SetTextureState();
            }
            if(index == 32){
                position.y++;
                updateFrame = true;
                source.x = 0;
                SetTextureState();
            }
        }
    }
    else if(action == 4){
        source.y=Right;
        SetTextureState();
        if(walkMap[position.x][position.y-1] != 1){
            playersprite.setPosition((position.y)*32 -index, (position.x)*32);
            if(index % 8 == 0){
                updateFrame = true;
                SetTextureState();
            }
            if(index == 32){
                position.y--;
                updateFrame = true;
                source.x = 0;
                SetTextureState();
            }
        }
    }
    notify();
}

