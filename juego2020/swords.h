#ifndef SWORDS_H
#define SWORDS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class swords: public QGraphicsItem      //esta opción es para crear las espadas objetivo, para lograr pasar el segundo nivel en individual

{
    int x;      //posicion en x (plano cartesiano)
    int y;      //posicion en y (plano cartesiano)
    int w;      //ancho(width)
    int h;      //altura(high)


public:
    swords();
    swords(int x_,int y_, int w_, int h_);
    QRectF boundingRect() const;        //dibuja una figura
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);     //pinta la figura creada anteriormente
    int getX() const;       //obtiene la posición en x (plano cartesiano)
    void setX(int value);   //dar un valor nuevo a la posición x
    int getY() const;       //obtiene la posición en y (plano cartesiano)
    void setY(int value);   //dar un valor nuevo a la posición y
};



#endif // SWORDS_H
