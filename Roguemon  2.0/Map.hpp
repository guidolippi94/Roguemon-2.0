//
//  Map.hpp
//  Roguemon  2.0
//
//  Created by Francesco Pegoraro on 23/04/16.
//  Copyright © 2016 guidolippi. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Constants.hpp"
#include "Observer.hpp"
#include "Elf.hpp"

class Map : public Observer{
    
public:
    
    Map(Elf* p);
    
    ~Map();
    
    virtual void update();
    
    void callMusic();
    
    
    int musicMap[dimMapx][dimMapy]=
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 1},
        {1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1},
        {1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
private:
    Elf* px;
    int currentI;
    int currentJ;
    int lastI;  //indicheranno la posizione in quel moomento del player
    int lastJ;

};
#endif /* Map_hpp */
