#include "Castle.h"

Castle::Castle()
{
    QPixmap pixmap(":/images/Images/bitch.jpg");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}
