#include "Enemy.h"
#include <QRandomGenerator>
#include <Qtimer>
#include "Brick.h"
#include "Bullet.h"
#include "Water.h"
#include "QGraphicsScene"
#include "Scene.h"

Enemy::Enemy()
{
    //隨機生成數字
    QPixmap pixmap;
    enemyState = QRandomGenerator::global()->bounded(1, 5);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemy::move);
    isMovementPaused = false;

    //依照數字生成enemy
    switch(enemyState){
    case 1:
        pixmap.load(":/images/Images/Tank_Enemy1.png");
        timer->start(100);
        bullet = new EnemyBullet(this,1000);
        timerBullet = new QTimer();
        connect(timerBullet, &QTimer::timeout, this, &Enemy::enemyShootBullet);
        timerBullet->start(3000);
        health = 1;
        break;
    case 2:
        pixmap.load(":/images/Images/Tank_Enemy2.png");
        timer->start(33);
        bullet = new EnemyBullet(this,500);
        timerBullet = new QTimer();
        connect(timerBullet, &QTimer::timeout, this, &Enemy::enemyShootBullet);
        timerBullet->start(3000);
        health = 1;
        break;
    case 3:
        pixmap.load(":/images/Images/Tank_Enemy3.png");
        timer->start(50);
        bullet = new EnemyBullet(this,333);
        timerBullet = new QTimer();
        connect(timerBullet, &QTimer::timeout, this, &Enemy::enemyShootBullet);
        timerBullet->start(3000);
        health = 1;
        break;
    case 4:
        pixmap.load(":/images/Images/Tank_Enemy4.png");
        timer->start(50);
        bullet = new EnemyBullet(this,500);
        timerBullet = new QTimer();
        connect(timerBullet, &QTimer::timeout, this, &Enemy::enemyShootBullet);
        timerBullet->start(3000);
        health = 4;
        break;
    }



    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
    setRotation(0);
    isChangingDirection = false;



}

Enemy::~Enemy()
{

    emit enemyDie(enemyState*100);

}

EnemyBullet *Enemy::getBullet() const
{
    return bullet;
}

void Enemy::setBullet(EnemyBullet *newBullet)
{
    bullet = newBullet;
}

void Enemy::enemyShootBullet()
{
    //當bullet不在螢幕上時收到shoot則將bullet射出
    if (this->getIsBulletInScene()==0) {
        this->getBullet()->setPos(this->x()+12,this->y()+12);
        this->getBullet()->Rotate(this->getRotation());
        scene()->addItem(this->getBullet());
        this->setIsBulletInScene(1);
    }
}

void Enemy::move()
{
    if (isMovementPaused) {
        return;
    }
    //讓enemy在框框內移動
    if (x() >= 10 && x() <= 458 && y() >= 10 && y() <= 298){
        QList<QGraphicsItem *> collidingItemsList = collidingItems();
        foreach(QGraphicsItem* item, collidingItemsList) {
            if (dynamic_cast<Brick*>(item) or dynamic_cast<Water*>(item)) {

                if(getRotation()==0 or getRotation()==360){
                    setPos(x(), y() + 4);
                } else if (getRotation() == 90) {
                setPos(x() - 4, y());
                } else if (getRotation() == 180) {
                    setPos(x(), y() - 4);
                } else if (getRotation() == 270) {
                    setPos(x() + 4, y());
                }
                //讓enemy撞牆後隨機轉彎
                int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
                while(newRotation == getRotation()){//改善enemy重複撞牆
                    newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
                }
                Rotate(newRotation);
                return;
            }
        }
        //讓enemy行駛到一半隨機轉彎
        int probToRotate = QRandomGenerator::global()->bounded(0, 50) ;
        if(probToRotate == 1){
            int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
            Rotate(newRotation);
        }
        if (getRotation() == 0 or getRotation() == 360) {
            setPos(x(), y() - 4);
        } else if (getRotation() == 90) {
            setPos(x() + 4, y());
        } else if (getRotation() == 180) {
            setPos(x(), y() + 4);
        } else if (getRotation() == 270) {
            setPos(x() - 4, y());
        }
    } else {
        if (x() < 10){
            setPos(10,y());
        }else if (x() > 458){
            setPos(458,y());
        }else if(y() < 10){
            setPos(x(),10);
        }else if(y() > 298){
            setPos(x(),298);
        }
        if (!isChangingDirection) {
            isChangingDirection = true;
            int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
            while(newRotation == getRotation()){
                newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
            }
            Rotate(newRotation);
        }
    }
    isChangingDirection = false;
}

int Enemy::getHealth() const
{
    return health;
}

void Enemy::decreaseHealth()
{
    health--;
}

void Enemy::toggleMovementPause()
{
    isMovementPaused = !isMovementPaused;
    if(isMovementPaused){
        timerBullet->stop();
    }else{
        timerBullet->start();
    }
}

