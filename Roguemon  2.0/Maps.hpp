//
//  Maps.hpp
//  Roguemon  2.0
//
//  Created by Guido Lippi on 05/05/16.
//  Copyright © 2016 guidolippi. All rights reserved.
//

#ifndef Maps_hpp
#define Maps_hpp

#include <stdio.h>
#include "Constants.hpp"

const int baseMap [dimMapx][dimMapy]={
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 0},
    {0, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 0},
    {0, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


int walkMap[dimMapx][dimMapy];

int level[dimMapx*dimMapy];

#endif /* Maps_hpp */




/*
 
 
 crea matrice BaseMap -> contiene 0,1,2,3 per musica e tile
 
 crea matrice di conversione da BasMap a walkableMap di binari
 
 crea vettore di 0,1,2,3 che andra in input a tilemap
 
 
 
 
 
 
 int *makeLevel(int b[dimMapx][dimMapy]);
 
 int *makeLevel(int b[dimMapx][dimMapy]){
 static int area[dimMapx*dimMapy];
 
 
 }
 return area;
 }

 
 */