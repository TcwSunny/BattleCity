#include "Scene.h"
#include <QGraphicsPixmapItem>

Scene::Scene(QObject *parent)
    :QGraphicsScene{parent}
{
    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/images/Images/backGround.jpg"));
    addItem(pixItem);

    player1 = new Player1;
    player1->setPos(400,300);
    addItem(player1);
}
