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

int Enemy::getenemy()
{
    if (pos().x() < 70){
        vida=1;
        return vida;

    }
    else{
        vida = 0;
        return vida;
    }

}

void Enemy::move()
{

    //move enemy up
    setPos(x(),y()+10);
    if(pos().y() > 610){
        setPos(x()-10,y()-10);

    }
    if (pos().x() < 70){
        vida=1;
        scene()->removeItem(this);
        delete this;
    }
    else{
        vida=0;
    }



}
