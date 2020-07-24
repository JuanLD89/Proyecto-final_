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
private:
    int vida;
    Q_OBJECT
public:
    Enemy();
    void getcolisionenemy(int vida);


public slots:
    void move();

};

#endif // ENEMY_H
