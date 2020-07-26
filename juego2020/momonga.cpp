#include "momonga.h"

int momonga::getX() const
{
    return x;       //retorna la posicion en x
}

void momonga::setX(int value)
{
    x = value;      //asigna un nuevo valor a x
}

int momonga::getY() const
{
    return y;       //retorna la posicion en y
}

void momonga::setY(int value)
{
    y = value;      //asigna un nuevo valor a y
}

momonga::momonga()
{

}

momonga::momonga(int x_, int y_, int w_, int h_)
{

    x=x_;           //asigna un valor para la posición en x
    y=y_;           //asigna un valor para la posición en y
    w=w_;           //asigna un valor para la anchura
    h=h_;           //asigna un valor para la altura
}

QRectF momonga::boundingRect() const
{
    return QRect(x,y,w,h);      //retorna la figura con las posiciones y las mediciones
}

void momonga::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/over.png");           //carga la imagen
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());       //dibuja la imagen
}

