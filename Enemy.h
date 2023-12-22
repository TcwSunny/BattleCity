#ifndef ENEMY_H
#define ENEMY_H

#include "EnemyBullet.h"
#include "Tank.h"



class Enemy: public Tank
{
    Q_OBJECT
public:
    explicit Enemy();
    ~Enemy();
    EnemyBullet *getBullet() const;
    void setBullet(EnemyBullet *newBullet);
    void enemyShootBullet();

    int getHealth() const;
    void decreaseHealth();


public slots:
    void move();

signals:

private:
    QTimer *timer;
    QTimer *timerBullet;
    bool isChangingDirection;
    EnemyBullet *bullet;
    int health;
    int enemyState;
    bool isMovementPaused;
};


#endif // ENEMY_H
