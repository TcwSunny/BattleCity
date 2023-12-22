#include "Castle.h"

Castle::Castle():health(1)
{
    QPixmap pixmap(":/images/Images/bitch.jpg");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}

void Castle::setHealth(int newHealth)
{
    health = newHealth;
}

int Castle::getHealth()
{
    return health;
}
