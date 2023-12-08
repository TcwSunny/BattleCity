#include "Bullet.h"
#include "Player.h"

Player::Player(int num):Health(2)
{
    if(num == 1){
        QPixmap pixmap(":/images/Images/Tank_Player1.png");
        pixmap = pixmap.scaled(QSize(32, 32));
        setPixmap(pixmap);
    }else if(num == 2){
        QPixmap pixmap(":/images/Images/Tank_Player2.png");
        pixmap = pixmap.scaled(QSize(32, 32));
        setPixmap(pixmap);
    }


    bullet = new PlayerBullet(this);
}

PlayerBullet *Player::getBullet() const
{
    return bullet;
}

void Player::setBullet(PlayerBullet *newBullet)
{
    bullet = newBullet;
}

int Player::getHealth() const
{
    return Health;
}

void Player::setHealth(int newHealth)
{
    Health = newHealth;
}
