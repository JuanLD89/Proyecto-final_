#include "obstaculos.h"


obstaculos::obstaculos(double posx, double posy, int anchoo, int altoo)
{
    px= posx;           //asigna una posición en x
    py = posy;          //asigna una posición en y
    ancho = anchoo;     //asigna un ancho a la bola de fuego
    alto = altoo;       //asigna un alto a la bola de fuego
    setPos(px,py);      // se asigna una posicion
}

void obstaculos::movimientoCircular()
{
    anguloRad=angulo*3.14/180;      //se configura el angulo del radio del ovimiento circular
    px= px+radio*cos(anguloRad);    //calcula la nueva posición en x
    py=py+radio*sin(anguloRad);     //calcula la nueva posición en y
    setPos(px,py);                  //declara la nueva posición para el movimiento
    angulo+=5;                      //le suma al angulo para calcular nuevamente en anguloRad
    if (angulo>=360)                //si da la vuelta completa el angulo vuelve a ser 0 para dar la vuelta y no dar otro movimieto extraño
    {
        angulo=0;                   //angulo vuelve a ser 0
    }
}

obstaculos1::obstaculos1(double posx1, double posy1, int anchoo1, int altoo1)
{
    px1= posx1;         //asigna una posición en x
    py1 = posy1;        //asigna una posición en y
    ancho1 = anchoo1;   //asigna un ancho a la bola de fuego
    alto1 = altoo1;     //asigna un alto a la bola de fuego
    setPos(px1,py1);    // se asigna una posicion
}

void obstaculos1::movimientoCircular1()
{
    anguloRad1=angulo1*3.14/180;        //se configura el angulo del radio del ovimiento circular
    px1= px1+radio1*cos(anguloRad1);    //calcula la nueva posición en x
    py1=py1+radio1*sin(anguloRad1);     //calcula la nueva posición en y
    setPos(px1,py1);                    //declara la nueva posición para el movimiento
    angulo1+=5;                         //le suma al angulo para calcular nuevamente en anguloRad
    if (angulo1>=360)                   //si da la vuelta completa el angulo vuelve a ser 0 para dar la vuelta y no dar otro movimieto extraño
    {
        angulo1=0;                      //angulo vuelve a ser 0
    }
}
obstaculos2::obstaculos2(double posx2, double posy2, int anchoo2, int altoo2)
{
    px2= posx2;         //asigna una posición en x
    py2 = posy2;        //asigna una posición en y
    ancho2 = anchoo2;   //asigna un ancho a la bola de fuego
    alto2 = altoo2;     //asigna un alto a la bola de fuego
    setPos(px2,py2);    // se asigna una posicion
}

void obstaculos2::movimientoCircular2()
{
    anguloRad2=-(angulo2*3.14/180);         //se configura el angulo del radio del ovimiento circular
    px2= (px2+radio2*cos(anguloRad2));      //calcula la nueva posición en x
    py2= (py2+radio2*sin(anguloRad2));      //calcula la nueva posición en y
    setPos(px2,py2);                        //declara la nueva posición para el movimiento
    angulo2+=5;                             //le suma al angulo para calcular nuevamente en anguloRad
    if (angulo2>=360)                       //si da la vuelta completa el angulo vuelve a ser 0 para dar la vuelta y no dar otro movimieto extraño
    {
        angulo2=0;                          //angulo vuelve a ser 0
    }
}
