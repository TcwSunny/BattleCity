#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Tank;

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(Tank *tank);

    virtual int getRotation() const;
    virtual void setRotation(int newRotation);


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
