#include "magia.h"
#include "enemy.h"

magia::magia()
{
       setPixmap(QPixmap(":/imagen/bluefire.png"));

       //MOVER LA FLECHA
       QTimer *timer = new QTimer();
       connect(timer,SIGNAL(timeout()),this,SLOT(move()));
       timer->start(50);

}
void magia::move()
{
    QList<QGraphicsItem *> colliding_items =collidingItems();
    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            scene()->removeItem(this);
            delete this;
            return;
        }

    }
    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(objetivos)){
            scene()->removeItem(colliding_items[i]);
            puntaje=1;
            getcolision(puntaje);
            delete colliding_items[i];
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(momonga)){
            scene()->removeItem(colliding_items[i]);
            puntaje=1;
            getcolision(puntaje);
            delete colliding_items[i];
            scene()->removeItem(this);
            delete this;
            return;
        }
    }


   // return false;
    setPos(x()+20,y());
    if (pos().x() > 1050){
        scene()->removeItem(this);
        delete this;
    }

}

void magia::getcolision(int puntaje)
{
    ofstream registro;
    registro.open("../juego2020/Nuevo documento de texto (2).txt", ios::out);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<puntaje;
}


magia1::magia1()
{
       setPixmap(QPixmap(":/imagen/momongasword (1).png"));

       //MOVER LA FLECHA
       QTimer *timer = new QTimer();
       connect(timer,SIGNAL(timeout()),this,SLOT(move1()));
       timer->start(50);
}

void magia1::getcolision1(int puntaje)
{
    ofstream registro;
    registro.open("../juego2020/Nuevo documento de texto (4).txt", ios::out);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<puntaje;
}
void magia1::move1()
{
    QList<QGraphicsItem *> colliding_items =collidingItems();

    for (int i = 0, n = colliding_items.size();i<n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(ainz)){
            scene()->removeItem(colliding_items[i]);
            puntaje=1;
            getcolision1(puntaje);
            delete colliding_items[i];
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x()-20,y());
    if (pos().x() < 30){
        scene()->removeItem(this);
        delete this;
    }
}


