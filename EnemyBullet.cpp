#include "EnemyBullet.h"
#include "Player.h"
#include "Scene.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QTimer>


EnemyBullet::EnemyBullet(Tank *tank,int speed):Bullet(tank)
{
    setPixmap(QPixmap(":/images/Images/bullet.png"));

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &EnemyBullet::move);//當發生time out時使用這個物件的move處理
    timer->start(speed); // 移動速度
    Parent = tank;
}
void EnemyBullet::move() {

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
                Player *player = dynamic_cast<Player*>(item);
                if (player) {
                    Parent->setIsBulletInScene(0);
                    player->setHealth(player->getHealth()-1);
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
