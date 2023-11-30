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

    int getRotation() const;
    void setRotation(int newRotation);

signals:
private:
    int Rotation;

};

#endif // PLAYER1_H
