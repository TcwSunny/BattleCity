#ifndef BRICK_H
#define BRICK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Brick:public QObject, public QGraphicsPixmapItem
{
public:
    Brick();
};

#endif // BRICK_H
