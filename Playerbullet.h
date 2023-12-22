#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "Bullet.h"
#include <QObject>


class PlayerBullet : public Bullet
{
    Q_OBJECT
public:
    PlayerBullet(Tank *tank);
    void move();
signals:

private:

};

#endif // PLAYERBULLET_H
