
#include "Map.hpp"


Map::Map(Elf* p) {    //alla costruzione 
    px = p;
    px->subscribe(this);
    lastJ=px->getPos().x;
    lastI=px->getPos().y;
}

Map::~Map(){
    px->unsubscribe(this);
}

void Map::update(){  //metodo update che non prende niente perchè pull ma chiama i get per sapere lastmsg e lastuser
    currentI= px->getPos().x;
    currentJ= px->getPos().y;
    callMusic();
}


void Map::callMusic(){
    if(musicMap[currentI][currentJ] != musicMap[lastI][lastJ]){
        lastI=currentI;
        lastJ=currentJ;
        std::cout<<"changed zone"<<std::endl;
    }
}

