#ifndef TRONO_H
#define TRONO_H


#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */
#include "actualizaciones.h"

class trono: public QObject, public QGraphicsPixmapItem
{
public:
    trono();
    ~trono();

    void actualizar1(float v_lim);
    actualizaciones* gettrono();
    trono *tronot1;

private:
    actualizaciones* tronot;
};

#endif // TRONO_H


