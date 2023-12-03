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
    Bullet();

    virtual int getRotation() const;
    virtual void setRotation(int newRotation);

    virtual Tank *getParent() const;
    virtual void setParent(Tank *newParent);

public slots:
    virtual void move();
    virtual void Rotate(int x);

signals:

protected:
    QTimer *timer;
    int Rotation;
    Tank *Parent;
};

#endif // BULLET_H
