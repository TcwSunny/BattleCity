#include "Scene.h"
#include "Environment.h"
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
                Environment *barrier = dynamic_cast<Environment *>(item);
                if (barrier && (barrier->getMapState()== 0 || barrier->getMapState()== 1)) {
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
                Environment *barrier = dynamic_cast<Environment *>(item);
                if (barrier && (barrier->getMapState()== 0 || barrier->getMapState()== 1)) {
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
    int BrickX[13] = {202, 202, 234, 266, 266, 74, 10, 138, 170, 106, 234, 270, 238};
    int BrickY[13] = {266, 298, 266, 266, 298, 106, 202, 10, 170, 266, 106, 10, 10};
    for(int i = 0; i <13;i++){
        if(i<5){
            for(int j= 0;j<5;j++){ //把堡壘的牆壁改厚一點 打五次才會消失
                Bricks[i*5+j] =new Environment();
                Bricks[i*5+j]->setBrick();
                Bricks[i*5+j]->setPos(BrickX[i],BrickY[i]);
                addItem(Bricks[i*5+j]);

            }
        }
        else{
            Bricks[i+20] =new Environment();
            Bricks[i+20]->setBrick();
            Bricks[i+20]->setPos(BrickX[i],BrickY[i]);
            addItem(Bricks[i+20]);
        }
    }

    int WaterX[9] = {298, 330, 330, 298, 298, 330, 362, 362, 298};
    int WaterY[9] = {170, 170, 138, 138, 106, 106, 138, 170, 74};
    for(int i = 0; i <9;i++){
            Water[i] =new Environment();
            Water[i]->setWater();
            Water[i]->setPos(WaterX[i],WaterY[i]);
            addItem(Water[i]);
    }

    int TreesX[11] = {362, 362, 394, 394, 394, 426, 426, 330, 458, 458, 485};
    int TreesY[11] = {42, 106, 10, 74, 138, 42, 106, 74, 10, 74, 138};
    for(int i = 0; i <9;i++){
        Trees[i] =new Environment();
        Trees[i]->setTree();
        Trees[i]->setPos(TreesX[i],TreesY[i]);
        Trees[i]->setZValue(1);
        addItem(Trees[i]);
    }

    Castle = new Environment();
    Castle->setCastle();
    Castle->setPos(234,298);
    addItem(Castle);
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
    // Brick* brick =new Brick;
    // brick->setPos(10,266);
    // addItem(brick);
    // for(int i = 1;i<=13;i++){
    //     Water* water =new Water;
    //     water->setPos(10+i*32,266);
    //     addItem(water);
    //     Brick* brick =new Brick;
    //     brick->setPos(10+i*32,266);
    //     addItem(brick);

    // }
    // for(int i = 0;i<=6;i++){
    //     Brick* brick =new Brick;
    //     brick->setPos(426,234-i*32);
    //     addItem(brick);
    // }
    // for(int i = 0;i<=11;i++){
    //     Water* water =new Water;
    //     water->setPos(42+i*32,42);
    //     addItem(water);
    //     Brick* brick =new Brick;
    //     brick->setPos(42+i*32,42);
    //     addItem(brick);
    // }
    // for(int i = 0;i<=4;i++){
    //     Brick* brick =new Brick;
    //     brick->setPos(42,74+i*32);
    //     addItem(brick);
    // }
    // for(int i = 0;i<=9;i++){
    //     Brick* brick =new Brick;
    //     brick->setPos(74+i*32,202);
    //     addItem(brick);
    // }

    // for(int i = 0;i<=2;i++){
    //     Brick* brick =new Brick;
    //     brick->setPos(362,170-i*32);
    //     addItem(brick);
    // }
    // for(int i = 0;i<=7;i++){
    //     Brick* brick =new Brick;
    //     brick->setPos(106+i*32,106);
    //     addItem(brick);
    // }
    // for(int i = 0;i<=7;i++){
    //     Water* water =new Water;
    //     water->setPos(106+i*32,138);
    //     addItem(water);
    //     Water* water2 =new Water;
    //     water2->setPos(106+i*32,170);
    //     addItem(water2);
    // }

}
