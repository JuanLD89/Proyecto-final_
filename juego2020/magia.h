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
    void ven();


};

#endif // MAGIA_H
