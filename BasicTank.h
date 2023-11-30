#ifndef BASICTANK_H
#define BASICTANK_H

#include "Tank.h"



class BasicTank: public Tank
{
public:
    BasicTank();

public slots:
    void move();

private:
    QTimer *timer;
    bool isChangingDirection;
};

#endif // BASICTANK_H
