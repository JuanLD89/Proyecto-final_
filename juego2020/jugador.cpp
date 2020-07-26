#include "jugador.h"
#include "QDebug"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */
#include <typeinfo>


Jugador::Jugador(int x)
{
    float posx, posy, velx , vely ,r, mass, K, e;

    if (x==1){
        setPixmap(QPixmap(":/imagen/momonga perfil.png"));      //dibuja el personaje con respecto a una figura predeterminada
    }

    if (x==2){
        setPixmap(QPixmap(":/imagen/momogawar.png"));           //dibuja el personaje con respecto a una figura predeterminada
    }
    if (x==1){
        posx = 550;         //determina una posicion inicial en x
        posy = 30;          //determina una posicion inicial en y
        r = 65;             //da un radio al personaje
        mass = 50;          //da una masa(peso) al personaje
        velx = 0;           //determina una velocidad inicial en x
        vely = 0;           //determina una velocidad inicial en y
        K = 0.08;           //resistencia del aire
        e = 0.2;            //coeficiente de restitucion.
        player = new actualizaciones(posx,posy,velx,vely,mass,r,K,e);

    }
    if (x==2){
        posx = 650;         //determina una posicion inicial en x
        posy = 30;          //determina una posicion inicial en y
        r = 65;             //da un radio al personaje
        mass = 50;          //da una masa(peso) al personaje
        velx = 0;           //determina una velocidad inicial en x
        vely = 0;           //determina una velocidad inicial en r
        K = 0.08;           //resistencia del aire
        e = 0.2;            //coeficiente de restitucion.
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


