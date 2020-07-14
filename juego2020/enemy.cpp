#include "enemy.h"


Enemy::Enemy()
{
    int random_number = rand() % 1100;
    setPos(random_number,55);

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
