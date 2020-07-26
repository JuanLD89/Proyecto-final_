#include "salud.h"

int salud::getX() const
{
    return x;           //retorna la posicion en x
}

void salud::setX(int value)
{
    x = value;          //asigna un nuevo valor a x
}

int salud::getY() const
{
    return y;       //retorna la posicion en y
}

void salud::setY(int value)
{
    y = value;      //asigna un nuevo valor a y
}

salud::salud()
{

}

salud::salud(int x_, int y_, int w_, int h_)
{

    x=x_;           //asigna un valor para la posición en x
    y=y_;           //asigna un valor para la posición en y
    w=w_;           //asigna un valor para la anchura
    h=h_;           //asigna un valor para la altura
}

QRectF salud::boundingRect() const
{
    return QRect(x,y,w,h);      //retorna la figura con las posiciones y las mediciones
}

void salud::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/simbolo.png");            //carga la imagen
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());   //dibuja la imagen
}
