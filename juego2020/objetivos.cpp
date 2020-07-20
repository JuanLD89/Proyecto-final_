#include "objetivos.h"

int objetivos::getX() const
{
    return x;
}

void objetivos::setX(int value)
{
    x = value;
}

int objetivos::getY() const
{
    return y;
}

void objetivos::setY(int value)
{
    y = value;
}

objetivos::objetivos()
{

}

objetivos::objetivos(int x_, int y_, int w_, int h_)
{
    x=x_;
    y=y_;
    w=w_;
    h=h_;
   // setPos(x,-y);
}

QRectF objetivos::boundingRect() const
{
    return QRect(x,y,w,h);
}

void objetivos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/imagen/objetivos.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

