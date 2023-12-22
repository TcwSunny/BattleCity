#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Bullet.h"
#include "Player.h"

class EnemyBullet :public Bullet
{
    Q_OBJECT
public:
    EnemyBullet(Tank *tank, int speed);

    void move();


signals:
    void playerDie();
    void castleDie();
private:
};

#endif // ENEMYBULLET_H
