
#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Constants.hpp"
#include "Observer.hpp"
#include "Elf.hpp"
#include "Music.hpp"

class Map : public Observer{
    
public:
    
    Map(MainCharacter* p, int mapCtor[dimMapx][dimMapy]);
    
    ~Map();
    
    virtual void update();
    
    void callMusic();
    
    
    int musicMap[dimMapx][dimMapy];
    
private:
    MainCharacter* px;
    int currentI;  //indicheranno la posizione in quel moomento del player
    int currentJ;
    int lastI;
    int lastJ;
    Music music;
};
#endif /* Map_hpp */
