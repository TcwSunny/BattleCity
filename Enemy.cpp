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
    QPixmap pixmap;
    enemyState = QRandomGenerator::global()->bounded(1, 5);

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &Enemy::move);//當發生time out時使用這個物件的move處理


    switch(enemyState){
    case 1:
        pixmap.load(":/images/Images/Tank_Enemy1.png");
        timer->start(100); // fires every 50ms
        bullet = new EnemyBullet(this,1000);
        timerBullet = new QTimer();
        connect(timerBullet, &QTimer::timeout, this, &Enemy::enemyShootBullet);
        timerBullet->start(3000);
        health = 1;
        break;
    case 2:
        pixmap.load(":/images/Images/Tank_Enemy2.png");
        timer->start(33); // fires every 50ms
        bullet = new EnemyBullet(this,500);
        timerBullet = new QTimer();
        connect(timerBullet, &QTimer::timeout, this, &Enemy::enemyShootBullet);
        timerBullet->start(3000);
        health = 1;
        break;
    case 3:
        pixmap.load(":/images/Images/Tank_Enemy3.png");
        timer->start(50); // fires every 50ms
        bullet = new EnemyBullet(this,333);
        timerBullet = new QTimer();
        connect(timerBullet, &QTimer::timeout, this, &Enemy::enemyShootBullet);
        timerBullet->start(3000);
        health = 1;
        break;
    case 4:
        pixmap.load(":/images/Images/Tank_Enemy4.png");
        timer->start(50); // fires every 50ms
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
    if (this->getIsBulletInScene()==0) {
        this->getBullet()->setPos(this->x()+12,this->y()+12);
        this->getBullet()->Rotate(this->getRotation());
        scene()->addItem(this->getBullet());
        this->setIsBulletInScene(1);
    }
}

void Enemy::move()
{
    if (x() >= 10 && x() <= 458 && y() >= 10 && y() <= 298){
        // Check for collisions with bricks
        QList<QGraphicsItem *> collidingItemsList = collidingItems();
        foreach(QGraphicsItem* item, collidingItemsList) {
            if (dynamic_cast<Brick*>(item) or dynamic_cast<Water*>(item)) {
                // Collided with a brick, change direction

                if(getRotation()==0 or getRotation()==360){
                    setPos(x(), y() + 4);
                } else if (getRotation() == 90) {
                setPos(x() - 4, y()); // 向右移動 4 個單位
                } else if (getRotation() == 180) {
                    setPos(x(), y() - 4); // 向下移動 4 個單位
                } else if (getRotation() == 270) {
                    setPos(x() + 4, y()); // 向左移動 4 個單位
                }
                int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
                while(newRotation == getRotation()){ //改善tank重複撞牆的窘境
                    newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
                }
                Rotate(newRotation);
                return;
            }
        }
        int probToRotate = QRandomGenerator::global()->bounded(0, 50) ;
        if(probToRotate == 1){ //讓basicTank有隨機轉彎的機會
            int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
            Rotate(newRotation);
        }
        if (getRotation() == 0 or getRotation() == 360) {
            setPos(x(), y() - 4); // 向上移動 4 個單位
        } else if (getRotation() == 90) {
            setPos(x() + 4, y()); // 向右移動 4 個單位
        } else if (getRotation() == 180) {
            setPos(x(), y() + 4); // 向下移動 4 個單位
        } else if (getRotation() == 270) {
            setPos(x() - 4, y()); // 向左移動 4 個單位
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
            while(newRotation == getRotation()){ //改善tank重複撞牆的窘境
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

