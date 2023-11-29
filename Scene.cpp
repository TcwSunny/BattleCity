#include "Scene.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

Scene::Scene(QObject *parent)
    :QGraphicsScene{parent}
{
    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/images/Images/backGround.jpg"));
    addItem(pixItem);

    player1 = new Player1;
    player1->setPos(30,638);
    addItem(player1);
}

void Scene::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left && player1->x()>30) {
        player1->setPos(player1->x()-4,player1->y());
        player1->Rotate(180);
    } else if (event->key() == Qt::Key_Right && player1->x()<638) {
        player1->setPos(player1->x()+4,player1->y());
        player1->Rotate(0);
    } else if (event->key() == Qt::Key_Up && player1->y()>30) {
        player1->setPos(player1->x(),player1->y()-4);
        player1->Rotate(270);
    } else if (event->key() == Qt::Key_Down && player1->y()<638) {
        player1->setPos(player1->x(),player1->y()+4);
        player1->Rotate(90);
    }


}
