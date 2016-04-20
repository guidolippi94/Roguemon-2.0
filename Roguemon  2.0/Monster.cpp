
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "Monster.hpp"
#include "Elf.hpp"

void Monster::initP(std::string addr)
{
    if(!playerTexture.loadFromFile(addr))//carico l immag del persongg
        std::cout<<"image2 not found"<<std::endl;
    
    playersprite.setTexture(playerTexture);
    playersprite.setPosition(96,96);
    
}

void Monster::SetTextureState(){
    if (updateFrame) {
        
        frameCounter = 0;
        source.x ++;//la camminata animata perchè scorre lungo la riga y
        
        if(source.x * 32 >= playerTexture.getSize().x)//e questo è per far ripartire la riga
            source.x=0;
    }
    
    playersprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
    
    updateFrame = false;
}


void Monster::walk(int mappa[dimMapx][dimMapy], int index , int action)
{
    if ( action == 1){ //indicheranno dove si muove il player nel display
        source.y = Up;
        SetTextureState();
        if(mappa[position.x-1][position.y] != 1){
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
        source.y=Down;
        SetTextureState();
        if(mappa[position.x+1][position.y] != 1){
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
        source.y=Right;
        SetTextureState();
        if(mappa[position.x][position.y+1] != 1){
            playersprite.setPosition((position.y)*32 + index, (position.x)*32);
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
        source.y=Left;
        SetTextureState();
        if(mappa[position.x][position.y-1] != 1){
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
    
}

