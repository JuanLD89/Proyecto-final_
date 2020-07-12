#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "jugador.h"
#include "mainwindow.h"


Enemy::Enemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    //set random posicion
    int random_number = rand() % 1100;
    setPos(random_number,55);
    //draw the bullet
    setPixmap(QPixmap(":/imagen/enemigo.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    //move enemy up
    setPos(x(),y()+5);
    if(pos().y() > 590){
        scene()->removeItem(this);
        delete this;
    }

}
