#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class Player : public Tank
{
    Q_OBJECT
public:
    explicit Player(int num);

    int getHealth() const;
    void setHealth(int newHealth);

signals:
private:
    int Health;

};

#endif // PLAYER_H
