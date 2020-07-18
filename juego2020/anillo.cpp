#include "anillo.h"

int Anillo::getX() const
{
    return x;
}

void Anillo::setX(int value)
{
    x = value;
}

int Anillo::getY() const
{
    return y;
}

void Anillo::setY(int value)
{
    y = value;
}

Anillo::Anillo()
{

}

Anillo::Anillo(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF Anillo::boundingRect() const
{
    return QRect(x,y,w,h);
}

void Anillo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/Ring_of_Ainz_Ooal_Gown (1).png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
