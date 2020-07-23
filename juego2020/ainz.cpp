#include "ainz.h"

int ainz::getX() const
{
    return x;
}

void ainz::setX(int value)
{
    x = value;
}

int ainz::getY() const
{
    return y;
}

void ainz::setY(int value)
{
    y = value;
}

ainz::ainz()
{

}

ainz::ainz(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF ainz::boundingRect() const
{
    return QRect(x,y,w,h);
}

void ainz::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/Jaldabaoth (1).png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
