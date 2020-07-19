#ifndef MAGIA_H
#define MAGIA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "anillo.h"
#include "mainwindow.h"
#include "jugador.h"

class magia: public QObject, public QGraphicsPixmapItem
{
    int puntaje;
    Q_OBJECT
public:
    magia();

public slots:
    void move();
    void ven();
    bool getcolision();


};

#endif // MAGIA_H
