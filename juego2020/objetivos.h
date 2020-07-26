#ifndef OBJETIVOS_H
#define OBJETIVOS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>



class objetivos: public QGraphicsItem       //esta clase se encarga de crear unos blancos que se necesiara en la opción individual primer nivel
{
    int x;      //posicion en x (plano cartesiano)
    int y;      //posicion en y (plano cartesiano)
    int w;      //ancho(width)
    int h;      //altura(high)

public:
    objetivos();
    objetivos(int x_,int y_, int w_, int h_);
    QRectF boundingRect() const;        //dibuja una figura
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);         //pinta la figura creada anteriormente
    int getX() const;       //obtiene la posición en x (plano cartesiano)
    void setX(int value);   //dar un valor nuevo a la posición x
    int getY() const;       //obtiene la posición en y (plano cartesiano)
    void setY(int value);   //dar un valor nuevo a la posición y
};

#endif // OBJETIVOS_H

