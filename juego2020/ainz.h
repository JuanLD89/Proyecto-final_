#ifndef AINZ_H
#define AINZ_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class ainz: public QGraphicsItem        //esta clase/cabezera es para crear uno de los objetivos en la opción de multiplayer

{
    int x;      //posicion en x (plano cartesiano)
    int y;      //posicion en y (plano cartesiano)
    int w;      //ancho(width)
    int h;      //altura(high)

public:
    ainz();
    ainz(int x_,int y_, int w_, int h_);
    QRectF boundingRect() const;        //dibuja el objeto ainz(en este caso en un objetivo al cual apuntar)
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);     //funcion para dar color e imagen al objeto
    int getX() const;       //obtiene la posición en x
    void setX(int value);   //dar un valor nuevo a la posición x
    int getY() const;       //obtiene la posición en y
    void setY(int value);   //dar un valor nuevo a la posición y
};

#endif // AINZ_H
