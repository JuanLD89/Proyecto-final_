#ifndef GUARDAR_H
#define GUARDAR_H


#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class guardar           //clase encargada de guardar el numero de vidas, el nivel y el puntaje
{
    int level,lives,points;     //variables privada que se escribiran en el archivo de texto
public:
    void agregar(int level,int lives,int points);       //función que invoca y escribe en el archivo de texto
};


#endif // GUARDAR_H
