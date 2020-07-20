#ifndef GUARDAR_H
#define GUARDAR_H


#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class guardar
{
    int level,lives,points;
public:
    void agregar(int level,int lives,int points);
};


#endif // GUARDAR_H
