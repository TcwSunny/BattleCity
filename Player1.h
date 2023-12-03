#ifndef PLAYER1_H
#define PLAYER1_H

#include "Tank.h"
#include "PlayerBullet.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class Player1 : public Tank
{
    Q_OBJECT
public:
    explicit Player1();

    PlayerBullet *getBullet() const;
    void setBullet(PlayerBullet *newBullet);

    int getHealth() const;
    void setHealth(int newHealth);

signals:
private:
    PlayerBullet *bullet;
    int Health;

};

#endif // PLAYER1_H
