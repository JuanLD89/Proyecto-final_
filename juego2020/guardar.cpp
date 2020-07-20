#include "guardar.h"


void guardar::agregar(int level,int lives,int points)
{
    ofstream registro;
    registro.open("../juego2020/Nuevo documento de texto.txt", ios::out);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<level;
    registro<<" ";
    registro<<lives;
    registro<<" ";
    registro<<points;
    registro<<endl;

}
