#ifndef OBSTACULOS_H
#define OBSTACULOS_H
#include <QGraphicsPixmapItem>
#include <math.h>
#include <jugador.h>
class obstaculos : public QGraphicsPixmapItem       //clase encargada del crear las bolas de fuego y su mov circular
{
public:
    obstaculos(double posx, double posy, int anchoo, int altoo);
    void movimientoCircular();      //la fisica del mov circular


private:
    double px;      //pos en x
    double py;      //pos en y
    int ancho;      //ancho dela bola
    int alto;       //alto de la bola
    double anguloRad=0; //angulo del radio
    double angulo=0;    //angulo para el movimiento
    double radio =5;    //radio,controja que tan grande es el movimiento circular



};
class obstaculos1 : public QGraphicsPixmapItem       //clase encargada del crear las bolas de fuego y su mov circular
{
public:
    obstaculos1(double posx1, double posy1, int anchoo1, int altoo1);
    void movimientoCircular1();     //la fisica del mov circular


private:
    double px1;     //pos en x
    double py1;     //pos en y
    int ancho1;     //ancho de la bola
    int alto1;      //alto de la bola
    double anguloRad1=0;    //angulo del radio
    double angulo1=0;       //angulo para el movimiento
    double radio1 =5;       //radio,controja que tan grande es el movimiento circular



};

class obstaculos2 : public QGraphicsPixmapItem       //clase encargada del crear las bolas de fuego y su mov circular
{
public:
    obstaculos2(double posx2, double posy2, int anchoo2, int altoo2);
    void movimientoCircular2();     //la fisica del mov circular


private:
    double px2;     //pos en x
    double py2;     //pos en y
    int ancho2;     //ancho de la bola
    int alto2;      //alto de la bola
    double anguloRad2=0;    //angulo del radio
    double angulo2=0;       //angulo para el movimiento
    double radio2 =5;       //radio,controja que tan grande es el movimiento circular



};

#endif // OBSTACULOS_H

