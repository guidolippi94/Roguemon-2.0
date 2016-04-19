//
//  MenuLoop.cpp
//  Roguemon  2.0
//
//  Created by Guido Lippi on 14/04/16.
//  Copyright © 2016 guidolippi. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "TileMap.hpp"
#include "Elf.hpp"
#include "Monster.hpp"
#include "CharacterFactory.hpp"
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdexcept>


int getPressedKey();

int MenuLoop(){
    sf::RenderWindow window1(sf::VideoMode(32*16, 32*8), "prova");
    int k=1;  //a seconda dell'ultimo tasto premuto nel menu ritorna o 1 o 2 o 3

    sf::Text elfName, druidName, paladinName;
    elfName.setString("Legolas");
    druidName.setString("Radagast");
    paladinName.setString("Fra il giusto");
    
    //Font
    sf::Font font;
    if (!font.loadFromFile("Lobster_1.3.otf"))
    {
        std::cout<< "failed to open font"<<std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Menu");
    text.setCharacterSize(36); // in pixels, not points!
    text.setColor(sf::Color::Red);
    text.setPosition(32*7, 0);
    
    //Character frontal sprites
    sf::Texture elfTexture, druidTexture, paladinTexture;
    sf::Sprite elfSprite, druidSprite, paladinSprite;
    
    if(!elfTexture.loadFromFile("Elf.png"))
        std::cout<<"Error, could not load elf texture"<<std::endl;
    elfSprite.setTexture(elfTexture);
    elfSprite.setTextureRect(sf::IntRect(0,64,32,32));
    elfSprite.setPosition(32*3,100);
    
    if(!druidTexture.loadFromFile("Druid.png"))
        std::cout<<"Error, could not load druid texture"<<std::endl;
    druidSprite.setTexture(druidTexture);
    druidSprite.setTextureRect(sf::IntRect(0,32,32,32));
    druidSprite.setPosition(32*7,100);
    
    if(!paladinTexture.loadFromFile("Paladin.png"))
        std::cout<<"Error, could not load paladin texture"<<std::endl;
    paladinSprite.setTexture(paladinTexture);
    paladinSprite.setTextureRect(sf::IntRect(0,32,32,32));
    paladinSprite.setPosition(32*11,100);
    
    
    //animazione quadrato di selezione
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(40, 40));
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setOutlineThickness(5);
    rectangle.setFillColor(sf::Color::Color(0,0,0,0));
    rectangle.setPosition(32*3-4, 100);
    sf::Event eevv;
    
    while (window1.isOpen()){
        while (window1.pollEvent(eevv)){
            if(eevv.type == sf::Event::Closed){
                k=0;
                window1.close();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                k=0;
                window1.close();
                
                }
            else if (eevv.key.code==sf::Keyboard::Left){
                rectangle.setPosition((32*3)-4,100);
                k=1;
                }
            else if(eevv.key.code==sf::Keyboard::Up){
                rectangle.setPosition((32*7)-4,100);
                k=2;
                }
            else if(eevv.key.code==sf::Keyboard::Right){
                rectangle.setPosition((32*11)-4,100);
                k=3;
                }
            else if(eevv.key.code==sf::Keyboard::Return){
                window1.close();
            }
            
            window1.clear();
            window1.draw(text);
            window1.draw(elfSprite);
            window1.draw(druidSprite);
            window1.draw(paladinSprite);
            window1.draw(rectangle);
            window1.display();
            }

    }
    return k;
}

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

