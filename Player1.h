#ifndef PLAYER1_H
#define PLAYER1_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Player1 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player1();
    void Rotate(int x);

signals:

};

#endif // PLAYER1_H
