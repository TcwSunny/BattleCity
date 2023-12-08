#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Bullet.h"
#include "Player.h"

class EnemyBullet :public Bullet
{
public:
    EnemyBullet(Tank *tank, int speed);

    void move();


signals:

private:
};

#endif // ENEMYBULLET_H
