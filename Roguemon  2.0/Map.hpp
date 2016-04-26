
#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Constants.hpp"
#include "Observer.hpp"
#include "Elf.hpp"
#include "Music.hpp"

class Map : public Observer{
    
public:
    
    Map(MainCharacter* p);
    
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
    MainCharacter* px;
    int currentI;  //indicheranno la posizione in quel moomento del player
    int currentJ;
    int lastI;
    int lastJ;
    Music music;
};
#endif /* Map_hpp */
