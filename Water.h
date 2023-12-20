#ifndef WATER_H
#define WATER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Water:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Water();
};

#endif // WATER_H
