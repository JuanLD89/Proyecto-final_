#include "trono.h"
#include "QDebug"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */

trono::trono()
{
    setPixmap(QPixmap(":/imagen/congrats.png").scaled(700,300));
    float posx, posy, velx , vely ,r, mass, K, e;
    posx = 200;
    posy = 550;
    r = 65;
    mass = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.2;

    tronot = new actualizaciones(posx,posy,velx,vely,mass,r,K,e);
}

trono::~trono()
{
    delete tronot;
}

void trono::actualizar1(float v_lim)
{
    tronot->actualizar();
    setPos(tronot->get_posX(),(v_lim-tronot->get_posY()));
}

actualizaciones *trono::gettrono()
{
    return tronot;
}
