#ifndef BASICTANK_H
#define BASICTANK_H

#include "EnemyBullet.h"
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
<<<<<<< HEAD
    Bullet *bullet;
=======
    EnemyBullet *bullet;
>>>>>>> c77999523b9164060937412abd99af0833f9ad62
};

#endif // BASICTANK_H
