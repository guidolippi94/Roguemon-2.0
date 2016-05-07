

#ifndef BattleLoop_hpp
#define BattleLoop_hpp



#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdexcept>



int BattleLoop(){
    sf::RenderWindow window2(sf::VideoMode(32*16, 32*8), "Battle!!");
    int k=1;  //a seconda dell'ultimo tasto premuto nel menu ritorna o 1 o 2 o 3
    
    sf::Event events;
    
    while (window2.isOpen()){
        while (window2.pollEvent(events)){
            if(events.type == sf::Event::Closed){
                window2.close();
                k=-1;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window2.close();
            }
            else if (events.key.code==sf::Keyboard::Left){
                k=1;
            }
            else if(events.key.code==sf::Keyboard::Up){
                k=2;
            }
            else if(events.key.code==sf::Keyboard::Right){
                k=3;
            }
            else if(events.key.code==sf::Keyboard::Return){
                window2.close();
            }
            
            window2.clear();
   
            
            window2.display();
        }
        
    }
    return k;
}



#endif /* BattleLoop_hpp */
