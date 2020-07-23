#include "momonga.h"

int momonga::getX() const
{
    return x;
}

void momonga::setX(int value)
{
    x = value;
}

int momonga::getY() const
{
    return y;
}

void momonga::setY(int value)
{
    y = value;
}

momonga::momonga()
{

}

momonga::momonga(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF momonga::boundingRect() const
{
    return QRect(x,y,w,h);
}

void momonga::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/over.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

