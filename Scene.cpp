#include "Enemy.h"
#include "Brick.h"
#include "Scene.h"
#include "Water.h"
#include "Trees.h"
#include "Castle.h"
#include <QGraphicsPixmapItem>
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
    GameOn = 0;
    player1Die = 0;
    player2Die = 0;
    score = 0;
    killnum = 0;
    isGamePaused = false;

    //generateLevelTwo();
}

void Scene::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_P) {
        togglePause();
    }
    if(GameOn == 1){
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
        if(isGamePaused){
            return; //如果game paused,不能動
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
        if(twoPlayer){
            bool IsBrick2 = false;
            bool IsWater2 = false;
            QList<QGraphicsItem*> colliding_items2 = player2->collidingItems();
            foreach (QGraphicsItem *item2, colliding_items2) {
                Brick *brick = dynamic_cast<Brick *>(item2);
                if (brick) {
                    IsBrick2 = true;
                }
                Water *water = dynamic_cast<Water *>(item2);
                if (water) {
                    IsWater2 = true;
                }
            }
            if(IsBrick2==0 && IsWater2==0){
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
            if (event->key() == Qt::Key_E && player2->getIsBulletInScene()==0) {
                player2->getBullet()->setPos(player2->x()+12,player2->y()+12);
                player2->getBullet()->Rotate(player2->getRotation());
                addItem(player2->getBullet());
                player2->setIsBulletInScene(1);
            }
        }

    }

    if(GameOn == 0 && (event->key() == Qt::Key_1)){
        GameOn = 1;
        twoPlayer = 0;
        generateLevelOne();
        qDebug() << "Start"<<twoPlayer;
    }
    if(GameOn == 0 && (event->key() == Qt::Key_2)){
        GameOn = 1;
        twoPlayer = 1;
        generateLevelOne();
        qDebug() << "Start"<<twoPlayer;
    }
}
void Scene::generateLevelOne()
{
    backGround = new QGraphicsPixmapItem(QPixmap(":/images/Images/backGround.jpg"));
    backGround->setZValue(-0.75);
    addItem(backGround);

    player1 = new Player(1);
    player1->setPos(10,298);
    player1->setZValue(-0.5);
    addItem(player1);

    if(twoPlayer){
        player2 = new Player(2);
        player2->setPos(300,298);
        player2->setZValue(-0.5);
        addItem(player2);
    }



    Enemy* enemy = new Enemy;
    enemy->setPos(10,10);
    enemy->setZValue(-0.5);
    connect(enemy->getBullet(),&EnemyBullet::playerDie,this,&Scene::updateGameState);
    connect(enemy,&Enemy::enemyDie,this,&Scene::addScore);
    addItem(enemy);
    enemyTimer = new QTimer();
    connect(enemyTimer, &QTimer::timeout, this, [=]() {
        static int generatedEnemyCount = 0;
        if (generatedEnemyCount < 20) {
            int enemyGenetate = QRandomGenerator::global()->bounded(0, 3);
            Enemy* enemy = new Enemy;
            connect(enemy->getBullet(),&EnemyBullet::playerDie,this,&Scene::updateGameState);
            connect(enemy,&Enemy::enemyDie,this,&Scene::addScore);
            enemy->setPos(enemyGenetate * 200, 10);
            enemy->setZValue(-0.5);
            addItem(enemy);
            generatedEnemyCount++;
        } else {
            enemyTimer->stop();  // 生成 20 台敵人坦克後停止計時器
        }
    });
    enemyTimer->start(4000);



    healthText1 = new QGraphicsTextItem();
    healthText1->setPos(510,288); // Adjust the position as needed
    QColor textColor(Qt::white); // Example: White text color
    healthText1->setDefaultTextColor(textColor);
    addItem(healthText1);
    healthText2 = new QGraphicsTextItem();
    healthText2->setPos(510,300); // Adjust the position as needed
    QColor textColor2(Qt::white); // Example: White text color
    healthText2->setDefaultTextColor(textColor2);
    addItem(healthText2);
    updateHealthText();

    pauseText = new QGraphicsTextItem();
    pauseText->setPos(495,200);
    pauseText->setDefaultTextColor(textColor);
    QString pauseStr = QString("Press P to pause");
    pauseText->setPlainText(pauseStr);
    addItem(pauseText);

    healthTimer= new QTimer();
    connect(healthTimer, &QTimer::timeout, this, &Scene::updateHealthText);
    healthTimer->start(500);
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


    connect(enemy->getBullet(),&EnemyBullet::castleDie,this,&Scene::clearLevelOne);
    connect(player1->getBullet(),&PlayerBullet::killOneEnemy,this,&Scene::killingCount);

    if(twoPlayer){
    connect(player2->getBullet(),&PlayerBullet::killOneEnemy,this,&Scene::killingCount);
    }
    //QTimer::singleShot(5000, this, &Scene::clearLevelOne);
}

void Scene::generateLevelTwo()
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


void Scene::clearLevelOne() //到時候換關的時候可以用 !!!!
    {
        enemyTimer->stop();
        // 清除所有Brick
        QList<QGraphicsItem*> brickItems = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem* item : brickItems) {
            Brick* brick = dynamic_cast<Brick*>(item);
            if (brick) {
                removeItem(brick);
                delete brick;
            }
        }

        // 清除所有Water
        QList<QGraphicsItem*> waterItems = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem* item : waterItems) {
            Water* water = dynamic_cast<Water*>(item);
            if (water) {
                removeItem(water);
                delete water;
            }
        }

        // 清除所有Tree
        QList<QGraphicsItem*> treeItems = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem* item : treeItems) {
            Trees* tree = dynamic_cast<Trees*>(item);
            if (tree) {
                removeItem(tree);
                delete tree;
            }
        }
        // 清除所有bitch
        QList<QGraphicsItem*> bitch = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem* item : bitch) {
            Castle* bitch = dynamic_cast<Castle*>(item);
            if (bitch) {
                removeItem(bitch);
                delete bitch;
            }
        }
        QList<QGraphicsItem*> tank = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem* item : tank) {
            Tank* tank = dynamic_cast<Tank*>(item);
            if (tank) {
                removeItem(tank);
                delete tank;
            }
        }
        QList<QGraphicsItem*> bullet = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem* item : bullet) {
            Bullet* bullet = dynamic_cast<Bullet*>(item);
            if (bullet) {
                removeItem(bullet);
                delete bullet;
            }
        }
        healthTimer->stop();
        removeItem(healthText1);
        delete healthText1;
        if(twoPlayer){
            removeItem(healthText2);
            delete healthText2;
            backGround = new QGraphicsPixmapItem(QPixmap(":/images/Images/End2Player.jpg"));
        }else{
            backGround = new QGraphicsPixmapItem(QPixmap(":/images/Images/End1Player.jpg"));
        }
        removeItem(pauseText);
        delete pauseText;
        backGround->setZValue(-0.75);
        addItem(backGround);
    }

    void Scene::addScore(int newScore)
    {
        score = score+newScore;
        qDebug() << score;
    }

    void Scene::killingCount()
    {
        killnum++;
        qDebug()<<killnum;
        if(killnum==3){
            GameOn = 0;
            clearLevelOne();
        }
    }

    void Scene::updateHealthText()
    {
        QString healthStr = QString("Health1 : %2").arg(player1->getHealth());
        healthText1->setPlainText(healthStr);

        if(twoPlayer){
            QString healthStr2 = QString("Health2 : %2").arg(player2->getHealth());
            healthText2->setPlainText(healthStr2);
        }

    }

    void Scene::togglePause()
    {
        isGamePaused = !isGamePaused;

        if (isGamePaused) {
            continueText = new QGraphicsTextItem("Press P to \n continue");
            continueText->setPos(70,70);
            continueText->setZValue(1.5);
            QFont font;
            font.setPointSize(60);  // Set the font size to 16
            font.setBold(true);
            continueText->setFont(font);
            QColor textColor(Qt::white);
            continueText->setDefaultTextColor(textColor);
            addItem(continueText);

            // Pause game logic (stop timers, freeze movements, etc.)
            // For example:
            enemyTimer->stop();
            healthTimer->stop();

        } else {
            // Resume game logic (start timers, allow movements, etc.)
            // For example:
            enemyTimer->start();
            healthTimer->start();
            removeItem(continueText);
            delete continueText;
        }
        QList<QGraphicsItem*> enemyItems = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem* item : enemyItems) {
            Enemy* enemy = dynamic_cast<Enemy*>(item);
            if (enemy) {
                enemy->toggleMovementPause();
            }
        }
        QList<QGraphicsItem *> bulletItems = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem *item : bulletItems) {
            EnemyBullet *bullet = dynamic_cast<EnemyBullet *>(item);
            if (bullet) {
                bullet->toggleMovementPause();
            }
        }
        QList<QGraphicsItem *> bulletItems2 = items(QRectF(0, 0, width(), height()), Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem *item : bulletItems2) {
            PlayerBullet *bullet = dynamic_cast<PlayerBullet *>(item);
            if (bullet) {
                bullet->toggleMovementPause();
            }
        }

    }

    void Scene::updateGameState()
    {
        if(twoPlayer){
            if(player1->getHealth() == 0){
                removeItem(player1);
                player1Die = 1;
                qDebug() << "1Die";
            }
            if(player2->getHealth() == 0){
                removeItem(player2);
                player2Die = 1;
                qDebug() << "2Die";
            }
            if(player1Die&&player2Die){
                GameOn = 0;
                clearLevelOne();
            }
        }else if(player1->getHealth() == 0){
            GameOn = 0;
            clearLevelOne();
        }

    }

