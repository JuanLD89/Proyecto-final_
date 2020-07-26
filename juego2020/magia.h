#ifndef MAGIA_H
#define MAGIA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "anillo.h"
#include "mainwindow.h"
#include "jugador.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

class magia: public QObject, public QGraphicsPixmapItem     //clase encargada de crear la magia que el jugador lanzara
{
    int puntaje;        //variable que se usara para afectar el puntaje
    Q_OBJECT
public:
    magia();
    void getcolision(int puntaje);      //mira las colisiones para afectar el puntaje en el mainwindow


public slots:
    void move();        //direcciona el movimiento de la magia


};
class magia1: public QObject, public QGraphicsPixmapItem        //clase encargada de crear la magia que el jugador lanzara  en multijugador
{
    int puntaje;        //variable que se usara para afectar el puntaje
    Q_OBJECT
public:
    magia1();
    void getcolision1(int puntaje);     //mira las colisiones para afectar el puntaje en el mainwindow


public slots:
    void move1();         //direcciona el movimiento de la magia


};

#endif // MAGIA_H
