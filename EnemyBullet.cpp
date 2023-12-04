#include "Brick.h"
#include "EnemyBullet.h"
#include "Player1.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QTimer>


EnemyBullet::EnemyBullet(Tank *tank):Bullet(tank)
{
    setPixmap(QPixmap(":/images/Images/bullet.png"));

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &Bullet::move);//當發生time out時使用這個物件的move處理
    timer->start(50); // fires every 50ms
    Parent = tank;
}


