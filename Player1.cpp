#include "Bullet.h"
#include "Player1.h"

Player1::Player1()
{
    QPixmap pixmap(":/images/Images/Tank_Player1.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);

    bullet = new Bullet(this);
}

Bullet *Player1::getBullet() const
{
    return bullet;
}

void Player1::setBullet(Bullet *newBullet)
{
    bullet = newBullet;
}
