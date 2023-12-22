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

    PlayerBullet *getBullet() const;
    void setBullet(PlayerBullet *newBullet);

    int getHealth() const;
    void setHealth(int newHealth);

    void setHelmetOn(bool hel);
    bool getHelmetOn();

signals:
private:
    PlayerBullet *bullet;
    int Health;
    bool helmetOn;
};

#endif // PLAYER_H
