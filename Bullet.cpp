#include "Brick.h"
#include "Bullet.h"
#include "Tank.h"

#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QTimer>

Bullet::Bullet()
{

}

void Bullet::move() {

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

