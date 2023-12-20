#include "Scene.h"
#include "Brick.h"
#include "Water.h"
#include "Trees.h"
#include "Castle.h"
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDebug>
#include <QTimer>
#include <QFont>

Scene::Scene(QObject *parent)
    :QGraphicsScene{parent}
{
    backGround = new QGraphicsPixmapItem(QPixmap(":/images/Images/EnterScene.png"));
    backGround->setZValue(-1);
    addItem(backGround);

    gameState = Start;
}
void Scene::keyPressEvent(QKeyEvent *event){
    if(gameState == Start){
        if(event->key() == Qt::Key_1){
            player1State = Alive;
            player2State = None;
            updateGameState(LevelOne);
        }
        if(event->key() == Qt::Key_2){
            player1State = Alive;
            player2State = Alive;
            updateGameState(LevelOne);
        }

    }
    if(gameState == LevelOne || gameState == LevelTwo){
        if(player1State == Alive){
            bool Stop = false;
            QList<QGraphicsItem*> colliding_items = player1->collidingItems();
            foreach (QGraphicsItem *item, colliding_items) {
                Brick *brick = dynamic_cast<Brick *>(item);
                if (brick) {
                    Stop = true;
                }
                Water *water = dynamic_cast<Water *>(item);
                if (water) {
                    Stop = true;
                }
            }
            if (!Stop){
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
        }
        if(player2State == Alive){
            bool Stop2 = false;
            QList<QGraphicsItem*> colliding_items = player2->collidingItems();
            foreach (QGraphicsItem *item, colliding_items) {
                Brick *brick = dynamic_cast<Brick *>(item);
                if (brick) {
                    Stop2 = true;
                }
                Water *water = dynamic_cast<Water *>(item);
                if (water) {
                    Stop2 = true;
                }
            }
            if (!Stop2){
                if (event->key() == Qt::Key_A && player2->x()>10) {
                    player2->setPos(player2->x()-4,player2->y());
                    player2->Rotate(270);
                } else if (event->key() == Qt::Key_D && player2->x()<458) {
                    player2->setPos(player2->x()+4,player2->y());
                    player2->Rotate(90);
                } else if (event->key() == Qt::Key_W && player2->y()>10) {
                    player2->setPos(player2->x(),player2->y()-4);
                    player2->Rotate(0);
                } else if (event->key() == Qt::Key_S && player2->y()<298) {
                    player2->setPos(player2->x(),player2->y()+4);
                    player2->Rotate(180);
                }
            }else{
                if (player2->getRotation() == 0){
                    player2->setPos(player2->x(),player2->y()+4);
                }else if (player2->getRotation() == 90){
                    player2->setPos(player2->x()-4,player2->y());
                }else if(player2->getRotation() == 180){
                    player2->setPos(player2->x(),player2->y()-4);
                }else if(player2->getRotation() == 270){
                    player2->setPos(player2->x()+4,player2->y());
                }
            }
        }
    }
    if(gameState == LevelOne){
        if (event->key() == Qt::Key_N) {
            updateGameState(LevelTwo);
        }
    }

}

void Scene::updateGameState(GameState newState)
{
    if(gameState == Start && newState == LevelOne){
        gameState = LevelOne;
        generateLevel();
    }if(gameState == LevelOne && newState == LevelTwo){
        gameState = LevelTwo;
        clearLevel();
        generateLevel();

    }
}

void Scene::generateLevel(){
    backGround = new QGraphicsPixmapItem(QPixmap(":/images/Images/backGround.jpg"));
    backGround->setZValue(-0.75);
    addItem(backGround);
    if(gameState == LevelOne){
        LevelOneMap();
    }else if(gameState == LevelTwo){
        LevelTwoMap();
    }


    if(player1State == Alive){
        player1 = new Player(1);
        player1->setPos(10,298);
        player1->setZValue(-0.5);
        addItem(player1);
    }
    if(player2State == Alive){
        player2 = new Player(2);
        player2->setPos(300,298);
        player2->setZValue(-0.5);
        addItem(player2);
    }

}
void Scene::LevelOneMap(){
    for(int i= 0;i<5;i++){ //把堡壘的牆壁改厚一點 打五次才會消失
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
        addItem(brick5);}

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
    tree->setZValue(1);
    tree2->setZValue(1);
    tree3->setZValue(1);
    tree4->setZValue(1);
    tree5->setZValue(1);
    tree6->setZValue(1);
    tree7->setZValue(1);
    tree8->setZValue(1);
    tree9->setZValue(1);
    tree10->setZValue(1);
    tree11->setZValue(1);
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

    Castle* castle = new Castle;
    castle->setPos(234,298);
    addItem(castle);
}

void Scene::clearLevel()
{
    QList<QGraphicsItem*> itemsList = items();
    for (QGraphicsItem* item : itemsList) {
        removeItem(item);
        delete item;
    }
}

void Scene::LevelTwoMap()
{
    Brick* brick =new Brick;
    brick->setPos(10,266);
    addItem(brick);
    for(int i = 1;i<=13;i++){
        Water* water =new Water;
        water->setPos(10+i*32,266);
        addItem(water);
        Brick* brick =new Brick;
        brick->setPos(10+i*32,266);
        addItem(brick);

    }
    for(int i = 0;i<=6;i++){
        Brick* brick =new Brick;
        brick->setPos(426,234-i*32);
        addItem(brick);
    }
    for(int i = 0;i<=11;i++){
        Water* water =new Water;
        water->setPos(42+i*32,42);
        addItem(water);
        Brick* brick =new Brick;
        brick->setPos(42+i*32,42);
        addItem(brick);
    }
    for(int i = 0;i<=4;i++){
        Brick* brick =new Brick;
        brick->setPos(42,74+i*32);
        addItem(brick);
    }
    for(int i = 0;i<=9;i++){
        Brick* brick =new Brick;
        brick->setPos(74+i*32,202);
        addItem(brick);
    }

    for(int i = 0;i<=2;i++){
        Brick* brick =new Brick;
        brick->setPos(362,170-i*32);
        addItem(brick);
    }
    for(int i = 0;i<=7;i++){
        Brick* brick =new Brick;
        brick->setPos(106+i*32,106);
        addItem(brick);
    }
    for(int i = 0;i<=7;i++){
        Water* water =new Water;
        water->setPos(106+i*32,138);
        addItem(water);
        Water* water2 =new Water;
        water2->setPos(106+i*32,170);
        addItem(water2);
    }

}
