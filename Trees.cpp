#include "Trees.h"

Trees::Trees()
{
    QPixmap pixmap(":/images/Images/trees.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}
