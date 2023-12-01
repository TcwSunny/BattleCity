#include "Bullet.h"
#include "Tank.h"

#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QTimer>

Bullet::Bullet(Tank *tank)
{
    //setRect(0, 0, 10, 50);
    setPixmap(QPixmap(":/images/Images/bullet.png"));

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &Bullet::move);//當發生time out時使用這個物件的move處理
    timer->start(50); // fires every 50ms
    Parent = tank;
}

void Bullet::move() {
    if(x()>15 && x()<475 && y()>15 && y()<315){
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

Tank *Bullet::getParent() const
{
    return Parent;
}

void Bullet::setParent(Tank *newParent)
{
    Parent = newParent;
}



int Bullet::getRotation() const
{
    return Rotation;
}

void Bullet::setRotation(int newRotation)
{
    Rotation = newRotation;
}

