#include "enemy.h"
#include "mainwindow.h"

Enemy::Enemy()
{
    setPos(1017,75);

    setPixmap(QPixmap(":/imagen/enemigo.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);

}

void Enemy::getcolisionenemy(int vida)
{
    ofstream registro;
    registro.open("../juego2020/enemigos.txt", ios::out);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<vida;
}

void Enemy::move()
{

    //move enemy up
    setPos(x(),y()+10);
    if(pos().y() > 610){
        setPos(x()-10,y()-10);

    }
    if (pos().x() < 75){
        vida=1;
        getcolisionenemy(vida);
        scene()->removeItem(this);
        delete this;
    }
}
