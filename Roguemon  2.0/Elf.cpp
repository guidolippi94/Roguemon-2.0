

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "Elf.hpp"

Elf::Elf(int x, int y, int id, std::string addr):Character(x, y, id){
    if(!playerTexture.loadFromFile("Elf.png"))//carico l immag del persongg
        std::cout<<"Elf not found"<<std::endl;
    playersprite.setTexture(playerTexture);
    playersprite.setPosition(32,32);
    source.x = 1;
    source.y = Right;  //cambiare per posizione di partenza
    updateFrame = false;
    frameCounter=0, switchFrame=200, frameSpeed = 500;
}

void Elf::SetTextureState(){
    if (updateFrame) {
        
        frameCounter = 0;
        source.x ++;//la camminata animata perche scorre lungo la riga y
        
        if(source.x * 32 >= playerTexture.getSize().x)//e questo è per far ripartire la riga
            source.x=0;
    }
    
    playersprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));    
    updateFrame = false;
}


void Elf::walk(int mappa[dimMapx][dimMapy] , int index , int action)
{
    if ( action == 1){ //indicheranno dove si muove il player nel display
        source.y = Down;//tutte scambiate per non cambiare la texture
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
        source.y=Right;
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
        source.y=Up;
        SetTextureState();
        if(mappa[position.x][position.y+1] != 1){
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

