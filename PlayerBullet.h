#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "Bullet.h"
#include <QObject>


class PlayerBullet : public Bullet
{
    Q_OBJECT
public:
    PlayerBullet(Tank *tank);
void toggleMovementPause();
    void move();
signals:
    //void killOneEnemy();
private:
    bool isMovementPaused;

};

#endif // PLAYERBULLET_H
