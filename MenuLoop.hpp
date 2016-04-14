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

int getPressedKey();

bool MenuLoop(sf::RenderWindow *window, bool *firstTimeRectangle){
    
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
    if(firstTimeRectangle){
        rectangle.setPosition(100, 100);
        *firstTimeRectangle=false;
        std::cout<<*firstTimeRectangle<<std::endl;
    }
    
    if(getPressedKey()==6){
        rectangle.setPosition((32*3)-4,100);
    }
    else if(getPressedKey()==7){
        rectangle.setPosition((32*7)-4,100);
    }
    else if(getPressedKey()==8){
        rectangle.setPosition((32*11)-4,100);
    }

    
    /*if(!playerTexture.loadFromFile(addr))//carico l immag del persongg
     std::cout<<"image2 not found"<<std::endl;
     
     playersprite.setTexture(playerTexture);
     playersprite.setPosition(64,64);
     */
    
    window->clear();
    window->draw(text);
    window->draw(elfSprite);
    window->draw(druidSprite);
    window->draw(paladinSprite);
    window->draw(rectangle);
    window->display();
    if(getPressedKey() == 5){
        window->clear();
        return false;
    }else{
        return true;
    }
}
