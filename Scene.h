#ifndef SCENE_H
#define SCENE_H

#include "Player1.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

private:
    Player1 *player1;

};

#endif // SCENE_H
