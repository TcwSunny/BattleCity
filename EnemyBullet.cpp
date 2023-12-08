#include "Brick.h"
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

    QList<QGraphicsItem *> colliding_items = collidingItems();//取得相撞物件清單
    foreach (QGraphicsItem *item, colliding_items) {//對每個item辨別enemy
        Brick * brick = dynamic_cast<Brick*>(item);//轉型，不是enemy則傳回none
        if (brick) {

            // Remove from the scene first
            scene()->removeItem(brick);
            scene()->removeItem(this);
            // Delete from the memory
            delete brick;
            Parent->setIsBulletInScene(false);
            return; // important
        }
    }

    if(x()>15 && x()<475 && y()>15 && y()<315){

        // Check for collisions with bricks
        QList<QGraphicsItem*> colliding_items = collidingItems();

        foreach (QGraphicsItem *item, colliding_items) {
            if (dynamic_cast<Brick*>(item)) {
                // Collided with a brick, remove both the bullet and the brick
                scene()->removeItem(this);
                Parent->setIsBulletInScene(0);


            }
            if (dynamic_cast<Player*>(item)) {
                // Collided with a brick, remove both the bullet and the brick
                scene()->removeItem(this);
                Parent->setIsBulletInScene(0);
                Player *player = dynamic_cast<Player*>(item);
                int playerHealth = player->getHealth();
                player->setHealth(playerHealth - 1);
            }
            break;
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
