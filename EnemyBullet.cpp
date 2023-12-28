#include "Brick.h"
#include "EnemyBullet.h"
#include "Player.h"
#include "Castle.h"
#include "Scene.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QTimer>
#include <QFile>


EnemyBullet::EnemyBullet(Tank *tank,int speed):Bullet(tank)
{
    setPixmap(QPixmap(":/images/Images/bullet.png"));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &EnemyBullet::move);
    timer->start(speed);
    Parent = tank;
    isMovementPaused = false;

}
void EnemyBullet::move() {
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
            if (dynamic_cast<Player*>(item)) {
                scene()->removeItem(this);
                Parent->setIsBulletInScene(0);
                Player *player = dynamic_cast<Player*>(item);
                int playerHealth = player->getHealth();

                if(player->getHelmetOn()==0){
                   player->setHealth(playerHealth - 1);
                }
                if(player->getHealth()==0){
                    emit playerDie();
                }
            }
            if(dynamic_cast<Castle*>(item)){
                scene()->removeItem(this);
                Parent->setIsBulletInScene(0);
                Castle *castle = dynamic_cast<Castle*>(item);
                int castleHealth = castle->getHealth();
                castle->setHealth(castleHealth-1);
                if(castle->getHealth()==0){
                    emit castleDie();}
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

void EnemyBullet::toggleMovementPause()
{
    isMovementPaused = !isMovementPaused;
}
