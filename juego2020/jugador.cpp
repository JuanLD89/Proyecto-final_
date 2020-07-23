#include "jugador.h"
#include "QDebug"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */
#include <typeinfo>


Jugador::Jugador(int x)
{
    float posx, posy, velx , vely ,r, mass, K, e;

    if (x==1){
        setPixmap(QPixmap(":/imagen/momonga perfil.png"));
    }

    if (x==2){
        setPixmap(QPixmap(":/imagen/momogawar.png"));
    }
    if (x==1){
        posx = 105;
        posy = 30;
        r = 65;
        mass = 50;
        velx = 0;
        vely = 0;
        K = 0.08;
        e = 0.2;
        player = new actualizaciones(posx,posy,velx,vely,mass,r,K,e);

    }
    if (x==2){
        posx = 1040;
        posy = 30;
        r = 65;
        mass = 50;
        velx = 0;
        vely = 0;
        K = 0.08;
        e = 0.2;
        player = new actualizaciones(posx,posy,velx,vely,mass,r,K,e);

    }
}

Jugador::~Jugador()         //destructor
{
    delete player;
}

void Jugador::actualizar(float v_lim)
{
    player->actualizar();                   //llama a la función alctualizar y actualiza las propiedades  personaje
    setPos(player->get_posX(),(v_lim-player->get_posY()));  //declara la posición final del personaje
}

actualizaciones *Jugador::getPlayer()
{
    return player;          //retornal personaje con todas sus cualidades, su posicion, su masa, su radio, sus velocidades iniciales, etc
}


