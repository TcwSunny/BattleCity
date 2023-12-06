#ifndef SCENE_H
#define SCENE_H

#include "Bullet.h"
#include "Player1.h"

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
    Player1 *player1;
    Bullet *bullet1;

    QGraphicsTextItem *healthText;

    QTimer *healthTimer;


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
