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
        for (int i = 0, n = colliding_items.size();i<n;i++) {
            if(typeid(*(colliding_items[i])) == typeid(Anillo)){

                    scene()->removeItem(colliding_items[i]);
                    delete colliding_items[i];

                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }



    setPos(x()+10,y());
    if (pos().x() > 1150){
        scene()->removeItem(this);
        delete this;
    }

}
