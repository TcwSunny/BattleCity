#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "Bullet.h"



class PlayerBullet : public Bullet
{
public:
    PlayerBullet(Tank *tank);
    void move();
};

#endif // PLAYERBULLET_H
