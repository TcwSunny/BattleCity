#ifndef SCENE_H
#define SCENE_H

#include "Bullet.h"
#include "Player.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void generateLevelOne();
    void generateLevelTwo();
    void clearLevelOne();
    void updateHealthText();

private:
    Player *player1;
    Player *player2;
    Bullet *bullet1;

    QGraphicsTextItem *healthText1;
    QGraphicsTextItem *healthText2;

    QTimer *healthTimer;
    QTimer *enemyTimer;


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    QGraphicsPixmapItem *backGround;
    bool GameOn;
    bool twoPlayer;
};

#endif // SCENE_H
