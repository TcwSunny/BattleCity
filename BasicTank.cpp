#include "BasicTank.h"
#include <QRandomGenerator>
#include <Qtimer>
#include "Brick.h"
#include "Bullet.h"
#include "Water.h"
#include "QGraphicsScene"
BasicTank::BasicTank()
{
    QPixmap pixmap(":/images/Images/Tank_Enemy1.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);

    setRotation(0);
    isChangingDirection = false;

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &BasicTank::move);//當發生time out時使用這個物件的move處理
    timer->start(100); // fires every 50ms

    bullet = new Bullet(this);
    timerBullet = new QTimer();
    connect(timerBullet, &QTimer::timeout, this, &BasicTank::enemyShootBullet);
    timerBullet->start(3000);

}

Bullet *BasicTank::getBullet() const
{
    return bullet;
}

void BasicTank::setBullet(Bullet *newBullet)
{
    bullet = newBullet;
}

void BasicTank::enemyShootBullet()
{
    if (this->getIsBulletInScene()==0) {
        this->getBullet()->setPos(this->x()+12,this->y()+12);
        this->getBullet()->Rotate(this->getRotation());
        scene()->addItem(this->getBullet());
        this->setIsBulletInScene(1);
    }
}

void BasicTank::move()
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
                qDebug() << getRotation();
                return;
            }
        }
        int probToRotate = QRandomGenerator::global()->bounded(0, 30) ;
        if(probToRotate == 1){
            int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
            Rotate(newRotation);
            qDebug() << getRotation();
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
            qDebug() << getRotation();
        }
    }
    isChangingDirection = false;
}



