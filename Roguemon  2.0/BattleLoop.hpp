

#ifndef BattleLoop_hpp
#define BattleLoop_hpp



#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdexcept>

void updateLife(std::string *pl,std::string *el,  Character *p, Character *e, sf::Text *et, sf::Text *ee );



void BattleLoop(std::vector<Character*> *chrt, int ID){
    
    Character *player = chrt->at(0);
    Character *enemy =  chrt->at(ID);
    
    //grafica battle
    sf::Texture playerTexture, enemyTexture, battleTexture;
    sf::Sprite playerSprite, enemySprite, battleSprite;
    
    sf::RectangleShape rectp, recte;

    rectp.setSize(sf::Vector2f(100, 50));
    recte.setSize(sf::Vector2f(100, 50));

    rectp.setOutlineColor(sf::Color::Red);
    recte.setOutlineColor(sf::Color::Red);

    rectp.setOutlineThickness(5);
    recte.setOutlineThickness(5);

    rectp.setPosition(400, 200);
    recte.setPosition(20, 10);
    
    sf::Font font;
    if (!font.loadFromFile("Lobster_1.3.otf"))
    {
        std::cout<< "failed to open font"<<std::endl;
    }
    
    sf::Text playerlife, enemylife;
  
    playerlife.setColor(sf::Color::Black);
    enemylife.setColor(sf::Color::Black);



    playerlife.setFont(font);
    enemylife.setFont(font);
    
    playerlife.setCharacterSize(20);
    enemylife.setCharacterSize(20);
    
    playerlife.setPosition(402, 200);
    enemylife.setPosition(22, 10);


    
    std::string playerpng = player->getType() + "battle.png";
    if(!playerTexture.loadFromFile(playerpng))
        std::cout<<"Error, could not load "<<playerpng<<std::endl;
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0,0,110,128));
    playerSprite.setPosition(32,128);
    
    
    std::string enemypng = std::to_string(enemy->getId()) + ".png";//prendo l'id del mostro perchè la frontalsprite del mostro si chiama ID.png
    if(!enemyTexture.loadFromFile(enemypng))
        std::cout<<"Error, could not load  "<<enemypng<<std::endl;
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(32*11,50);
    
    if(!battleTexture.loadFromFile("battlebackground.png"))
        std::cout<<"Error, could not load battlebackground texture"<<std::endl;
    battleSprite.setTexture(battleTexture);
    battleSprite.setScale(2.2, 2.4);
    

    bool enemyatk = false;
    
    sf::RenderWindow window2(sf::VideoMode(32*16, 32*8), "Battle!!");
    
    //window2.setKeyRepeatEnabled(false);
    window2.setMouseCursorVisible(false);

    std::string playerlifeConv = std::to_string(player->getLife());
    playerlife.setString(playerlifeConv);
    
    
    std::string enemylifeConv = std::to_string(enemy->getLife());
    enemylife.setString(enemylifeConv);
    
    sf::Event events;
    
    while (window2.isOpen()){
        
        
        updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

    
     
       
        
        window2.clear();
        window2.draw(battleSprite);
        window2.draw(playerSprite);
        window2.draw(rectp);
        window2.draw(recte);
        window2.draw(enemySprite);
        window2.draw(playerlife);
        window2.draw(enemylife);
        window2.display();
        updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

        while (window2.pollEvent(events)){
            updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

            
            if(events.type == sf::Event::Closed){
                window2.close();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window2.close();
            }
            if (events.type == sf::Event::KeyReleased) {
                updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

                if (events.key.code==sf::Keyboard::Space) {
                    updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

                    enemy->reduceLife(player->getAttack());
                    enemyatk=true;

                    if (enemy->getLife()<=0) {
                        updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

                        chrt->erase(chrt->begin()+ID);
                        enemyatk=false;
                        window2.close();
                    }
                    updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

                  
                    if (enemyatk) {
                        player->reduceLife(enemy->getAttack());
                        enemyatk = false;
                        updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

                    }
                    if (player->getLife()<=0) {
                        chrt->erase(chrt->begin());
                        window2.close();
                    }
                    updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

                    
                }
            }
            
           
            updateLife(&playerlifeConv, &enemylifeConv, player, enemy, &playerlife, &enemylife);

            window2.clear();
            window2.draw(battleSprite);
            window2.draw(playerSprite);
            window2.draw(rectp);
            window2.draw(recte);
            window2.draw(enemySprite);
            window2.draw(playerlife);
            window2.draw(enemylife);
            window2.display();
   
        }//eventloop

    }//gameloop
}

bool collision (sf::Vector2f vp1, sf::Vector2f vp2){  //metodo per collisioni con nemici, se ci troviamo in un raggio di 4px
    float a=fabs(vp1.x-vp2.x);  //fabs fa il valore assoluto
    float b=fabs(vp1.y-vp2.y);
    if (a<4 && b<4) {
        return true;
    }
    return false;
}

void updateLife(std::string *pl,std::string *el,  Character *p, Character *e, sf::Text *et, sf::Text *ee){
    *pl = std::to_string(p->getLife());
    *el = std::to_string(e->getLife());
    et->setString(*pl);
    ee->setString(*el);


}

#endif /* BattleLoop_hpp */
