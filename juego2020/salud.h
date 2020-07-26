#ifndef SALUD_H
#define SALUD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class salud: public QGraphicsItem           //esta clase se encarga de crear unos objetos que daran una vida extra en la opción individual

{
    int x;      //posicion en x (plano cartesiano)
    int y;      //posicion en y (plano cartesiano)
    int w;      //ancho(width)
    int h;      //altura(high)

public:
    salud();
    salud(int x_,int y_, int w_, int h_);
    QRectF boundingRect() const;        //dibuja una figura
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);     //pinta la figura creada anteriormente
    int getX() const;       //obtiene la posición en x (plano cartesiano)
    void setX(int value);   //dar un valor nuevo a la posición x
    int getY() const;       //obtiene la posición en y (plano cartesiano)
    void setY(int value);   //dar un valor nuevo a la posición y
};

#endif // SALUD_H
