

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

//per observer
#include "Map.hpp"
#include "Maps.hpp"



int main()
{
    //movimento telecamera
    sf::Vector2i positionview(0,0);
    sf::Vector2i screenDimensions(screenY, screenX);
    sf::View view;

    
    for(int i=0; i<dimMapx; i++){
        std::cout<<" "<<std::endl;
        for(int j=0; j<dimMapy; j++){
            if(baseMap[i][j]!=0)
                walkMap[i][j]=0;
            else walkMap[i][j]=1;
            std::cout<<walkMap[i][j];
        }
    }
    
    
    int count=0;
    for(int i=0; i<dimMapx; i++){
        for(int j=0; j<dimMapy; j++){
            level[count]=baseMap[i][j];
            count++;
        }
    }
    
    //---->fino a qui

    /*
     int level[40000];
     int walkMap[200][200]={0};
     
     //setta tutti i confini come no-walkable
     for(int i=0; i<40000; i++){
     if(i%199==0 || i%200==0)
     level[i]=0;
     else
     level[i]=1;
     }
     //margini della walkMap non walkable con alberi
     for (int i=0; i<200; i++) {
     level[i]=0;
     }
     
     for (int i=40000; i>39800; i--) {
     level[i]=0;
     }
     
     
     
     
     for(int i=0; i<200; i++)
     {
     walkMap[0][i]=1;
     walkMap[199][i]=1;
     walkMap[i][0]=1;
     walkMap[i][199]=1;
     
     }
     
     int counterVector=0;
     
     for(int i=0; i<200; i++){
     for(int j=0; j<200; j++){
     if(level[counterVector]!=0)
     walkMap[i][j]=0;
     else
     walkMap[i][j]=1;
     counterVector++;
     }
     }
     
     */
    
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
    
    Map* Obs1 = new Map((MainCharacter*)ch);
    
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
