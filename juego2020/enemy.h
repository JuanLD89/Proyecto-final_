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
    int vida;
    Q_OBJECT
public:
    Enemy();
    bool getenemy();

public slots:
    void move();

};

#endif // ENEMY_H
