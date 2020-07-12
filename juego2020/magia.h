#ifndef MAGIA_H
#define MAGIA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class magia: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    magia();

public slots:
    void move();
};

#endif // MAGIA_H
