#include "Player1.h"

Player1::Player1()
{
    QPixmap pixmap(":/images/Images/Tank_Player1.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);

}
