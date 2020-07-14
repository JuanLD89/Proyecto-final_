#include "enemy.h"


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
    setPos(x(),y()+5);
    if(pos().y() > 630){
        setPos(x()-5,y()-5);

    }
    if (pos().x() < 30){
        scene()->removeItem(this);
        delete this;
    }

}
