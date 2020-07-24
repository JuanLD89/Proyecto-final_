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

class magia: public QObject, public QGraphicsPixmapItem
{
    int puntaje;
    Q_OBJECT
public:
    magia();
    void getcolision(int puntaje);


public slots:
    void move();


};
class magia1: public QObject, public QGraphicsPixmapItem
{
    int puntaje;
    Q_OBJECT
public:
    magia1();
    void getcolision1(int puntaje);


public slots:
    void move1();


};

#endif // MAGIA_H
