#include "PlayerBullet.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QTimer>

PlayerBullet::PlayerBullet(Tank *tank)
{
    //setRect(0, 0, 10, 50);
    setPixmap(QPixmap(":/images/Images/bullet.png"));

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &Bullet::move);//當發生time out時使用這個物件的move處理
    timer->start(50); // fires every 50ms
    Parent = tank;
}
