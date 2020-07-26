#ifndef ANILLO_H
#define ANILLO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Anillo: public QGraphicsItem  //esta opción es para crear el anillo objetivo, para lograr pasar el primer nivel en individual

{
    int x;      //posicion en x (plano cartesiano)
    int y;      //posicion en y (plano cartesiano)
    int w;      //ancho(width)
    int h;      //altura(high)


public:
    Anillo();
    Anillo(int x_,int y_, int w_, int h_);
    QRectF boundingRect() const;        //dibuja el objeto ,en este caso un anillo en el primer nivel
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);     //pinta la imagen, el objeto que anteriormente se creo
    int getX() const;       //obtiene la posición en x (plano cartesiano)
    void setX(int value);   //dar un valor nuevo a la posición x
    int getY() const;       //obtiene la posición en y (plano cartesiano)
    void setY(int value);   //dar un valor nuevo a la posición y
};

#endif // ANILLO_H
