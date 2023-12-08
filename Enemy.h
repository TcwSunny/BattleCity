#ifndef ENEMY_H
#define ENEMY_H

#include "EnemyBullet.h"
#include "Tank.h"



class Enemy: public Tank
{
public:
    Enemy();
    EnemyBullet *getBullet() const;
    void setBullet(EnemyBullet *newBullet);
    void enemyShootBullet();

    int getHealth() const;
    void decreaseHealth();

public slots:
    void move();

private:
    QTimer *timer;
    QTimer *timerBullet;
    bool isChangingDirection;
    EnemyBullet *bullet;
    int health;
};


#endif // ENEMY_H