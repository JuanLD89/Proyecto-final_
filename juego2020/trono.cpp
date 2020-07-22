#include "trono.h"

int trono::getX() const
{
    return x;
}

void trono::setX(int value)
{
    x = value;
}

int trono::getY() const
{
    return y;
}

void trono::setY(int value)
{
    y = value;
}

trono::trono()
{

}

trono::trono(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF trono::boundingRect() const
{
    return QRect(x,y,w,h);
}

void trono::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/Ring_of_Ainz_Ooal_Gown (1).png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
