#include "BasicTank.h"
#include "FastTank.h"
#include "Brick.h"
#include "Scene.h"
#include "Water.h"
#include "Trees.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDebug>

Scene::Scene(QObject *parent)
    :QGraphicsScene{parent}
{
    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/images/Images/backGround.jpg"));
    addItem(pixItem);

    player1 = new Player1;
    player1->setPos(10,298);
    addItem(player1);

    BasicTank* basicTank = new BasicTank;
    basicTank->setPos(10,10);
    addItem(basicTank);

    FastTank* fastTank = new FastTank;
    fastTank->setPos(490,10);
    addItem(fastTank);

    Brick* brick =new Brick;
    brick->setPos(202,266);
    addItem(brick);
    Brick* brick3 =new Brick;
    brick3->setPos(202,298);
    addItem(brick3);
    Brick* brick2 =new Brick;
    brick2->setPos(234,266);
    addItem(brick2);
    Brick* brick4 =new Brick;
    brick4->setPos(266,266);
    addItem(brick4);
    Brick* brick5 =new Brick;
    brick5->setPos(266,298);
    addItem(brick5);
    Brick* brick6 =new Brick;
    brick6->setPos(74,106);
    addItem(brick6);
    Brick* brick7 =new Brick;
    brick7->setPos(10,202);
    addItem(brick7);
    Brick* brick8 =new Brick;
    brick8->setPos(138,10);
    addItem(brick8);
    Brick* brick9 =new Brick;
    brick9->setPos(170,170);
    addItem(brick9);
    Brick* brick10 =new Brick;
    brick10->setPos(106,266);
    addItem(brick10);
    Brick* brick11 =new Brick;
    brick11->setPos(234,106);
    addItem(brick11);
    Brick* brick12 =new Brick;
    brick12->setPos(270,10);
    addItem(brick12);
    Brick* brick13 =new Brick;
    brick13->setPos(270-32,10);
    addItem(brick13);

    Water* water = new Water;
    water -> setPos(298,170);
    addItem(water);
    Water* water2 = new Water;
    water2 -> setPos(330,170);
    addItem(water2);
    Water* water3 = new Water;
    water3 -> setPos(330,138);
    addItem(water3);
    Water* water4 = new Water;
    water4 -> setPos(298,138);
    addItem(water4);
    Water* water5 = new Water;
    water5 -> setPos(298,106);
    addItem(water5);
    Water* water6 = new Water;
    water6 -> setPos(330,106);
    addItem(water6);
    Water* water7 = new Water;
    water7 -> setPos(362,138);
    addItem(water7);
    Water* water8 = new Water;
    water8 -> setPos(362,170);
    addItem(water8);
    Water* water9 = new Water;
    water9 -> setPos(298,74);
    addItem(water9);

    Trees* tree = new Trees;
    Trees* tree2 = new Trees;
    Trees* tree3 = new Trees;
    Trees* tree4 = new Trees;
    Trees* tree5 = new Trees;
    Trees* tree6 = new Trees;
    Trees* tree7 = new Trees;
    Trees* tree8 = new Trees;
    Trees* tree9 = new Trees;
    Trees* tree10 = new Trees;
    Trees* tree11 = new Trees;
    tree8->setPos(330,74);
    tree->setPos(362,42);
    tree2->setPos(362,106);
    tree3->setPos(394,10);
    tree4->setPos(394,74);
    tree5->setPos(394,138);
    tree6->setPos(426,42);
    tree7->setPos(426,106);
    tree9->setPos(458,10);
    tree10->setPos(458,74);
    tree11->setPos(458,138);
    addItem(tree);
    addItem(tree2);
    addItem(tree3);
    addItem(tree4);
    addItem(tree5);
    addItem(tree6);
    addItem(tree7);
    addItem(tree8);
    addItem(tree9);
    addItem(tree10);
    addItem(tree11);


}


void Scene::keyPressEvent(QKeyEvent *event){
    bool IsBrick = false;
    bool IsWater = false;

    QList<QGraphicsItem*> colliding_items = player1->collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
        Brick *brick = dynamic_cast<Brick *>(item);
        if (brick) {
            IsBrick = true;
        }
        Water *water = dynamic_cast<Water *>(item);
        if (water) {
            IsWater = true;
        }
    }

    if(IsBrick==0 && IsWater==0){
        if (event->key() == Qt::Key_Left && player1->x()>10) {
            player1->setPos(player1->x()-4,player1->y());
            player1->Rotate(270);
        } else if (event->key() == Qt::Key_Right && player1->x()<458) {
            player1->setPos(player1->x()+4,player1->y());
            player1->Rotate(90);
        } else if (event->key() == Qt::Key_Up && player1->y()>10) {
            player1->setPos(player1->x(),player1->y()-4);
            player1->Rotate(0);
        } else if (event->key() == Qt::Key_Down && player1->y()<298) {
            player1->setPos(player1->x(),player1->y()+4);
            player1->Rotate(180);
        }
    }else{
        if (player1->getRotation() == 0){
            player1->setPos(player1->x(),player1->y()+4);
        }else if (player1->getRotation() == 90){
            player1->setPos(player1->x()-4,player1->y());
        }else if(player1->getRotation() == 180){
            player1->setPos(player1->x(),player1->y()-4);
        }else if(player1->getRotation() == 270){
            player1->setPos(player1->x()+4,player1->y());
        }
    }
    if (event->key() == Qt::Key_Space && player1->getIsBulletInScene()==0) {
        player1->getBullet()->setPos(player1->x()+12,player1->y()+12);
        player1->getBullet()->Rotate(player1->getRotation());
        addItem(player1->getBullet());
        player1->setIsBulletInScene(1);
    }


}
