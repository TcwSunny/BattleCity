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
    void updateHealthText();
    void togglePause();

public slots:
    void updateGameState();
    void clearLevelOne();
    void addScore(int newScore);
    void killingCount();

private:
    Player *player1;
    Player *player2;
    Bullet *bullet1;

    QGraphicsTextItem *healthText1;
    QGraphicsTextItem *healthText2;
    QGraphicsTextItem *pauseText;
    QGraphicsTextItem *continueText;
    QGraphicsTextItem *scoreText;

    QTimer *healthTimer;
    QTimer *enemyTimer;
    QGraphicsPixmapItem *backGround;
    bool GameOn;
    bool twoPlayer;

    bool player1Die;
    bool player2Die;

    int score;
    int killnum;

    bool isGamePaused ;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
