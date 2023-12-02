#ifndef BASICTANK_H
#define BASICTANK_H

#include "Tank.h"



class BasicTank: public Tank
{
public:
    BasicTank();
    Bullet *getBullet() const;
    void setBullet(Bullet *newBullet);
    void enemyShootBullet();

public slots:
    void move();

private:
    QTimer *timer;
    QTimer *timerBullet;
    bool isChangingDirection;
    Bullet *bullet;
};

#endif // BASICTANK_H
