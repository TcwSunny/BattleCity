#ifndef FASTTANK_H
#define FASTTANK_H

#include "Tank.h"
#include "EnemyBullet.h"

class FastTank : public Tank
{
public:
    FastTank();

public slots:
    void move();

signals:
private:
    QTimer *timer;
    QTimer *timerBullet2;
    bool isChangingDirection;


};

#endif // FASTTANK_H
