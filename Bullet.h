#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

// 前置宣告
class Tank;

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(Tank *tank);

    int getRotation() const;
    void setRotation(int newRotation);

    Tank *getParent() const;
    void setParent(Tank *newParent);

public slots:
    void move();
    void Rotate(int x);

signals:

private:
    QTimer *timer;
    int Rotation;
    Tank *Parent;
};

#endif // BULLET_H
