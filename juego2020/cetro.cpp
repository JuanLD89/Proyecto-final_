#include "cetro.h"

int cetro::getX() const
{
    return x;
}

void cetro::setX(int value)
{
    x = value;
}

int cetro::getY() const
{
    return y;
}

void cetro::setY(int value)
{
    y = value;
}

cetro::cetro()
{

}

cetro::cetro(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF cetro::boundingRect() const
{
    return QRect(x,y,w,h);
}

void cetro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/cetroainz.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
