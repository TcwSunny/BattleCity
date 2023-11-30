#include "Tank.h"

Tank::Tank():isBulletInScene(0)
{

}

void Tank::Rotate(int x)
{
    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(), c.y());
    t.rotate(x);
    t.translate(-c.x(), -c.y());
    setTransform(t);
    Rotation = x;
}

int Tank::getRotation() const
{
    return Rotation;
}

void Tank::setRotation(int newRotation)
{
    Rotation = newRotation;
}

bool Tank::getIsBulletInScene() const
{
    return isBulletInScene;
}

void Tank::setIsBulletInScene(bool newIsBulletInScene)
{
    isBulletInScene = newIsBulletInScene;
}
