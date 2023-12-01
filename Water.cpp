#include "Water.h"

Water::Water()
{
    QPixmap pixmap(":/images/Images/water.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}
