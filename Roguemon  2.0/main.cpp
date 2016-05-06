#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdexcept>

#include "CharacterFactory.hpp"
#include "Monster.hpp"
#include "Elf.hpp"
#include "TileMap.hpp"
#include "MenuLoop.hpp"
#include "Constants.hpp"
#include "Maps.hpp"

//per observer
#include "Map.hpp"




int main()
{
    //movimento telecamera
    sf::Vector2i positionview(0,0);
    sf::Vector2i screenDimensions(screenY, screenX);
    sf::View view;

    baseMap = createBaseMap(dimMapy, dimMapx);
    walkMap=createWalkable(dimMapy, dimMapx);
    level=createLevel(dimMapy, dimMapx);
    

    bool walk = true;
    int p=0;
    
    // create the tilemap from the level definition
    TileMap map;
    if (!map.load(sf::Vector2u(32, 32), level, dimMapy, dimMapx))
        return -1;
    
    sf::Clock c;
    
    std::vector<Character*> characters;
    std::vector<Character*>::const_iterator itr;
    
    p = MenuLoop();
    if(p==-1){
        return 1;
    }
    Character * ch = nullptr;

    
    switch (p) {  //a seconda di cosa ritorna menuloop:...
            
        case 1:{
            ch = (CharacterFactory::makeCharacter(CharacterFactory::Elfo, 1, 1, 1,""));
            characters.push_back(ch);
            break;
        }
        case 2:{
            ch = (CharacterFactory::makeCharacter(CharacterFactory::Druido, 1, 1, 1,""));
            characters.push_back(ch);
            break;
        }
        case 3:{
            ch = (CharacterFactory::makeCharacter(CharacterFactory::Paladino, 1, 1, 1,""));
            characters.push_back(ch);
            break;
        }
        default:
            break;
    }
    
    Map* Obs1 = new Map((MainCharacter*)ch, baseMap);
    
    characters.push_back(CharacterFactory::makeCharacter(CharacterFactory::Poke, 3, 3, 2,"mewtwo.png"));
    characters.push_back(CharacterFactory::makeCharacter(CharacterFactory::Poke, 3, 3, 3,"greeninja.png"));
    

    sf::RenderWindow window(sf::VideoMode(screenY, screenX), "Roguemon");
    // run the main loop
    while (window.isOpen())
    {
        
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }//chiuso loop eventi
        
        for (itr = characters.begin() ; itr != characters.end() ; itr++){
            (*itr)->SetTextureState();
        }
        
        // draw the map
        window.clear();
        window.draw(map);
        view.reset(sf::FloatRect(positionview.x, positionview.y, screenDimensions.x, screenDimensions.y));

        
        if (walk) {
            int k = getPressedKey();
            if(k != -1){
                for(int index = 2 ; index < 33 ; index++){
                    characters.at(0)->walk(walkMap, index , k);
                    window.clear();
                    window.draw(map);
                    for (itr = characters.begin() ; itr != characters.end() ; itr++){
                        window.draw((*itr)->getSprite());
                    }
                    window.display();
                    //position per il movimento telecamera
                    positionview.x=characters.at(0)->getSprite().getPosition().x+32 - (screenDimensions.x/2); //metto in position la posizione dell omino - mezzo display
                    positionview.y=characters.at(0)->getSprite().getPosition().y+32 - (screenDimensions.y/2);
                    
                    if (positionview.x<0) {
                        positionview.x=0;
                    }
                    if (positionview.y<0) {
                        positionview.y=0;
                    }
                    usleep(6000);
                }
            }
            walk = false;

        }
        
        if (c.getElapsedTime().asMilliseconds() > 150) {
            srand((unsigned int)c.getElapsedTime().asMicroseconds());
            int action = rand() % 4 + 1;
            for(int index = 2 ; index < 33 ; index++){
                for (itr = characters.begin() ; itr != characters.end()-1 ; ){
                    itr++;
                    (*itr)->walk(walkMap, index, (action+(*itr)->getId())%4+1);
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
        /*for (itr = characters.begin() ; itr != characters.end()-1 ; ){  //modo rudimentale per fare incontro con mostri
            itr++;
            if(characters.at(0)->getPos() == (*itr)->getPos() ){
                std::cout << "Monster " << (*itr)->getId() << " wants to fight!"<<std::endl;
            }
        }*/
        for (itr = characters.begin() ; itr != characters.end() ; itr++){
            (*itr)->SetTextureState();
            window.draw((*itr)->getSprite());
        }
        
        window.setView(view); //--->setto la view della telecamera
        
        window.display();
        window.clear();
        
    } //chiude game loop
    delete Obs1;  //delete perchè senno da unused
    return 0;
}//chiude main
