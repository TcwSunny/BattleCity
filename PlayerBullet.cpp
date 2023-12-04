#include "PlayerBullet.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QTimer>

PlayerBullet::PlayerBullet(Tank *tank) : Bullet(tank) {
    setPixmap(QPixmap(":/images/Images/bullet.png"));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(50);

    Parent = tank;
}
