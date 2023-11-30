#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QGraphicsPixmapItem>

// 前置宣告
class Bullet;

class Tank : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Tank();
    virtual void Rotate(int x);

    virtual int getRotation() const;
    virtual void setRotation(int newRotation);

    bool getIsBulletInScene() const;
    void setIsBulletInScene(bool newIsBulletInScene);

    Bullet* getBullet() const;
    void setBullet(Bullet *newBullet);

signals:
private:
    int Rotation;
    Bullet *bullet;
    bool isBulletInScene;

};

#endif // TANK_H
