

#ifndef BattleLoop_hpp
#define BattleLoop_hpp



#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdexcept>



void BattleLoop(Character *player, Character *enemy){
    sf::RenderWindow window2(sf::VideoMode(32*16, 32*8), "Battle!!");

    
    //grafica battle
    sf::Texture playerTexture, enemyTexture, battleTexture;
    sf::Sprite playerSprite, enemySprite, battleSprite;

    std::string enemypng = std::to_string(enemy->getId()) + ".png";//prendo l'id del mostro perchè la frontalsprite del mostro si chiama ID.png
    
    //std::string playerpng = std::to_string(enemy->getId()) + ".png";
    
    if(!enemyTexture.loadFromFile(enemypng))
        std::cout<<"Error, could not load player texture"<<std::endl;
    enemySprite.setTexture(enemyTexture);
    //enemySprite.setTextureRect(sf::IntRect(0,64,32,32));
    enemySprite.setPosition(32*11,50);

    if(!battleTexture.loadFromFile("battlebackground.png"))
        std::cout<<"Error, could not load battlebackground texture"<<std::endl;
    battleSprite.setTexture(battleTexture);
    battleSprite.setScale(2.2, 2.4);
    
    
    
    
    sf::Event events;
    
    while (window2.isOpen()){
        while (window2.pollEvent(events)){
            if(events.type == sf::Event::Closed){
                window2.close();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window2.close();
            }
        
            else if(events.key.code==sf::Keyboard::Return){
                window2.close();
            }
            
            
       
        }
        window2.clear();
        window2.draw(battleSprite);
        window2.draw(enemySprite);
        window2.display();
        
    }
}

bool collision (sf::Vector2f vp1, sf::Vector2f vp2){  //metodo per collisioni con nemici, se ci troviamo in un raggio di 4px
    float a=fabs(vp1.x-vp2.x);  //fabs fa il valore assoluto
    float b=fabs(vp1.y-vp2.y);
    if (a<4 && b<4) {
        return true;
    }
    return false;
}



#endif /* BattleLoop_hpp */