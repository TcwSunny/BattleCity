#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Bullet.h"
#include "Player1.h"

class EnemyBullet :public Bullet
{
public:
    EnemyBullet(Tank *tank);

    void move();


signals:

private:
};

#endif // ENEMYBULLET_H