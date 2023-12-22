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
    enum gameOn{game1,game2, levelOneWin,levelTwoWin, end};
    explicit Scene(QObject *parent = nullptr);
    void generateLevel();
    void updateHealthText();
    void togglePause();

    void useGrenade();
    void map1();
    void map2();



public slots:
    void updateGameState();
    void clearLevelOne();
    void addScore(int newScore);
    void killingCount();
    void generatePowerUp();


private:
    Player *player1;
    Player *player2;
   // Bullet *bullet1;
    gameOn GameOn;

    QGraphicsTextItem *healthText1;
    QGraphicsTextItem *healthText2;
    QGraphicsTextItem *pauseText;
    QGraphicsTextItem *continueText;
    QGraphicsTextItem *scoreText;

    QTimer *healthTimer;
    QTimer *enemyTimer;
    QGraphicsPixmapItem *backGround;

    bool twoPlayer;

    bool player1Die;
    bool player2Die;

    int score;
    int killnum;
    int generatedEnemyCount;

    bool isGamePaused ;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
