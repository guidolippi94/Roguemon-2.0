


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


int main()
{
    bool walk = true;
    int p=0;
    
    
    // define the level with an array of tile indices  //la window è 32*16,32*8

     const int level[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    
    int mappa[8][16]=
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    
    std::cout << mappa[0][0]<<std::endl;

    
    // create the tilemap from the level definition
    TileMap map;
    if (!map.load(sf::Vector2u(32, 32), level, 16, 8))
        return -1;
    
    sf::Clock c;

    std::vector<Character*> characters;
    std::vector<Character*>::const_iterator itr;
    p = MenuLoop();
    
    switch (p) {
        case 0:
            try{
                throw std::invalid_argument( "closed window" );
            }
            catch( const std::invalid_argument& e ) {
                std::cout << "exception";
                exit(0);
            }
            
        case 1:
            characters.push_back(((Elf*)CharacterFactory::makeCharacter(CharacterFactory::Elfo)));

            break;
        case 2:
            characters.push_back(((Druid*)CharacterFactory::makeCharacter(CharacterFactory::Druid)));
            
            break;
        case 3:
            characters.push_back(((Paladin*)CharacterFactory::makeCharacter(CharacterFactory::Paladin)));
            
            break;
            
        default:
            break;
    }
   
    
    

    characters.push_back((Monster*)CharacterFactory::makeCharacter(CharacterFactory::Poke));
    characters.push_back((Monster*)CharacterFactory::makeCharacter(CharacterFactory::Poke));
    
    characters.at(0)->init(1,1,1 , "");
    characters.at(1)->init(2,2,2 , "mewtwo.png");
    characters.at(2)->init(3,3,3 , "greeninja.png");
    
    /*for (itr = characters.begin() ; itr != characters.end() ; itr++){
        (*itr)->init();
    }*/
    sf::RenderWindow window(sf::VideoMode(32*16, 32*8), "prova");    

    // run the main loop
    while (window.isOpen())
    {
        
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
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
    
    

    return 0;
}
