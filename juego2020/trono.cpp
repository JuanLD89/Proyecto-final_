#include "trono.h"

int trono::getX() const
{
    return x;               //retorna la posicion en x
}

void trono::setX(int value)
{
    x = value;              //asigna un nuevo valor a x
}

int trono::getY() const
{
    return y;               //retorna la posicion en y
}

void trono::setY(int value)
{
    y = value;              //asigna un nuevo valor a y
}

trono::trono()
{

}

trono::trono(int x_, int y_, int w_, int h_)
{

    x=x_;           //asigna un valor para la posición en x
    y=y_;           //asigna un valor para la posición en y
    w=w_;           //asigna un valor para la anchura
    h=h_;           //asigna un valor para la altura
}

QRectF trono::boundingRect() const
{
    return QRect(x,y,w,h);      //retorna la figura con las posiciones y las mediciones
}

void trono::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/Ring_of_Ainz_Ooal_Gown (1).png");         //carga la imagen
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());       //dibuja la imagen
}
