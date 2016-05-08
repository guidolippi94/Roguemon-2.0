
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "Monster.hpp"
#include "Elf.hpp"

Monster::Monster(int x, int y, int id, std::string addr):Character(x, y, id){
    if(!playerTexture.loadFromFile(addr))//carico l immag del persongg
        std::cout<<addr<<" not found"<<std::endl;
    playersprite.setTexture(playerTexture);
    playersprite.setPosition(32*position.y,32*position.x);
    source.x = 1;
    source.y = Right;  //cambiare per posizione di partenza
    updateFrame = false;
    frameCounter=0, switchFrame=200, frameSpeed = 500;
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


void Monster::walk(int** walkMap, int index , int action)
{
    if ( action == 1){ //indicheranno dove si muove il player nel display
        source.y = Up;
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
        source.y=Down;
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
        source.y=Right;
        SetTextureState();
        if(walkMap[position.x][position.y+1] != 1){
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
    
}

