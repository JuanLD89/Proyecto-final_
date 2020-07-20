#ifndef OBJETIVOS_H
#define OBJETIVOS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>



class objetivos: public QGraphicsItem
{
    int x;
    int y;
    int w;
    int h;

public:
    objetivos();
    objetivos(int x_,int y_, int w_, int h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
};

#endif // OBJETIVOS_H

