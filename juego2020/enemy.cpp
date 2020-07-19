#include "enemy.h"
#include "mainwindow.h"


Enemy::Enemy()
{
    setPos(999,55);

    setPixmap(QPixmap(":/imagen/enemigo.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{

    //move enemy up
    setPos(x(),y()+10);
    if(pos().y() > 610){
        setPos(x()-10,y()-10);

    }
    if (pos().x() < 70){
        scene()->removeItem(this);
        delete this;

    }


}
