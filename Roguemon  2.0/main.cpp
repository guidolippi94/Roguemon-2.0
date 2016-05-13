#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <cmath>


#include "CharacterFactory.hpp"
#include "Monster.hpp"
#include "TileMap.hpp"
#include "MenuLoop.hpp"
#include "BattleLoop.hpp"
#include "EndLoop.hpp"

#include "Constants.hpp"
#include "Maps.hpp"

//per observer
#include "Map.hpp"
#include "Maps.hpp"



int main()
{
    //icon
    sf::Image icon;
    if (!icon.loadFromFile("icon.png")) {
        return EXIT_FAILURE;
    }
    
    

    //movimento telecamera
    sf::Vector2i positionview(0,0);
    sf::Vector2i screenDimensions(screenY, screenX);
    sf::View view;

    baseMap = createBaseMap(dimMapy, dimMapx);
    generateTrees(dimMapy, dimMapy, baseMap);
    baseMap[1][1]=0;
    createArea(2, 2, 30, 10, 's');
    createArea(5, 5, 3, 3, 'a');
    walkMap = createWalkable(dimMapy, dimMapx);
    level = createLevel(dimMapy, dimMapx);
    

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
            ch = (CharacterFactory::makeCharacter(CharacterFactory::Elfo, 1, 1, 0, 120, 60, ""));
            characters.push_back(ch);
            break;
        }
        case 2:{
            ch = (CharacterFactory::makeCharacter(CharacterFactory::Druido, 1, 1, 0, 60, 60, ""));
            characters.push_back(ch);
            break;
        }
        case 3:{
            ch = (CharacterFactory::makeCharacter(CharacterFactory::Paladino, 1, 1, 0, 60, 60, ""));
            characters.push_back(ch);
            break;
        }
        default:
            break;
    }
    
    Map* Obs1 = new Map((MainCharacter*)ch, baseMap);
    
    characters.push_back(CharacterFactory::makeCharacter(CharacterFactory::Poke, 2, 2, 1, 60*4, 10, "mewtwo.png"));
    characters.push_back(CharacterFactory::makeCharacter(CharacterFactory::Poke, 3, 1, 2, 60*4, 10, "greeninja.png"));
    characters.push_back(CharacterFactory::makeCharacter(CharacterFactory::Poke, 4, 1, 3, 60*4, 10, "greeninja.png"));
    characters.push_back(CharacterFactory::makeCharacter(CharacterFactory::Poke, 6, 3, 4, 60*4, 10, "charizard.png"));

    


    sf::RenderWindow window(sf::VideoMode(screenY, screenX), "Roguemon");
    
    window.setMouseCursorVisible(false);
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    
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
   
        if (characters.size() == 1|| characters.at(0)->getType() == "monster") {
            EndLoop(characters);
            delete Obs1;  //delete perchè senno da unused
            return 1;
        }
        if (c.getElapsedTime().asMilliseconds() > 150) {
            srand((unsigned int)c.getElapsedTime().asMicroseconds());
            int action = rand() % 4 + 1;
            for(int index = 2 ; index < 33 ; index++){
                for (int id=1; id<characters.size(); id++ ){  //non è il for completo cosi salta il mainplayer!
                    characters.at(id)->walk(walkMap, index, (action+characters.at(id)->getId())%4+1);
                    if (characters.size() == 1|| characters.at(0)->getType() == "monster") {
                        EndLoop(characters);
                        delete Obs1;  //delete perchè senno da unused
                        return 1;
                    }
                    if(collision(characters.at(0)->getSprite().getPosition(), characters.at(id)->getSprite().getPosition())){  //added method collision
                        std::cout << "Monster " << characters.at(id)->getId() << " wants to fight!"<<std::endl;
                        BattleLoop(&characters, id);
                    }

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
