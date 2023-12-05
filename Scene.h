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
public slots:

private:
    Player1 *player1;
    Bullet *bullet1;


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
