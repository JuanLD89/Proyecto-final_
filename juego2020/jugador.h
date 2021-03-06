#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */
#include "actualizaciones.h"
#include "enemy.h"

class Jugador: public QObject, public QGraphicsPixmapItem              //usa la libreria QGraphicsPixmapItem para dibujar al personaje
{
public:
    Jugador(int x);
    ~Jugador();

    void actualizar(float v_lim);               //actualiza las posiciones del jugador
    actualizaciones* getPlayer();               //declara un puntero getplayer como conexión con la clase actualizaciones
    Jugador *player1;

private:
    actualizaciones* player;                     //declara un puntero player como conexión con la clase actualizacionesz
    int player3;


};

#endif // JUGADOR_H
