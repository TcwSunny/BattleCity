#ifndef FASTTANK_H
#define FASTTANK_H

#include "Tank.h"

class FastTank : public Tank
{
public:
    FastTank();
public slots:
    void move();

signals:
private:
    QTimer *timer;

    bool isChangingDirection;

};

#endif // FASTTANK_H
