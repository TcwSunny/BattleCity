#ifndef BASICTANK_H
#define BASICTANK_H

#include "EnemyBullet.h"
#include "Tank.h"



class BasicTank: public Tank
{
public:
    BasicTank();
    EnemyBullet *getBullet() const;
    void setBullet(EnemyBullet *newBullet);
    void enemyShootBullet();

public slots:
    void move();

private:
    QTimer *timer;
    bool isChangingDirection;
    EnemyBullet *bullet;
    QTimer *timerBullet;
};

#endif // BASICTANK_H
