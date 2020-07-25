#ifndef OBSTACULOS_H
#define OBSTACULOS_H
#include <QGraphicsPixmapItem>
#include <math.h>
#include <jugador.h>
class obstaculos : public QGraphicsPixmapItem
{
public:
    obstaculos(double posx, double posy, int anchoo, int altoo);
    void movimientoCircular();


private:
    double px;
    double py;
    int ancho;
    int alto;
    double anguloRad=0;
    double angulo=0;
    double radio =5;



};
class obstaculos1 : public QGraphicsPixmapItem
{
public:
    obstaculos1(double posx1, double posy1, int anchoo1, int altoo1);
    void movimientoCircular1();


private:
    double px1;
    double py1;
    int ancho1;
    int alto1;
    double anguloRad1=0;
    double angulo1=0;
    double radio1 =5;



};

class obstaculos2 : public QGraphicsPixmapItem
{
public:
    obstaculos2(double posx2, double posy2, int anchoo2, int altoo2);
    void movimientoCircular2();


private:
    double px2;
    double py2;
    int ancho2;
    int alto2;
    double anguloRad2=0;
    double angulo2=0;
    double radio2 =5;



};

#endif // OBSTACULOS_H

