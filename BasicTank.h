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
    QTimer *timerBullet;
    bool isChangingDirection;
    EnemyBullet *bullet;
};


#endif // BASICTANK_H
