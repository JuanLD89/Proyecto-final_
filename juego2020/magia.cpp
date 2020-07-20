#include "magia.h"
#include "enemy.h"

magia::magia()
{
       setPixmap(QPixmap(":/imagen/bluefire.png"));

       //MOVER LA FLECHA
       QTimer *timer = new QTimer();
       connect(timer,SIGNAL(timeout()),this,SLOT(move()));
       timer->start(50);
       QTimer *timerr = new QTimer();
       connect(timerr,SIGNAL(timeout()),this,SLOT(ven()));
       timerr->start(50);
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


   // return false;
    setPos(x()+20,y());
    if (pos().x() > 1050){
        scene()->removeItem(this);
        delete this;
    }

}

void magia::ven()
{


}

void magia::getcolision(int puntaje)
{
    ofstream registro;
    registro.open("../juego2020/Nuevo documento de texto (2).txt", ios::out);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<puntaje;
}

