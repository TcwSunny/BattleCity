#include "PlayerBullet.h"
#include "Environment.h"
#include "Tank.h"
#include "Enemy.h"
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
void PlayerBullet::move() {
    if(x()>15 && x()<475 && y()>15 && y()<315){

        QList<QGraphicsItem*> colliding_items = collidingItems();
        foreach (QGraphicsItem *item, colliding_items) {
            Environment *barrier = dynamic_cast<Environment *>(item);
            if (barrier && (barrier->getMapState()== 0)) {
                Parent->setIsBulletInScene(0);
                scene()->removeItem(barrier);
                delete barrier;
                scene()->removeItem(this);
            }else{
                Enemy *enemy = dynamic_cast<Enemy*>(item);
                if (enemy) {
                    Parent->setIsBulletInScene(0);
                    enemy->decreaseHealth();
                    if(enemy->getHealth()==0){
                        delete enemy;
                    }
                    scene()->removeItem(this);
                }


            }

        }

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
