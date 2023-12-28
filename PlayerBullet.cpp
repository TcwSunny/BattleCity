#include "Enemy.h"
#include "Brick.h"
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
    isMovementPaused = false;
}

void PlayerBullet::toggleMovementPause()
{
    isMovementPaused = !isMovementPaused;
}
void PlayerBullet::move() {
    if (isMovementPaused) {
        return;
    }
    //當bullet撞到brick時，刪除brick及bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
        Brick * brick = dynamic_cast<Brick*>(item);
        if (brick) {
            scene()->removeItem(brick);
            scene()->removeItem(this);
            delete brick;
            Parent->setIsBulletInScene(false);
            return;
        }
    }

    if(x()>15 && x()<475 && y()>15 && y()<315){
        //當bullet撞到player及castle
        QList<QGraphicsItem*> colliding_items = collidingItems();
        foreach (QGraphicsItem *item, colliding_items) {
            if (dynamic_cast<Enemy*>(item)) {
                Enemy *enemy = dynamic_cast<Enemy*>(item);
                scene()->removeItem(this);
                Parent->setIsBulletInScene(0);
                enemy->decreaseHealth();
                if(enemy->getHealth()==0){
                    delete enemy;
                }

            }
            break;
        }
        //移動
        if(Rotation == 0){
            setPos(x(), y()-8);
        }else if(Rotation == 90){
            setPos(x()+8, y());
        }else if(Rotation == 180){
            setPos(x(), y()+8);
        }else if(Rotation == 270){
            setPos(x()-8, y());
        }
    }else{
        if (scene() != nullptr) {
            scene()->removeItem(this);
            Parent->setIsBulletInScene(0);
        }
    }
}
