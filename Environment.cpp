#include "Environment.h"
#include <QMetaObject>

Environment::Environment()
{

}

void Environment::setMapState(MapType state)
{
    environmentState = state;
}

Environment::MapType Environment::getMapState()
{
    return environmentState;
}

void Environment::setBrick()
{
    setMapState(mapBrick);
    QPixmap pixmap(":/images/Images/bricks.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}

void Environment::setWater()
{
    setMapState(mapWater);
    QPixmap pixmap(":/images/Images/water.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}


void Environment::setTree()
{
    setMapState(mapTree);
    QPixmap pixmap(":/images/Images/trees.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}

void Environment::setCastle()
{
    setMapState(mapCastle);
    QPixmap pixmap(":/images/Images/bitch.jpg");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);
}
