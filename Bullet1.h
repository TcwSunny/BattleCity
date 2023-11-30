#ifndef BULLET1_H
#define BULLET1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>


class Bullet1 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet1();

    int getRotation() const;
    void setRotation(int newRotation);

    bool getIsBulletInScene() const;
    void setIsBulletInScene(bool newIsBulletInScene);

public slots:
    void move();
    void Rotate(int x);

signals:

private:
    QTimer *timer;
    int Rotation;
    bool isBulletInScene;
};
#endif // BULLET1_H
