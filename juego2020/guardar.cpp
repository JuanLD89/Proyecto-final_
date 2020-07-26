#include "guardar.h"


void guardar::agregar(int level,int lives,int points)
{
    ofstream registro;      //se le permite a registro copiar en el archivo
    registro.open("../juego2020/Nuevo documento de texto.txt", ios::out);       //se abre el archivo Nuevo documento de texto.txt
    if (registro.fail())            //si hay alguna falla abriendo el archivo se retorna error
        cerr << "Error" << endl;
    registro<<level;    //se escribe en el archivo de texto el nivel
    registro<<" ";      //se escribe en el archivo de texto
    registro<<lives;    //se escribe en el archivo de texto las vidas
    registro<<" ";      //se escribe en el archivo de texto
    registro<<points;   //se escribe en el archivo de texto el puntaje
    registro<<endl;     //se escribe en el archivo de texto

}
