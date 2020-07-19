#include "swords.h"

int swords::getX() const
{
    return x;
}

void swords::setX(int value)
{
    x = value;
}

int swords::getY() const
{
    return y;
}

void swords::setY(int value)
{
    y = value;
}

swords::swords()
{

}

swords::swords(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF swords::boundingRect() const
{
    return QRect(x,y,w,h);
}

void swords::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/swords (1).png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

