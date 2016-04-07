


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "TileMap.hpp"
#include "Elf.hpp"
#include "Monster.hpp"
#include <unistd.h>

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
    else return -1;
}

bool MenuLoop(sf::RenderWindow *window , sf::Text text){
    window->clear();
    window->draw(text);
    window->display();
    if(getPressedKey() == 5){
        window->clear();
        return false;
    }else{
        return true;
    }
}

void GameLoop(){
    
}

int main()
{
    bool walk = true;
    bool menu = true;
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(32*16, 32*8), "prova");
    
    sf::Font font;
    if (!font.loadFromFile("Lobster_1.3.otf"))
    {
        std::cout<< "failed to open font"<<std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Menu");
    text.setCharacterSize(100); // in pixels, not points!
    text.setColor(sf::Color::Red);
    
    // set the text style
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    // inside the main loop, between window.clear() and window.display()
    
    
    
    // define the level with an array of tile indices  //la window è 32*16,32*8
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
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
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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
    
    std::vector<Character*> characters;
    
    Elf *elfo = new Elf(1,1, 5);
    Monster *mostro = new Monster(2,2,6 , "mewtwo.png");
    Monster *mostro2 = new Monster(3,3,7, "greeninja.png");
    
    characters.push_back(mostro);
    characters.push_back(mostro2);
    characters.push_back(elfo);
    
    sf::Clock c;
    
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
        
        if(menu){
            if(!MenuLoop(&window , text)){
                menu = false;
            }
        }
        else{
            mostro->SetTextureState();
            elfo->SetTextureState();
            mostro2->SetTextureState();
            
            // draw the map
            window.clear();
            
            window.draw(map);
            
            if (walk) {
                int k = getPressedKey();
                if(k != -1){
                    for(int index = 2 ; index < 33 ; index++){
                        elfo->walk(mappa, index , k);
                        window.clear();
                        window.draw(map);
                        window.draw(elfo->getSprite());
                        window.draw(mostro->getSprite());
                        window.draw(mostro2->getSprite());
                        window.display();
                        usleep(6000);
                    }
                }
                walk = false;
            }
            //std::cout << c.getElapsedTime().asMilliseconds() << std::endl;
            if (c.getElapsedTime().asMilliseconds() > 150) {
                srand (c.getElapsedTime().asMicroseconds());
                int action = rand() % 4 +1;
                srand (c.getElapsedTime().asMilliseconds());
                int action2 = rand() % 4 +1;
                for(int index = 2 ; index < 33 ; index++){
                    mostro->walk(mappa , index , action);
                    mostro2->walk(mappa, index, action2);
                    window.clear();
                    window.draw(map);
                    window.draw(elfo->getSprite());
                    window.draw(mostro2->getSprite());
                    window.draw(mostro->getSprite());
                    window.display();
                    usleep(6000);
                }
                walk=true;
                c.restart();
            }
            if(elfo->getPos() == mostro->getPos()){
                std::cout << "Let's fight1!" << std::endl;
            }
            if(elfo->getPos() == mostro2->getPos()){
                std::cout << "Let's fight2!" << std::endl;
            }
            
            mostro->SetTextureState();
            elfo->SetTextureState();
            mostro2->SetTextureState();
            window.draw(mostro->getSprite());
            window.draw(elfo->getSprite());
            window.draw(mostro2->getSprite());
            window.display();
            window.clear();
            
        }
    }
    
    return 0;
}