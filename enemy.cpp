#include "enemy.h"
#include "mainwindow.h"
#include <QTextStream>


Enemy::Enemy()
{
    setPos(1017,75);    //se declara la posición por la cual apareceran los enemigos

    setPixmap(QPixmap(":/imagen/enemigo.png"));     //dibuja al enemigo con una imagen predeterminada

    //connect
    QTimer * timer = new QTimer();          //crea un timer
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));        //conecta el timer con la funcion move que se encarga del movimiento del enemigo

    timer->start(50);       //cada determinado tiempo revisara la función move

}

void Enemy::getcolisionenemy(int vida)
{
    QFile Archivo ("enemigos.txt");             //busca el archivo
      if(Archivo.open(QIODevice::WriteOnly | QIODevice::Text)){        //abre el archivo
       QTextStream datosArchivo(&Archivo);          //se ubica en el archivo para escribir
       datosArchivo<<vida;        //escribe en el archivo
    }
      Archivo.close();              //cierra el archivo

}
void Enemy::move()
{

    //move enemy up
    setPos(x(),y()+10);         //el objeto enemigo se moverá en y
    if(pos().y() > 610){        //si el objeto llega a una determinada posición cambia la trayectoria
        setPos(x()-10,y()-10);  //el objeto enemigo se moverá en x y en y

    }
    if (pos().x() < 75){        //si enemigo llega a cierta posición
        vida=1;                 //vida, la varuable declarada anteriormente en header se modifica a uno
        getcolisionenemy(vida); //se llama a la funcion getcolisiones
        scene()->removeItem(this);  //se remueve el objeto enemigos
        delete this;        //se borra el objeto
    }
}
