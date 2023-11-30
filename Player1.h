#ifndef PLAYER1_H
#define PLAYER1_H

#include "Tank.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class Player1 : public Tank
{
    Q_OBJECT
public:
    explicit Player1();

    Bullet *getBullet() const;
    void setBullet(Bullet *newBullet);

signals:
private:
    Bullet *bullet;

};

#endif // PLAYER1_H
