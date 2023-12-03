#ifndef BASICTANK_H
#define BASICTANK_H

#include "EnemyBullet.h"
#include "Tank.h"



class BasicTank: public Tank
{
public:
    BasicTank();

public slots:
    void move();

private:
    QTimer *timer;
    bool isChangingDirection;
    EnemyBullet *bullet;
};

#endif // BASICTANK_H
