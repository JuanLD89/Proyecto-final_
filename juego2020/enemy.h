#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QLCDNumber>

class Enemy:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();

};

#endif // ENEMY_H
