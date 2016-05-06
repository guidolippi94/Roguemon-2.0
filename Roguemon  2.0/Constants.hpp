

#ifndef Constants_hpp
#define Constants_hpp

#include <stdio.h>

const int dimMapx = 100;
const int dimMapy = 100;

const int screenX = 32*24;
const int screenY = 32*48;

const int viewX = 32*1;
const int viewY = 32*1;


int baseMap[dimMapx][dimMapy]={0};

int walkMap[dimMapx][dimMapy];

int level[dimMapx*dimMapy];

#endif /* Constants_hpp */
