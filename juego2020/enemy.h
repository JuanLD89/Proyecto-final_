#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QLCDNumber>

class Enemy:public QObject, public QGraphicsPixmapItem      //clase encargada de crear lo enemigos del primer nivel
{
private:
    int vida;       //variable privad que nos ayuda con el tma dla vidas en el mainwindow
    Q_OBJECT
public:
    Enemy();
    void getcolisionenemy(int vida);        //funcion que se encargara de escribir en un archivo de texto para llevar la cuenta de vidas


public slots:
    void move();        //se encarga de direccionar el movimiento del enemigo

};

#endif // ENEMY_H
