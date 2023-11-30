#include "Player1.h"

Player1::Player1()
{
    QPixmap pixmap(":/images/Images/Tank_Player1.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);

}

void Player1::Rotate(int x)
{
    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(), c.y());
    t.rotate(x);
    t.translate(-c.x(), -c.y());
    setTransform(t);
    Rotation = x;
}

int Player1::getRotation() const
{
    return Rotation;
}

void Player1::setRotation(int newRotation)
{
    Rotation = newRotation;
}
