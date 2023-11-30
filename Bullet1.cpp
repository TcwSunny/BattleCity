#include "Bullet1.h"

#include <QGraphicsScene>
#include <QList>
#include <QDebug>

Bullet1::Bullet1():isBulletInScene(0)
{
    //setRect(0, 0, 10, 50);
    setPixmap(QPixmap(":/images/Images/bullet.png"));

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &Bullet1::move);//當發生time out時使用這個物件的move處理
    timer->start(50); // fires every 50ms
}

void Bullet1::move() {
    if(x()>35 && x()<655 && y()>40 && y()<655){
        if(Rotation == 360){
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
            isBulletInScene = 0;
        }
    }
}

void Bullet1::Rotate(int x)
{
    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(), c.y());
    t.rotate(x+90);
    t.translate(-c.x(), -c.y());
    setTransform(t);
    Rotation = x+90;
}

bool Bullet1::getIsBulletInScene() const
{
    return isBulletInScene;
}

void Bullet1::setIsBulletInScene(bool newIsBulletInScene)
{
    isBulletInScene = newIsBulletInScene;
}

int Bullet1::getRotation() const
{
    return Rotation;
}

void Bullet1::setRotation(int newRotation)
{
    Rotation = newRotation;
}

