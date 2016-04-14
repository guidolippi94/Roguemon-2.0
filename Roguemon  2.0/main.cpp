


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "TileMap.hpp"
#include "Elf.hpp"
#include "Monster.hpp"
#include "CharacterFactory.hpp"
#include <unistd.h>
#include <iostream>
#include "MenuLoop.hpp"


int getPressedKey(){
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        return 1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        return 2;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        return 3;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        return 4;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        return 5;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        return 6;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
        return 7;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
        return 8;
    }
    
    else return -1;
}


void GameLoop(){
    
}

int main()
{
    bool walk = true;
    bool menu = true;
    bool firstTimeRectangle=true;
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(32*16, 32*11), "prova");
    
    
    // define the level with an array of tile indices  //la window è 32*16,32*8

     const int level[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    
    int mappa[8][16]=
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    
    std::cout << mappa[0][0]<<std::endl;
    /*for(int i = 0; i < 8; i++){
     for(int j = 0; j < 16; j++){
     if(level[ i + j * 16] == 0){
     mappa[i][j] = 0;
     }
     else{
     mappa[i][j] = 1;
     }
     }
     }*/
    
    // create the tilemap from the level definition
    TileMap map;
    if (!map.load(sf::Vector2u(32, 32), level, 16, 8))
        return -1;
    
    sf::Clock c;

    std::vector<Character*> characters;
    std::vector<Character*>::const_iterator itr;
    
    characters.push_back(((Elf*)CharacterFactory::makeCharacter(CharacterFactory::Elfo)));
    characters.push_back((Monster*)CharacterFactory::makeCharacter(CharacterFactory::Poke));
    characters.push_back((Monster*)CharacterFactory::makeCharacter(CharacterFactory::Poke));
    
    characters.at(0)->init(1,1,1 , "");
    characters.at(1)->init(2,2,2 , "mewtwo.png");
    characters.at(2)->init(3,3,3 , "greeninja.png");
    
    /*for (itr = characters.begin() ; itr != characters.end() ; itr++){
        (*itr)->init();
    }*/
    
    // run the main loop
    while (window.isOpen())
    {
        
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        
        if(menu){
            if(!MenuLoop(&window, &firstTimeRectangle)){
                menu = false;
            }
        }
        else{
            for (itr = characters.begin() ; itr != characters.end() ; itr++){
                (*itr)->SetTextureState();
            }
            
            // draw the map
            window.clear();
            window.draw(map);
            
            if (walk) {
                int k = getPressedKey();
                if(k != -1){
                    for(int index = 2 ; index < 33 ; index++){
                        characters.at(0)->walk(mappa, index , k);
                        window.clear();
                        window.draw(map);
                        for (itr = characters.begin() ; itr != characters.end() ; itr++){
                            window.draw((*itr)->getSprite());
                        }
                        window.display();
                        usleep(6000);
                    }
                }
                walk = false;
            }
            //std::cout << c.getElapsedTime().asMilliseconds() << std::endl;
            if (c.getElapsedTime().asMilliseconds() > 150) {
                srand (c.getElapsedTime().asMicroseconds());
                int action = rand() % 4 + 1;
                for(int index = 2 ; index < 33 ; index++){
                    for (itr = characters.begin() ; itr != characters.end()-1 ; ){
                        itr++;
                        (*itr)->walk(mappa, index, (action+(*itr)->getId())%4+1);
                    }
                    window.clear();
                    window.draw(map);
                    for (itr = characters.begin() ; itr != characters.end() ; itr++){
                        window.draw((*itr)->getSprite());
                    }
                    window.display();
                    usleep(6000);
                }
                walk=true;
                c.restart();
            }
            for (itr = characters.begin() ; itr != characters.end()-1 ; ){
                itr++;
                if(characters.at(0)->getPos() == (*itr)->getPos() ){
                    std::cout << "Monster " << (*itr)->getId() << " wants to fight!"<<std::endl;
                }
            }
            for (itr = characters.begin() ; itr != characters.end() ; itr++){
                (*itr)->SetTextureState();
                window.draw((*itr)->getSprite());
            }
            window.display();
            window.clear();
            
        }
    }
    
    return 0;
}