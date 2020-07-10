#include "jugador.h"
#include "QDebug"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */


Jugador::Jugador()
{
    setPixmap(QPixmap(":/imagen/momonga perfil.png"));      //da una imagen al personaje
    float posx, posy, velx , vely ,r, mass, K, e;
    posx = 105;      //declara la posición en X inicial del personaje
    posy = 300;     //declara la posición en Y inicial del personaje
    r = 65;         //declara el radio del personaje
    mass = 50;      //declara la masa del personaje
    velx = 0;       //la velocidad inicial  X del personaje
    vely = 0;       //la velocidad inicial  Y del personaje
    K = 0.08;       //determina la resistencia al aire del personaje
    e = 0.2;        //determina el coeficiente de restitución que tendra el personaje

    player = new actualizaciones(posx,posy,velx,vely,mass,r,K,e);       //aplica las propiedades anteriores al personaje
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
