//
//  Music.hpp
//  Roguemon  2.0
//
//  Created by Francesco Pegoraro on 23/04/16.
//  Copyright © 2016 guidolippi. All rights reserved.
//

#ifndef Music_hpp
#define Music_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <curses.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <stdio.h>


class Music {
public:
    
    void playMusic();
    
protected:
    
    sf::SoundBuffer soundtrack;
    sf::Sound sound;
    
};

#endif /* Music_hpp */
