#ifndef SCENE_H
#define SCENE_H

#include "Player.h"
#include "Environment.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum GameState{Start, LevelOne, LevelTwo};
    enum PlayerState{Alive, Died, None};
    Scene(QObject *parent = nullptr); // 多載的建構子宣告
    void keyPressEvent(QKeyEvent *event);
    void updateGameState(GameState newState);
    void generateLevel();
    void LevelOneMap();
    void clearLevel();
    void LevelTwoMap();
private:
    QGraphicsPixmapItem *backGround;
    GameState gameState;
    PlayerState player1State;
    PlayerState player2State;
    bool twoPlayer;
    Player *player1;
    Player *player2;

    Environment* Bricks[35] = {} ;
    Environment* Water[30] = {} ;
    Environment* Trees[30] = {};
    Environment* Castle;

};

#endif // SCENE_H

