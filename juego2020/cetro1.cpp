#include "cetro1.h"

int cetro1::getX() const
{
    return x;
}

void cetro1::setX(int value)
{
    x = value;
}

int cetro1::getY() const
{
    return y;
}

void cetro1::setY(int value)
{
    y = value;
}

cetro1::cetro1()
{

}

cetro1::cetro1(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF cetro1::boundingRect() const
{
    return QRect(x,y,w,h);
}

void cetro1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/cetroainz.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
