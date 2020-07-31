#include "guardar.h"
#include <QFile>
#include <QTextStream>


void guardar::agregar(int level,int lives,int points)
{
    QFile Archivo ("Nuevo documento de texto.txt");             //busca el archivo
      if(Archivo.open(QIODevice::WriteOnly | QIODevice::Text)){        //abre el archivo
       QTextStream datosArchivo(&Archivo);          //se ubica en el archivo para escribir
       datosArchivo<<level;    //se escribe en el archivo de texto el nivel
       datosArchivo<<" ";      //se escribe en el archivo de texto
       datosArchivo<<lives;    //se escribe en el archivo de texto las vidas
       datosArchivo<<" ";      //se escribe en el archivo de texto
       datosArchivo<<points;   //se escribe en el archivo de texto el puntaje
       datosArchivo<<endl;     //se escribe en el archivo de texto
    }
      Archivo.close();              //cierra el archivo

}
