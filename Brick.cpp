#include "Brick.h"

Brick::Brick()
{
    QPixmap pixmap(":/images/Images/bricks.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}
