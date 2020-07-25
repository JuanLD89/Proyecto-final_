#include "obstaculos.h"


obstaculos::obstaculos(double posx, double posy, int anchoo, int altoo)
{
    px= posx;
    py = posy;
    ancho = anchoo;
    alto = altoo;
    setPixmap(QPixmap(":/imagen/bolaFuego.png").scaled(40,40));
    setPos(px,py);
}

void obstaculos::movimientoCircular()
{
    anguloRad=angulo*3.14/180;
    px= px+radio*cos(anguloRad);
    py=py+radio*sin(anguloRad);
    setPos(px,py);
    angulo+=5;
    if (angulo>=360)
    {
        angulo=0;
    }
}

obstaculos1::obstaculos1(double posx1, double posy1, int anchoo1, int altoo1)
{
    px1= posx1;
    py1 = posy1;
    ancho1 = anchoo1;
    alto1 = altoo1;
    setPixmap(QPixmap(":/imagen/bolaFuego.png").scaled(40,40));
    setPos(px1,py1);
}

void obstaculos1::movimientoCircular1()
{
    anguloRad1=angulo1*3.14/180;
    px1= px1+radio1*cos(anguloRad1);
    py1=py1+radio1*sin(anguloRad1);
    setPos(px1,py1);
    angulo1+=5;
    if (angulo1>=360)
    {
        angulo1=0;
    }
}
obstaculos2::obstaculos2(double posx2, double posy2, int anchoo2, int altoo2)
{
    px2= posx2;
    py2 = posy2;
    ancho2 = anchoo2;
    alto2 = altoo2;
    setPos(px2,py2);
}

void obstaculos2::movimientoCircular2()
{
    anguloRad2=-(angulo2*3.14/180);
    px2= (px2+radio2*cos(anguloRad2));
    py2= (py2+radio2*sin(anguloRad2));
    setPos(px2,py2);
    angulo2+=5;
    if (angulo2>=360)
    {
        angulo2=0;
    }
}
