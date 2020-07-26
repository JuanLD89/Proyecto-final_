#ifndef TRONO_H
#define TRONO_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class trono: public QGraphicsItem       //fución no necesaria. pendiente de eliminar
{
    int x;      //posicion en x (plano cartesiano)
    int y;      //posicion en y (plano cartesiano)
    int w;      //ancho(width)
    int h;      //altura(high)
public:
    trono();
    trono(int x_,int y_, int w_, int h_);
    QRectF boundingRect() const;        //dibuja una figura
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);         //pinta la figura creada anteriormente
    int getX() const;       //obtiene la posición en x (plano cartesiano)
    void setX(int value);   //dar un valor nuevo a la posición x
    int getY() const;       //obtiene la posición en y (plano cartesiano)
    void setY(int value);   //dar un valor nuevo a la posición y
};

#endif // TRONO_H


