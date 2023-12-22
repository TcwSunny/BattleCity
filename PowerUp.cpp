#include "PowerUp.h"
#include "QGraphicsScene"
#include "Scene.h"
#include <QRandomGenerator>

PowerUp::PowerUp()
{
    QPixmap pixmap;
    powerUpNumber  = QRandomGenerator::global()->bounded(1,3);
    //powerUpNumber =1;

    switch (powerUpNumber) {
    case 1:
        pixmap.load(":/images/Images/Powerup_Grenade.png");

        break;
    case 2:
        pixmap.load(":/images/Images/Powerup_Tank.png");

        break;
    case 3:
        pixmap.load(":/images/Images/Powerup_Timer.png");

        break;
    }
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);

}

PowerUp::~PowerUp()
{
    //目前用不到
    switch(powerUpNumber){
    case 1:
        qDebug()<<"gernade";
        break;
    case 2:
        qDebug()<<"Tank.";
        break;
    case 3:
        qDebug()<<"Time";
        break;

    }
}

int PowerUp::getPowerUpNumber()
{
    return powerUpNumber;
}
