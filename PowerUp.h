#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsPixmapItem>
#include <QObject>

class PowerUp :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PowerUp();
    ~PowerUp();
    int getPowerUpNumber();
signals:
    void activatePowerUp(int);
private:
    int powerUpNumber;
};

#endif // POWERUP_H
