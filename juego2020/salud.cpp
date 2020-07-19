#include "salud.h"

int salud::getX() const
{
    return x;
}

void salud::setX(int value)
{
    x = value;
}

int salud::getY() const
{
    return y;
}

void salud::setY(int value)
{
    y = value;
}

salud::salud()
{

}

salud::salud(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF salud::boundingRect() const
{
    return QRect(x,y,w,h);
}

void salud::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/simbolo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
