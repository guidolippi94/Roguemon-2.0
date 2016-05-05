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

const int level[] = //mappa  0->albero   1->erba   2->sabbia   3->roccia
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 0,
    0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 0,
    0, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 0,
    0, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
//walkable    1->NO     0->SI
int mappa[dimMapx][dimMapy]=
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


#endif /* Maps_hpp */


/*
 TileMap prende in ingresso un vettore
 Migliore gestione con matrice
 
 
 crea matrice BaseMap -> contiene 
 
 */