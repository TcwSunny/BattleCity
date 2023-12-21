#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"
#include "PlayerBullet.h"
#include <QObject>
#include <QGraphicsPixmapItem>

class Player : public Tank
{
    Q_OBJECT
public:
    explicit Player(int num);

    int getHealth() const;
    void setHealth(int newHealth);

    Bullet *getBullet() const;
    void setBullet(Bullet *newBullet);

signals:
private:
    int Health;
    Bullet *bullet;

};

#endif // PLAYER_H
