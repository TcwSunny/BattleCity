#include "Bullet.h"
#include "Player1.h"

Player1::Player1():Health(2)
{
    QPixmap pixmap(":/images/Images/Tank_Player1.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);

    bullet = new PlayerBullet(this);
}

PlayerBullet *Player1::getBullet() const
{
    return bullet;
}

void Player1::setBullet(PlayerBullet *newBullet)
{
    bullet = newBullet;
}

int Player1::getHealth() const
{
    return Health;
}

void Player1::setHealth(int newHealth)
{
    Health = newHealth;
}
