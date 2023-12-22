#ifndef CASTLE_H
#define CASTLE_H

#include <QObject>

#include <QGraphicsPixmapItem>

class Castle : public QGraphicsPixmapItem
{
public:
    Castle();
    void setHealth(int newHealth);
    int getHealth();
private:
    int health;
};

#endif // CASTLE_H
