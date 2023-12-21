#include "Bullet.h"
#include "Tank.h"
#include "Player.h"
#include "Environment.h"
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QTimer>

Bullet::Bullet(Tank *tank)
{
    setPixmap(QPixmap(":/images/Images/bullet.png"));

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &Bullet::move);//當發生time out時使用這個物件的move處理
    timer->start(50); // fires every 50ms
    Parent = tank;
}



void Bullet::Rotate(int x)
{
    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(), c.y());
    t.rotate(x);
    t.translate(-c.x(), -c.y());
    setTransform(t);
    Rotation = x;
}
void Bullet::move() {

    if(x()>15 && x()<475 && y()>15 && y()<315){

        QList<QGraphicsItem*> colliding_items = collidingItems();
        foreach (QGraphicsItem *item, colliding_items) {
            Environment *barrier = dynamic_cast<Environment *>(item);
            if (barrier && (barrier->getMapState()== 0)) {
                Parent->setIsBulletInScene(0);
                scene()->removeItem(barrier);
                delete barrier;
                scene()->removeItem(this);
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


int Bullet::getRotation() const
{
    return Rotation;
}

void Bullet::setRotation(int newRotation)
{
    Rotation = newRotation;
}

